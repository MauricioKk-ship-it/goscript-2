#include "common.h"
#include "lexer.h"

typedef struct {
    const char* start;
    const char* current;
    int line;
} Lexer;

Lexer scanner;

void init_lexer(const char* source) {
    scanner.start = source;
    scanner.current = source;
    scanner.line = 1;
}

static bool is_at_end() {
    return *scanner.current == '\0';
}

static Token make_token(TokenType type) {
    Token token;
    token.type = type;
    token.start = scanner.start;
    token.length = (int)(scanner.current - scanner.start);
    token.line = scanner.line;
    return token;
}

static TokenType check_keyword(int start, int length, const char* rest, TokenType type) {
    if (scanner.current - scanner.start == start + length &&
        memcmp(scanner.start + start, rest, length) == 0) {
        return type;
    }
    return TOKEN_IDENTIFIER;
}

static TokenType identifier_type() {
    switch (scanner.start[0]) {
        case 'a': 
            if (scanner.current - scanner.start > 1) {
                switch (scanner.start[1]) {
                    case 's': return check_keyword(2, 4, "sync", TOKEN_ASYNC);
                    case 'w': return check_keyword(2, 3, "ait", TOKEN_AWAIT);
                }
            }
            break;
        case 'c': return check_keyword(1, 4, "lass", TOKEN_CLASS);
        case 'e': return check_keyword(1, 3, "num", TOKEN_ENUM);
        case 'f': return check_keyword(1, 1, "n", TOKEN_FN);
        case 'g': return check_keyword(1, 4, "etlf", TOKEN_GETLF);
        case 'i': return check_keyword(1, 1, "f", TOKEN_IF);
        case 'l': return check_keyword(1, 2, "et", TOKEN_LET);
        case 'u': return check_keyword(1, 2, "se", TOKEN_USE);
    }
    return TOKEN_IDENTIFIER;
}

static Token identifier() {
    while (isalnum(*scanner.current)) scanner.current++;
    return make_token(identifier_type());
}

Token scan_token() {
    scanner.start = scanner.current;

    if (is_at_end()) return make_token(TOKEN_EOF);

    char c = *scanner.current++;

    // Sauter les espaces et gérer les lignes
    while (c == ' ' || c == '\r' || c == '\t' || c == '\n') {
        if (c == '\n') scanner.line++;
        scanner.start = scanner.current;
        if (is_at_end()) return make_token(TOKEN_EOF);
        c = *scanner.current++;
    }

    if (isalpha(c)) return identifier();

    switch (c) {
        case '(': return make_token(TOKEN_LPAREN);
        case ')': return make_token(TOKEN_RPAREN);
        case '{': return make_token(TOKEN_LBRACE);
        case '}': return make_token(TOKEN_RBRACE);
        case ';': return make_token(TOKEN_SEMICOLON);
        case '=': return make_token(TOKEN_EQUAL);
        case '.': return make_token(TOKEN_DOT);
        case '+': return make_token(TOKEN_PLUS);
    }

    return make_token(TOKEN_ERROR);
}

