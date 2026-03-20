CC = gcc
CFLAGS = -Wall -g -O2 -I./src
LDFLAGS = -lm

SRC_DIR = src
LEXER_DIR = $(SRC_DIR)/lexer
PARSER_DIR = $(SRC_DIR)/parser
AST_DIR = $(SRC_DIR)/ast
INTERPRETER_DIR = $(SRC_DIR)/interpreter

LEXER_SRC = $(LEXER_DIR)/scanner.l
PARSER_SRC = $(PARSER_DIR)/parser.y
AST_SRC = $(AST_DIR)/ast.c
INTERPRETER_SRC = $(INTERPRETER_DIR)/interpreter.c
MAIN_SRC = $(SRC_DIR)/main.c

# Fichiers générés
SCANNER_C = scanner.c
PARSER_C = parser.c
PARSER_H = parser.h

OBJS = $(SCANNER_C:.c=.o) $(PARSER_C:.c=.o) ast.o interpreter.o main.o

all: $(PARSER_H) $(SCANNER_C) $(PARSER_C) $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o goscript

$(SCANNER_C): $(LEXER_SRC)
	flex -o $(SCANNER_C) $(LEXER_SRC)

$(PARSER_C) $(PARSER_H): $(PARSER_SRC)
	bison -d -o $(PARSER_C) $(PARSER_SRC)

scanner.o: $(SCANNER_C) $(PARSER_H)
	$(CC) $(CFLAGS) -c $(SCANNER_C) -o scanner.o

parser.o: $(PARSER_C)
	$(CC) $(CFLAGS) -c $(PARSER_C) -o parser.o

ast.o: $(AST_SRC) $(PARSER_H)
	$(CC) $(CFLAGS) -c $(AST_SRC) -o ast.o

interpreter.o: $(INTERPRETER_SRC) $(PARSER_H)
	$(CC) $(CFLAGS) -c $(INTERPRETER_SRC) -o interpreter.o

main.o: $(MAIN_SRC) $(PARSER_H)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o main.o

clean:
	rm -f $(SCANNER_C) $(PARSER_C) $(PARSER_H)
	rm -f *.o
	rm -f goscript

.PHONY: all clean
