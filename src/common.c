#include "../inc/common.h"

// Gestion d'erreurs centralisée pour GOScript
void error(const char* message, int line) {
    fprintf(stderr, "[GOScript Error] Ligne %d: %s\n", line, message);
    exit(1); 
}

// Wrapper d'allocation mémoire pour le Garbage Collector futur
void* allocate(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        error("Erreur critique: Mémoire insuffisante pour GOScript.", 0);
    }
    return ptr;
}

// Ici tu ajouteras plus tard tes fonctions de manipulation d'objets,
// comme la création de nouvelles instances de classes ou de fonctions.

