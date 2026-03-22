/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_FN = 258,                /* TOKEN_FN  */
    TOKEN_LET = 259,               /* TOKEN_LET  */
    TOKEN_CONST = 260,             /* TOKEN_CONST  */
    TOKEN_RETURN = 261,            /* TOKEN_RETURN  */
    TOKEN_IF = 262,                /* TOKEN_IF  */
    TOKEN_ELSE = 263,              /* TOKEN_ELSE  */
    TOKEN_FOR = 264,               /* TOKEN_FOR  */
    TOKEN_WHILE = 265,             /* TOKEN_WHILE  */
    TOKEN_LOOP = 266,              /* TOKEN_LOOP  */
    TOKEN_BREAK = 267,             /* TOKEN_BREAK  */
    TOKEN_CONTINUE = 268,          /* TOKEN_CONTINUE  */
    TOKEN_IMPORT = 269,            /* TOKEN_IMPORT  */
    TOKEN_EXPORT = 270,            /* TOKEN_EXPORT  */
    TOKEN_PACKET = 271,            /* TOKEN_PACKET  */
    TOKEN_STRUCT = 272,            /* TOKEN_STRUCT  */
    TOKEN_ENUM = 273,              /* TOKEN_ENUM  */
    TOKEN_IMPL = 274,              /* TOKEN_IMPL  */
    TOKEN_MATCH = 275,             /* TOKEN_MATCH  */
    TOKEN_TYPE = 276,              /* TOKEN_TYPE  */
    TOKEN_TRUE = 277,              /* TOKEN_TRUE  */
    TOKEN_FALSE = 278,             /* TOKEN_FALSE  */
    TOKEN_NIL = 279,               /* TOKEN_NIL  */
    TOKEN_AS = 280,                /* TOKEN_AS  */
    TOKEN_IN = 281,                /* TOKEN_IN  */
    TOKEN_FROM = 282,              /* TOKEN_FROM  */
    TOKEN_PUB = 283,               /* TOKEN_PUB  */
    TOKEN_NEW = 284,               /* TOKEN_NEW  */
    TOKEN_UNSAFE = 285,            /* TOKEN_UNSAFE  */
    TOKEN_MODULE = 286,            /* TOKEN_MODULE  */
    TOKEN_ONLY = 287,              /* TOKEN_ONLY  */
    TOKEN_TIMEOUT = 288,           /* TOKEN_TIMEOUT  */
    TOKEN_SANDBOX = 289,           /* TOKEN_SANDBOX  */
    TOKEN_ALLOW_FFI = 290,         /* TOKEN_ALLOW_FFI  */
    TOKEN_EXTENDS = 291,           /* TOKEN_EXTENDS  */
    TOKEN_UNDERSCORE = 292,        /* TOKEN_UNDERSCORE  */
    TOKEN_PLUS = 293,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 294,             /* TOKEN_MINUS  */
    TOKEN_MULTIPLY = 295,          /* TOKEN_MULTIPLY  */
    TOKEN_DIVIDE = 296,            /* TOKEN_DIVIDE  */
    TOKEN_MODULO = 297,            /* TOKEN_MODULO  */
    TOKEN_ASSIGN = 298,            /* TOKEN_ASSIGN  */
    TOKEN_PLUS_ASSIGN = 299,       /* TOKEN_PLUS_ASSIGN  */
    TOKEN_MINUS_ASSIGN = 300,      /* TOKEN_MINUS_ASSIGN  */
    TOKEN_MULTIPLY_ASSIGN = 301,   /* TOKEN_MULTIPLY_ASSIGN  */
    TOKEN_DIVIDE_ASSIGN = 302,     /* TOKEN_DIVIDE_ASSIGN  */
    TOKEN_MODULO_ASSIGN = 303,     /* TOKEN_MODULO_ASSIGN  */
    TOKEN_EQ = 304,                /* TOKEN_EQ  */
    TOKEN_NEQ = 305,               /* TOKEN_NEQ  */
    TOKEN_LT = 306,                /* TOKEN_LT  */
    TOKEN_LTE = 307,               /* TOKEN_LTE  */
    TOKEN_GT = 308,                /* TOKEN_GT  */
    TOKEN_GTE = 309,               /* TOKEN_GTE  */
    TOKEN_AND = 310,               /* TOKEN_AND  */
    TOKEN_OR = 311,                /* TOKEN_OR  */
    TOKEN_NOT = 312,               /* TOKEN_NOT  */
    TOKEN_AMP = 313,               /* TOKEN_AMP  */
    TOKEN_PIPE = 314,              /* TOKEN_PIPE  */
    TOKEN_XOR = 315,               /* TOKEN_XOR  */
    TOKEN_LSHIFT = 316,            /* TOKEN_LSHIFT  */
    TOKEN_RSHIFT = 317,            /* TOKEN_RSHIFT  */
    TOKEN_DOUBLE_COLON = 318,      /* TOKEN_DOUBLE_COLON  */
    TOKEN_DOT = 319,               /* TOKEN_DOT  */
    TOKEN_SECURITY = 320,          /* TOKEN_SECURITY  */
    TOKEN_COLON = 321,             /* TOKEN_COLON  */
    TOKEN_SEMICOLON = 322,         /* TOKEN_SEMICOLON  */
    TOKEN_COMMA = 323,             /* TOKEN_COMMA  */
    TOKEN_ARROW = 324,             /* TOKEN_ARROW  */
    TOKEN_FAT_ARROW = 325,         /* TOKEN_FAT_ARROW  */
    TOKEN_PIPE_FORWARD = 326,      /* TOKEN_PIPE_FORWARD  */
    TOKEN_OPTIONAL = 327,          /* TOKEN_OPTIONAL  */
    TOKEN_COALESCE = 328,          /* TOKEN_COALESCE  */
    TOKEN_RANGE = 329,             /* TOKEN_RANGE  */
    TOKEN_RANGE_INC = 330,         /* TOKEN_RANGE_INC  */
    TOKEN_MUTS = 331,              /* TOKEN_MUTS  */
    TOKEN_LPAREN = 332,            /* TOKEN_LPAREN  */
    TOKEN_RPAREN = 333,            /* TOKEN_RPAREN  */
    TOKEN_LBRACE = 334,            /* TOKEN_LBRACE  */
    TOKEN_RBRACE = 335,            /* TOKEN_RBRACE  */
    TOKEN_LBRACKET = 336,          /* TOKEN_LBRACKET  */
    TOKEN_RBRACKET = 337,          /* TOKEN_RBRACKET  */
    TOKEN_IDENTIFIER = 338,        /* TOKEN_IDENTIFIER  */
    TOKEN_NUMBER = 339,            /* TOKEN_NUMBER  */
    TOKEN_FLOAT = 340,             /* TOKEN_FLOAT  */
    TOKEN_STRING = 341             /* TOKEN_STRING  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/parser/parser.y"

    int number;
    double float_val;
    char* string;
    struct ASTNode* node;
    struct ASTNodeList* node_list;

#line 158 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
