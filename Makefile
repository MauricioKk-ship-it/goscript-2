CC = gcc
CFLAGS = -Wall -g -O2
LDFLAGS = -lm -ldl

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

OBJS = scanner.o parser.o ast.o interpreter.o main.o

all: goscript

scanner.c: $(LEXER_SRC)
	flex -o scanner.c $(LEXER_SRC)

parser.c: $(PARSER_SRC)
	bison -d -o parser.c $(PARSER_SRC)

scanner.o: scanner.c parser.h
	$(CC) $(CFLAGS) -c scanner.c -o scanner.o

parser.o: parser.c
	$(CC) $(CFLAGS) -c parser.c -o parser.o

ast.o: $(AST_SRC)
	$(CC) $(CFLAGS) -c $(AST_SRC) -o ast.o

interpreter.o: $(INTERPRETER_SRC)
	$(CC) $(CFLAGS) -c $(INTERPRETER_SRC) -o interpreter.o

main.o: $(MAIN_SRC)
	$(CC) $(CFLAGS) -c $(MAIN_SRC) -o main.o

goscript: $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o goscript

clean:
	rm -f scanner.c parser.c parser.h
	rm -f *.o
	rm -f goscript

install:
	cp goscript /usr/local/bin/
	mkdir -p /usr/local/lib/goscript/granul/

test:
	./goscript examples/test.gjs

.PHONY: all clean install test
