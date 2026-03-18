#include "common.h"
#include "lexer.h"
#include "parser.h"

static char* read_file(const char* path) {
    FILE* file = fopen(path, "rb");
    if (file == NULL) {
        fprintf(stderr, "Erreur : Impossible d'ouvrir le fichier '%s'.\n", path);
        exit(74);
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char* buffer = (char*)allocate(fileSize + 1);
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file);
    buffer[bytesRead] = '\0';
    fclose(file);
    return buffer;
}

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: goscript [chemin_vers_fichier.gjs]\n");
        return 64;
    }

    char* source = read_file(argv[1]);
    
    // Initialisation
    init_lexer(source);

    // Lancement du parsing (et à terme de l'exécution)
    // C'est ici que ton code devient silencieux et efficace
    Node* ast = parse();

    // Libération mémoire finale
    free_ast(ast);
    free(source);
    
    return 0;
}

