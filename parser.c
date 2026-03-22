/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylineno;
extern char* yytext;

void yyerror(const char* msg);
int yylex(void);

ASTNode* program_root;

#line 86 "parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_FN = 3,                   /* TOKEN_FN  */
  YYSYMBOL_TOKEN_LET = 4,                  /* TOKEN_LET  */
  YYSYMBOL_TOKEN_CONST = 5,                /* TOKEN_CONST  */
  YYSYMBOL_TOKEN_RETURN = 6,               /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_IF = 7,                   /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 8,                 /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_FOR = 9,                  /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_WHILE = 10,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_LOOP = 11,                /* TOKEN_LOOP  */
  YYSYMBOL_TOKEN_BREAK = 12,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 13,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_IMPORT = 14,              /* TOKEN_IMPORT  */
  YYSYMBOL_TOKEN_EXPORT = 15,              /* TOKEN_EXPORT  */
  YYSYMBOL_TOKEN_PACKET = 16,              /* TOKEN_PACKET  */
  YYSYMBOL_TOKEN_STRUCT = 17,              /* TOKEN_STRUCT  */
  YYSYMBOL_TOKEN_ENUM = 18,                /* TOKEN_ENUM  */
  YYSYMBOL_TOKEN_IMPL = 19,                /* TOKEN_IMPL  */
  YYSYMBOL_TOKEN_MATCH = 20,               /* TOKEN_MATCH  */
  YYSYMBOL_TOKEN_TYPE = 21,                /* TOKEN_TYPE  */
  YYSYMBOL_TOKEN_TRUE = 22,                /* TOKEN_TRUE  */
  YYSYMBOL_TOKEN_FALSE = 23,               /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_NIL = 24,                 /* TOKEN_NIL  */
  YYSYMBOL_TOKEN_AS = 25,                  /* TOKEN_AS  */
  YYSYMBOL_TOKEN_IN = 26,                  /* TOKEN_IN  */
  YYSYMBOL_TOKEN_FROM = 27,                /* TOKEN_FROM  */
  YYSYMBOL_TOKEN_PUB = 28,                 /* TOKEN_PUB  */
  YYSYMBOL_TOKEN_NEW = 29,                 /* TOKEN_NEW  */
  YYSYMBOL_TOKEN_UNSAFE = 30,              /* TOKEN_UNSAFE  */
  YYSYMBOL_TOKEN_MODULE = 31,              /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_ONLY = 32,                /* TOKEN_ONLY  */
  YYSYMBOL_TOKEN_TIMEOUT = 33,             /* TOKEN_TIMEOUT  */
  YYSYMBOL_TOKEN_SANDBOX = 34,             /* TOKEN_SANDBOX  */
  YYSYMBOL_TOKEN_ALLOW_FFI = 35,           /* TOKEN_ALLOW_FFI  */
  YYSYMBOL_TOKEN_EXTENDS = 36,             /* TOKEN_EXTENDS  */
  YYSYMBOL_TOKEN_UNDERSCORE = 37,          /* TOKEN_UNDERSCORE  */
  YYSYMBOL_TOKEN_PLUS = 38,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 39,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLY = 40,            /* TOKEN_MULTIPLY  */
  YYSYMBOL_TOKEN_DIVIDE = 41,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_MODULO = 42,              /* TOKEN_MODULO  */
  YYSYMBOL_TOKEN_ASSIGN = 43,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 44,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 45,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULTIPLY_ASSIGN = 46,     /* TOKEN_MULTIPLY_ASSIGN  */
  YYSYMBOL_TOKEN_DIVIDE_ASSIGN = 47,       /* TOKEN_DIVIDE_ASSIGN  */
  YYSYMBOL_TOKEN_MODULO_ASSIGN = 48,       /* TOKEN_MODULO_ASSIGN  */
  YYSYMBOL_TOKEN_EQ = 49,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 50,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LT = 51,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_LTE = 52,                 /* TOKEN_LTE  */
  YYSYMBOL_TOKEN_GT = 53,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_GTE = 54,                 /* TOKEN_GTE  */
  YYSYMBOL_TOKEN_AND = 55,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 56,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 57,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AMP = 58,                 /* TOKEN_AMP  */
  YYSYMBOL_TOKEN_PIPE = 59,                /* TOKEN_PIPE  */
  YYSYMBOL_TOKEN_XOR = 60,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_LSHIFT = 61,              /* TOKEN_LSHIFT  */
  YYSYMBOL_TOKEN_RSHIFT = 62,              /* TOKEN_RSHIFT  */
  YYSYMBOL_TOKEN_DOUBLE_COLON = 63,        /* TOKEN_DOUBLE_COLON  */
  YYSYMBOL_TOKEN_DOT = 64,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_SECURITY = 65,            /* TOKEN_SECURITY  */
  YYSYMBOL_TOKEN_COLON = 66,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMICOLON = 67,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_COMMA = 68,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_ARROW = 69,               /* TOKEN_ARROW  */
  YYSYMBOL_TOKEN_FAT_ARROW = 70,           /* TOKEN_FAT_ARROW  */
  YYSYMBOL_TOKEN_PIPE_FORWARD = 71,        /* TOKEN_PIPE_FORWARD  */
  YYSYMBOL_TOKEN_OPTIONAL = 72,            /* TOKEN_OPTIONAL  */
  YYSYMBOL_TOKEN_COALESCE = 73,            /* TOKEN_COALESCE  */
  YYSYMBOL_TOKEN_RANGE = 74,               /* TOKEN_RANGE  */
  YYSYMBOL_TOKEN_RANGE_INC = 75,           /* TOKEN_RANGE_INC  */
  YYSYMBOL_TOKEN_MUTS = 76,                /* TOKEN_MUTS  */
  YYSYMBOL_TOKEN_LPAREN = 77,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 78,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LBRACE = 79,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 80,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_LBRACKET = 81,            /* TOKEN_LBRACKET  */
  YYSYMBOL_TOKEN_RBRACKET = 82,            /* TOKEN_RBRACKET  */
  YYSYMBOL_TOKEN_IDENTIFIER = 83,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_NUMBER = 84,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_FLOAT = 85,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_STRING = 86,              /* TOKEN_STRING  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_program = 88,                   /* program  */
  YYSYMBOL_statement_list = 89,            /* statement_list  */
  YYSYMBOL_unsafe_stmt = 90,               /* unsafe_stmt  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_import_statement = 92,          /* import_statement  */
  YYSYMBOL_import_constraints = 93,        /* import_constraints  */
  YYSYMBOL_import_options = 94,            /* import_options  */
  YYSYMBOL_name_list = 95,                 /* name_list  */
  YYSYMBOL_export_statement = 96,          /* export_statement  */
  YYSYMBOL_packet_decl = 97,               /* packet_decl  */
  YYSYMBOL_function_decl = 98,             /* function_decl  */
  YYSYMBOL_param_list = 99,                /* param_list  */
  YYSYMBOL_param = 100,                    /* param  */
  YYSYMBOL_type = 101,                     /* type  */
  YYSYMBOL_return_type = 102,              /* return_type  */
  YYSYMBOL_let_decl = 103,                 /* let_decl  */
  YYSYMBOL_const_decl = 104,               /* const_decl  */
  YYSYMBOL_if_statement = 105,             /* if_statement  */
  YYSYMBOL_break_statement = 106,          /* break_statement  */
  YYSYMBOL_for_statement = 107,            /* for_statement  */
  YYSYMBOL_while_statement = 108,          /* while_statement  */
  YYSYMBOL_loop_statement = 109,           /* loop_statement  */
  YYSYMBOL_match_statement = 110,          /* match_statement  */
  YYSYMBOL_match_cases = 111,              /* match_cases  */
  YYSYMBOL_match_case = 112,               /* match_case  */
  YYSYMBOL_pattern = 113,                  /* pattern  */
  YYSYMBOL_struct_decl = 114,              /* struct_decl  */
  YYSYMBOL_struct_fields = 115,            /* struct_fields  */
  YYSYMBOL_struct_field = 116,             /* struct_field  */
  YYSYMBOL_enum_decl = 117,                /* enum_decl  */
  YYSYMBOL_enum_variants = 118,            /* enum_variants  */
  YYSYMBOL_module_decl = 119,              /* module_decl  */
  YYSYMBOL_impl_decl = 120,                /* impl_decl  */
  YYSYMBOL_function_decl_list = 121,       /* function_decl_list  */
  YYSYMBOL_return_statement = 122,         /* return_statement  */
  YYSYMBOL_expression = 123,               /* expression  */
  YYSYMBOL_binary_expr = 124,              /* binary_expr  */
  YYSYMBOL_unary_expr = 125,               /* unary_expr  */
  YYSYMBOL_primary_expr = 126,             /* primary_expr  */
  YYSYMBOL_member_access = 127,            /* member_access  */
  YYSYMBOL_call_expr = 128,                /* call_expr  */
  YYSYMBOL_argument_list = 129,            /* argument_list  */
  YYSYMBOL_array_expr = 130,               /* array_expr  */
  YYSYMBOL_array_items = 131,              /* array_items  */
  YYSYMBOL_struct_expr = 132,              /* struct_expr  */
  YYSYMBOL_struct_init_fields = 133        /* struct_init_fields  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  91
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  143
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  302

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,   100,   104,   110,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   141,   144,   150,   156,   160,
     166,   169,   175,   181,   184,   190,   194,   201,   207,   213,
     216,   220,   229,   232,   236,   243,   246,   252,   255,   258,
     264,   267,   270,   277,   280,   283,   289,   292,   297,   300,
     309,   312,   317,   322,   328,   334,   340,   347,   353,   357,
     364,   370,   373,   376,   379,   385,   388,   394,   397,   401,
     405,   412,   418,   424,   427,   431,   438,   445,   451,   454,
     458,   465,   468,   474,   475,   476,   480,   483,   486,   489,
     492,   495,   498,   501,   504,   507,   510,   513,   516,   519,
     522,   525,   528,   531,   534,   540,   543,   549,   552,   555,
     558,   561,   564,   567,   570,   573,   574,   575,   576,   580,
     583,   589,   592,   598,   601,   605,   612,   618,   621,   625,
     632,   638,   641,   645
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_FN",
  "TOKEN_LET", "TOKEN_CONST", "TOKEN_RETURN", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_FOR", "TOKEN_WHILE", "TOKEN_LOOP", "TOKEN_BREAK",
  "TOKEN_CONTINUE", "TOKEN_IMPORT", "TOKEN_EXPORT", "TOKEN_PACKET",
  "TOKEN_STRUCT", "TOKEN_ENUM", "TOKEN_IMPL", "TOKEN_MATCH", "TOKEN_TYPE",
  "TOKEN_TRUE", "TOKEN_FALSE", "TOKEN_NIL", "TOKEN_AS", "TOKEN_IN",
  "TOKEN_FROM", "TOKEN_PUB", "TOKEN_NEW", "TOKEN_UNSAFE", "TOKEN_MODULE",
  "TOKEN_ONLY", "TOKEN_TIMEOUT", "TOKEN_SANDBOX", "TOKEN_ALLOW_FFI",
  "TOKEN_EXTENDS", "TOKEN_UNDERSCORE", "TOKEN_PLUS", "TOKEN_MINUS",
  "TOKEN_MULTIPLY", "TOKEN_DIVIDE", "TOKEN_MODULO", "TOKEN_ASSIGN",
  "TOKEN_PLUS_ASSIGN", "TOKEN_MINUS_ASSIGN", "TOKEN_MULTIPLY_ASSIGN",
  "TOKEN_DIVIDE_ASSIGN", "TOKEN_MODULO_ASSIGN", "TOKEN_EQ", "TOKEN_NEQ",
  "TOKEN_LT", "TOKEN_LTE", "TOKEN_GT", "TOKEN_GTE", "TOKEN_AND",
  "TOKEN_OR", "TOKEN_NOT", "TOKEN_AMP", "TOKEN_PIPE", "TOKEN_XOR",
  "TOKEN_LSHIFT", "TOKEN_RSHIFT", "TOKEN_DOUBLE_COLON", "TOKEN_DOT",
  "TOKEN_SECURITY", "TOKEN_COLON", "TOKEN_SEMICOLON", "TOKEN_COMMA",
  "TOKEN_ARROW", "TOKEN_FAT_ARROW", "TOKEN_PIPE_FORWARD", "TOKEN_OPTIONAL",
  "TOKEN_COALESCE", "TOKEN_RANGE", "TOKEN_RANGE_INC", "TOKEN_MUTS",
  "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE", "TOKEN_RBRACE",
  "TOKEN_LBRACKET", "TOKEN_RBRACKET", "TOKEN_IDENTIFIER", "TOKEN_NUMBER",
  "TOKEN_FLOAT", "TOKEN_STRING", "$accept", "program", "statement_list",
  "unsafe_stmt", "statement", "import_statement", "import_constraints",
  "import_options", "name_list", "export_statement", "packet_decl",
  "function_decl", "param_list", "param", "type", "return_type",
  "let_decl", "const_decl", "if_statement", "break_statement",
  "for_statement", "while_statement", "loop_statement", "match_statement",
  "match_cases", "match_case", "pattern", "struct_decl", "struct_fields",
  "struct_field", "enum_decl", "enum_variants", "module_decl", "impl_decl",
  "function_decl_list", "return_statement", "expression", "binary_expr",
  "unary_expr", "primary_expr", "member_access", "call_expr",
  "argument_list", "array_expr", "array_items", "struct_expr",
  "struct_init_fields", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
#endif

#define YYPACT_NINF (-186)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     864,   -41,   -36,   -26,   -14,   -14,   100,   -14,     4,  -186,
     -37,   -25,     1,     3,    36,    66,   -14,  -186,  -186,  -186,
     141,    67,     8,    68,   -14,   -14,    70,   -14,   -14,  -186,
    -186,  -186,  -186,   128,   864,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  1114,  -186,  -186,    54,  -186,  -186,
    -186,  -186,    71,   -21,   111,  1114,   210,   113,   913,   932,
     864,   -29,   -11,  -186,    76,   -18,    91,    94,   974,    92,
      93,    95,   103,   864,  -186,   191,   161,   -15,  1035,  1114,
     -34,  -186,  -186,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,    96,   104,   -14,   105,   -14,   -43,   -14,   864,
     -14,   864,   864,   289,   110,  -186,   107,   -57,   159,  -186,
     864,   109,   116,   117,    16,   -24,   124,   151,   171,   132,
     320,   -14,   -43,  -186,   -14,  -186,   191,   191,   161,   161,
     161,   224,   224,   224,   224,   224,   224,   685,   685,   120,
     120,   120,   120,   570,   455,   139,  -186,  1114,    -2,   153,
      52,  -186,   338,   135,   149,   179,   338,   404,  1054,   435,
     519,  -186,   140,  -186,   142,  -186,   158,    -3,   550,   148,
     162,   -31,  -186,  -186,    41,   226,  -186,     2,  -186,  -186,
    -186,  -186,    -5,  -186,   172,   105,   -14,   -14,   175,    58,
    -186,   338,   200,  1114,   -14,   -14,  -186,   -43,   105,   -30,
     -43,  -186,   -14,   237,   -14,  -186,  -186,  -186,  -186,   165,
     159,  -186,  -186,   116,   -43,   116,  -186,  -186,   192,  -186,
    -186,  -186,  -186,  -186,   -14,    65,   338,   338,   -14,   194,
    -186,   -14,    74,  1114,  -186,  -186,   -43,   112,   -38,  -186,
     338,   195,  1084,   199,   215,     5,  -186,  -186,  -186,  1114,
     -30,  1114,   212,   338,  -186,  -186,    54,   -14,   864,   864,
     -14,  -186,    45,  -186,   205,   -14,  1114,   634,   665,   993,
     202,  -186,   864,  1114,  -186,  -186,   864,  -186,   749,   780,
    -186,  -186
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    92,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   123,
     117,   118,   119,     0,     2,    19,     3,     6,     7,     9,
      10,    14,    16,    17,    15,    18,    20,    21,    22,    11,
      12,     8,    13,    23,    24,    93,    94,    95,   128,   125,
     126,   127,     0,     0,     0,    91,     0,   123,     0,     0,
       0,     0,    25,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,   116,   115,     0,     0,   138,
       0,     1,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,    31,
       0,     0,    77,    83,    88,     0,     0,     0,     0,   141,
       0,     0,     0,   124,     0,   136,    96,    97,    98,    99,
     100,   109,   110,   111,   112,   113,   114,   101,   102,   103,
     104,   105,   106,   107,   108,   130,   129,   134,     0,    45,
       0,    43,    53,     0,    47,     0,    58,     0,     0,     0,
       0,    66,     0,    30,     0,    28,     0,     0,     0,     0,
       0,     0,    78,    84,     0,     0,    89,     0,    74,    73,
      71,    72,     0,    68,     0,    42,     0,     0,     0,     0,
       5,    56,     0,   139,   133,     0,   131,     0,     0,    50,
       0,    48,     0,    60,     0,    64,    65,    27,    29,     0,
       0,    32,    38,    77,     0,     0,    75,    80,     0,    82,
      87,    90,    67,    69,     0,     0,    55,    59,     0,     0,
     140,     0,     0,   135,    46,    44,     0,     0,     0,    49,
      54,     0,     0,     0,    34,     0,    81,    79,    85,    70,
      50,   142,     0,    57,   132,    51,    52,     0,     0,     0,
       0,    35,     0,    76,     0,     0,    41,     0,     0,     0,
       0,    33,     0,   143,    39,    61,     0,    36,     0,     0,
      40,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -186,  -186,   -66,  -186,    -8,  -186,  -186,    56,  -186,  -186,
    -186,  -123,    82,    79,  -109,    18,  -186,  -186,  -186,  -186,
    -186,  -186,  -186,  -186,  -186,   108,  -186,  -186,    69,  -185,
    -186,  -186,  -186,  -186,  -186,  -186,    -4,  -186,  -186,    57,
    -186,  -186,   101,  -186,  -186,  -186,  -186
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    33,    34,    35,    36,    37,   129,   187,   282,    38,
      39,    40,   170,   171,   175,   258,    41,    42,    43,    44,
      45,    46,    47,    48,   202,   203,   204,    49,   191,   192,
      50,   194,    51,    52,   197,    53,    54,    55,    56,    57,
      58,    59,   168,    60,    90,    61,   209
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    66,    68,    69,   123,     1,   237,   184,    17,    18,
      19,   196,    78,   198,   126,    21,   127,   140,   131,     1,
      85,    86,   116,    88,    89,    24,    92,    71,   141,   185,
     195,   277,   198,   212,   144,   124,   256,   235,   173,   257,
     174,   278,    62,    25,   195,   117,    72,    63,   145,   236,
     267,   142,   190,   177,   125,   179,   180,    64,    73,   199,
     200,   132,   201,    27,   188,   230,   215,    28,   128,    29,
      30,    31,    32,   235,   241,   242,   216,   231,   199,   200,
     237,   201,   240,    70,    74,   283,    75,    83,   190,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   254,   238,
     167,   259,   172,   290,   176,    92,   178,   112,   113,    76,
     218,   239,    17,    18,    19,   266,   249,   291,    91,    21,
     219,   114,    92,   218,    17,    18,    19,   211,   250,    24,
     213,    21,   215,   270,    79,    80,    81,   275,   115,    77,
      82,    84,   274,    87,   118,   130,   120,    25,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    92,
     133,    92,    92,   134,   182,   136,   137,    27,   138,   165,
      92,    28,   139,    67,    30,    31,    32,   166,   169,    27,
     183,   186,   189,    28,   206,    29,    30,    31,    32,   190,
     193,   205,   246,   247,    98,    99,   100,   101,   102,   103,
     167,   253,   287,   288,   207,   208,   214,   220,   260,   217,
     262,   221,   222,   227,   229,   228,   298,   233,   234,    79,
     299,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     269,   248,   244,   251,   271,   261,   263,   273,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   286,   279,   268,   289,   272,   285,    92,
      92,   293,   281,   230,   292,   297,   264,   245,   284,   119,
      92,    92,     1,     2,     3,     4,     5,   255,     6,     7,
       8,     9,   265,    10,    11,    12,    13,    14,    15,    16,
     243,    17,    18,    19,   276,   252,     0,    20,    21,    22,
      23,     0,     0,     1,     2,     3,     4,     5,    24,     6,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,     0,    25,     0,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,    26,    27,     0,     0,   181,
      28,     0,    29,    30,    31,    32,    93,    25,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,    26,    27,     0,     0,
     210,    28,     0,    29,    30,    31,    32,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,     0,
       0,     0,    20,    21,    22,    23,     0,     0,     1,     2,
       3,     4,     5,    24,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,    19,
       0,    25,     0,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
      26,    27,     0,     0,   223,    28,     0,    29,    30,    31,
      32,     0,    25,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,    26,    27,     0,     0,   225,    28,     0,    29,    30,
      31,    32,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,     0,     0,     0,    20,    21,    22,
      23,     0,     0,     1,     2,     3,     4,     5,    24,     6,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,     0,    25,     0,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,    26,    27,     0,     0,   226,
      28,     0,    29,    30,    31,    32,     0,    25,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,    26,    27,     0,     0,
     232,    28,     0,    29,    30,    31,    32,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,     0,
       0,     0,    20,    21,    22,    23,     0,     0,     1,     2,
       3,     4,     5,    24,     6,     7,     8,     9,     0,    10,
      11,    12,    13,    14,    15,    16,     0,    17,    18,    19,
       0,    25,     0,    20,    21,    22,    23,     0,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
      26,    27,     0,     0,   294,    28,     0,    29,    30,    31,
      32,     0,    25,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,   106,   107,   108,   109,
       0,    26,    27,     0,     0,   295,    28,     0,    29,    30,
      31,    32,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,     0,     0,     0,    20,    21,    22,
      23,     0,     0,     1,     2,     3,     4,     5,    24,     6,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,     0,    25,     0,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,     0,     0,    26,    27,     0,     0,   300,
      28,     0,    29,    30,    31,    32,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    27,     0,     0,
     301,    28,     0,    29,    30,    31,    32,     1,     2,     3,
       4,     5,     0,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,     0,    17,    18,    19,     0,
       0,     0,    20,    21,    22,    23,     0,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      26,    27,     0,     0,     0,    28,     0,    29,    30,    31,
      32,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,     0,     0,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   296,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   224,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   280,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,    70,     3,   191,    64,    22,    23,
      24,   134,    16,    37,    25,    29,    27,    83,    36,     3,
      24,    25,    43,    27,    28,    39,    34,    64,    43,    86,
      28,    69,    37,   142,    68,    64,    66,    68,    81,    69,
      83,    79,    83,    57,    28,    66,    83,    83,    82,    80,
     235,    66,    83,   119,    83,   121,   122,    83,    83,    83,
      84,    79,    86,    77,   130,    68,    68,    81,    79,    83,
      84,    85,    86,    68,   197,    80,    78,    80,    83,    84,
     265,    86,    80,    79,    83,    80,    83,    79,    83,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   217,    68,
     114,   220,   116,    68,   118,   123,   120,    63,    64,    83,
      68,    80,    22,    23,    24,   234,    68,    82,     0,    29,
      78,    77,   140,    68,    22,    23,    24,   141,    80,    39,
     144,    29,    68,    78,     3,     4,     5,   256,    77,    83,
      83,    83,    78,    83,    43,    79,    43,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   177,
      79,   179,   180,    79,    64,    83,    83,    77,    83,    83,
     188,    81,    79,    83,    84,    85,    86,    83,    83,    77,
      83,    32,    83,    81,    43,    83,    84,    85,    86,    83,
      83,    77,   206,   207,    43,    44,    45,    46,    47,    48,
     214,   215,   278,   279,    43,    83,    77,    82,   222,    66,
     224,    72,    43,    83,    66,    83,   292,    79,    66,     3,
     296,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     244,    66,    70,    43,   248,     8,    81,   251,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    43,    44,    45,
      46,    47,    48,   277,    79,    83,   280,    83,    66,   287,
     288,   285,    83,    68,    79,    83,   230,   205,   270,    79,
     298,   299,     3,     4,     5,     6,     7,   218,     9,    10,
      11,    12,   233,    14,    15,    16,    17,    18,    19,    20,
     202,    22,    23,    24,   257,   214,    -1,    28,    29,    30,
      31,    -1,    -1,     3,     4,     5,     6,     7,    39,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    57,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,
      81,    -1,    83,    84,    85,    86,    38,    57,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    76,    77,    -1,    -1,
      80,    81,    -1,    83,    84,    85,    86,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,     3,     4,
       5,     6,     7,    39,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    57,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    80,    81,    -1,    83,    84,    85,
      86,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    76,    77,    -1,    -1,    80,    81,    -1,    83,    84,
      85,    86,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,     3,     4,     5,     6,     7,    39,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    57,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,
      81,    -1,    83,    84,    85,    86,    -1,    57,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    -1,    76,    77,    -1,    -1,
      80,    81,    -1,    83,    84,    85,    86,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,     3,     4,
       5,     6,     7,    39,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    -1,    22,    23,    24,
      -1,    57,    -1,    28,    29,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    80,    81,    -1,    83,    84,    85,
      86,    -1,    57,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    -1,    51,    52,    53,    54,
      -1,    76,    77,    -1,    -1,    80,    81,    -1,    83,    84,
      85,    86,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,    -1,     3,     4,     5,     6,     7,    39,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    57,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    80,
      81,    -1,    83,    84,    85,    86,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,
      80,    81,    -1,    83,    84,    85,    86,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,    23,    24,    -1,
      -1,    -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    -1,    -1,    -1,    81,    -1,    83,    84,    85,
      86,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    79,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      14,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      28,    29,    30,    31,    39,    57,    76,    77,    81,    83,
      84,    85,    86,    88,    89,    90,    91,    92,    96,    97,
      98,   103,   104,   105,   106,   107,   108,   109,   110,   114,
     117,   119,   120,   122,   123,   124,   125,   126,   127,   128,
     130,   132,    83,    83,    83,   123,   123,    83,   123,   123,
      79,    64,    83,    83,    83,    83,    83,    83,   123,     3,
       4,     5,    83,    79,    83,   123,   123,    83,   123,   123,
     131,     0,    91,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    63,    64,    77,    77,    43,    66,    43,    79,
      43,    79,    79,    89,    64,    83,    25,    27,    79,    93,
      79,    36,    79,    79,    79,    79,    83,    83,    83,    79,
      89,    43,    66,    78,    68,    82,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,    83,    83,   123,   129,    83,
      99,   100,   123,    81,    83,   101,   123,    89,   123,    89,
      89,    80,    64,    83,    64,    86,    32,    94,    89,    83,
      83,   115,   116,    83,   118,    28,    98,   121,    37,    83,
      84,    86,   111,   112,   113,    77,    43,    43,    83,   133,
      80,   123,   101,   123,    77,    68,    78,    66,    68,    78,
      82,    72,    43,    80,    67,    80,    80,    83,    83,    66,
      68,    80,    80,    79,    66,    68,    80,   116,    68,    80,
      80,    98,    80,   112,    70,    99,   123,   123,    66,    68,
      80,    43,   129,   123,   101,   100,    66,    69,   102,   101,
     123,     8,   123,    81,    94,   115,   101,   116,    83,   123,
      78,   123,    83,   123,    78,   101,   126,    69,    79,    79,
      67,    83,    95,    80,   102,    66,   123,    89,    89,   123,
      68,    82,    79,   123,    80,    80,    79,    83,    89,    89,
      80,    80
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    89,    89,    90,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    93,    94,    94,    95,    95,    96,    97,    98,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   106,   107,   107,   108,   109,   110,   111,   111,
     112,   113,   113,   113,   113,   114,   114,   115,   115,   115,
     115,   116,   117,   118,   118,   118,   119,   120,   121,   121,
     121,   122,   122,   123,   123,   123,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   127,
     127,   128,   128,   129,   129,   129,   130,   131,   131,   131,
     132,   133,   133,   133
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     5,     4,     5,
       4,     3,     3,     5,     3,     1,     3,     2,     5,     9,
      10,     8,     0,     1,     3,     1,     3,     1,     2,     3,
       0,     2,     2,     4,     6,     5,     4,     6,     4,     5,
       5,     9,     1,    11,     5,     5,     4,     5,     1,     2,
       3,     1,     1,     1,     1,     5,     7,     0,     1,     3,
       2,     3,     5,     0,     1,     3,     2,     5,     0,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       3,     4,     6,     0,     1,     3,     3,     0,     1,     3,
       5,     0,     3,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 94 "src/parser/parser.y"
                   {
        program_root = create_program_node((yyvsp[0].node_list));
    }
#line 1622 "parser.c"
    break;

  case 3: /* statement_list: statement  */
#line 100 "src/parser/parser.y"
              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1631 "parser.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 104 "src/parser/parser.y"
                               {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 1640 "parser.c"
    break;

  case 5: /* unsafe_stmt: TOKEN_UNSAFE TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 110 "src/parser/parser.y"
                                                          {
        (yyval.node) = create_unsafe_node((yyvsp[-1].node_list));
    }
#line 1648 "parser.c"
    break;

  case 24: /* statement: expression  */
#line 134 "src/parser/parser.y"
                 {
        (yyval.node) = create_expr_statement((yyvsp[0].node));
    }
#line 1656 "parser.c"
    break;

  case 25: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER  */
#line 141 "src/parser/parser.y"
                                  {
        (yyval.node) = create_import_node((yyvsp[0].string), NULL, NULL);
    }
#line 1664 "parser.c"
    break;

  case 26: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 144 "src/parser/parser.y"
                                              {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1675 "parser.c"
    break;

  case 27: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_DOT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 150 "src/parser/parser.y"
                                                                  {
        char* path = malloc(strlen((yyvsp[0].string)) + 4);
        sprintf(path, "../%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1686 "parser.c"
    break;

  case 28: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_STRING  */
#line 156 "src/parser/parser.y"
                                                            {
        (yyval.node) = create_import_node((yyvsp[0].string), (yyvsp[-2].string), NULL);
    }
#line 1694 "parser.c"
    break;

  case 29: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_DOT TOKEN_IDENTIFIER  */
#line 160 "src/parser/parser.y"
                                                                          {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, (yyvsp[-3].string), NULL);
        free(path);
    }
#line 1705 "parser.c"
    break;

  case 30: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_AS TOKEN_IDENTIFIER  */
#line 166 "src/parser/parser.y"
                                                              {
        (yyval.node) = create_import_node((yyvsp[-2].string), (yyvsp[0].string), NULL);
    }
#line 1713 "parser.c"
    break;

  case 31: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER import_constraints  */
#line 169 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_import_node((yyvsp[-1].string), NULL, (yyvsp[0].node));
    }
#line 1721 "parser.c"
    break;

  case 32: /* import_constraints: TOKEN_LBRACE import_options TOKEN_RBRACE  */
#line 175 "src/parser/parser.y"
                                             {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1729 "parser.c"
    break;

  case 33: /* import_options: TOKEN_ONLY TOKEN_COLON TOKEN_LBRACKET name_list TOKEN_RBRACKET  */
#line 181 "src/parser/parser.y"
                                                                   {
        (yyval.node) = create_constraints_node("only", (yyvsp[-1].node_list));
    }
#line 1737 "parser.c"
    break;

  case 34: /* import_options: import_options TOKEN_COMMA import_options  */
#line 184 "src/parser/parser.y"
                                                {
        (yyval.node) = merge_constraints((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1745 "parser.c"
    break;

  case 35: /* name_list: TOKEN_IDENTIFIER  */
#line 190 "src/parser/parser.y"
                     {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 1754 "parser.c"
    break;

  case 36: /* name_list: name_list TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 194 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1763 "parser.c"
    break;

  case 37: /* export_statement: TOKEN_EXPORT TOKEN_IDENTIFIER  */
#line 201 "src/parser/parser.y"
                                  {
        (yyval.node) = create_export_node((yyvsp[0].string));
    }
#line 1771 "parser.c"
    break;

  case 38: /* packet_decl: TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 207 "src/parser/parser.y"
                                                                           {
        (yyval.node) = create_packet_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 1779 "parser.c"
    break;

  case 39: /* function_decl: TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 213 "src/parser/parser.y"
                                                                                                                        {
        (yyval.node) = create_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1787 "parser.c"
    break;

  case 40: /* function_decl: TOKEN_PUB TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 216 "src/parser/parser.y"
                                                                                                                                    {
        (yyval.node) = create_public_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1795 "parser.c"
    break;

  case 41: /* function_decl: TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_ARROW expression  */
#line 220 "src/parser/parser.y"
                                                                                                        {
        ASTNodeList* body = create_node_list();
        ASTNode* return_stmt = create_return_node((yyvsp[0].node));
        add_to_node_list(body, return_stmt);
        (yyval.node) = create_function_node((yyvsp[-6].string), (yyvsp[-4].node_list), (yyvsp[-2].node), body);
    }
#line 1806 "parser.c"
    break;

  case 42: /* param_list: %empty  */
#line 229 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 1814 "parser.c"
    break;

  case 43: /* param_list: param  */
#line 232 "src/parser/parser.y"
            {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1823 "parser.c"
    break;

  case 44: /* param_list: param_list TOKEN_COMMA param  */
#line 236 "src/parser/parser.y"
                                   {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1832 "parser.c"
    break;

  case 45: /* param: TOKEN_IDENTIFIER  */
#line 243 "src/parser/parser.y"
                     {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 1840 "parser.c"
    break;

  case 46: /* param: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 246 "src/parser/parser.y"
                                        {
        (yyval.node) = create_param_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1848 "parser.c"
    break;

  case 47: /* type: TOKEN_IDENTIFIER  */
#line 252 "src/parser/parser.y"
                     {
        (yyval.node) = create_type_node((yyvsp[0].string));
    }
#line 1856 "parser.c"
    break;

  case 48: /* type: TOKEN_IDENTIFIER TOKEN_OPTIONAL  */
#line 255 "src/parser/parser.y"
                                      {
        (yyval.node) = create_optional_type_node((yyvsp[-1].string));
    }
#line 1864 "parser.c"
    break;

  case 49: /* type: TOKEN_LBRACKET TOKEN_RBRACKET type  */
#line 258 "src/parser/parser.y"
                                         {
        (yyval.node) = create_array_type_node((yyvsp[0].node));
    }
#line 1872 "parser.c"
    break;

  case 50: /* return_type: %empty  */
#line 264 "src/parser/parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1880 "parser.c"
    break;

  case 51: /* return_type: TOKEN_COLON type  */
#line 267 "src/parser/parser.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1888 "parser.c"
    break;

  case 52: /* return_type: TOKEN_ARROW primary_expr  */
#line 270 "src/parser/parser.y"
                               {
        // Pour les retours directs: -> expr
        (yyval.node) = create_return_direct_node((yyvsp[0].node));
    }
#line 1897 "parser.c"
    break;

  case 53: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 277 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_let_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
    }
#line 1905 "parser.c"
    break;

  case 54: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expression  */
#line 280 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_let_node((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1913 "parser.c"
    break;

  case 55: /* let_decl: TOKEN_PUB TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 283 "src/parser/parser.y"
                                                                   {
        ASTNode* node = create_let_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
        node->var_decl.is_public = 1;
        (yyval.node) = node;
    }
#line 1923 "parser.c"
    break;

  case 56: /* let_decl: TOKEN_MUTS TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 289 "src/parser/parser.y"
                                                          {
        (yyval.node) = create_muts_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
    }
#line 1931 "parser.c"
    break;

  case 57: /* let_decl: TOKEN_MUTS TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expression  */
#line 292 "src/parser/parser.y"
                                                                           {
        (yyval.node) = create_muts_node((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1939 "parser.c"
    break;

  case 58: /* const_decl: TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 297 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_const_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1947 "parser.c"
    break;

  case 59: /* const_decl: TOKEN_PUB TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 300 "src/parser/parser.y"
                                                                     {
        // Créer une constante publique
        ASTNode* node = create_const_node((yyvsp[-2].string), (yyvsp[0].node));
        node->var_decl.is_public = 1;
        (yyval.node) = node;
    }
#line 1958 "parser.c"
    break;

  case 60: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 309 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_if_node((yyvsp[-3].node), (yyvsp[-1].node_list), NULL);
    }
#line 1966 "parser.c"
    break;

  case 61: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 312 "src/parser/parser.y"
                                                                                                                       {
        (yyval.node) = create_if_node((yyvsp[-7].node), (yyvsp[-5].node_list), (yyvsp[-1].node_list));
    }
#line 1974 "parser.c"
    break;

  case 62: /* break_statement: TOKEN_BREAK  */
#line 317 "src/parser/parser.y"
                {
        (yyval.node) = create_break_node();
    }
#line 1982 "parser.c"
    break;

  case 63: /* for_statement: TOKEN_FOR TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON expression TOKEN_SEMICOLON expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 322 "src/parser/parser.y"
                                                                                                                                                      {
        ASTNode* init = create_let_node((yyvsp[-9].string), NULL, (yyvsp[-7].node));
        ASTNode* cond = (yyvsp[-5].node);
        ASTNode* inc = create_expr_statement((yyvsp[-3].node));
        (yyval.node) = create_for_node(init, cond, inc, (yyvsp[-1].node_list));
    }
#line 1993 "parser.c"
    break;

  case 64: /* for_statement: TOKEN_FOR expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 328 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2001 "parser.c"
    break;

  case 65: /* while_statement: TOKEN_WHILE expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 334 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2009 "parser.c"
    break;

  case 66: /* loop_statement: TOKEN_LOOP TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 340 "src/parser/parser.y"
                                                        {
        (yyval.node) = create_loop_node((yyvsp[-1].node_list));
    }
#line 2017 "parser.c"
    break;

  case 67: /* match_statement: TOKEN_MATCH expression TOKEN_LBRACE match_cases TOKEN_RBRACE  */
#line 347 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_match_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2025 "parser.c"
    break;

  case 68: /* match_cases: match_case  */
#line 353 "src/parser/parser.y"
               {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2034 "parser.c"
    break;

  case 69: /* match_cases: match_cases match_case  */
#line 357 "src/parser/parser.y"
                             {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2043 "parser.c"
    break;

  case 70: /* match_case: pattern TOKEN_FAT_ARROW expression  */
#line 364 "src/parser/parser.y"
                                       {
        (yyval.node) = create_match_case_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2051 "parser.c"
    break;

  case 71: /* pattern: TOKEN_NUMBER  */
#line 370 "src/parser/parser.y"
                 {
        (yyval.node) = create_pattern_number((yyvsp[0].number));
    }
#line 2059 "parser.c"
    break;

  case 72: /* pattern: TOKEN_STRING  */
#line 373 "src/parser/parser.y"
                   {
        (yyval.node) = create_pattern_string((yyvsp[0].string));
    }
#line 2067 "parser.c"
    break;

  case 73: /* pattern: TOKEN_IDENTIFIER  */
#line 376 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_ident((yyvsp[0].string));
    }
#line 2075 "parser.c"
    break;

  case 74: /* pattern: TOKEN_UNDERSCORE  */
#line 379 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_wildcard();
    }
#line 2083 "parser.c"
    break;

  case 75: /* struct_decl: TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE  */
#line 385 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_struct_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2091 "parser.c"
    break;

  case 76: /* struct_decl: TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_EXTENDS TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE  */
#line 388 "src/parser/parser.y"
                                                                                                           {
        (yyval.node) = create_struct_extend_node((yyvsp[-5].string), (yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2099 "parser.c"
    break;

  case 77: /* struct_fields: %empty  */
#line 394 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2107 "parser.c"
    break;

  case 78: /* struct_fields: struct_field  */
#line 397 "src/parser/parser.y"
                   {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2116 "parser.c"
    break;

  case 79: /* struct_fields: struct_fields TOKEN_COMMA struct_field  */
#line 401 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2125 "parser.c"
    break;

  case 80: /* struct_fields: struct_fields struct_field  */
#line 405 "src/parser/parser.y"
                                 {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2134 "parser.c"
    break;

  case 81: /* struct_field: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 412 "src/parser/parser.y"
                                      {
        (yyval.node) = create_field_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 2142 "parser.c"
    break;

  case 82: /* enum_decl: TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LBRACE enum_variants TOKEN_RBRACE  */
#line 418 "src/parser/parser.y"
                                                                        {
        (yyval.node) = create_enum_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2150 "parser.c"
    break;

  case 83: /* enum_variants: %empty  */
#line 424 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2158 "parser.c"
    break;

  case 84: /* enum_variants: TOKEN_IDENTIFIER  */
#line 427 "src/parser/parser.y"
                       {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 2167 "parser.c"
    break;

  case 85: /* enum_variants: enum_variants TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 431 "src/parser/parser.y"
                                                 {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2176 "parser.c"
    break;

  case 86: /* module_decl: TOKEN_MODULE TOKEN_IDENTIFIER  */
#line 438 "src/parser/parser.y"
                                  {
        // Créer un nœud nil pour éviter l'erreur
        (yyval.node) = create_expr_statement(create_nil_node());
    }
#line 2185 "parser.c"
    break;

  case 87: /* impl_decl: TOKEN_IMPL TOKEN_IDENTIFIER TOKEN_LBRACE function_decl_list TOKEN_RBRACE  */
#line 445 "src/parser/parser.y"
                                                                             {
        (yyval.node) = create_impl_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2193 "parser.c"
    break;

  case 88: /* function_decl_list: %empty  */
#line 451 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2201 "parser.c"
    break;

  case 89: /* function_decl_list: function_decl  */
#line 454 "src/parser/parser.y"
                    {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2210 "parser.c"
    break;

  case 90: /* function_decl_list: function_decl_list function_decl  */
#line 458 "src/parser/parser.y"
                                       {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2219 "parser.c"
    break;

  case 91: /* return_statement: TOKEN_RETURN expression  */
#line 465 "src/parser/parser.y"
                            {
        (yyval.node) = create_return_node((yyvsp[0].node));
    }
#line 2227 "parser.c"
    break;

  case 92: /* return_statement: TOKEN_RETURN  */
#line 468 "src/parser/parser.y"
                   {
        (yyval.node) = create_return_node(NULL);
    }
#line 2235 "parser.c"
    break;

  case 96: /* binary_expr: expression TOKEN_PLUS expression  */
#line 480 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_ADD, (yyvsp[0].node));
    }
#line 2243 "parser.c"
    break;

  case 97: /* binary_expr: expression TOKEN_MINUS expression  */
#line 483 "src/parser/parser.y"
                                        {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_SUB, (yyvsp[0].node));
    }
#line 2251 "parser.c"
    break;

  case 98: /* binary_expr: expression TOKEN_MULTIPLY expression  */
#line 486 "src/parser/parser.y"
                                           {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MUL, (yyvsp[0].node));
    }
#line 2259 "parser.c"
    break;

  case 99: /* binary_expr: expression TOKEN_DIVIDE expression  */
#line 489 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_DIV, (yyvsp[0].node));
    }
#line 2267 "parser.c"
    break;

  case 100: /* binary_expr: expression TOKEN_MODULO expression  */
#line 492 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MOD, (yyvsp[0].node));
    }
#line 2275 "parser.c"
    break;

  case 101: /* binary_expr: expression TOKEN_EQ expression  */
#line 495 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_EQ, (yyvsp[0].node));
    }
#line 2283 "parser.c"
    break;

  case 102: /* binary_expr: expression TOKEN_NEQ expression  */
#line 498 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_NEQ, (yyvsp[0].node));
    }
#line 2291 "parser.c"
    break;

  case 103: /* binary_expr: expression TOKEN_LT expression  */
#line 501 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LT, (yyvsp[0].node));
    }
#line 2299 "parser.c"
    break;

  case 104: /* binary_expr: expression TOKEN_LTE expression  */
#line 504 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LTE, (yyvsp[0].node));
    }
#line 2307 "parser.c"
    break;

  case 105: /* binary_expr: expression TOKEN_GT expression  */
#line 507 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GT, (yyvsp[0].node));
    }
#line 2315 "parser.c"
    break;

  case 106: /* binary_expr: expression TOKEN_GTE expression  */
#line 510 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GTE, (yyvsp[0].node));
    }
#line 2323 "parser.c"
    break;

  case 107: /* binary_expr: expression TOKEN_AND expression  */
#line 513 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_AND, (yyvsp[0].node));
    }
#line 2331 "parser.c"
    break;

  case 108: /* binary_expr: expression TOKEN_OR expression  */
#line 516 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_OR, (yyvsp[0].node));
    }
#line 2339 "parser.c"
    break;

  case 109: /* binary_expr: expression TOKEN_ASSIGN expression  */
#line 519 "src/parser/parser.y"
                                         {
        (yyval.node) = create_assign_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2347 "parser.c"
    break;

  case 110: /* binary_expr: expression TOKEN_PLUS_ASSIGN expression  */
#line 522 "src/parser/parser.y"
                                              {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_ADD_ASSIGN, (yyvsp[0].node));
    }
#line 2355 "parser.c"
    break;

  case 111: /* binary_expr: expression TOKEN_MINUS_ASSIGN expression  */
#line 525 "src/parser/parser.y"
                                               {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_SUB_ASSIGN, (yyvsp[0].node));
    }
#line 2363 "parser.c"
    break;

  case 112: /* binary_expr: expression TOKEN_MULTIPLY_ASSIGN expression  */
#line 528 "src/parser/parser.y"
                                                  {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MUL_ASSIGN, (yyvsp[0].node));
    }
#line 2371 "parser.c"
    break;

  case 113: /* binary_expr: expression TOKEN_DIVIDE_ASSIGN expression  */
#line 531 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_DIV_ASSIGN, (yyvsp[0].node));
    }
#line 2379 "parser.c"
    break;

  case 114: /* binary_expr: expression TOKEN_MODULO_ASSIGN expression  */
#line 534 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MOD_ASSIGN, (yyvsp[0].node));
    }
#line 2387 "parser.c"
    break;

  case 115: /* unary_expr: TOKEN_NOT expression  */
#line 540 "src/parser/parser.y"
                         {
        (yyval.node) = create_unary_op(OP_NOT, (yyvsp[0].node));
    }
#line 2395 "parser.c"
    break;

  case 116: /* unary_expr: TOKEN_MINUS expression  */
#line 543 "src/parser/parser.y"
                             {
        (yyval.node) = create_unary_op(OP_NEG, (yyvsp[0].node));
    }
#line 2403 "parser.c"
    break;

  case 117: /* primary_expr: TOKEN_NUMBER  */
#line 549 "src/parser/parser.y"
                 {
        (yyval.node) = create_number_node((yyvsp[0].number));
    }
#line 2411 "parser.c"
    break;

  case 118: /* primary_expr: TOKEN_FLOAT  */
#line 552 "src/parser/parser.y"
                  {
        (yyval.node) = create_float_node((yyvsp[0].float_val));
    }
#line 2419 "parser.c"
    break;

  case 119: /* primary_expr: TOKEN_STRING  */
#line 555 "src/parser/parser.y"
                   {
        (yyval.node) = create_string_node((yyvsp[0].string));
    }
#line 2427 "parser.c"
    break;

  case 120: /* primary_expr: TOKEN_TRUE  */
#line 558 "src/parser/parser.y"
                 {
        (yyval.node) = create_bool_node(1);
    }
#line 2435 "parser.c"
    break;

  case 121: /* primary_expr: TOKEN_FALSE  */
#line 561 "src/parser/parser.y"
                  {
        (yyval.node) = create_bool_node(0);
    }
#line 2443 "parser.c"
    break;

  case 122: /* primary_expr: TOKEN_NIL  */
#line 564 "src/parser/parser.y"
                {
        (yyval.node) = create_nil_node();
    }
#line 2451 "parser.c"
    break;

  case 123: /* primary_expr: TOKEN_IDENTIFIER  */
#line 567 "src/parser/parser.y"
                       {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 2459 "parser.c"
    break;

  case 124: /* primary_expr: TOKEN_LPAREN expression TOKEN_RPAREN  */
#line 570 "src/parser/parser.y"
                                           {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2467 "parser.c"
    break;

  case 129: /* member_access: primary_expr TOKEN_DOT TOKEN_IDENTIFIER  */
#line 580 "src/parser/parser.y"
                                            {
        (yyval.node) = create_member_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2475 "parser.c"
    break;

  case 130: /* member_access: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER  */
#line 583 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_static_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2483 "parser.c"
    break;

  case 131: /* call_expr: primary_expr TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 589 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_call_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2491 "parser.c"
    break;

  case 132: /* call_expr: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 592 "src/parser/parser.y"
                                                                                               {
        (yyval.node) = create_method_call_node((yyvsp[-5].node), (yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2499 "parser.c"
    break;

  case 133: /* argument_list: %empty  */
#line 598 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2507 "parser.c"
    break;

  case 134: /* argument_list: expression  */
#line 601 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_arg_list();
        add_arg((yyval.node_list), (yyvsp[0].node));
    }
#line 2516 "parser.c"
    break;

  case 135: /* argument_list: argument_list TOKEN_COMMA expression  */
#line 605 "src/parser/parser.y"
                                           {
        add_arg((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2525 "parser.c"
    break;

  case 136: /* array_expr: TOKEN_LBRACKET array_items TOKEN_RBRACKET  */
#line 612 "src/parser/parser.y"
                                              {
        (yyval.node) = create_array_node((yyvsp[-1].node_list));
    }
#line 2533 "parser.c"
    break;

  case 137: /* array_items: %empty  */
#line 618 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2541 "parser.c"
    break;

  case 138: /* array_items: expression  */
#line 621 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2550 "parser.c"
    break;

  case 139: /* array_items: array_items TOKEN_COMMA expression  */
#line 625 "src/parser/parser.y"
                                         {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2559 "parser.c"
    break;

  case 140: /* struct_expr: TOKEN_NEW TOKEN_IDENTIFIER TOKEN_LBRACE struct_init_fields TOKEN_RBRACE  */
#line 632 "src/parser/parser.y"
                                                                            {
        (yyval.node) = create_struct_init_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2567 "parser.c"
    break;

  case 141: /* struct_init_fields: %empty  */
#line 638 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2575 "parser.c"
    break;

  case 142: /* struct_init_fields: TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 641 "src/parser/parser.y"
                                              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
    }
#line 2584 "parser.c"
    break;

  case 143: /* struct_init_fields: struct_init_fields TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 645 "src/parser/parser.y"
                                                                             {
        add_to_node_list((yyvsp[-4].node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
        (yyval.node_list) = (yyvsp[-4].node_list);
    }
#line 2593 "parser.c"
    break;


#line 2597 "parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 657 "src/parser/parser.y"


void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, msg, yytext);
}
