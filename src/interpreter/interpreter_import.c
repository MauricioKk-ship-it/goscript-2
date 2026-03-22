#include "interpreter.h"
#include <libgen.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

extern ASTNode* program_root;
extern int yyparse(void);
extern FILE* yyin;
extern void free_ast(ASTNode* node);
extern int evaluate_statement(ASTNode* node, Environment* env, char* current_file);
extern Value evaluate_expr(ASTNode* node, Environment* env);
extern void interpret_program(ASTNode* program);
extern void register_impl(char* struct_name, ASTNode* impl_node);
extern void env_set(Environment* env, char* name, Value value);
extern Environment* create_env(Environment* parent);
extern int yylineno;

// ==================== STRUCTURES DES MODULES ====================

typedef enum {
    MODULE_STATUS_UNLOADED = 0,
    MODULE_STATUS_LOADING,
    MODULE_STATUS_LOADED,
    MODULE_STATUS_ERROR
} ModuleStatus;

typedef struct GoscriptModule {
    char* path;              // Chemin absolu (clé unique)
    char* name;              // Nom du module
    char* alias;             // Alias d'import
    ModuleStatus status;
    Environment* env;        // Environnement isolé du module
    int ref_count;           // Compteur de références
    struct {
        char** exported_names;   // Noms exportés publiquement
        int exported_count;
        char** only_allowed;     // Filtre "only" pour l'import
        int only_count;
        int timeout_ms;          // Timeout en millisecondes
        int sandbox;             // Mode sandboxé (1 = activé)
        int allow_ffi;           // 1 = FFI autorisé
    } constraints;
} GoscriptModule;

// Registre global des modules
static GoscriptModule* modules[1024];
static int module_count = 0;
static int module_capacity = 1024;

// ==================== RÉSOLUTION DE CHEMIN ====================

static char* resolve_module_path(const char* import_path, const char* current_file) {
    char resolved[PATH_MAX];
    struct stat st;
    
    // Chemins de recherche (comme V)
    const char* search_paths[] = {
        "./modules",                    // Modules locaux
        "./src",                        // Source locale
        "/usr/local/lib/goscript",      // Modules système
        "/usr/lib/goscript",
        "./",                           // Dossier courant
        NULL
    };
    
    // 1. Chemin absolu
    if (import_path[0] == '/') {
        snprintf(resolved, PATH_MAX, "%s", import_path);
        
        // Vérifier si c'est un fichier .gjs
        char with_ext[PATH_MAX];
        snprintf(with_ext, PATH_MAX, "%s.gjs", resolved);
        if (access(with_ext, F_OK) == 0) {
            if (realpath(with_ext, resolved)) {
                return strdup(resolved);
            }
        }
        
        // Vérifier si c'est un dossier avec __self__.gjs
        snprintf(with_ext, PATH_MAX, "%s/__self__.gjs", resolved);
        if (access(with_ext, F_OK) == 0) {
            if (realpath(with_ext, resolved)) {
                return strdup(resolved);
            }
        }
        
        if (access(resolved, F_OK) == 0) {
            if (realpath(resolved, resolved)) {
                return strdup(resolved);
            }
        }
    }
    
    // 2. Chemin relatif
    if (import_path[0] == '.') {
        char base[PATH_MAX];
        
        if (current_file && current_file[0] && strcmp(current_file, "REPL") != 0) {
            strcpy(base, current_file);
            char* dir = dirname(base);
            snprintf(resolved, PATH_MAX, "%s/%s", dir, import_path);
        } else {
            if (getcwd(resolved, PATH_MAX) == NULL) {
                return NULL;
            }
            strcat(resolved, "/");
            strcat(resolved, import_path);
        }
        
        // Nettoyer le chemin
        char clean_path[PATH_MAX];
        if (realpath(resolved, clean_path)) {
            strcpy(resolved, clean_path);
        }
        
        // Vérifier si c'est un fichier .gjs
        char with_ext[PATH_MAX];
        snprintf(with_ext, PATH_MAX, "%s.gjs", resolved);
        if (access(with_ext, F_OK) == 0) {
            if (realpath(with_ext, resolved)) {
                return strdup(resolved);
            }
        }
        
        // Vérifier si c'est un dossier avec __self__.gjs
        snprintf(with_ext, PATH_MAX, "%s/__self__.gjs", resolved);
        if (access(with_ext, F_OK) == 0) {
            if (realpath(with_ext, resolved)) {
                return strdup(resolved);
            }
        }
        
        if (access(resolved, F_OK) == 0) {
            if (realpath(resolved, resolved)) {
                return strdup(resolved);
            }
        }
    }
    
    // 3. Recherche dans les chemins standards (comme V)
    for (int i = 0; search_paths[i]; i++) {
        // Fichier .gjs
        snprintf(resolved, PATH_MAX, "%s/%s.gjs", search_paths[i], import_path);
        if (access(resolved, F_OK) == 0) {
            char real_path[PATH_MAX];
            if (realpath(resolved, real_path)) {
                return strdup(real_path);
            }
        }
        
        // Dossier avec __self__.gjs
        snprintf(resolved, PATH_MAX, "%s/%s/__self__.gjs", search_paths[i], import_path);
        if (access(resolved, F_OK) == 0) {
            char real_path[PATH_MAX];
            if (realpath(resolved, real_path)) {
                return strdup(real_path);
            }
        }
        
        // Fichier simple sans extension
        snprintf(resolved, PATH_MAX, "%s/%s", search_paths[i], import_path);
        if (access(resolved, F_OK) == 0) {
            struct stat path_stat;
            if (stat(resolved, &path_stat) == 0 && !S_ISDIR(path_stat.st_mode)) {
                char real_path[PATH_MAX];
                if (realpath(resolved, real_path)) {
                    return strdup(real_path);
                }
            }
        }
    }
    
    return NULL;
}

// ==================== GESTION DU CACHE ====================

static GoscriptModule* find_module_by_path(const char* path) {
    for (int i = 0; i < module_count; i++) {
        if (modules[i] && modules[i]->path && strcmp(modules[i]->path, path) == 0) {
            return modules[i];
        }
    }
    return NULL;
}

static GoscriptModule* find_module_by_name(const char* name) {
    for (int i = 0; i < module_count; i++) {
        if (modules[i] && modules[i]->name && strcmp(modules[i]->name, name) == 0) {
            return modules[i];
        }
    }
    return NULL;
}

static GoscriptModule* create_module(const char* path, const char* name, const char* alias) {
    if (module_count >= module_capacity) {
        fprintf(stderr, "Module registry full\n");
        return NULL;
    }
    
    GoscriptModule* mod = malloc(sizeof(GoscriptModule));
    if (!mod) return NULL;
    
    mod->path = path ? strdup(path) : NULL;
    mod->name = name ? strdup(name) : NULL;
    mod->alias = alias ? strdup(alias) : NULL;
    mod->status = MODULE_STATUS_LOADING;
    mod->env = create_env(NULL);
    mod->ref_count = 1;
    
    // Initialiser les contraintes
    mod->constraints.exported_names = NULL;
    mod->constraints.exported_count = 0;
    mod->constraints.only_allowed = NULL;
    mod->constraints.only_count = 0;
    mod->constraints.timeout_ms = 0;
    mod->constraints.sandbox = 0;
    mod->constraints.allow_ffi = 1;
    
    modules[module_count++] = mod;
    return mod;
}

static void free_module(GoscriptModule* mod) {
    if (!mod) return;
    
    if (mod->path) free(mod->path);
    if (mod->name) free(mod->name);
    if (mod->alias) free(mod->alias);
    if (mod->env) free(mod->env);
    
    if (mod->constraints.exported_names) {
        for (int i = 0; i < mod->constraints.exported_count; i++) {
            if (mod->constraints.exported_names[i]) free(mod->constraints.exported_names[i]);
        }
        free(mod->constraints.exported_names);
    }
    
    if (mod->constraints.only_allowed) {
        for (int i = 0; i < mod->constraints.only_count; i++) {
            if (mod->constraints.only_allowed[i]) free(mod->constraints.only_allowed[i]);
        }
        free(mod->constraints.only_allowed);
    }
    
    free(mod);
}

// ==================== EXPORTATION DE SYMBOLES ====================

static void register_export(GoscriptModule* mod, const char* symbol, const char* alias) {
    if (!mod || !symbol) return;
    
    if (!mod->constraints.exported_names) {
        mod->constraints.exported_names = malloc(32 * sizeof(char*));
        mod->constraints.exported_count = 0;
    }
    
    // Vérifier si déjà exporté
    for (int i = 0; i < mod->constraints.exported_count; i++) {
        if (mod->constraints.exported_names[i] && 
            strcmp(mod->constraints.exported_names[i], symbol) == 0) {
            return;
        }
    }
    
    const char* export_name = alias ? alias : symbol;
    mod->constraints.exported_names[mod->constraints.exported_count] = strdup(export_name);
    mod->constraints.exported_count++;
}

static bool is_exported(GoscriptModule* mod, const char* symbol) {
    if (!mod || !mod->constraints.exported_names) return false;
    
    for (int i = 0; i < mod->constraints.exported_count; i++) {
        if (mod->constraints.exported_names[i] && 
            strcmp(mod->constraints.exported_names[i], symbol) == 0) {
            return true;
        }
    }
    return false;
}

// ==================== TRAITEMENT DES CONTRAINTES ====================

void process_constraints(GoscriptModule* module, ASTNode* constraints) {
    if (!module || !constraints) return;
    
    if (constraints->type == NODE_CONSTRAINT) {
        if (strcmp(constraints->constraint.constraint_type, "only") == 0) {
            if (constraints->constraint.list) {
                module->constraints.only_count = constraints->constraint.list->count;
                module->constraints.only_allowed = malloc(module->constraints.only_count * sizeof(char*));
                for (int i = 0; i < module->constraints.only_count; i++) {
                    ASTNode* name_node = constraints->constraint.list->nodes[i];
                    if (name_node->type == NODE_IDENTIFIER) {
                        module->constraints.only_allowed[i] = strdup(name_node->identifier.name);
                    }
                }
            }
        } else if (strcmp(constraints->constraint.constraint_type, "timeout") == 0) {
            module->constraints.timeout_ms = constraints->constraint.int_value;
        } else if (strcmp(constraints->constraint.constraint_type, "sandbox") == 0) {
            module->constraints.sandbox = 1;
        } else if (strcmp(constraints->constraint.constraint_type, "allow_ffi") == 0) {
            module->constraints.allow_ffi = constraints->constraint.int_value;
        }
    } else if (constraints->type == NODE_CONSTRAINT_LIST) {
        process_constraints(module, constraints->constraint_list.a);
        process_constraints(module, constraints->constraint_list.b);
    }
}

// ==================== VÉRIFICATION DES PERMISSIONS ====================

int is_name_allowed(GoscriptModule* module, char* name) {
    if (!module) return 1;
    if (module->constraints.only_count == 0) return 1;
    
    for (int i = 0; i < module->constraints.only_count; i++) {
        if (module->constraints.only_allowed[i] && 
            strcmp(module->constraints.only_allowed[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_ffi_allowed(GoscriptModule* module) {
    if (!module) return 1;
    return module->constraints.allow_ffi;
}

// ==================== CHARGEMENT DE MODULE (CŒUR) ====================

bool load_module(Environment* parent_env, const char* current_file,
                 const char* import_path, const char* alias,
                 ASTNode* constraints) {
    // 1. Résoudre le chemin
    char* full_path = resolve_module_path(import_path, current_file);
    if (!full_path) {
        fprintf(stderr, "Module not found: %s\n", import_path);
        return false;
    }
    
    // 2. Vérifier le cache
    GoscriptModule* existing = find_module_by_path(full_path);
    if (existing) {
        // Détection de cycle
        if (existing->status == MODULE_STATUS_LOADING) {
            fprintf(stderr, "Circular import detected: %s\n", import_path);
            free(full_path);
            return false;
        }
        
        existing->ref_count++;
        
        // Lier le module à l'environnement parent
        Value module_val;
        module_val.type = 7;  // Type MODULE
        module_val.int_val = (int)existing;
        env_set(parent_env, alias ? alias : existing->name, module_val);
        
        free(full_path);
        return true;
    }
    
    // 3. Créer le module en cache
    GoscriptModule* mod = create_module(full_path, import_path, alias);
    free(full_path);
    
    if (!mod) return false;
    
    // 4. Lire le fichier
    FILE* f = fopen(mod->path, "r");
    if (!f) {
        mod->status = MODULE_STATUS_ERROR;
        fprintf(stderr, "Cannot open module: %s\n", mod->path);
        return false;
    }
    
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char* source = malloc(size + 1);
    if (!source) {
        fclose(f);
        mod->status = MODULE_STATUS_ERROR;
        return false;
    }
    
    fread(source, 1, size, f);
    source[size] = '\0';
    fclose(f);
    
    // 5. Parser le module
    FILE* old_yyin = yyin;
    int old_lineno = yylineno;
    
    yyin = fmemopen(source, size, "r");
    if (!yyin) {
        free(source);
        mod->status = MODULE_STATUS_ERROR;
        return false;
    }
    
    int parse_result = yyparse();
    fclose(yyin);
    yyin = old_yyin;
    yylineno = old_lineno;
    
    if (parse_result != 0 || !program_root) {
        mod->status = MODULE_STATUS_ERROR;
        free(source);
        return false;
    }
    
    // 6. Premier passage : Enregistrer les fonctions
    for (int i = 0; i < program_root->program.statements->count; i++) {
        ASTNode* stmt = program_root->program.statements->nodes[i];
        if (stmt->type == NODE_FUNCTION || stmt->type == NODE_PUBLIC_FUNCTION) {
            Value func_val;
            func_val.type = 4;
            func_val.func_val.node = stmt;
            func_val.func_val.closure = mod->env;
            env_set(mod->env, stmt->function.name, func_val);
        }
    }
    
    // 7. Deuxième passage : Enregistrer les constantes et structures
    for (int i = 0; i < program_root->program.statements->count; i++) {
        ASTNode* stmt = program_root->program.statements->nodes[i];
        if (stmt->type == NODE_CONST) {
            Value const_val = evaluate_expr(stmt->var_decl.value, mod->env);
            env_set(mod->env, stmt->var_decl.name, const_val);
        } else if (stmt->type == NODE_STRUCT) {
            Value struct_val;
            struct_val.type = 6;
            struct_val.struct_val.struct_name = strdup(stmt->struct_def.name);
            struct_val.struct_val.fields = NULL;
            struct_val.struct_val.field_count = 0;
            env_set(mod->env, stmt->struct_def.name, struct_val);
        }
    }
    
    // 8. Troisième passage : Traiter les exports (pub)
    for (int i = 0; i < program_root->program.statements->count; i++) {
        ASTNode* stmt = program_root->program.statements->nodes[i];
        if (stmt->type == NODE_EXPORT) {
            register_export(mod, stmt->export.name, NULL);
        }
    }
    
    // 9. Exécuter le corps du module (expressions à la racine)
    for (int i = 0; i < program_root->program.statements->count; i++) {
        ASTNode* stmt = program_root->program.statements->nodes[i];
        if (stmt->type == NODE_EXPR_STMT) {
            evaluate_statement(stmt, mod->env, mod->path);
        }
    }
    
    // 10. Appliquer les contraintes
    if (constraints) {
        process_constraints(mod, constraints);
    }
    
    // 11. Marquer comme chargé
    mod->status = MODULE_STATUS_LOADED;
    
    // 12. Lier le module à l'environnement parent
    Value module_val;
    module_val.type = 7;
    module_val.int_val = (int)mod;
    env_set(parent_env, alias ? alias : mod->name, module_val);
    
    // 13. Nettoyage
    free_ast(program_root);
    program_root = NULL;
    free(source);
    
    return true;
}

// ==================== FONCTIONS D'ACCÈS PUBLIC ====================

void* get_module_symbol(const char* module_name, const char* symbol) {
    GoscriptModule* mod = find_module_by_name(module_name);
    if (!mod || mod->status != MODULE_STATUS_LOADED) {
        return NULL;
    }
    
    if (!is_exported(mod, symbol)) {
        fprintf(stderr, "Symbol '%s' not exported from module '%s'\n", symbol, module_name);
        return NULL;
    }
    
    if (!is_name_allowed(mod, (char*)symbol)) {
        fprintf(stderr, "Symbol '%s' not allowed in import (only filter)\n", symbol);
        return NULL;
    }
    
    Value* val = env_get(mod->env, (char*)symbol);
    if (!val) return NULL;
    
    // Retourner un pointeur vers la valeur
    return val;
}

void dump_modules(void) {
    printf("\n=== MODULE REGISTRY ===\n");
    for (int i = 0; i < module_count; i++) {
        GoscriptModule* mod = modules[i];
        printf("Module %d:\n", i);
        printf("  Path: %s\n", mod->path ? mod->path : "(null)");
        printf("  Name: %s\n", mod->name ? mod->name : "(null)");
        printf("  Alias: %s\n", mod->alias ? mod->alias : "(null)");
        printf("  Status: %d\n", mod->status);
        printf("  RefCount: %d\n", mod->ref_count);
        printf("  Exports: %d\n", mod->constraints.exported_count);
        if (mod->constraints.only_count > 0) {
            printf("  Only filter: ");
            for (int j = 0; j < mod->constraints.only_count; j++) {
                printf("%s ", mod->constraints.only_allowed[j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("Total modules: %d\n", module_count);
    printf("========================\n");
}

void free_all_modules(void) {
    for (int i = 0; i < module_count; i++) {
        free_module(modules[i]);
        modules[i] = NULL;
    }
    module_count = 0;
}

// ==================== FONCTIONS DE COMPATIBILITÉ ====================

ModuleRegistry* init_module_registry(void) {
    // Pour compatibilité avec l'ancienne API
    return (ModuleRegistry*)1; // Dummy
}

void register_module(ModuleRegistry* reg, LoadedModule* mod) {
    // Compatibilité - non utilisé
    (void)reg;
    (void)mod;
}

LoadedModule* find_module(ModuleRegistry* reg, char* path) {
    // Compatibilité - utiliser find_module_by_path
    (void)reg;
    return (LoadedModule*)find_module_by_path(path);
}

void free_module_registry(ModuleRegistry* reg) {
    // Compatibilité
    (void)reg;
    free_all_modules();
}

LoadedModule* load_module_legacy(ModuleRegistry* reg, Environment* parent_env,
                                 char* current_file, char* import_path, 
                                 char* alias, ASTNode* constraints) {
    (void)reg;
    bool result = load_module(parent_env, current_file, import_path, alias, constraints);
    if (!result) return NULL;
    
    GoscriptModule* mod = find_module_by_name(alias ? alias : import_path);
    return (LoadedModule*)mod;
}
