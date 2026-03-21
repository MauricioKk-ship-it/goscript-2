#include "interpreter.h"
#include <libgen.h>
#include <sys/stat.h>

// Résoudre un chemin d'import
char* resolve_module_path(char* current_file, char* import_path) {
    char* result = NULL;
    
    // Chemin absolu ?
    if (import_path[0] == '/') {
        result = strdup(import_path);
    }
    // Chemin relatif (commence par . ou ..)
    else if (import_path[0] == '.') {
        char* dir = strdup(current_file);
        char* dirname_ptr = dirname(dir);
        
        // Construire le chemin complet
        char full_path[1024];
        if (import_path[1] == '/') {
            // ./module
            snprintf(full_path, sizeof(full_path), "%s/%s", dirname_ptr, import_path + 2);
        } else if (import_path[1] == '.') {
            // ../module
            char* parent = dirname(dirname_ptr);
            snprintf(full_path, sizeof(full_path), "%s/%s", parent, import_path + 3);
        } else {
            snprintf(full_path, sizeof(full_path), "%s/%s", dirname_ptr, import_path);
        }
        
        result = strdup(full_path);
        free(dir);
    }
    // Module standard
    else {
        // Chercher dans /usr/local/lib/goscript/granul/packages/
        char* paths[] = {
            "/usr/local/lib/goscript/granul/packages/",
            "/usr/lib/goscript/",
            "./modules/"
        };
        
        for (int i = 0; i < 3; i++) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s%s", paths[i], import_path);
            
            // Vérifier si c'est un dossier avec __self__.gjs
            char self_path[1024];
            snprintf(self_path, sizeof(self_path), "%s/__self__.gjs", full_path);
            if (access(self_path, F_OK) == 0) {
                result = strdup(self_path);
                break;
            }
            
            // Vérifier si c'est un fichier .gjs
            snprintf(self_path, sizeof(self_path), "%s.gjs", full_path);
            if (access(self_path, F_OK) == 0) {
                result = strdup(self_path);
                break;
            }
        }
    }
    
    return result;
}

// Charger un module avec ses contraintes
LoadedModule* load_module(ModuleRegistry* reg, char* current_file, 
                          char* import_path, char* alias, 
                          ASTNode* constraints) {
    // 1. Résoudre le chemin
    char* module_path = resolve_module_path(current_file, import_path);
    if (!module_path) {
        fprintf(stderr, "Module not found: %s\n", import_path);
        return NULL;
    }
    
    // 2. Vérifier si déjà chargé
    LoadedModule* existing = find_module(reg, module_path);
    if (existing) {
        existing->ref_count++;
        free(module_path);
        return existing;
    }
    
    // 3. Créer un nouvel environnement pour le module
    Environment* module_env = create_env(NULL);  // Environnement isolé
    
    // 4. Parser et exécuter __self__.gjs
    FILE* f = fopen(module_path, "r");
    if (!f) {
        free(module_path);
        return NULL;
    }
    
    // Sauvegarder l'ancien yyin
    extern FILE* yyin;
    FILE* old_yyin = yyin;
    yyin = f;
    
    extern ASTNode* program_root;
    int parse_result = yyparse();
    
    fclose(f);
    yyin = old_yyin;
    
    if (parse_result != 0 || !program_root) {
        free(module_path);
        return NULL;
    }
    
    // 5. Appliquer les contraintes
    LoadedModule* module = malloc(sizeof(LoadedModule));
    module->module_path = module_path;
    module->module_name = alias ? strdup(alias) : strdup(import_path);
    module->env = module_env;
    module->status = 1;
    module->ref_count = 1;
    
    // Initialiser les contraintes par défaut
    module->constraints.allowed_names = NULL;
    module->constraints.allowed_count = 0;
    module->constraints.timeout_ms = 0;
    module->constraints.sandbox = 0;
    module->constraints.allow_ffi = 1;
    
    // 6. Exécuter le module dans son environnement
    // Interpreter le programme du module
    interpret_program_in_env(program_root, module_env);
    
    // 7. Enregistrer le module
    register_module(reg, module);
    
    // 8. Lier le module à l'environnement parent
    Value module_val;
    module_val.type = 7;  // Type module
    module_val.int_val = (int)module;
    env_set(env, alias ? alias : import_path, module_val);
    
    return module;
}
