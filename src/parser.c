#include "common.h"
#include "lexer.h"
#include "ast.h"
#include "parser.h"

static Token current;
static Token previous;

// Prototypes internes
static void advance();
static void consume(TokenType type, const char* message);
static bool match(TokenType type);
static void declaration();
static void statement();
static void block();

static void advance() {
    previous = current;
    for (;;) {
        current = scan_token();
        if (current.type != TOKEN_ERROR) break;
        error("Erreur de scan", current.line);
    }
}

static void consume(TokenType type, const char* message) {
    if (current.type == type) {
        advance();
        return;
    }
    error(message, current.line);
}

static bool match(TokenType type) {
    if (current.type == type) {
        advance();
        return true;
    }
    return false;
}

// Gère le contenu entre { et }
static void block() {
    while (current.type != TOKEN_RBRACE && current.type != TOKEN_EOF) {
        declaration();
    }
    consume(TOKEN_RBRACE, "Attendu '}' après le bloc.");
}

// Gère les déclarations de haut niveau (fn, etc.)
static void declaration() {
    if (match(TOKEN_FN)) {
        consume(TOKEN_IDENTIFIER, "Attendu un nom de fonction.");
        consume(TOKEN_LPAREN, "Attendu '(' après le nom.");
        consume(TOKEN_RPAREN, "Attendu ')' après les arguments.");
        consume(TOKEN_LBRACE, "Attendu '{' avant le corps de la fonction.");
        block();
    } else {
        statement();
    }
}

// Gère les instructions simples (let, getlf, etc.)
static void statement() {
    if (match(TOKEN_LET)) {
        consume(TOKEN_IDENTIFIER, "Attendu un nom de variable.");
        consume(TOKEN_EQUAL, "Attendu '=' après la variable.");
        // Pour l'instant, on ignore l'expression
        consume(TOKEN_NUMBER, "Attendu un nombre.");
        consume(TOKEN_SEMICOLON, "Attendu ';'.");
    } else if (match(TOKEN_GETLF)) {
        consume(TOKEN_LPAREN, "Attendu '(' après getlf.");
        consume(TOKEN_IDENTIFIER, "Attendu une variable.");
        consume(TOKEN_RPAREN, "Attendu ')' après l'identifiant.");
        consume(TOKEN_SEMICOLON, "Attendu ';'.");
    } else {
        advance(); // On avance pour éviter une boucle infinie en cas d'erreur
    }
}

Node* parse(void) {
    advance();
    while (current.type != TOKEN_EOF) {
        declaration();
    }
    return NULL; // Retournera l'AST complet une fois finalisé
}

