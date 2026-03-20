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

/* Function declarations for AST creation */
ASTNode* create_program_node(ASTNodeList* statements);
ASTNode* create_import_node(char* path, char* alias);
ASTNode* create_packet_import_node(char* path);
ASTNode* create_packet_node(char* name, ASTNodeList* statements);
ASTNode* create_function_node(char* name, ASTNodeList* params, ASTNode* return_type, ASTNodeList* body);
ASTNode* create_main_function_node(char* name, ASTNodeList* params, ASTNode* return_type, ASTNodeList* body);
ASTNode* create_let_node(char* name, ASTNode* type, ASTNode* value);
ASTNode* create_const_node(char* name, ASTNode* value);
ASTNode* create_if_node(ASTNode* condition, ASTNodeList* then_branch, ASTNodeList* else_branch);
ASTNode* create_while_node(ASTNode* condition, ASTNodeList* body);
ASTNode* create_loop_node(ASTNodeList* body);
ASTNode* create_return_node(ASTNode* value);
ASTNode* create_expr_statement(ASTNode* expr);
ASTNode* create_binary_op(ASTNode* left, int op, ASTNode* right);
ASTNode* create_unary_op(int op, ASTNode* operand);
ASTNode* create_number_node(int value);
ASTNode* create_float_node(double value);
ASTNode* create_string_node(char* value);
ASTNode* create_bool_node(int value);
ASTNode* create_nil_node();
ASTNode* create_identifier_node(char* name);
ASTNode* create_call_node(ASTNode* callee, ASTNodeList* args);
ASTNode* create_array_node(ASTNodeList* elements);
ASTNode* create_struct_node(char* name, ASTNodeList* fields);
ASTNode* create_enum_node(char* name, ASTNodeList* variants);
ASTNode* create_for_node(ASTNode* init, ASTNode* cond, ASTNode* inc, ASTNodeList* body);
ASTNode* create_assign_node(ASTNode* left, ASTNode* right);

ASTNodeList* create_node_list();
void add_to_node_list(ASTNodeList* list, ASTNode* node);
ASTNodeList* create_arg_list();
void add_arg(ASTNodeList* list, ASTNode* arg);
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
%token TOKEN_NIL TOKEN_TRUE TOKEN_FALSE TOKEN_AS TOKEN_IN TOKEN_FROM
%token TOKEN_AT

/* Operators */
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY TOKEN_DIVIDE TOKEN_MODULO
%token TOKEN_ASSIGN TOKEN_EQ TOKEN_NEQ TOKEN_LT TOKEN_LTE TOKEN_GT TOKEN_GTE
%token TOKEN_AND TOKEN_OR TOKEN_NOT TOKEN_AMP TOKEN_PIPE
%token TOKEN_ARROW TOKEN_FAT_ARROW TOKEN_RANGE TOKEN_RANGE_INC
%token TOKEN_COALESCE TOKEN_OPTIONAL
%token TOKEN_COLON TOKEN_SEMICOLON TOKEN_COMMA TOKEN_DOT TOKEN_DOUBLE_COLON
%token TOKEN_PIPE_FORWARD

/* Delimiters */
%token TOKEN_LPAREN TOKEN_RPAREN TOKEN_LBRACE TOKEN_RBRACE
%token TOKEN_LBRACKET TOKEN_RBRACKET

/* Types */
%token <string> TOKEN_IDENTIFIER
%token <number> TOKEN_NUMBER
%token <float_val> TOKEN_FLOAT
%token <string> TOKEN_STRING

/* Non-terminals */
%type <node> program statement expression block
%type <node> function_decl let_decl const_decl return_statement
%type <node> if_statement for_statement while_statement loop_statement
%type <node> binary_expr unary_expr primary_expr call_expr
%type <node> import_statement packet_decl struct_decl enum_decl
%type <node_list> statement_list argument_list param_list struct_fields enum_variants

/* Operator precedence */
%left TOKEN_PIPE_FORWARD
%left TOKEN_OR
%left TOKEN_AND
%left TOKEN_EQ TOKEN_NEQ
%left TOKEN_LT TOKEN_LTE TOKEN_GT TOKEN_GTE
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE TOKEN_MODULO
%right TOKEN_NOT TOKEN_OPTIONAL
%nonassoc TOKEN_RANGE TOKEN_RANGE_INC

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
    | struct_decl
    | enum_decl
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

/* Imports */
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
    | TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_IDENTIFIER {
        $$ = create_import_node($4, $2);
    }
    | TOKEN_IMPORT TOKEN_DOT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_IDENTIFIER {
        char* path = malloc(strlen($3) + 3);
        sprintf(path, "./%s", $3);
        $$ = create_import_node(path, $5);
        free(path);
    }
    ;

packet_decl:
    TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_packet_node($2, $4);
    }
    | TOKEN_PACKET TOKEN_IDENTIFIER {
        $$ = create_packet_node($2, NULL);
    }
    ;

/* Functions */
function_decl:
    TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_function_node($2, $4, NULL, $7);
    }
    | TOKEN_FN TOKEN_AT TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_main_function_node($3, $5, NULL, $8);
    }
    ;

param_list:
    /* empty */ {
        $$ = NULL;
    }
    | TOKEN_IDENTIFIER {
        $$ = create_node_list();
        add_to_node_list($$, create_identifier_node($1));
    }
    | param_list TOKEN_COMMA TOKEN_IDENTIFIER {
        add_to_node_list($1, create_identifier_node($3));
        $$ = $1;
    }
    ;

/* Variables */
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

/* Conditionals */
if_statement:
    TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_if_node($2, $4, NULL);
    }
    | TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = create_if_node($2, $4, $8);
    }
    | TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE TOKEN_ELSEIF expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        ASTNodeList* else_branch = create_node_list();
        add_to_node_list(else_branch, create_if_node($7, $9, NULL));
        $$ = create_if_node($2, $4, else_branch);
    }
    ;

/* Loops */
for_statement:
    TOKEN_FOR TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON expression TOKEN_SEMICOLON expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
        ASTNode* init = create_let_node($2, NULL, $4);
        ASTNode* cond = $6;
        ASTNode* inc = create_expr_statement($8);
        $$ = create_for_node(init, cond, inc, $10);
    }
    | TOKEN_FOR expression TOKEN_LBRACE statement_list TOKEN_RBRACE {
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

/* Return */
return_statement:
    TOKEN_RETURN expression TOKEN_SEMICOLON {
        $$ = create_return_node($2);
    }
    | TOKEN_RETURN TOKEN_SEMICOLON {
        $$ = create_return_node(NULL);
    }
    ;

/* Structs */
struct_decl:
    TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE {
        $$ = create_struct_node($2, $4);
    }
    ;

struct_fields:
    /* empty */ {
        $$ = NULL;
    }
    | TOKEN_IDENTIFIER TOKEN_COLON TOKEN_IDENTIFIER TOKEN_COMMA {
        $$ = create_node_list();
        add_to_node_list($$, create_identifier_node($1));
    }
    | struct_fields TOKEN_IDENTIFIER TOKEN_COLON TOKEN_IDENTIFIER TOKEN_COMMA {
        add_to_node_list($1, create_identifier_node($2));
        $$ = $1;
    }
    ;

/* Enums */
enum_decl:
    TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LBRACE enum_variants TOKEN_RBRACE {
        $$ = create_enum_node($2, $4);
    }
    ;

enum_variants:
    /* empty */ {
        $$ = NULL;
    }
    | TOKEN_IDENTIFIER TOKEN_COMMA {
        $$ = create_node_list();
        add_to_node_list($$, create_identifier_node($1));
    }
    | enum_variants TOKEN_IDENTIFIER TOKEN_COMMA {
        add_to_node_list($1, create_identifier_node($2));
        $$ = $1;
    }
    ;

/* Expressions */
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
    | expression TOKEN_MODULO expression {
        $$ = create_binary_op($1, OP_MOD, $3);
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
    | expression TOKEN_LTE expression {
        $$ = create_binary_op($1, OP_LTE, $3);
    }
    | expression TOKEN_GT expression {
        $$ = create_binary_op($1, OP_GT, $3);
    }
    | expression TOKEN_GTE expression {
        $$ = create_binary_op($1, OP_GTE, $3);
    }
    | expression TOKEN_AND expression {
        $$ = create_binary_op($1, OP_AND, $3);
    }
    | expression TOKEN_OR expression {
        $$ = create_binary_op($1, OP_OR, $3);
    }
    | expression TOKEN_ASSIGN expression {
        $$ = create_assign_node($1, $3);
    }
    | expression TOKEN_RANGE expression {
        $$ = create_binary_op($1, OP_RANGE, $3);
    }
    | expression TOKEN_PIPE_FORWARD expression {
        $$ = create_binary_op($1, OP_PIPE, $3);
    }
    ;

unary_expr:
    TOKEN_NOT expression {
        $$ = create_unary_op(OP_NOT, $2);
    }
    | TOKEN_MINUS expression {
        $$ = create_unary_op(OP_NEG, $2);
    }
    | TOKEN_OPTIONAL expression {
        $$ = create_unary_op(OP_OPTIONAL, $2);
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
    | array_expr
    | struct_expr
    ;

call_expr:
    primary_expr TOKEN_LPAREN argument_list TOKEN_RPAREN {
        $$ = create_call_node($1, $3);
    }
    | primary_expr TOKEN_DOT TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN {
        ASTNode* member = create_member_access($1, $3);
        $$ = create_call_node(member, $5);
    }
    | primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN {
        ASTNode* static_member = create_static_access($1, $3);
        $$ = create_call_node(static_member, $5);
    }
    ;

argument_list:
    /* empty */ {
        $$ = NULL;
    }
    | expression {
        $$ = create_arg_list();
        add_arg($$, $1);
    }
    | argument_list TOKEN_COMMA expression {
        add_arg($1, $3);
        $$ = $1;
    }
    ;

array_expr:
    TOKEN_LBRACKET array_items TOKEN_RBRACKET {
        $$ = create_array_node($2);
    }
    ;

array_items:
    /* empty */ {
        $$ = NULL;
    }
    | expression {
        $$ = create_node_list();
        add_to_node_list($$, $1);
    }
    | array_items TOKEN_COMMA expression {
        add_to_node_list($1, $3);
        $$ = $1;
    }
    ;

struct_expr:
    TOKEN_IDENTIFIER TOKEN_LBRACE struct_init_fields TOKEN_RBRACE {
        $$ = create_struct_init_node($1, $3);
    }
    ;

struct_init_fields:
    /* empty */ {
        $$ = NULL;
    }
    | TOKEN_IDENTIFIER TOKEN_COLON expression {
        $$ = create_node_list();
        add_to_node_list($$, create_binary_op(create_identifier_node($1), OP_ASSIGN, $3));
    }
    | struct_init_fields TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON expression {
        add_to_node_list($1, create_binary_op(create_identifier_node($3), OP_ASSIGN, $5));
        $$ = $1;
    }
    ;

block:
    TOKEN_LBRACE statement_list TOKEN_RBRACE {
        $$ = (ASTNode*)$2;
    }
    ;

%%

void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, msg, yytext);
}
