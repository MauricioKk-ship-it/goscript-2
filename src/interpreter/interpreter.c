#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ast/ast.h"

typedef struct Value {
    int type;  // 0=int, 1=float, 2=string, 3=bool
    union {
        int int_val;
        double float_val;
        char* string_val;
        int bool_val;
    };
} Value;

typedef struct Environment {
    struct Environment* parent;
    struct {
        char* name;
        Value value;
    }* vars;
    int var_count;
    int var_capacity;
} Environment;

Environment* create_env(Environment* parent) {
    Environment* env = malloc(sizeof(Environment));
    env->parent = parent;
    env->vars = NULL;
    env->var_count = 0;
    env->var_capacity = 0;
    return env;
}

void env_set(Environment* env, char* name, Value value) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->vars[i].name, name) == 0) {
            env->vars[i].value = value;
            return;
        }
    }
    
    if (env->var_count >= env->var_capacity) {
        env->var_capacity = env->var_capacity == 0 ? 10 : env->var_capacity * 2;
        env->vars = realloc(env->vars, env->var_capacity * sizeof(*env->vars));
    }
    
    env->vars[env->var_count].name = strdup(name);
    env->vars[env->var_count].value = value;
    env->var_count++;
}

Value* env_get(Environment* env, char* name) {
    for (int i = 0; i < env->var_count; i++) {
        if (strcmp(env->vars[i].name, name) == 0) {
            return &env->vars[i].value;
        }
    }
    if (env->parent) {
        return env_get(env->parent, name);
    }
    return NULL;
}

Value evaluate_expr(ASTNode* node, Environment* env) {
    Value result = {0};
    
    switch (node->type) {
        case NODE_NUMBER:
            result.type = 0;
            result.int_val = node->number.value;
            break;
            
        case NODE_IDENTIFIER: {
            Value* val = env_get(env, node->identifier.name);
            if (val) {
                result = *val;
            } else {
                fprintf(stderr, "Undefined variable: %s\n", node->identifier.name);
                exit(1);
            }
            break;
        }
        
        case NODE_BINARY_OP: {
            Value left = evaluate_expr(node->binary.left, env);
            Value right = evaluate_expr(node->binary.right, env);
            
            switch (node->binary.op) {
                case OP_ADD:
                    if (left.type == 0 && right.type == 0) {
                        result.type = 0;
                        result.int_val = left.int_val + right.int_val;
                    }
                    break;
                case OP_SUB:
                    if (left.type == 0 && right.type == 0) {
                        result.type = 0;
                        result.int_val = left.int_val - right.int_val;
                    }
                    break;
                case OP_MUL:
                    if (left.type == 0 && right.type == 0) {
                        result.type = 0;
                        result.int_val = left.int_val * right.int_val;
                    }
                    break;
                case OP_DIV:
                    if (left.type == 0 && right.type == 0) {
                        result.type = 0;
                        result.int_val = left.int_val / right.int_val;
                    }
                    break;
            }
            break;
        }
        
        case NODE_CALL: {
            char* func_name = node->call.callee->identifier.name;
            // Find function in program
            // For now, just handle built-in or simple calls
            result.type = 0;
            result.int_val = 0;
            break;
        }
        
        default:
            break;
    }
    
    return result;
}

void evaluate_statement(ASTNode* node, Environment* env) {
    switch (node->type) {
        case NODE_LET: {
            Value val = evaluate_expr(node->var_decl.value, env);
            env_set(env, node->var_decl.name, val);
            break;
        }
        
        case NODE_RETURN: {
            Value val = evaluate_expr(node->return_stmt.value, env);
            printf("%d\n", val.int_val);
            exit(0);
            break;
        }
        
        case NODE_IF: {
            Value cond = evaluate_expr(node->if_stmt.condition, env);
            if (cond.type == 0 && cond.int_val != 0) {
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
        
        default:
            break;
    }
}

void interpret_program(ASTNode* program) {
    Environment* global = create_env(NULL);
    
    // Find main function
    ASTNode* main_func = NULL;
    for (int i = 0; i < program->program.statements->count; i++) {
        ASTNode* stmt = program->program.statements->nodes[i];
        if (stmt->type == NODE_FUNCTION && strcmp(stmt->function.name, "main") == 0) {
            main_func = stmt;
            break;
        }
    }
    
    if (!main_func) {
        fprintf(stderr, "Error: No main function found\n");
        return;
    }
    
    // Execute main function body
    for (int i = 0; i < main_func->function.body->count; i++) {
        evaluate_statement(main_func->function.body->nodes[i], global);
    }
    
    free(global);
}
