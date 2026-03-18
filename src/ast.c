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
    node->extra = NULL;
    return node;
}

Node* create_block(Node* statements) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_BLOCK;
    node->left = statements;
    node->right = NULL;
    node->extra = NULL;
    return node;
}

Node* create_number(double value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_NUMBER;
    node->data.number_value = value;
    node->left = node->right = node->extra = NULL;
    return node;
}

Node* create_string(const char* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_STRING;
    node->data.string_value = copy_string(value);
    node->left = node->right = node->extra = NULL;
    return node;
}

Node* create_bool(bool value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_LITERAL_BOOL;
    node->data.bool_value = value;
    node->left = node->right = node->extra = NULL;
    return node;
}

Node* create_variable(const char* name) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_VARIABLE;
    node->data.identifier = copy_string(name);
    node->left = node->right = node->extra = NULL;
    return node;
}

Node* create_binary_op(char op, Node* left, Node* right) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_BINARY_OP;
    node->data.binary.op = op;
    node->left = left;
    node->right = right;
    node->extra = NULL;
    return node;
}

Node* create_unary_op(char op, Node* right) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_UNARY_OP;
    node->data.binary.op = op;
    node->left = NULL;
    node->right = right;
    node->extra = NULL;
    return node;
}

Node* create_grouping(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_GROUPING;
    node->left = expr;
    node->right = node->extra = NULL;
    return node;
}

Node* create_expression_stmt(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_EXPRESSION_STMT;
    node->left = expr;
    node->right = node->extra = NULL;
    return node;
}

Node* create_var_decl(const char* name, Node* initializer) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_VARIABLE_DECL;
    node->data.identifier = copy_string(name);
    node->left = initializer;
    node->right = node->extra = NULL;
    return node;
}

Node* create_assignment(const char* name, Node* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_ASSIGNMENT;
    node->data.identifier = copy_string(name);
    node->left = value;
    node->right = node->extra = NULL;
    return node;
}

Node* create_print(Node* expr) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_PRINT_STMT;
    node->left = expr;
    node->right = node->extra = NULL;
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
    node->extra = NULL;
    return node;
}

Node* create_for(Node* init, Node* cond, Node* incr, Node* body) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FOR_STMT;
    node->left = init;
    node->right = cond;
    
    // On utilise un noeud intermédiaire pour l'incrément et le corps
    Node* extra = (Node*)allocate(sizeof(Node));
    extra->left = body;
    extra->right = incr;
    node->extra = extra;
    
    return node;
}

Node* create_function(const char* name, Node* params, Node* body) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FUNCTION_DECL;
    node->data.identifier = copy_string(name);
    node->left = params;
    node->extra = body; // CRITIQUE: On stocke le corps dans extra pour libérer 'right'
    node->right = NULL; 
    return node;
}

Node* create_function_call(const char* name, Node* args) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_FUNCTION_CALL;
    node->data.identifier = copy_string(name);
    node->left = args;
    node->right = node->extra = NULL;
    return node;
}

Node* create_return(Node* value) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_RETURN_STMT;
    node->left = value;
    node->right = node->extra = NULL;
    return node;
}

void free_ast(Node* node) {
    if (node == NULL) return;
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->extra);
    if (node->type == NODE_VARIABLE || node->type == NODE_FUNCTION_DECL || node->type == NODE_VARIABLE_DECL) {
        if (node->data.identifier) free(node->data.identifier);
    }
    free(node);
}
