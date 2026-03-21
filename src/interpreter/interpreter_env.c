#include "interpreter.h"

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
