#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <ffi.h>
#include <setjmp.h>
#include "../ast/ast.h"

// Forward declarations
struct Environment;
struct LoadedModule;
struct ModuleRegistry;

// ========== DÉFINITION DE LA STRUCTURE VALUE ==========
// Définir Value AVANT de l'utiliser
typedef struct Value {
    int type;
    union {
        int int_val;
        double float_val;
        char* string_val;
        int bool_val;
        struct {
            struct ASTNode* node;
            struct Environment* closure;
        } func_val;
        struct {
            void* func_ptr;
            ffi_cif cif;
            ffi_type** arg_types;
            ffi_type* ret_type;
            int arg_count;
            char* name;
        } cfunc_val;
        struct {
            char* struct_name;
            struct {
                char* name;
                struct Value* value;
            }* fields;
            int field_count;
        } struct_val;
        // Tableau
        struct {
            struct Value* elements;  // Maintenant Value est défini
            int count;
        } array_val;
        // Lambda
        struct {
            struct ASTNode* node;
            struct Environment* closure;
        } lambda_val;
    };
} Value;

// ========== STRUCTURES DE L'ENVIRONNEMENT ==========
struct Environment {
    struct Environment* parent;
    struct {
        char* name;
        Value value;
    }* vars;
    int var_count;
    int var_capacity;
};

// ========== STRUCTURE POUR UN MODULE CHARGÉ ==========
typedef struct LoadedModule {
    char* module_path;
    char* module_name;
    char* alias;
    struct Environment* env;
    int status;
    int ref_count;
    struct {
        char** allowed_names;
        int allowed_count;
        int timeout_ms;
        int sandbox;
        int allow_ffi;
    } constraints;
} LoadedModule;

// ========== TABLE GLOBALE DES MODULES ==========
typedef struct ModuleRegistry {
    LoadedModule** modules;
    int count;
    int capacity;
} ModuleRegistry;

// ========== DÉCLARATIONS DES FONCTIONS ==========
ModuleRegistry* init_module_registry(void);
void register_module(ModuleRegistry* reg, LoadedModule* mod);
LoadedModule* find_module(ModuleRegistry* reg, char* path);
void free_module_registry(ModuleRegistry* reg);
char* resolve_module_path(char* current_file, char* import_path);
LoadedModule* load_module(ModuleRegistry* reg, struct Environment* parent_env,
                          char* current_file, char* import_path, 
                          char* alias, ASTNode* constraints);
void process_constraints(LoadedModule* module, ASTNode* constraints);
int is_name_allowed(LoadedModule* module, char* name);
int is_ffi_allowed(LoadedModule* module);

// Fonctions d'environnement
struct Environment* create_env(struct Environment* parent);
void env_set(struct Environment* env, char* name, Value value);
Value* env_get(struct Environment* env, char* name);

// Fonctions FFI
ffi_type* get_ffi_type(char* type_name);
void register_c_function(struct Environment* env, char* name, void* func_ptr, 
                         char* ret_type, int arg_count, ...);
void* load_c_library(char* path);
void call_c_function(Value* cfunc, Value* args, int arg_count, Value* result);
Value call_c_function_ffi(void* func_ptr, Value* args, int arg_count, 
                          ffi_type* ret_type, ffi_type** arg_types);

// Fonctions d'affichage
void print_value(Value val, int newline);

// Fonctions d'évaluation
void init_interpreter(void);
int evaluate_statement(ASTNode* node, struct Environment* env, char* current_file);
void interpret_program(ASTNode* program);
Value evaluate_expr(ASTNode* node, struct Environment* env);

// Fonctions natives
void register_native_c_functions(struct Environment* env);
void register_impl(char* struct_name, ASTNode* impl_node);
ModuleRegistry* get_module_registry(void);

// Définition des types de valeurs
#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_STRING 2
#define TYPE_BOOL 3
#define TYPE_FUNCTION 4
#define TYPE_CFUNCTION 5
#define TYPE_STRUCT 6
#define TYPE_MODULE 7
#define TYPE_ARRAY 8
#define TYPE_LAMBDA 9

#endif /* INTERPRETER_H */
