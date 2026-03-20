#include "ast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef struct Value {
    enum { VAL_INT, VAL_FLOAT, VAL_STRING, VAL_BOOL, VAL_NIL, VAL_FUNCTION, VAL_ARRAY, VAL_STRUCT } type;
    union {
        int int_val;
        double float_val;
        char* string_val;
        int bool_val;
        struct {
            ASTNode* node;
            struct Environment* closure;
        } func_val;
        struct {
            struct Value** elements;
            int count;
        } array_val;
        struct {
            char* name;
            struct Value** fields;
        } struct_val;
    };
} Value;

typedef struct Environment {
    struct Environment* parent;
    struct {
        char* name;
        Value value;
    }* variables;
    int var_count;
    int var_capacity;
} Environment;

// Initialisation de l'environnement
Environment* create_environment(Environment* parent) {
    Environment* env = malloc(sizeof(Environment));
    env->parent = parent;
    env->variables = NULL;
    env->var_count = 0;
    env->var_capacity = 0;
    return env;
}

void env_set(Environment* env, char* name, Value value) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            env->variables[i].value = value;
            return;
        }
    }
    
    if (env->var_count >= env->var_capacity) {
        env->var_capacity = env->var_capacity == 0 ? 10 : env->var_capacity * 2;
        env->variables = realloc(env->variables, env->var_capacity * sizeof(*env->variables));
    }
    
    env->variables[env->var_count].name = strdup(name);
    env->variables[env->var_count].value = value;
    env->var_count++;
}

Value* env_get(Environment* env, char* name) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->variables[i].name, name) == 0) {
            return &env->variables[i].value;
        }
    }
    
    if (env->parent) {
        return env_get(env->parent, name);
    }
    
    return NULL;
}

// Évaluation des expressions
Value evaluate_expression(ASTNode* node, Environment* env) {
    Value result;
    
    switch (node->type) {
        case NODE_NUMBER:
            result.type = VAL_INT;
            result.int_val = node->number.value;
            break;
            
        case NODE_FLOAT:
            result.type = VAL_FLOAT;
            result.float_val = node->float_val.value;
            break;
            
        case NODE_STRING:
            result.type = VAL_STRING;
            result.string_val = strdup(node->string_val.value);
            break;
            
        case NODE_BOOL:
            result.type = VAL_BOOL;
            result.bool_val = node->bool_val.value;
            break;
            
        case NODE_NIL:
            result.type = VAL_NIL;
            break;
            
        case NODE_IDENTIFIER: {
            Value* val = env_get(env, node->identifier.name);
            if (val) {
                result = *val;
            } else {
                fprintf(stderr, "Variable non définie: %s\n", node->identifier.name);
                exit(1);
            }
            break;
        }
        
        case NODE_BINARY_OP: {
            Value left = evaluate_expression(node->binary.left, env);
            Value right = evaluate_expression(node->binary.right, env);
            
            switch (node->binary.op) {
                case OP_ADD:
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.type = VAL_INT;
                        result.int_val = left.int_val + right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.type = VAL_FLOAT;
                        result.float_val = left.float_val + right.float_val;
                    } else if (left.type == VAL_STRING || right.type == VAL_STRING) {
                        result.type = VAL_STRING;
                        char* left_str = value_to_string(left);
                        char* right_str = value_to_string(right);
                        result.string_val = malloc(strlen(left_str) + strlen(right_str) + 1);
                        strcpy(result.string_val, left_str);
                        strcat(result.string_val, right_str);
                        free(left_str);
                        free(right_str);
                    }
                    break;
                case OP_SUB:
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.type = VAL_INT;
                        result.int_val = left.int_val - right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.type = VAL_FLOAT;
                        result.float_val = left.float_val - right.float_val;
                    }
                    break;
                case OP_MUL:
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.type = VAL_INT;
                        result.int_val = left.int_val * right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.type = VAL_FLOAT;
                        result.float_val = left.float_val * right.float_val;
                    }
                    break;
                case OP_DIV:
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.type = VAL_INT;
                        result.int_val = left.int_val / right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.type = VAL_FLOAT;
                        result.float_val = left.float_val / right.float_val;
                    }
                    break;
                case OP_EQ:
                    result.type = VAL_BOOL;
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.bool_val = left.int_val == right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.bool_val = left.float_val == right.float_val;
                    } else if (left.type == VAL_STRING && right.type == VAL_STRING) {
                        result.bool_val = strcmp(left.string_val, right.string_val) == 0;
                    } else if (left.type == VAL_BOOL && right.type == VAL_BOOL) {
                        result.bool_val = left.bool_val == right.bool_val;
                    }
                    break;
                case OP_LT:
                    result.type = VAL_BOOL;
                    if (left.type == VAL_INT && right.type == VAL_INT) {
                        result.bool_val = left.int_val < right.int_val;
                    } else if (left.type == VAL_FLOAT && right.type == VAL_FLOAT) {
                        result.bool_val = left.float_val < right.float_val;
                    }
                    break;
                default:
                    fprintf(stderr, "Opérateur non supporté\n");
                    exit(1);
            }
            break;
        }
        
        case NODE_CALL: {
            Value callee = evaluate_expression(node->call.callee, env);
            if (callee.type == VAL_FUNCTION) {
                Environment* func_env = create_environment(callee.func_val.closure);
                
                // Évaluer les arguments
                if (node->call.args) {
                    for (int i = 0; i < node->call.args->count && i < callee.func_val.node->function.params->count; i++) {
                        Value arg_val = evaluate_expression(node->call.args->nodes[i], env);
                        ASTNode* param = callee.func_val.node->function.params->nodes[i];
                        env_set(func_env, param->identifier.name, arg_val);
                    }
                }
                
                // Exécuter le corps de la fonction
                Value ret_val;
                ret_val.type = VAL_NIL;
                
                for (int i = 0; i < callee.func_val.node->function.body->count; i++) {
                    ASTNode* stmt = callee.func_val.node->function.body->nodes[i];
                    if (stmt->type == NODE_RETURN) {
                        if (stmt->return_stmt.value) {
                            ret_val = evaluate_expression(stmt->return_stmt.value, func_env);
                        }
                        break;
                    } else {
                        evaluate_expression(stmt, func_env);
                    }
                }
                
                free(func_env);
                result = ret_val;
            } else {
                fprintf(stderr, "L'appel n'est pas une fonction\n");
                exit(1);
            }
            break;
        }
        
        default:
            result.type = VAL_NIL;
            break;
    }
    
    return result;
}

// Évaluation des statements
void evaluate_statement(ASTNode* node, Environment* env) {
    switch (node->type) {
        case NODE_LET: {
            Value value;
            if (node->var_decl.value) {
                value = evaluate_expression(node->var_decl.value, env);
            } else {
                value.type = VAL_NIL;
            }
            env_set(env, node->var_decl.name, value);
            break;
        }
        
        case NODE_CONST: {
            Value value = evaluate_expression(node->var_decl.value, env);
            env_set(env, node->var_decl.name, value);
            break;
        }
        
        case NODE_IF: {
            Value cond = evaluate_expression(node->if_stmt.condition, env);
            if (cond.type == VAL_BOOL && cond.bool_val) {
                for (int i = 0; i < node->if_stmt.then_branch->count; i++) {
                    evaluate_statement(node->if_stmt.then_branch->nodes[i], env);
                }
            } else if (node->if_stmt.else_branch) {
                for (int i = 0; i < node->if_stmt.else_branch->count; i++) {
                    evaluate_statement(node->if_stmt.else_branch->nodes[i], env);
                }
            }
            break;
        }
        
        case NODE_WHILE: {
            while (1) {
                Value cond = evaluate_expression(node->while_stmt.condition, env);
                if (cond.type != VAL_BOOL || !cond.bool_val) {
                    break;
                }
                for (int i = 0; i < node->while_stmt.body->count; i++) {
                    evaluate_statement(node->while_stmt.body->nodes[i], env);
                }
            }
            break;
        }
        
        case NODE_RETURN:
            // Géré dans l'appel de fonction
            break;
            
        default:
            evaluate_expression(node, env);
            break;
    }
}

// Système d'import
void handle_import(ASTNode* import_node, Environment* env) {
    char path[1024];
    
    if (import_node->import.path[0] == '.') {
        // Import local
        snprintf(path, sizeof(path), "%s.gjs", import_node->import.path);
    } else if (strncmp(import_node->import.path, "packet", 6) == 0) {
        // Import packet
        char* packet_path = import_node->import.path + 7;
        snprintf(path, sizeof(path), "/usr/local/lib/goscript/granul/%s/__self__.gjs", packet_path);
    } else {
        // Import standard
        snprintf(path, sizeof(path), "/usr/local/lib/goscript/%s.gjs", import_node->import.path);
    }
    
    // Vérifier si le fichier existe
    FILE* f = fopen(path, "r");
    if (!f) {
        fprintf(stderr, "Impossible d'importer: %s\n", path);
        return;
    }
    fclose(f);
    
    // Ici, on devrait parser et exécuter le fichier importé
    // Pour l'instant, on affiche juste un message
    printf("Import: %s\n", path);
}

// Fonction main
int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <fichier.gjs>\n", argv[0]);
        return 1;
    }
    
    extern FILE* yyin;
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Impossible d'ouvrir le fichier: %s\n", argv[1]);
        return 1;
    }
    
    yyparse();
    fclose(yyin);
    
    if (!program_root) {
        fprintf(stderr, "Erreur lors du parsing\n");
        return 1;
    }
    
    Environment* global_env = create_environment(NULL);
    
    // Ajouter les fonctions natives
    Value print_func;
    print_func.type = VAL_FUNCTION;
    // print_func.func_val = native_print; (à implémenter)
    
    // Exécuter le programme
    for (int i = 0; i < program_root->program.statements->count; i++) {
        ASTNode* stmt = program_root->program.statements->nodes[i];
        
        if (stmt->type == NODE_IMPORT) {
            handle_import(stmt, global_env);
        } else {
            evaluate_statement(stmt, global_env);
        }
    }
    
    free_ast(program_root);
    free(global_env);
    
    return 0;
}
