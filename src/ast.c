#include "../inc/common.h"
#include "../inc/ast.h"

// Création d'un nœud d'opération binaire (ex: addition)
Node* create_binary_node(NodeType type, Node* left, Node* right) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

// Création d'un nœud pour une déclaration de variable
Node* create_var_decl(const char* name, Node* initializer) {
    Node* node = (Node*)allocate(sizeof(Node));
    node->type = NODE_VARIABLE_DECL;
    // On pourrait stocker le nom ici
    node->right = initializer;
    return node;
}

// Libération mémoire de l'AST (indispensable pour ton interpréteur)
void free_ast(Node* node) {
    if (node == NULL) return;
    free_ast(node->left);
    free_ast(node->right);
    free(node);
}

