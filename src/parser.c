#include "common.h"
#include "lexer.h"
#include "ast.h"
#include "parser.h"

typedef struct {
    Token current;
    Token previous;
    bool had_error;
    bool panic_mode;
} Parser;

static Parser parser;

static void advance();
static void consume(TokenType type, const char* message);
static bool match(TokenType type);
static bool check(TokenType type);
static void error_at_current(const char* message);
static void synchronize();

// Fonctions de parsing par niveau de précédence
static Node* expression();
static Node* assignment();
static Node* equality();
static Node* comparison();
static Node* term();
static Node* factor();
static Node* unary();
static Node* call();
static Node* primary();

// Déclarations et statements
static Node* declaration();
static Node* statement();
static Node* var_declaration();
static Node* print_statement();
static Node* getlf_statement();
static Node* input_statement();
static Node* if_statement();
static Node* while_statement();
static Node* for_statement();
static Node* block_statement();
static Node* return_statement();
static Node* function_declaration();
static Node* function_call(Token name);
static Node* arguments();

static void advance() {
    parser.previous = parser.current;
    
    for (;;) {
        parser.current = scan_token();
        if (parser.current.type != TOKEN_ERROR) break;
        
        error_at_current(parser.current.start);
    }
}

static void consume(TokenType type, const char* message) {
    if (parser.current.type == type) {
        advance();
        return;
    }
    
    error_at_current(message);
}

static bool match(TokenType type) {
    if (!check(type)) return false;
    advance();
    return true;
}

static bool check(TokenType type) {
    return parser.current.type == type;
}

static void error_at_current(const char* message) {
    if (parser.panic_mode) return;
    parser.panic_mode = true;
    
    fprintf(stderr, "[Erreur] Ligne %d: ", parser.current.line);
    fprintf(stderr, "%s\n", message);
    
    parser.had_error = true;
}

static void synchronize() {
    parser.panic_mode = false;
    
    while (parser.current.type != TOKEN_EOF) {
        if (parser.previous.type == TOKEN_SEMICOLON) return;
        
        switch (parser.current.type) {
            case TOKEN_CLASS:
            case TOKEN_FN:
            case TOKEN_LET:
            case TOKEN_CONST:
            case TOKEN_IF:
            case TOKEN_WHILE:
            case TOKEN_FOR:
            case TOKEN_PRINT:
            case TOKEN_GETLF:
            case TOKEN_RETURN:
                return;
            default:
                break;
        }
        
        advance();
    }
}

// Parsing des expressions avec précédence
static Node* expression() {
    return assignment();
}

static Node* assignment() {
    Node* expr = equality();
    
    if (match(TOKEN_EQUAL)) {
        Token equals = parser.previous;
        Node* value = assignment();
        
        if (expr->type == NODE_VARIABLE) {
            Token name = parser.previous;
            return create_assignment(expr->data.identifier, value);
        }
        
        error_at_current("Cible d'affectation invalide");
        return expr;
    }
    
    return expr;
}

static Node* equality() {
    Node* expr = comparison();
    
    while (match(TOKEN_BANG_EQUAL) || match(TOKEN_EQUAL_EQUAL)) {
        char op = parser.previous.type == TOKEN_BANG_EQUAL ? '!' : '=';
        Node* right = comparison();
        expr = create_binary_op(op, expr, right);
    }
    
    return expr;
}

static Node* comparison() {
    Node* expr = term();
    
    while (match(TOKEN_GREATER) || match(TOKEN_GREATER_EQUAL) ||
           match(TOKEN_LESS) || match(TOKEN_LESS_EQUAL)) {
        char op = parser.previous.start[0];
        if (parser.previous.type == TOKEN_GREATER_EQUAL) op = 'g'; // g pour >=
        else if (parser.previous.type == TOKEN_LESS_EQUAL) op = 'l'; // l pour <=
        
        Node* right = term();
        expr = create_binary_op(op, expr, right);
    }
    
    return expr;
}

static Node* term() {
    Node* expr = factor();
    
    while (match(TOKEN_MINUS) || match(TOKEN_PLUS)) {
        char op = parser.previous.type == TOKEN_PLUS ? '+' : '-';
        Node* right = factor();
        expr = create_binary_op(op, expr, right);
    }
    
    return expr;
}

static Node* factor() {
    Node* expr = unary();
    
    while (match(TOKEN_SLASH) || match(TOKEN_STAR)) {
        char op = parser.previous.type == TOKEN_STAR ? '*' : '/';
        Node* right = unary();
        expr = create_binary_op(op, expr, right);
    }
    
    return expr;
}

static Node* unary() {
    if (match(TOKEN_BANG) || match(TOKEN_MINUS)) {
        char op = parser.previous.type == TOKEN_BANG ? '!' : '-';
        Node* right = unary();
        return create_unary_op(op, right);
    }
    
    return call();
}

static Node* call() {
    Node* expr = primary();
    
    while (true) {
        if (match(TOKEN_LPAREN)) {
            expr = function_call(parser.previous);
        } else {
            break;
        }
    }
    
    return expr;
}

static Node* function_call(Token name) {
    Node* args = arguments();
    consume(TOKEN_RPAREN, "Attendu ')' après les arguments.");
    
    // Extraire le nom de la fonction de l'expression primaire
    char* func_name = NULL;
    if (name.type == TOKEN_IDENTIFIER) {
        func_name = (char*)allocate(name.length + 1);
        memcpy(func_name, name.start, name.length);
        func_name[name.length] = '\0';
    }
    
    return create_function_call(func_name, args);
}

static Node* arguments() {
    if (check(TOKEN_RPAREN)) return NULL;
    
    Node* args = expression();
    Node* current = args;
    
    while (match(TOKEN_COMMA)) {
        Node* next_arg = expression();
        if (current) {
            current->right = next_arg;
            current = next_arg;
        }
    }
    
    return args;
}

static Node* primary() {
    if (match(TOKEN_FALSE)) return create_bool(false);
    if (match(TOKEN_TRUE)) return create_bool(true);
    
    if (match(TOKEN_NUMBER)) {
        double value = strtod(parser.previous.start, NULL);
        return create_number(value);
    }
    
    if (match(TOKEN_STRING)) {
        char* str = (char*)allocate(parser.previous.length + 1);
        memcpy(str, parser.previous.start, parser.previous.length);
        str[parser.previous.length] = '\0';
        return create_string(str);
    }
    
    if (match(TOKEN_IDENTIFIER)) {
        char* name = (char*)allocate(parser.previous.length + 1);
        memcpy(name, parser.previous.start, parser.previous.length);
        name[parser.previous.length] = '\0';
        return create_variable(name);
    }
    
    if (match(TOKEN_LPAREN)) {
        Node* expr = expression();
        consume(TOKEN_RPAREN, "Attendu ')' après l'expression.");
        return create_grouping(expr);
    }
    
    error_at_current("Attendu une expression.");
    return create_number(0);
}

static Node* declaration() {
    if (match(TOKEN_FN)) return function_declaration();
    if (match(TOKEN_LET)) return var_declaration();
    
    return statement();
}

static Node* var_declaration() {
    consume(TOKEN_IDENTIFIER, "Attendu un nom de variable.");
    
    char* name = (char*)allocate(parser.previous.length + 1);
    memcpy(name, parser.previous.start, parser.previous.length);
    name[parser.previous.length] = '\0';
    
    Node* initializer = NULL;
    if (match(TOKEN_EQUAL)) {
        initializer = expression();
    }
    
    consume(TOKEN_SEMICOLON, "Attendu ';' après la déclaration de variable.");
    return create_var_decl(name, initializer);
}

static Node* statement() {
    if (match(TOKEN_PRINT)) return print_statement();
    if (match(TOKEN_GETLF)) return getlf_statement();
    if (match(TOKEN_INPUT)) return input_statement();
    if (match(TOKEN_IF)) return if_statement();
    if (match(TOKEN_WHILE)) return while_statement();
    if (match(TOKEN_FOR)) return for_statement();
    if (match(TOKEN_RETURN)) return return_statement();
    if (match(TOKEN_LBRACE)) return block_statement();
    
    return expression_statement();
}

static Node* expression_statement() {
    Node* expr = expression();
    consume(TOKEN_SEMICOLON, "Attendu ';' après l'expression.");
    return create_expression_stmt(expr);
}

static Node* print_statement() {
    consume(TOKEN_LPAREN, "Attendu '(' après print.");
    Node* expr = expression();
    consume(TOKEN_RPAREN, "Attendu ')' après la valeur à afficher.");
    consume(TOKEN_SEMICOLON, "Attendu ';' après print.");
    return create_print(expr);
}

static Node* getlf_statement() {
    consume(TOKEN_LPAREN, "Attendu '(' après getlf.");
    Node* expr = expression();
    consume(TOKEN_RPAREN, "Attendu ')' après getlf.");
    consume(TOKEN_SEMICOLON, "Attendu ';' après getlf.");
    return create_getlf(expr);
}

static Node* input_statement() {
    Node* prompt = NULL;
    if (match(TOKEN_LPAREN)) {
        if (!match(TOKEN_RPAREN)) {
            prompt = expression();
            consume(TOKEN_RPAREN, "Attendu ')' après le prompt.");
        }
    }
    consume(TOKEN_SEMICOLON, "Attendu ';' après input.");
    return create_input(prompt ? prompt->data.string_value : NULL);
}

static Node* if_statement() {
    consume(TOKEN_LPAREN, "Attendu '(' après if.");
    Node* condition = expression();
    consume(TOKEN_RPAREN, "Attendu ')' après la condition.");
    
    Node* then_branch = statement();
    Node* else_branch = NULL;
    
    if (match(TOKEN_ELSE)) {
        else_branch = statement();
    }
    
    return create_if(condition, then_branch, else_branch);
}

static Node* while_statement() {
    consume(TOKEN_LPAREN, "Attendu '(' après while.");
    Node* condition = expression();
    consume(TOKEN_RPAREN, "Attendu ')' après la condition.");
    
    Node* body = statement();
    
    return create_while(condition, body);
}

static Node* for_statement() {
    consume(TOKEN_LPAREN, "Attendu '(' après for.");
    
    // Initialisation
    Node* initializer = NULL;
    if (match(TOKEN_SEMICOLON)) {
        // Pas d'initialisation
    } else if (match(TOKEN_LET)) {
        initializer = var_declaration();
    } else {
        initializer = expression_statement();
    }
    
    // Condition
    Node* condition = NULL;
    if (!check(TOKEN_SEMICOLON)) {
        condition = expression();
    }
    consume(TOKEN_SEMICOLON, "Attendu ';' après la condition de la boucle.");
    
    // Incrément
    Node* increment = NULL;
    if (!check(TOKEN_RPAREN)) {
        increment = expression();
    }
    consume(TOKEN_RPAREN, "Attendu ')' après les clauses du for.");
    
    Node* body = statement();
    
    // Transformer en while
    // Pour simplifier, on va retourner un noeud spécial for
    return create_for(initializer, condition, increment, body);
}

static Node* block_statement() {
    Node* statements = NULL;
    Node* current = NULL;
    
    while (!check(TOKEN_RBRACE) && !check(TOKEN_EOF)) {
        Node* stmt = declaration();
        
        if (!statements) {
            statements = stmt;
            current = stmt;
        } else {
            current->right = stmt;
            current = stmt;
        }
    }
    
    consume(TOKEN_RBRACE, "Attendu '}' après le bloc.");
    return create_block(statements);
}

static Node* return_statement() {
    Node* value = NULL;
    if (!check(TOKEN_SEMICOLON)) {
        value = expression();
    }
    consume(TOKEN_SEMICOLON, "Attendu ';' après return.");
    return create_return(value);
}

static Node* function_declaration() {
    consume(TOKEN_IDENTIFIER, "Attendu un nom de fonction.");
    
    char* name = (char*)allocate(parser.previous.length + 1);
    memcpy(name, parser.previous.start, parser.previous.length);
    name[parser.previous.length] = '\0';
    
    consume(TOKEN_LPAREN, "Attendu '(' après le nom de la fonction.");
    
    // Paramètres
    Node* params = NULL;
    Node* current_param = NULL;
    
    if (!check(TOKEN_RPAREN)) {
        do {
            consume(TOKEN_IDENTIFIER, "Attendu un nom de paramètre.");
            char* param_name = (char*)allocate(parser.previous.length + 1);
            memcpy(param_name, parser.previous.start, parser.previous.length);
            param_name[parser.previous.length] = '\0';
            
            Node* param = create_variable(param_name);
            if (!params) {
                params = param;
                current_param = param;
            } else {
                current_param->right = param;
                current_param = param;
            }
        } while (match(TOKEN_COMMA));
    }
    
    consume(TOKEN_RPAREN, "Attendu ')' après les paramètres.");
    consume(TOKEN_LBRACE, "Attendu '{' avant le corps de la fonction.");
    
    Node* body = block_statement();
    
    return create_function(name, params, body);
}

Node* parse(void) {
    parser.had_error = false;
    parser.panic_mode = false;
    
    advance();
    
    Node* statements = NULL;
    Node* current = NULL;
    
    while (!check(TOKEN_EOF)) {
        Node* stmt = declaration();
        
        if (!statements) {
            statements = stmt;
            current = stmt;
        } else if (stmt) {
            if (current) current->right = stmt;
            current = stmt;
        }
        
        if (parser.panic_mode) synchronize();
    }
    
    if (parser.had_error) {
        free_ast(statements);
        return NULL;
    }
    
    return create_program(statements);
}
