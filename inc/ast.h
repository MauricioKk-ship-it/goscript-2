#ifndef GOSCRIPT_AST_H
#define GOSCRIPT_AST_H


typedef enum {
    NODE_BINARY_OP,
    NODE_LITERAL,
    NODE_VARIABLE_DECL,
    NODE_FUNCTION_DECL,
    NODE_CALL
} NodeType;

typedef struct Node {
    NodeType type;
    struct Node *left;
    struct Node *right;
    // Données spécifiques (valeur, nom de variable, etc.)
} Node;

#endif // GOSCRIPT_AST_H

