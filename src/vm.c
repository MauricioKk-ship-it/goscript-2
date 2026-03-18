#include "common.h"
#include "vm.h"

static Value* find_variable(VM* vm, const char* name) {
    // Chercher dans le frame courant
    Frame* frame = vm->current_frame;
    while (frame) {
        for (int i = 0; i < frame->local_count; i++) {
            if (strcmp(frame->locals[i].name, name) == 0) {
                return &frame->locals[i];
            }
        }
        frame = frame->parent;
    }
    
    // Chercher dans les globals
    for (int i = 0; i < vm->global_count; i++) {
        if (strcmp(vm->globals[i].name, name) == 0) {
            return &vm->globals[i];
        }
    }
    
    return NULL;
}

static void define_variable(VM* vm, const char* name, Value value) {
    // Toujours en global pour l'instant
    if (vm->global_count >= GLOBALS_MAX) {
        fprintf(stderr, "Erreur: Trop de variables globales\n");
        vm->had_error = true;
        return;
    }
    
    vm->globals[vm->global_count].name = strdup(name);
    vm->globals[vm->global_count].is_initialized = true;
    vm->globals[vm->global_count].value = value.value;
    vm->globals[vm->global_count].type = value.type;
    vm->global_count++;
}

static void set_variable(VM* vm, const char* name, Value value) {
    Value* var = find_variable(vm, name);
    if (var) {
        var->is_initialized = true;
        var->value = value.value;
        var->type = value.type;
    } else {
        fprintf(stderr, "Erreur: Variable '%s' non définie\n", name);
        vm->had_error = true;
    }
}

static Value get_variable(VM* vm, const char* name) {
    Value* var = find_variable(vm, name);
    if (var && var->is_initialized) {
        return *var;
    } else {
        fprintf(stderr, "Erreur: Variable '%s' non définie ou non initialisée\n", name);
        vm->had_error = true;
        Value error_val = {0};
        return error_val;
    }
}

static double evaluate(VM* vm, Node* node) {
    if (!node || vm->had_error) return 0;
    
    switch (node->type) {
        case NODE_LITERAL_NUMBER:
            return node->data.number_value;
            
        case NODE_LITERAL_BOOL:
            return node->data.bool_value ? 1.0 : 0.0;
            
        case NODE_LITERAL_STRING:
            // Pour l'instant, on retourne 0 pour les strings
            return 0;
            
        case NODE_VARIABLE: {
            Value val = get_variable(vm, node->data.identifier);
            if (val.type == 0) return val.value.number;
            return 0;
        }
        
        case NODE_GROUPING:
            return evaluate(vm, node->left);
            
        case NODE_UNARY_OP: {
            double right = evaluate(vm, node->right);
            if (node->data.binary.op == '-') return -right;
            if (node->data.binary.op == '!') return !right;
            return right;
        }
        
        case NODE_BINARY_OP: {
            double left = evaluate(vm, node->left);
            double right = evaluate(vm, node->right);
            
            switch (node->data.binary.op) {
                case '+': return left + right;
                case '-': return left - right;
                case '*': return left * right;
                case '/': 
                    if (right == 0) {
                        fprintf(stderr, "Erreur: Division par zéro\n");
                        vm->had_error = true;
                        return 0;
                    }
                    return left / right;
                case '=': return left == right ? 1.0 : 0.0;
                case '!': return left != right ? 1.0 : 0.0;
                case '<': return left < right ? 1.0 : 0.0;
                case '>': return left > right ? 1.0 : 0.0;
                case 'g': return left >= right ? 1.0 : 0.0; // >=
                case 'l': return left <= right ? 1.0 : 0.0; // <=
                default:
                    fprintf(stderr, "Erreur: Opérateur inconnu %c\n", node->data.binary.op);
                    vm->had_error = true;
                    return 0;
            }
        }
        
        default:
            return 0;
    }
}

static void execute_statement(VM* vm, Node* node) {
    if (!node || vm->had_error || vm->return_flag) return;
    
    switch (node->type) {
        case NODE_PROGRAM: {
            Node* stmt = node->left;
            while (stmt && !vm->had_error && !vm->return_flag) {
                execute_statement(vm, stmt);
                stmt = stmt->right;
            }
            break;
        }
        
        case NODE_BLOCK: {
            Node* stmt = node->left;
            while (stmt && !vm->had_error && !vm->return_flag) {
                execute_statement(vm, stmt);
                stmt = stmt->right;
            }
            break;
        }
        
        case NODE_EXPRESSION_STMT:
            evaluate(vm, node->left);
            break;
            
        case NODE_PRINT_STMT: {
            double value = evaluate(vm, node->left);
            if (!vm->had_error) {
                printf("%g\n", value);
            }
            break;
        }
        
        case NODE_GETLF_STMT: {
            double value = evaluate(vm, node->left);
            if (!vm->had_error) {
                printf("GETLF: %g\n", value);
            }
            break;
        }
        
        case NODE_INPUT_STMT: {
            char buffer[256];
            printf("%s", node->data.string_value ? node->data.string_value : "");
            if (fgets(buffer, sizeof(buffer), stdin)) {
                buffer[strcspn(buffer, "\n")] = 0;
                // Pour l'instant, on convertit en nombre
                char* endptr;
                double val = strtod(buffer, &endptr);
                push(vm, val);
            }
            break;
        }
        
        case NODE_VARIABLE_DECL: {
            double value = 0;
            if (node->left) {
                value = evaluate(vm, node->left);
            }
            
            if (!vm->had_error) {
                Value val;
                val.type = 0;
                val.value.number = value;
                val.is_initialized = true;
                val.name = node->data.identifier;
                define_variable(vm, node->data.identifier, val);
            }
            break;
        }
        
        case NODE_ASSIGNMENT: {
            double value = evaluate(vm, node->left);
            if (!vm->had_error) {
                Value val;
                val.type = 0;
                val.value.number = value;
                val.is_initialized = true;
                set_variable(vm, node->data.identifier, val);
            }
            break;
        }
        
        case NODE_IF_STMT: {
            double condition = evaluate(vm, node->left);
            if (!vm->had_error) {
                if (condition != 0) {
                    execute_statement(vm, node->right);
                } else if (node->extra) {
                    execute_statement(vm, node->extra);
                }
            }
            break;
        }
        
        case NODE_WHILE_STMT: {
            while (!vm->had_error && !vm->return_flag) {
                double condition = evaluate(vm, node->left);
                if (condition == 0) break;
                execute_statement(vm, node->right);
            }
            break;
        }
        
        case NODE_FOR_STMT: {
            // Initialisation
            if (node->left) {
                execute_statement(vm, node->left);
            }
            
            // Boucle
            while (!vm->had_error && !vm->return_flag) {
                // Condition
                double condition = 1.0;
                if (node->right) {
                    condition = evaluate(vm, node->right);
                }
                if (condition == 0) break;
                
                // Corps
                if (node->extra) {
                    // Le corps est stocké dans l'extra de l'extra
                    // C'est un peu hacky, mais ça marche pour l'instant
                    Node* body = node->extra;
                    execute_statement(vm, body);
                }
                
                // Incrément
                if (node->extra && node->extra->right) {
                    evaluate(vm, node->extra->right);
                }
            }
            break;
        }
        
        case NODE_RETURN_STMT: {
            if (node->left) {
                vm->return_value = evaluate(vm, node->left);
            } else {
                vm->return_value = 0;
            }
            vm->return_flag = true;
            break;
        }
        
        default:
            // Ignorer les autres types
            break;
    }
}

void init_vm(VM* vm) {
    vm->global_count = 0;
    vm->stack_top = 0;
    vm->had_error = false;
    vm->return_flag = false;
    vm->return_value = 0;
    vm->current_frame = NULL;
    vm->functions = NULL;
    vm->function_count = 0;
}

void free_vm(VM* vm) {
    for (int i = 0; i < vm->global_count; i++) {
        if (vm->globals[i].name) free(vm->globals[i].name);
    }
    
    Function* func = vm->functions;
    while (func) {
        Function* next = func->next;
        if (func->name) free(func->name);
        free(func);
        func = next;
    }
}

bool execute(VM* vm, Node* ast) {
    if (!ast) return false;
    
    vm->had_error = false;
    vm->return_flag = false;
    
    execute_statement(vm, ast);
    
    return !vm->had_error;
}

void push(VM* vm, double value) {
    if (vm->stack_top >= STACK_MAX) {
        fprintf(stderr, "Erreur: Stack overflow\n");
        vm->had_error = true;
        return;
    }
    vm->stack[vm->stack_top++] = value;
}

double pop(VM* vm) {
    if (vm->stack_top <= 0) {
        fprintf(stderr, "Erreur: Stack underflow\n");
        vm->had_error = true;
        return 0;
    }
    return vm->stack[--vm->stack_top];
}
