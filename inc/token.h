#ifndef GOSCRIPT_TOKEN_H
#define GOSCRIPT_TOKEN_H

typedef enum {
    // Mots-clés
    TOKEN_FN, TOKEN_CLASS, TOKEN_ENUM, TOKEN_LET, TOKEN_CONST,
    TOKEN_USE, TOKEN_EXPORT, TOKEN_IF, TOKEN_ELSE, TOKEN_ASYNC, TOKEN_AWAIT,
    
    // Identifiants et valeurs
    TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,
    
    // Opérateurs et ponctuation
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_STAR, TOKEN_SLASH,
    TOKEN_EQUAL, TOKEN_DOT, TOKEN_COMMA, TOKEN_SEMICOLON,
    TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_LBRACE, TOKEN_RBRACE,
  
    // Système spécifique
    TOKEN_GETLF, // Ta fonction de sortie
    
    TOKEN_EOF,   // Fin de fichier
    TOKEN_ERROR  // Erreur de scan
} TokenType;

typedef struct {
    TokenType type;
    const char* start; // Pointeur vers le début du lexème
    int length;        // Longueur du lexème
    int line;          // Numéro de ligne pour le débogage
} Token;

#endif

