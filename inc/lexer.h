#ifndef GOSCRIPT_LEXER_H
#define GOSCRIPT_LEXER_H

#include "token.h"

void init_lexer(const char* source);
Token scan_token();

#endif

