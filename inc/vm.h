#ifndef GOSCRIPT_VM_H
#define GOSCRIPT_VM_H

#include "ast.h"

#define STACK_MAX 256
#define GLOBALS_MAX 256
#define LOCALS_MAX 64

typedef struct {
    char* name;
    bool is_initialized;
    union {
        double number;
        char* string;
        bool boolean;
    } value;
    int type; // 0: number, 1: string, 2: bool
} Value;

typedef struct {
    Value* locals;
    int local_count;
    struct Frame* parent;
} Frame;

typedef struct {
    Value globals[GLOBALS_MAX];
    int global_count;
    
    Frame* current_frame;
    
    double stack[STACK_MAX];
    int stack_top;
    
    bool had_error;
    bool return_flag;
    double return_value;
    
    // Pour les fonctions
    struct Function* functions;
    int function_count;
} VM;

typedef struct Function {
    char* name;
    Node* params;
    Node* body;
    struct Function* next;
} Function;

void init_vm(VM* vm);
void free_vm(VM* vm);
bool execute(VM* vm, Node* ast);
void push(VM* vm, double value);
double pop(VM* vm);

#endif
