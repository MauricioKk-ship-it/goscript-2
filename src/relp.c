#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ast.h"
#include "../parser.h"

extern ASTNode* program_root;
extern FILE* yyin;
extern int yyparse(void);
extern int yylineno;
extern char* yytext;

// Couleurs ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#define COLOR_BOLD    "\033[1m"

// Liste des mots-clés pour coloration
const char* keywords[] = {
    "fn", "lt", "cn", "ret", "if", "else", "for", "while", 
    "loop", "break", "continue", "import", "packet", "true", 
    "false", "nil", "struct", "enm", "impl", "match", "type",
    NULL
};

// Liste des types
const char* types[] = {
    "int", "float", "string", "bool", NULL
};

// Fonction de coloration syntaxique
char* colorize_line(const char* line) {
    static char buffer[4096];
    buffer[0] = '\0';
    char word[256];
    int i = 0, j = 0;
    int in_string = 0;
    int in_comment = 0;
    
    while (line[i] != '\0') {
        // Gestion des chaînes
        if (line[i] == '"' && !in_comment) {
            strcat(buffer, COLOR_GREEN);
            strcat(buffer, "\"");
            i++;
            while (line[i] != '"' && line[i] != '\0') {
                char c[2] = {line[i], '\0'};
                strcat(buffer, c);
                i++;
            }
            if (line[i] == '"') {
                strcat(buffer, "\"");
                i++;
            }
            strcat(buffer, COLOR_RESET);
            continue;
        }
        
        // Gestion des commentaires
        if (line[i] == '/' && line[i+1] == '/' && !in_string) {
            strcat(buffer, COLOR_CYAN);
            while (line[i] != '\0') {
                char c[2] = {line[i], '\0'};
                strcat(buffer, c);
                i++;
            }
            strcat(buffer, COLOR_RESET);
            break;
        }
        
        // Extraction des mots
        if ((line[i] >= 'a' && line[i] <= 'z') || 
            (line[i] >= 'A' && line[i] <= 'Z') || 
            line[i] == '_') {
            j = 0;
            while ((line[i] >= 'a' && line[i] <= 'z') ||
                   (line[i] >= 'A' && line[i] <= 'Z') ||
                   (line[i] >= '0' && line[i] <= '9') ||
                   line[i] == '_') {
                word[j++] = line[i++];
            }
            word[j] = '\0';
            
            // Vérifier si c'est un mot-clé
            int is_keyword = 0;
            for (int k = 0; keywords[k] != NULL; k++) {
                if (strcmp(word, keywords[k]) == 0) {
                    strcat(buffer, COLOR_BOLD COLOR_MAGENTA);
                    strcat(buffer, word);
                    strcat(buffer, COLOR_RESET);
                    is_keyword = 1;
                    break;
                }
            }
            
            // Vérifier si c'est un type
            if (!is_keyword) {
                for (int k = 0; types[k] != NULL; k++) {
                    if (strcmp(word, types[k]) == 0) {
                        strcat(buffer, COLOR_CYAN);
                        strcat(buffer, word);
                        strcat(buffer, COLOR_RESET);
                        is_keyword = 1;
                        break;
                    }
                }
            }
            
            if (!is_keyword) {
                strcat(buffer, word);
            }
            continue;
        }
        
        // Nombres
        if (line[i] >= '0' && line[i] <= '9') {
            strcat(buffer, COLOR_YELLOW);
            while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.') {
                char c[2] = {line[i], '\0'};
                strcat(buffer, c);
                i++;
            }
            strcat(buffer, COLOR_RESET);
            continue;
        }
        
        // Opérateurs
        if (strchr("+-*/=<>!&|%", line[i])) {
            strcat(buffer, COLOR_BLUE);
            char c[2] = {line[i], '\0'};
            strcat(buffer, c);
            strcat(buffer, COLOR_RESET);
            i++;
            continue;
        }
        
        // Parenthèses, accolades, etc.
        if (strchr("(){}[];,", line[i])) {
            strcat(buffer, COLOR_RED);
            char c[2] = {line[i], '\0'};
            strcat(buffer, c);
            strcat(buffer, COLOR_RESET);
            i++;
            continue;
        }
        
        // Caractères normaux
        char c[2] = {line[i], '\0'};
        strcat(buffer, c);
        i++;
    }
    
    return buffer;
}

// Fonction d'affichage du prompt
char* get_prompt() {
    static char prompt[256];
    snprintf(prompt, sizeof(prompt), "%sgoscript%s> ", COLOR_GREEN, COLOR_RESET);
    return prompt;
}

// Fonction d'évaluation d'une ligne
int evaluate_line(const char* line) {
    if (strlen(line) == 0) return 0;
    
    // Créer un fichier temporaire
    char temp_file[] = "/tmp/goscript_XXXXXX";
    int fd = mkstemp(temp_file);
    if (fd == -1) {
        printf("Error: Cannot create temp file\n");
        return 1;
    }
    
    // Écrire la ligne dans le fichier temporaire
    write(fd, line, strlen(line));
    write(fd, "\n", 1);
    close(fd);
    
    // Ouvrir le fichier pour parsing
    yyin = fopen(temp_file, "r");
    if (!yyin) {
        printf("Error: Cannot open temp file\n");
        unlink(temp_file);
        return 1;
    }
    
    // Parser
    yylineno = 1;
    int parse_result = yyparse();
    fclose(yyin);
    
    if (parse_result == 0 && program_root) {
        // Exécuter le code
        interpret_program(program_root);
        free_ast(program_root);
        program_root = NULL;
    } else if (parse_result != 0) {
        printf("%sError: Parsing failed%s\n", COLOR_RED, COLOR_RESET);
    }
    
    unlink(temp_file);
    return 0;
}

// Fonction d'affichage du help
void show_help() {
    printf("\n");
    printf("=== Goscript REPL Help ===\n");
    printf("\n");
    printf("Commands:\n");
    printf("  %s.exit%s     - Exit the REPL\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s.help%s     - Show this help\n", COLOR_YELLOW, COLOR_RESET);
    printf("  %s.clear%s    - Clear screen\n", COLOR_YELLOW, COLOR_RESET);
    printf("\n");
    printf("Features:\n");
    printf("  - Syntax highlighting for keywords, strings, numbers\n");
    printf("  - Command history (use Up/Down arrows)\n");
    printf("  - Multi-line input (use \\ at end of line)\n");
    printf("\n");
    printf("Example:\n");
    printf("  >>> lt a = 10\n");
    printf("  >>> lt b = 20\n");
    printf("  >>> println(a + b)\n");
    printf("  30\n");
    printf("\n");
}

// Fonction principale du REPL
int repl_main() {
    printf("\n");
    printf("\n");
    printf("       Goscript REPL v1.0              \n");
    printf("       Type .help for help             \n");
    printf("powered by (c) 2026 GOPU INC. MIT LICENSE\n");
    printf("\n");
    
    // Initialiser readline
    rl_bind_key('\t', rl_complete);  // Tab completion
    
    char* input;
    char* line_buffer = NULL;
    size_t buffer_size = 0;
    
    while (1) {
        char* prompt = get_prompt();
        input = readline(prompt);
        free(prompt);
        
        if (!input) {
            printf("\n");
            break;
        }
        
        if (strlen(input) > 0) {
            add_history(input);
        }
        
        // Gérer les commandes spéciales
        if (strcmp(input, ".exit") == 0) {
            free(input);
            break;
        } else if (strcmp(input, ".help") == 0) {
            show_help();
            free(input);
            continue;
        } else if (strcmp(input, ".clear") == 0) {
            printf("\033[2J\033[H");
            free(input);
            continue;
        }
        
        // Vérifier si c'est une ligne multiligne
        if (input[strlen(input)-1] == '\\') {
            // Multi-line input
            if (line_buffer == NULL) {
                line_buffer = malloc(1);
                line_buffer[0] = '\0';
            }
            
            size_t len = strlen(line_buffer) + strlen(input);
            line_buffer = realloc(line_buffer, len + 1);
            strcat(line_buffer, input);
            // Remplacer le \ final par un espace
            line_buffer[len-1] = ' ';
            free(input);
            continue;
        } else if (line_buffer) {
            // Fin du multiline
            size_t len = strlen(line_buffer) + strlen(input) + 1;
            line_buffer = realloc(line_buffer, len);
            strcat(line_buffer, input);
            free(input);
            
            // Évaluer la ligne complète
            evaluate_line(line_buffer);
            free(line_buffer);
            line_buffer = NULL;
        } else {
            // Ligne simple
            evaluate_line(input);
            free(input);
        }
        
        printf("\n");
    }
    
    printf("New use bye user Stat locked!\n");
    return 0;
}
