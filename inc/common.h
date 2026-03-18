#ifndef GOSCRIPT_COMMON_H
#define GOSCRIPT_COMMON_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

// Inclusion de ton système de tokens
#include "token.h"

// Définitions de structures globales partagées
typedef struct {
    char* source;
    size_t length;
    int line;
} GOScriptContext;

// Prototypes généraux partagés
void error(const char* message, int line);
void* allocate(size_t size);

#endif

