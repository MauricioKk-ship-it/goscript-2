#include "interpreter.h"

ffi_type* get_ffi_type(char* type_name) {
    if (strcmp(type_name, "int") == 0 || strcmp(type_name, "i32") == 0) {
        return &ffi_type_sint32;
    } else if (strcmp(type_name, "float") == 0 || strcmp(type_name, "f32") == 0) {
        return &ffi_type_float;
    } else if (strcmp(type_name, "double") == 0 || strcmp(type_name, "f64") == 0) {
        return &ffi_type_double;
    } else if (strcmp(type_name, "string") == 0 || strcmp(type_name, "char*") == 0) {
        return &ffi_type_pointer;
    } else if (strcmp(type_name, "void") == 0) {
        return &ffi_type_void;
    } else if (strcmp(type_name, "bool") == 0) {
        return &ffi_type_sint8;
    }
    return &ffi_type_pointer;
}

void register_c_function(Environment* env, char* name, void* func_ptr, char* ret_type, int arg_count, ...) {
    Value func_val;
    func_val.type = 5;
    func_val.cfunc_val.func_ptr = func_ptr;
    func_val.cfunc_val.ret_type = get_ffi_type(ret_type);
    func_val.cfunc_val.arg_count = arg_count;
    func_val.cfunc_val.name = strdup(name);
    
    func_val.cfunc_val.arg_types = malloc(arg_count * sizeof(ffi_type*));
    
    va_list args;
    va_start(args, arg_count);
    for (int i = 0; i < arg_count; i++) {
        char* arg_type = va_arg(args, char*);
        func_val.cfunc_val.arg_types[i] = get_ffi_type(arg_type);
    }
    va_end(args);
    
    ffi_prep_cif(&func_val.cfunc_val.cif, FFI_DEFAULT_ABI, arg_count,
                 func_val.cfunc_val.ret_type, func_val.cfunc_val.arg_types);
    
    env_set(env, name, func_val);
}

void* load_c_library(char* path) {
    void* handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error loading library %s: %s\n", path, dlerror());
        return NULL;
    }
    return handle;
}

void call_c_function(Value* cfunc, Value* args, int arg_count, Value* result) {
    if (cfunc->type != 5) {
        fprintf(stderr, "Not a C function\n");
        return;
    }
    
    void** values = malloc(arg_count * sizeof(void*));
    void* ret_val = malloc(32);
    
    for (int i = 0; i < arg_count && i < cfunc->cfunc_val.arg_count; i++) {
        switch (args[i].type) {
            case 0: values[i] = &args[i].int_val; break;
            case 1: values[i] = &args[i].float_val; break;
            case 2: values[i] = &args[i].string_val; break;
            case 3: values[i] = &args[i].bool_val; break;
            default: values[i] = NULL;
        }
    }
    
    ffi_call(&cfunc->cfunc_val.cif, FFI_FN(cfunc->cfunc_val.func_ptr), ret_val, values);
    
    if (cfunc->cfunc_val.ret_type == &ffi_type_sint32) {
        result->type = 0;
        result->int_val = *(int*)ret_val;
    } else if (cfunc->cfunc_val.ret_type == &ffi_type_float) {
        result->type = 1;
        result->float_val = *(float*)ret_val;
    } else if (cfunc->cfunc_val.ret_type == &ffi_type_double) {
        result->type = 1;
        result->float_val = *(double*)ret_val;
    } else if (cfunc->cfunc_val.ret_type == &ffi_type_pointer) {
        result->type = 2;
        result->string_val = strdup(*(char**)ret_val);
    } else if (cfunc->cfunc_val.ret_type == &ffi_type_sint8) {
        result->type = 3;
        result->bool_val = *(int*)ret_val;
    } else {
        result->type = 0;
        result->int_val = 0;
    }
    
    free(values);
    free(ret_val);
}
