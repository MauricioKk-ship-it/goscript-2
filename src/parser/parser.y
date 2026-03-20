%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno;
extern char* yytext;

void yyerror(const char* msg);
int yylex(void);

ASTNode* program_root;
%}

%union {
    int number;
    double float_val;
    char* string;
    struct ASTNode* node;
    struct ASTNodeList* node_list;
}

/* Tokens */
%token TOKEN_FN TOKEN_LET TOKEN_CONST TOKEN_RETURN
%token TOKEN_IF TOKEN_ELSE TOKEN_ELSEIF TOKEN_THEN
%token TOKEN_FOR TOKEN_WHILE TOKEN_LOOP TOKEN_BREAK TOKEN_CONTINUE
%token TOKEN_MATCH TOKEN_STRUCT TOKEN_ENUM TOKEN_IMPL
%token TOKEN_IMPORT TOKEN_PACKET TOKEN_EXPORT TOKEN_TYPE
%token TOKEN_GO TOKEN_CHAN TOKEN_SELECT
%token TOKEN_TRY TOKEN_CATCH TOKEN_FINALLY
%token TOKEN_NIL TOKEN_TRUE TOKEN_FALSE TOKEN_WHERE TOKEN_AS

/* Opérateurs */
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY TOKEN_DIVIDE TOKEN_MODULO
%token TOKEN_ASSIGN TOKEN_EQ TOKEN_NEQ TOKEN_LT TOKEN_LTE TOKEN_GT TOKEN_GTE
%token TOKEN_AND TOKEN_OR TOKEN_NOT TOKEN_AMP TOKEN_PIPE
%token TOKEN_ARROW TOKEN_FAT_ARROW TOKEN_RANGE TOKEN_RANGE_INC
%token TOKEN_COALESCE TOKEN_OPTIONAL
%token TOKEN_COLON TOKEN_SEMICOLON TOKEN_COMMA TOKEN_DOT TOKEN_DOUBLE_COLON
%token TOKEN_PIPE_FORWARD

/* Délimiteurs */
%token TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACE TOKEN_RBRACE
%token TOKEN_LBRACKET TOKEN_RBRACKET

/* Types */
%token <string> TOKEN_IDENTIFIER
%token <number> TOKEN_NUMBER
%token <float_val> TOKEN_FLOAT
%token <string> TOKEN_STRING

/* Types non-terminaux */
%type <node> program statement expression
%type <node> if_statement for_statement while_statement loop_statement
%type <node> import_statement packet_decl function_decl
%type <node> let_decl const_decl return_statement
%type <node> binary_expr unary_expr primary_expr call_expr
%type <node_list> statement_list

%start program

%%

program:
    statement_list {
        program_root = create_program_node($1);
    }
    ;

statement_list:
    statement {
        $$ = create_node_list();
        add_to_node_list($$, $1);
    }
    | statement_list statement {
        add_to_node_list($1, $2);
        $$ = $1;
    }
    ;

statement:
    import_statement
    | packet_decl
    | function_decl
    | let_decl
    | const_decl
    | if_statement
    | for_statement
    | while_statement
    | loop_statement
    | return_statement
    | expression TOKEN_SEMICOLON {
        $$ = create_expr_statement($1);
    }
    ;

import_statement:
    TOKEN_IMPORT TOKEN_IDENTIFIER {
        $$ = create_import_node($2, NULL);
    }
    | TOKEN_IMPORT TOKEN_DOT TOKEN_IDENTIFIER {
        char* path = malloc(strlen($3) + 3);
        sprintf(path, "./%s", $3);
        $$ = create_import_node(path, NULL);
        free(path);
    }
    | TOKEN_IMPORT TOKEN_PACKET TOKEN_IDENTIFIER {
        char* path = malloc(strlen($3) + 50);
        sprintf(path, "/usr/local/lib/goscript/granul/%s/__self__.gjs", $3);
        $$ = create_import_node(path, NULL);
        free(path);
    }
    ;

packet_decl:
    TOKEN_PACKET TOKEN_IDENTIFIER {
        $$ = create_packet_node($2, NULL);
    }
    ;

function_decl:
    TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_function_node($2, NULL, NULL, $6);
    }
    ;

let_decl:
    TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON {
        $$ = create_let_node($2, NULL, $4);
    }
    ;

const_decl:
    TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON {
        $$ = create_const_node($2, $4);
    }
    ;

if_statement:
    TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_if_node($2, $4, NULL);
    }
    ;

for_statement:
    TOKEN_FOR TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON expression TOKEN_SEMICOLON expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        // Simple for loop: for i = 0; i < 10; i = i + 1 { ... }
        ASTNode* init = create_let_node($2, NULL, $4);
        ASTNode* cond = $6;
        ASTNode* inc = create_expr_statement($8);
        // Créer un noeud for spécial
        $$ = create_for_node(init, cond, inc, $10);
    }
    | TOKEN_FOR expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        // While-style for: for condition { ... }
        $$ = create_while_node($2, $4);
    }
    ;

while_statement:
    TOKEN_WHILE expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_while_node($2, $4);
    }
    ;

loop_statement:
    TOKEN_LOOP TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_loop_node($3);
    }
    ;

return_statement:
    TOKEN_RETURN expression TOKEN_SEMICOLON {
        $$ = create_return_node($2);
    }
    ;

expression:
    binary_expr
    | unary_expr
    | primary_expr
    ;

binary_expr:
    expression TOKEN_PLUS expression {
        $$ = create_binary_op($1, OP_ADD, $3);
    }
    | expression TOKEN_MINUS expression {
        $$ = create_binary_op($1, OP_SUB, $3);
    }
    | expression TOKEN_MULTIPLY expression {
        $$ = create_binary_op($1, OP_MUL, $3);
    }
    | expression TOKEN_DIVIDE expression {
        $$ = create_binary_op($1, OP_DIV, $3);
    }
    | expression TOKEN_EQ expression {
        $$ = create_binary_op($1, OP_EQ, $3);
    }
    | expression TOKEN_NEQ expression {
        $$ = create_binary_op($1, OP_NEQ, $3);
    }
    | expression TOKEN_LT expression {
        $$ = create_binary_op($1, OP_LT, $3);
    }
    | expression TOKEN_GT expression {
        $$ = create_binary_op($1, OP_GT, $3);
    }
    | expression TOKEN_ASSIGN expression {
        $$ = create_assign_node($1, $3);
    }
    ;

unary_expr:
    TOKEN_NOT expression {
        $$ = create_unary_op(OP_NOT, $2);
    }
    | TOKEN_MINUS expression {
        $$ = create_unary_op(OP_NEG, $2);
    }
    ;

primary_expr:
    TOKEN_NUMBER {
        $$ = create_number_node($1);
    }
    | TOKEN_FLOAT {
        $$ = create_float_node($1);
    }
    | TOKEN_STRING {
        $$ = create_string_node($1);
    }
    | TOKEN_TRUE {
        $$ = create_bool_node(1);
    }
    | TOKEN_FALSE {
        $$ = create_bool_node(0);
    }
    | TOKEN_NIL {
        $$ = create_nil_node();
    }
    | TOKEN_IDENTIFIER {
        $$ = create_identifier_node($1);
    }
    | TOKEN_LPAREN expression TOKEN_RPAREN {
        $$ = $2;
    }
    | call_expr
    ;

call_expr:
    TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN {
        ASTNode* callee = create_identifier_node($1);
        $$ = create_call_node(callee, $3);
    }
    ;

argument_list:
    /* empty */ { $$ = NULL; }
    | expression {
        $$ = create_arg_list();
        add_arg($$, $1);
    }
    | argument_list TOKEN_COMMA expression {
        add_arg($1, $3);
        $$ = $1;
    }
    ;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "Erreur ligne %d: %s near '%s'\n", yylineno, msg, yytext);
}
