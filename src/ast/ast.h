#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NODE_PROGRAM,
    NODE_IMPORT,
    NODE_PACKET,
    NODE_FUNCTION,
    NODE_LET,
    NODE_CONST,
    NODE_IF,
    NODE_FOR,
    NODE_WHILE,
    NODE_LOOP,
    NODE_MATCH,
    NODE_RETURN,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_NUMBER,
    NODE_FLOAT,
    NODE_STRING,
    NODE_BOOL,
    NODE_IDENTIFIER,
    NODE_CALL,
    NODE_MEMBER_ACCESS,
    NODE_ARRAY,
    NODE_STRUCT,
    NODE_ENUM,
    NODE_RANGE,
    NODE_PIPE,
    NODE_NIL
} NodeType;

typedef enum {
    OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_EQ, OP_NEQ, OP_LT, OP_GT,
    OP_AND, OP_OR, OP_NOT, OP_NEG
} Operator;

typedef struct ASTNode {
    NodeType type;
    int line;
    union {
        struct {
            char* name;
            struct ASTNodeList* statements;
        } program;
        struct {
            char* path;
            char* alias;
            struct ASTNode* condition;
        } import;
        struct {
            char* name;
            struct ASTNodeList* statements;
        } packet;
        struct {
            char* name;
            struct ASTNodeList* params;
            struct ASTNode* return_type;
            struct ASTNodeList* body;
            int is_main;
        } function;
        struct {
            char* name;
            struct ASTNode* type;
            struct ASTNode* value;
        } var_decl;
        struct {
            struct ASTNode* condition;
            struct ASTNode* then_branch;
            struct ASTNode* else_branch;
        } if_stmt;
        struct {
            struct ASTNode* init;
            struct ASTNode* condition;
            struct ASTNode* body;
        } for_stmt;
        struct {
            struct ASTNode* condition;
            struct ASTNode* body;
        } while_stmt;
        struct {
            struct ASTNode* body;
        } loop_stmt;
        struct {
            struct ASTNode* value;
            struct ASTNodeList* cases;
        } match_stmt;
        struct {
            Operator op;
            struct ASTNode* left;
            struct ASTNode* right;
        } binary;
        struct {
            Operator op;
            struct ASTNode* operand;
        } unary;
        struct {
            int value;
        } number;
        struct {
            double value;
        } float_val;
        struct {
            char* value;
        } string_val;
        struct {
            int value;
        } bool_val;
        struct {
            char* name;
        } identifier;
        struct {
            struct ASTNode* callee;
            struct ASTNodeList* args;
        } call;
        struct {
            struct ASTNode* object;
            char* member;
        } member;
        struct {
            struct ASTNode* start;
            struct ASTNode* end;
            int inclusive;
        } range;
        struct {
            struct ASTNode* value;
            struct ASTNode* next;
        } pipe;
        struct {
            struct ASTNodeList* elements;
        } array;
        struct {
            char* name;
            struct ASTNodeList* fields;
        } struct_def;
        struct {
            char* name;
            struct ASTNodeList* variants;
        } enum_def;
    };
} ASTNode;

typedef struct ASTNodeList {
    ASTNode** nodes;
    int count;
    int capacity;
} ASTNodeList;

// Fonctions de création
ASTNode* create_program_node(ASTNodeList* statements);
ASTNode* create_import_node(char* path, char* alias);
ASTNode* create_packet_import_node(char* path);
ASTNode* create_conditional_import_node(char* path, ASTNode* condition);
ASTNode* create_packet_node(char* name, ASTNodeList* statements);
ASTNode* create_function_node(char* name, ASTNodeList* params, ASTNode* return_type, ASTNodeList* body);
ASTNode* create_main_function_node(char* name, ASTNodeList* params, ASTNode* return_type, ASTNodeList* body);
ASTNode* create_let_node(char* name, ASTNode* type, ASTNode* value);
ASTNode* create_const_node(char* name, ASTNode* value);
ASTNode* create_if_node(ASTNode* condition, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* create_elseif_node(ASTNode* condition, ASTNode* then_branch, ASTNode* else_branch);
ASTNode* create_for_range_node(char* var, ASTNode* start, ASTNode* end, ASTNodeList* body);
ASTNode* create_for_cond_node(ASTNode* condition, ASTNodeList* body);
ASTNode* create_while_node(ASTNode* condition, ASTNodeList* body);
ASTNode* create_loop_node(ASTNodeList* body);
ASTNode* create_match_node(ASTNode* value, ASTNodeList* cases);
ASTNode* create_return_node(ASTNode* value);
ASTNode* create_binary_op(ASTNode* left, Operator op, ASTNode* right);
ASTNode* create_unary_op(Operator op, ASTNode* operand);
ASTNode* create_number_node(int value);
ASTNode* create_float_node(double value);
ASTNode* create_string_node(char* value);
ASTNode* create_bool_node(int value);
ASTNode* create_nil_node();
ASTNode* create_identifier_node(char* name);
ASTNode* create_call_node(ASTNode* callee, ASTNodeList* args);
ASTNode* create_member_access(ASTNode* object, char* member);
ASTNode* create_static_access(ASTNode* object, char* member);
ASTNode* create_pipe_op(ASTNode* left, ASTNode* right);
ASTNode* create_range_node(ASTNode* start, ASTNode* end, int inclusive);
ASTNode* create_array_node(ASTNodeList* elements);
ASTNode* create_struct_node(char* name, ASTNodeList* fields);
ASTNode* create_enum_node(char* name, ASTNodeList* variants);

// Fonctions pour les listes
ASTNodeList* create_node_list();
void add_to_node_list(ASTNodeList* list, ASTNode* node);
ASTNodeList* create_param_list();
void add_param(ASTNodeList* list, ASTNode* param);
ASTNode* create_param_node(char* name, ASTNode* type);
ASTNode* create_type_node(char* name);
ASTNode* create_array_type_node(ASTNode* element_type);
ASTNode* create_chan_type_node(ASTNode* channel_type);
ASTNodeList* create_case_list();
void add_case(ASTNodeList* list, ASTNode* case_node);
ASTNode* create_match_case_node(ASTNode* pattern, ASTNode* value);
ASTNodeList* create_field_list();
void add_field(ASTNodeList* list, ASTNode* field);
ASTNode* create_field_node(char* name, ASTNode* type);
ASTNodeList* create_variant_list();
void add_variant(ASTNodeList* list, ASTNode* variant);
ASTNode* create_variant_node(char* name, ASTNodeList* types);
ASTNodeList* create_arg_list();
void add_arg(ASTNodeList* list, ASTNode* arg);
ASTNodeList* create_array_items();
void add_array_item(ASTNodeList* list, ASTNode* item);
ASTNodeList* create_field_init_list();
void add_field_init(ASTNodeList* list, ASTNode* init);
ASTNode* create_field_init_node(char* name, ASTNode* value);
ASTNodeList* create_type_list();
void add_type(ASTNodeList* list, ASTNode* type);

// Fonctions utilitaires
void free_ast(ASTNode* node);
void print_ast(ASTNode* node, int depth);
ASTNode* evaluate(ASTNode* node, struct Environment* env);

#endif
