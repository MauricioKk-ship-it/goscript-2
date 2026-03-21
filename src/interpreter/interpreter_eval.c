// interpreter_import.c - version épurée
#include "interpreter.h"
#include <libgen.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern ASTNode* program_root;
extern int yyparse(void);
extern FILE* yyin;

// ==================== RÉSOLVEUR DE CHEMIN ====================

char* resolve_module_path(char* current_file, char* import_path) {
    char* result = NULL;
    
    if (import_path[0] == '/') {
        result = strdup(import_path);
    }
    else if (import_path[0] == '.') {
        char* dir = strdup(current_file);
        char* dirname_ptr = dirname(dir);
        
        char full_path[1024];
        if (import_path[1] == '/') {
            snprintf(full_path, sizeof(full_path), "%s/%s", dirname_ptr, import_path + 2);
        } else if (import_path[1] == '.' && import_path[2] == '/') {
            char* parent = dirname(dirname_ptr);
            snprintf(full_path, sizeof(full_path), "%s/%s", parent, import_path + 3);
        } else {
            snprintf(full_path, sizeof(full_path), "%s/%s", dirname_ptr, import_path);
        }
        
        result = strdup(full_path);
        free(dir);
    }
    else {
        char* paths[] = {
            "/usr/local/lib/goscript/granul/packages/",
            "/usr/lib/goscript/",
            "./modules/"
        };
        
        for (int i = 0; i < 3; i++) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s%s", paths[i], import_path);
            
            char self_path[1024];
            snprintf(self_path, sizeof(self_path), "%s/__self__.gjs", full_path);
            if (access(self_path, F_OK) == 0) {
                result = strdup(self_path);
                break;
            }
            
            snprintf(self_path, sizeof(self_path), "%s.gjs", full_path);
            if (access(self_path, F_OK) == 0) {
                result = strdup(self_path);
                break;
            }
        }
    }
    
    return result;
}

// ==================== GESTION DE LA TABLE DES MODULES ====================
void register_sys_functions(Environment* env) {
    // Charger la bibliothèque sys
    void* libsys = dlopen("./lib/libsys.so", RTLD_LAZY);
    if (!libsys) {
        libsys = dlopen("/usr/local/lib/goscript/libsys.so", RTLD_LAZY);
    }
    
    if (libsys) {
        // Informations système
        register_c_function(env, "sys_get_info", dlsym(libsys, "sys_get_info"), "void*", 0);
        register_c_function(env, "sys_getpid", dlsym(libsys, "sys_getpid"), "int", 0);
        
        // Environnement
        register_c_function(env, "sys_getenv", dlsym(libsys, "sys_getenv"), "char*", 1, "char*");
        
        // Fichiers
        register_c_function(env, "sys_write_file", dlsym(libsys, "sys_write_file"), "int", 2, "char*", "char*");
        register_c_function(env, "sys_read_file", dlsym(libsys, "sys_read_file"), "char*", 1, "char*");
        register_c_function(env, "sys_remove_file", dlsym(libsys, "sys_remove_file"), "int", 1, "char*");
        
        // Processus
        register_c_function(env, "sys_system", dlsym(libsys, "sys_system"), "int", 1, "char*");
        
        // Temps
        register_c_function(env, "sys_timestamp", dlsym(libsys, "sys_timestamp"), "long", 0);
        
        // I/O
        register_c_function(env, "sys_input", dlsym(libsys, "sys_input"), "char*", 0);
        register_c_function(env, "sys_print", dlsym(libsys, "sys_print"), "void", 1, "char*");
        register_c_function(env, "sys_println", dlsym(libsys, "sys_println"), "void", 1, "char*");
    }
}
ModuleRegistry* init_module_registry(void) {
    ModuleRegistry* reg = malloc(sizeof(ModuleRegistry));
    reg->modules = NULL;
    reg->count = 0;
    reg->capacity = 0;
    return reg;
}

void register_module(ModuleRegistry* reg, LoadedModule* mod) {
    if (reg->count >= reg->capacity) {
        reg->capacity = reg->capacity == 0 ? 10 : reg->capacity * 2;
        reg->modules = realloc(reg->modules, reg->capacity * sizeof(LoadedModule*));
    }
    reg->modules[reg->count++] = mod;
}

LoadedModule* find_module(ModuleRegistry* reg, char* path) {
    for (int i = 0; i < reg->count; i++) {
        if (strcmp(reg->modules[i]->module_path, path) == 0) {
            return reg->modules[i];
        }
    }
    return NULL;
}

void free_module_registry(ModuleRegistry* reg) {
    if (!reg) return;
    for (int i = 0; i < reg->count; i++) {
        if (reg->modules[i]) {
            free(reg->modules[i]->module_path);
            free(reg->modules[i]->module_name);
            if (reg->modules[i]->constraints.allowed_names) {
                for (int j = 0; j < reg->modules[i]->constraints.allowed_count; j++) {
                    free(reg->modules[i]->constraints.allowed_names[j]);
                }
                free(reg->modules[i]->constraints.allowed_names);
            }
            free(reg->modules[i]);
        }
    }
    free(reg->modules);
    free(reg);
}

// ==================== CHARGEMENT D'UN MODULE ====================

LoadedModule* load_module(ModuleRegistry* reg, Environment* parent_env,
                          char* current_file, char* import_path, 
                          char* alias, ASTNode* constraints) {
    char* module_path = resolve_module_path(current_file, import_path);
    if (!module_path) {
        fprintf(stderr, "Module not found: %s\n", import_path);
        return NULL;
    }
    
    LoadedModule* existing = find_module(reg, module_path);
    if (existing) {
        existing->ref_count++;
        free(module_path);
        return existing;
    }
    
    Environment* module_env = create_env(NULL);
    
    FILE* f = fopen(module_path, "r");
    if (!f) {
        free(module_path);
        free(module_env);
        return NULL;
    }
    
    FILE* old_yyin = yyin;
    yyin = f;
    
    int parse_result = yyparse();
    
    fclose(f);
    yyin = old_yyin;
    
    if (parse_result != 0 || !program_root) {
        free(module_path);
        free(module_env);
        return NULL;
    }
    
    LoadedModule* module = malloc(sizeof(LoadedModule));
    module->module_path = module_path;
    module->module_name = alias ? strdup(alias) : strdup(import_path);
    module->env = module_env;
    module->status = 1;
    module->ref_count = 1;
    
    module->constraints.allowed_names = NULL;
    module->constraints.allowed_count = 0;
    module->constraints.timeout_ms = 0;
    module->constraints.sandbox = 0;
    module->constraints.allow_ffi = 1;
    
    interpret_program(program_root);
    
    register_module(reg, module);
    
    Value module_val;
    module_val.type = 7;
    module_val.int_val = (int)module;
    if (parent_env) {
        env_set(parent_env, alias ? alias : import_path, module_val);
    }
    
    return module;
}

// ==================== VÉRIFICATION DES PERMISSIONS ====================

int is_name_allowed(LoadedModule* module, char* name) {
    if (!module) return 1;
    if (module->constraints.allowed_count == 0) return 1;
    
    for (int i = 0; i < module->constraints.allowed_count; i++) {
        if (strcmp(module->constraints.allowed_names[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_ffi_allowed(LoadedModule* module) {
    if (!module) return 1;
    return module->constraints.allow_ffi;
}
