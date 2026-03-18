#include "common.h"
#include "lexer.h"
#include "parser.h"
#include "vm.h"

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
    if (bytesRead < fileSize) {
        fprintf(stderr, "Erreur : Impossible de lire le fichier '%s'.\n", path);
        exit(74);
    }
    buffer[bytesRead] = '\0';
    fclose(file);
    return buffer;
}

static void repl() {
    VM vm;
    init_vm(&vm);
    
    char line[1024];
    printf("GOScript REPL v0.1 - Tapez 'exit' pour quitter\n");
    
    while (true) {
        printf("> ");
        if (!fgets(line, sizeof(line), stdin)) break;
        
        // Enlever le newline
        line[strcspn(line, "\n")] = 0;
        
        if (strcmp(line, "exit") == 0) break;
        if (strlen(line) == 0) continue;
        
        init_lexer(line);
        Node* ast = parse();
        
        if (ast) {
            execute(&vm, ast);
            free_ast(ast);
        }
    }
    
    free_vm(&vm);
}

static void run_file(const char* path) {
    char* source = read_file(path);
    
    // Initialisation
    init_lexer(source);
    
    // Parsing
    Node* ast = parse();
    
    if (ast) {
        // Exécution
        VM vm;
        init_vm(&vm);
        
        bool success = execute(&vm, ast);
        
        free_vm(&vm);
        free_ast(ast);
        
        if (!success) {
            exit(70); // Erreur d'exécution
        }
    } else {
        exit(65); // Erreur de parsing
    }
    
    free(source);
}

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        // Mode REPL (interactif)
        repl();
        return 0;
    } else if (argc == 2) {
        // Exécuter un fichier
        run_file(argv[1]);
        return 0;
    } else {
        fprintf(stderr, "Usage: goscript [chemin_vers_fichier.gjs]\n");
        fprintf(stderr, "   ou: goscript (mode interactif)\n");
        return 64;
    }
}
