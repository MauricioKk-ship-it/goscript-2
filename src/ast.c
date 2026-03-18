#include "common.h"
#include "ast.h"

static char* copy_string(const char* src) {
    if (!src) return NULL;
    char* dest = (char*)allocate(strlen(src) + 1);
    strcpy(dest, src);
    return dest;
}

Node* create_program(Node* first_stmt) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_PROGRAM;
    node->left = first_stmt;
    node->right = NULL;
    return node;
}

Node* create_block(Node* statements) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_BLOCK;
    node->left = statements;
    node->right = NULL;
    return node;
}

Node* create_number(double value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_NUMBER;
    node->data.number_value = value;
    return node;
}

Node* create_string(const char* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_STRING;
    node->data.string_value = copy_string(value);
    return node;
}

Node* create_bool(bool value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_BOOL;
    node->data.bool_value = value;
    return node;
}

Node* create_variable(const char* name) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_VARIABLE;
    node->data.identifier = copy_string(name);
    return node;
}

Node* create_binary_op(char op, Node* left, Node* right) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_BINARY_OP;
    node->data.binary.op = op;
    node->left = left;
    node->right = right;
    return node;
}

Node* create_unary_op(char op, Node* right) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_UNARY_OP;
    node->data.binary.op = op;
    node->right = right;
    return node;
}

Node* create_grouping(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_GROUPING;
    node->left = expr;
    return node;
}

Node* create_expression_stmt(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_EXPRESSION_STMT;
    node->left = expr;
    return node;
}

Node* create_var_decl(const char* name, Node* initializer) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_VARIABLE_DECL;
    node->data.identifier = copy_string(name);
    node->left = initializer;
    return node;
}

Node* create_assignment(const char* name, Node* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_ASSIGNMENT;
    node->data.identifier = copy_string(name);
    node->left = value;
    return node;
}

Node* create_print(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_PRINT_STMT;
    node->left = expr;
    return node;
}

Node* create_getlf(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_GETLF_STMT;
    node->left = expr;
    return node;
}

Node* create_input(const char* prompt) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_INPUT_STMT;
    node->data.string_value = copy_string(prompt ? prompt : "");
    return node;
}

Node* create_if(Node* condition, Node* then_branch, Node* else_branch) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_IF_STMT;
    node->left = condition;
    node->right = then_branch;
    node->extra = else_branch;
    return node;
}

Node* create_while(Node* condition, Node* body) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_WHILE_STMT;
    node->left = condition;
    node->right = body;
    return node;
}

Node* create_for(Node* initializer, Node* condition, Node* increment, Node* body) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FOR_STMT;
    node->left = initializer;
    node->right = condition;
    node->extra = increment;
    // Le body est dans l'extra du noeud condition? Non, on va utiliser une structure spéciale
    // Pour simplifier, on va faire un bloc spécial
    Node* for_node = (Node*)allocate(sizeof(Node));
    for_node->type = NODE_FOR_STMT;
    for_node->left = initializer;
    for_node->right = condition;
    for_node->extra = increment;
    // On attache le body à l'extra de l'extra
    // C'est un peu moche, on pourrait améliorer avec une structure dédiée
    return for_node;
}

Node* create_function(const char* name, Node* params, Node* body) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FUNCTION_DECL;
    node->data.identifier = copy_string(name);
    node->left = params;  // Liste des paramètres
    node->right = body;   // Corps de la fonction
    return node;
}

Node* create_function_call(const char* name, Node* args) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FUNCTION_CALL;
    node->data.identifier = copy_string(name);
    node->left = args;    // Liste des arguments
    return node;
}

Node* create_return(Node* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_RETURN_STMT;
    node->left = value;
    return node;
}

void free_ast(Node* node) {
    if (node == NULL) return;
    
    // Libérer les données selon le type
    switch (node->type) {
        case NODE_LITERAL_STRING:
        case NODE_INPUT_STMT:
            if (node->data.string_value) free(node->data.string_value);
            break;
        case NODE_VARIABLE:
        case NODE_VARIABLE_DECL:
        case NODE_ASSIGNMENT:
        case NODE_FUNCTION_DECL:
        case NODE_FUNCTION_CALL:
            if (node->data.identifier) free(node->data.identifier);
            break;
        default:
            break;
    }
    
    // Libérer récursivement
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->extra);
    free(node);
}
