#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast/ast.h"

extern ASTNode* program_root;
extern FILE* yyin;
extern int yyparse(void);
extern int yylineno;

// Fonction pour afficher l'aide
void print_usage(const char* program_name) {
    printf("Usage: %s [options] <fichier.gjs>\n", program_name);
    printf("\nOptions:\n");
    printf("  -h, --help     Affiche cette aide\n");
    printf("  -v, --version  Affiche la version du langage\n");
    printf("  -d, --debug    Active le mode debug (affiche l'AST)\n");
    printf("\nExemples:\n");
    printf("  %s mon_programme.gjs\n", program_name);
    printf("  %s -d test.gjs\n", program_name);
}

// Fonction pour afficher la version
void print_version() {
    printf("Goscript Language v0.1.0\n");
    printf("Copyright (c) 2024 Goscript Team\n");
    printf("Un langage interprété moderne avec syntaxe inspirée de VLang et Rust\n");
}

// Fonction pour afficher l'AST (mode debug)
void print_ast(ASTNode* node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) printf("  ");
    
    switch (node->type) {
        case NODE_PROGRAM:
            printf("Program\n");
            if (node->program.statements) {
                for (int i = 0; i < node->program.statements->count; i++) {
                    print_ast(node->program.statements->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_IMPORT:
            printf("Import: %s", node->import.path);
            if (node->import.alias) printf(" as %s", node->import.alias);
            printf("\n");
            break;
            
        case NODE_PACKET:
            printf("Packet: %s\n", node->packet.name);
            if (node->packet.statements) {
                for (int i = 0; i < node->packet.statements->count; i++) {
                    print_ast(node->packet.statements->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_FUNCTION:
            printf("Function: %s", node->function.name);
            if (node->function.is_main) printf(" (main)");
            printf("\n");
            if (node->function.body) {
                for (int i = 0; i < node->function.body->count; i++) {
                    print_ast(node->function.body->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_LET:
            printf("Let: %s = ", node->var_decl.name);
            if (node->var_decl.value) {
                print_ast(node->var_decl.value, 0);
            } else {
                printf("nil");
            }
            printf("\n");
            break;
            
        case NODE_CONST:
            printf("Const: %s = ", node->var_decl.name);
            if (node->var_decl.value) {
                print_ast(node->var_decl.value, 0);
            }
            printf("\n");
            break;
            
        case NODE_IF:
            printf("If: ");
            print_ast(node->if_stmt.condition, 0);
            printf("\n");
            printf("Then:\n");
            if (node->if_stmt.then_branch) {
                for (int i = 0; i < node->if_stmt.then_branch->count; i++) {
                    print_ast(node->if_stmt.then_branch->nodes[i], depth + 1);
                }
            }
            if (node->if_stmt.else_branch) {
                for (int i = 0; i < depth; i++) printf("  ");
                printf("Else:\n");
                for (int i = 0; i < node->if_stmt.else_branch->count; i++) {
                    print_ast(node->if_stmt.else_branch->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_WHILE:
            printf("While: ");
            print_ast(node->while_stmt.condition, 0);
            printf("\n");
            if (node->while_stmt.body) {
                for (int i = 0; i < node->while_stmt.body->count; i++) {
                    print_ast(node->while_stmt.body->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_LOOP:
            printf("Loop\n");
            if (node->loop_stmt.body) {
                for (int i = 0; i < node->loop_stmt.body->count; i++) {
                    print_ast(node->loop_stmt.body->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_FOR:
            printf("For: ");
            if (node->for_range.var) {
                printf("%s in ", node->for_range.var);
                print_ast(node->for_range.start, 0);
                printf("..");
                if (node->for_range.end) print_ast(node->for_range.end, 0);
            } else if (node->for_range.start) {
                print_ast(node->for_range.start, 0);
            }
            printf("\n");
            if (node->for_range.body) {
                for (int i = 0; i < node->for_range.body->count; i++) {
                    print_ast(node->for_range.body->nodes[i], depth + 1);
                }
            }
            break;
            
        case NODE_RETURN:
            printf("Return: ");
            if (node->return_stmt.value) {
                print_ast(node->return_stmt.value, 0);
            } else {
                printf("nil");
            }
            printf("\n");
            break;
            
        case NODE_BINARY_OP:
            printf("(");
            print_ast(node->binary.left, 0);
            switch (node->binary.op) {
                case OP_ADD: printf(" + "); break;
                case OP_SUB: printf(" - "); break;
                case OP_MUL: printf(" * "); break;
                case OP_DIV: printf(" / "); break;
                case OP_EQ: printf(" == "); break;
                case OP_NEQ: printf(" != "); break;
                case OP_LT: printf(" < "); break;
                case OP_GT: printf(" > "); break;
                case OP_ASSIGN: printf(" = "); break;
                default: printf(" ? "); break;
            }
            print_ast(node->binary.right, 0);
            printf(")");
            break;
            
        case NODE_UNARY_OP:
            switch (node->unary.op) {
                case OP_NOT: printf("!"); break;
                case OP_NEG: printf("-"); break;
                default: printf("?"); break;
            }
            print_ast(node->unary.operand, 0);
            break;
            
        case NODE_NUMBER:
            printf("%d", node->number.value);
            break;
            
        case NODE_FLOAT:
            printf("%f", node->float_val.value);
            break;
            
        case NODE_STRING:
            printf("\"%s\"", node->string_val.value);
            break;
            
        case NODE_BOOL:
            printf("%s", node->bool_val.value ? "true" : "false");
            break;
            
        case NODE_NIL:
            printf("nil");
            break;
            
        case NODE_IDENTIFIER:
            printf("%s", node->identifier.name);
            break;
            
        case NODE_CALL:
            print_ast(node->call.callee, 0);
            printf("(");
            if (node->call.args) {
                for (int i = 0; i < node->call.args->count; i++) {
                    if (i > 0) printf(", ");
                    print_ast(node->call.args->nodes[i], 0);
                }
            }
            printf(")");
            break;
            
        case NODE_ARRAY:
            printf("[");
            if (node->array.elements) {
                for (int i = 0; i < node->array.elements->count; i++) {
                    if (i > 0) printf(", ");
                    print_ast(node->array.elements->nodes[i], 0);
                }
            }
            printf("]");
            break;
            
        case NODE_EXPR_STMT:
            print_ast(node->expr_stmt.expr, 0);
            printf("\n");
            break;
            
        default:
            printf("Unknown node type: %d\n", node->type);
            break;
    }
}

int main(int argc, char** argv) {
    int debug_mode = 0;
    char* filename = NULL;
    
    // Parser les arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0) {
            print_version();
            return 0;
        } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--debug") == 0) {
            debug_mode = 1;
        } else if (argv[i][0] != '-') {
            filename = argv[i];
        } else {
            fprintf(stderr, "Erreur: Option inconnue %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }
    
    // Vérifier qu'un fichier a été spécifié
    if (!filename) {
        fprintf(stderr, "Erreur: Aucun fichier source spécifié\n");
        print_usage(argv[0]);
        return 1;
    }
    
    // Vérifier l'extension du fichier
    char* ext = strrchr(filename, '.');
    if (!ext || strcmp(ext, ".gjs") != 0) {
        fprintf(stderr, "Erreur: Le fichier doit avoir l'extension .gjs\n");
        return 1;
    }
    
    // Ouvrir le fichier
    yyin = fopen(filename, "r");
    if (!yyin) {
        fprintf(stderr, "Erreur: Impossible d'ouvrir le fichier %s\n", filename);
        return 1;
    }
    
    printf("=== Goscript Interpreter ===\n");
    printf("Fichier: %s\n", filename);
    printf("Mode: %s\n", debug_mode ? "Debug" : "Normal");
    printf("\n");
    
    // Parser le fichier
    int parse_result = yyparse();
    fclose(yyin);
    
    if (parse_result != 0 || !program_root) {
        fprintf(stderr, "\nErreur: Échec du parsing\n");
        return 1;
    }
    
    printf("✓ Parsing réussi!\n");
    
    // Afficher l'AST en mode debug
    if (debug_mode) {
        printf("\n=== AST (Abstract Syntax Tree) ===\n");
        print_ast(program_root, 0);
        printf("\n");
    }
    
    printf("\n=== Exécution ===\n");
    
    // TODO: Exécuter le programme avec l'interpréteur
    // Pour l'instant, on affiche juste un message
    printf("L'interpréteur est en cours de développement...\n");
    printf("Le programme a été parsé avec succès!\n");
    
    // Libérer la mémoire
    free_ast(program_root);
    
    printf("\n✓ Programme terminé\n");
    
    return 0;
}
