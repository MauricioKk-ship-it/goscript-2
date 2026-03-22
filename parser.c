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
  YYSYMBOL_TOKEN_MODULE = 30,              /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_ONLY = 31,                /* TOKEN_ONLY  */
  YYSYMBOL_TOKEN_TIMEOUT = 32,             /* TOKEN_TIMEOUT  */
  YYSYMBOL_TOKEN_SANDBOX = 33,             /* TOKEN_SANDBOX  */
  YYSYMBOL_TOKEN_ALLOW_FFI = 34,           /* TOKEN_ALLOW_FFI  */
  YYSYMBOL_TOKEN_UNDERSCORE = 35,          /* TOKEN_UNDERSCORE  */
  YYSYMBOL_TOKEN_PLUS = 36,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 37,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLY = 38,            /* TOKEN_MULTIPLY  */
  YYSYMBOL_TOKEN_DIVIDE = 39,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_MODULO = 40,              /* TOKEN_MODULO  */
  YYSYMBOL_TOKEN_ASSIGN = 41,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 42,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 43,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULTIPLY_ASSIGN = 44,     /* TOKEN_MULTIPLY_ASSIGN  */
  YYSYMBOL_TOKEN_DIVIDE_ASSIGN = 45,       /* TOKEN_DIVIDE_ASSIGN  */
  YYSYMBOL_TOKEN_MODULO_ASSIGN = 46,       /* TOKEN_MODULO_ASSIGN  */
  YYSYMBOL_TOKEN_EQ = 47,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 48,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LT = 49,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_LTE = 50,                 /* TOKEN_LTE  */
  YYSYMBOL_TOKEN_GT = 51,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_GTE = 52,                 /* TOKEN_GTE  */
  YYSYMBOL_TOKEN_AND = 53,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 54,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 55,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AMP = 56,                 /* TOKEN_AMP  */
  YYSYMBOL_TOKEN_PIPE = 57,                /* TOKEN_PIPE  */
  YYSYMBOL_TOKEN_XOR = 58,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_LSHIFT = 59,              /* TOKEN_LSHIFT  */
  YYSYMBOL_TOKEN_RSHIFT = 60,              /* TOKEN_RSHIFT  */
  YYSYMBOL_TOKEN_DOUBLE_COLON = 61,        /* TOKEN_DOUBLE_COLON  */
  YYSYMBOL_TOKEN_DOT = 62,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_SECURITY = 63,            /* TOKEN_SECURITY  */
  YYSYMBOL_TOKEN_COLON = 64,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMICOLON = 65,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_COMMA = 66,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_ARROW = 67,               /* TOKEN_ARROW  */
  YYSYMBOL_TOKEN_FAT_ARROW = 68,           /* TOKEN_FAT_ARROW  */
  YYSYMBOL_TOKEN_PIPE_FORWARD = 69,        /* TOKEN_PIPE_FORWARD  */
  YYSYMBOL_TOKEN_OPTIONAL = 70,            /* TOKEN_OPTIONAL  */
  YYSYMBOL_TOKEN_COALESCE = 71,            /* TOKEN_COALESCE  */
  YYSYMBOL_TOKEN_RANGE = 72,               /* TOKEN_RANGE  */
  YYSYMBOL_TOKEN_RANGE_INC = 73,           /* TOKEN_RANGE_INC  */
  YYSYMBOL_TOKEN_LPAREN = 74,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 75,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LBRACE = 76,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 77,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_LBRACKET = 78,            /* TOKEN_LBRACKET  */
  YYSYMBOL_TOKEN_RBRACKET = 79,            /* TOKEN_RBRACKET  */
  YYSYMBOL_TOKEN_IDENTIFIER = 80,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_NUMBER = 81,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_FLOAT = 82,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_STRING = 83,              /* TOKEN_STRING  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_statement_list = 86,            /* statement_list  */
  YYSYMBOL_statement = 87,                 /* statement  */
  YYSYMBOL_import_statement = 88,          /* import_statement  */
  YYSYMBOL_import_constraints = 89,        /* import_constraints  */
  YYSYMBOL_import_options = 90,            /* import_options  */
  YYSYMBOL_name_list = 91,                 /* name_list  */
  YYSYMBOL_export_statement = 92,          /* export_statement  */
  YYSYMBOL_packet_decl = 93,               /* packet_decl  */
  YYSYMBOL_function_decl = 94,             /* function_decl  */
  YYSYMBOL_param_list = 95,                /* param_list  */
  YYSYMBOL_param = 96,                     /* param  */
  YYSYMBOL_type = 97,                      /* type  */
  YYSYMBOL_return_type = 98,               /* return_type  */
  YYSYMBOL_let_decl = 99,                  /* let_decl  */
  YYSYMBOL_const_decl = 100,               /* const_decl  */
  YYSYMBOL_if_statement = 101,             /* if_statement  */
  YYSYMBOL_break_statement = 102,          /* break_statement  */
  YYSYMBOL_for_statement = 103,            /* for_statement  */
  YYSYMBOL_while_statement = 104,          /* while_statement  */
  YYSYMBOL_loop_statement = 105,           /* loop_statement  */
  YYSYMBOL_match_statement = 106,          /* match_statement  */
  YYSYMBOL_match_cases = 107,              /* match_cases  */
  YYSYMBOL_match_case = 108,               /* match_case  */
  YYSYMBOL_pattern = 109,                  /* pattern  */
  YYSYMBOL_struct_decl = 110,              /* struct_decl  */
  YYSYMBOL_struct_fields = 111,            /* struct_fields  */
  YYSYMBOL_struct_field = 112,             /* struct_field  */
  YYSYMBOL_enum_decl = 113,                /* enum_decl  */
  YYSYMBOL_enum_variants = 114,            /* enum_variants  */
  YYSYMBOL_impl_decl = 115,                /* impl_decl  */
  YYSYMBOL_function_decl_list = 116,       /* function_decl_list  */
  YYSYMBOL_return_statement = 117,         /* return_statement  */
  YYSYMBOL_expression = 118,               /* expression  */
  YYSYMBOL_binary_expr = 119,              /* binary_expr  */
  YYSYMBOL_unary_expr = 120,               /* unary_expr  */
  YYSYMBOL_primary_expr = 121,             /* primary_expr  */
  YYSYMBOL_member_access = 122,            /* member_access  */
  YYSYMBOL_call_expr = 123,                /* call_expr  */
  YYSYMBOL_argument_list = 124,            /* argument_list  */
  YYSYMBOL_array_expr = 125,               /* array_expr  */
  YYSYMBOL_array_items = 126,              /* array_items  */
  YYSYMBOL_struct_expr = 127,              /* struct_expr  */
  YYSYMBOL_struct_init_fields = 128        /* struct_init_fields  */
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
#define YYFINAL  81
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1005

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  268

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    92,    92,    98,   102,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   132,   135,   141,   147,   151,   157,   160,   166,
     172,   175,   181,   185,   192,   198,   204,   207,   213,   216,
     220,   227,   230,   236,   239,   242,   248,   251,   257,   260,
     266,   272,   275,   280,   285,   291,   297,   303,   309,   315,
     319,   326,   332,   335,   338,   341,   347,   353,   356,   360,
     364,   371,   377,   383,   386,   390,   397,   403,   406,   410,
     417,   420,   426,   427,   428,   432,   435,   438,   441,   444,
     447,   450,   453,   456,   459,   462,   465,   468,   471,   474,
     477,   480,   483,   486,   492,   495,   501,   504,   507,   510,
     513,   516,   519,   522,   525,   526,   527,   528,   532,   535,
     541,   544,   550,   553,   557,   564,   570,   573,   577,   584,
     590,   593,   597
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
  "TOKEN_FROM", "TOKEN_PUB", "TOKEN_NEW", "TOKEN_MODULE", "TOKEN_ONLY",
  "TOKEN_TIMEOUT", "TOKEN_SANDBOX", "TOKEN_ALLOW_FFI", "TOKEN_UNDERSCORE",
  "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULTIPLY", "TOKEN_DIVIDE",
  "TOKEN_MODULO", "TOKEN_ASSIGN", "TOKEN_PLUS_ASSIGN",
  "TOKEN_MINUS_ASSIGN", "TOKEN_MULTIPLY_ASSIGN", "TOKEN_DIVIDE_ASSIGN",
  "TOKEN_MODULO_ASSIGN", "TOKEN_EQ", "TOKEN_NEQ", "TOKEN_LT", "TOKEN_LTE",
  "TOKEN_GT", "TOKEN_GTE", "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT",
  "TOKEN_AMP", "TOKEN_PIPE", "TOKEN_XOR", "TOKEN_LSHIFT", "TOKEN_RSHIFT",
  "TOKEN_DOUBLE_COLON", "TOKEN_DOT", "TOKEN_SECURITY", "TOKEN_COLON",
  "TOKEN_SEMICOLON", "TOKEN_COMMA", "TOKEN_ARROW", "TOKEN_FAT_ARROW",
  "TOKEN_PIPE_FORWARD", "TOKEN_OPTIONAL", "TOKEN_COALESCE", "TOKEN_RANGE",
  "TOKEN_RANGE_INC", "TOKEN_LPAREN", "TOKEN_RPAREN", "TOKEN_LBRACE",
  "TOKEN_RBRACE", "TOKEN_LBRACKET", "TOKEN_RBRACKET", "TOKEN_IDENTIFIER",
  "TOKEN_NUMBER", "TOKEN_FLOAT", "TOKEN_STRING", "$accept", "program",
  "statement_list", "statement", "import_statement", "import_constraints",
  "import_options", "name_list", "export_statement", "packet_decl",
  "function_decl", "param_list", "param", "type", "return_type",
  "let_decl", "const_decl", "if_statement", "break_statement",
  "for_statement", "while_statement", "loop_statement", "match_statement",
  "match_cases", "match_case", "pattern", "struct_decl", "struct_fields",
  "struct_field", "enum_decl", "enum_variants", "impl_decl",
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
     335,   336,   337,   338
};
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     688,   -66,   -11,    -8,   641,   641,   704,   641,   -14,  -162,
     -52,    30,    32,    33,    46,    47,   641,  -162,  -162,  -162,
      71,    59,   641,   641,   641,   641,  -162,  -162,  -162,  -162,
     115,   688,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,   951,
    -162,  -162,     3,  -162,  -162,  -162,  -162,    49,    35,   106,
     951,    -5,   109,   752,   771,   688,    39,   -18,  -162,    69,
      75,    86,    98,   812,    95,   100,   168,   139,   872,   951,
     -49,  -162,  -162,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   111,   112,   641,   113,   641,   -55,   641,   688,
     641,   688,   688,   149,   132,  -162,   116,   -56,   167,  -162,
     688,   119,   120,    23,   -13,   128,   123,  -162,   641,  -162,
     168,   168,   139,   139,   139,   266,   266,   266,   266,   266,
     266,    92,    92,   517,   517,   517,   517,   407,   297,   141,
    -162,   951,   -51,   153,     0,  -162,   791,   140,   150,   180,
     791,   248,   891,   277,   358,  -162,   142,  -162,   144,  -162,
     161,    41,   387,   164,    37,  -162,  -162,    43,  -162,     1,
    -162,  -162,  -162,  -162,   -24,  -162,   165,   113,   170,    45,
     951,   641,   641,  -162,   -55,   113,   171,   -55,  -162,   641,
     228,   641,  -162,  -162,  -162,  -162,   159,   167,  -162,  -162,
     -55,   119,  -162,  -162,   160,  -162,  -162,  -162,  -162,  -162,
     641,    50,   641,   162,  -162,   104,   951,  -162,  -162,   -55,
     169,  -162,   791,   185,   921,   163,   175,  -162,  -162,  -162,
     951,   171,   951,   182,  -162,  -162,   688,   688,   641,  -162,
      -6,   193,   641,   468,   497,   831,   176,  -162,   688,   951,
    -162,  -162,   688,  -162,   578,   607,  -162,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    81,     0,     0,     0,     0,    53,
       0,     0,     0,     0,     0,     0,     0,   109,   110,   111,
       0,     0,     0,     0,     0,   126,   112,   106,   107,   108,
       0,     2,     3,     5,     6,     7,     8,    12,    14,    15,
      13,    16,    17,    18,    19,     9,    10,    11,    20,    21,
      82,    83,    84,   117,   114,   115,   116,     0,     0,     0,
      80,     0,   112,     0,     0,     0,     0,    22,    34,     0,
       0,     0,     0,     0,     0,     0,   105,   104,     0,   127,
       0,     1,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,    28,
       0,    67,    73,    77,     0,     0,   130,   113,     0,   125,
      85,    86,    87,    88,    89,    98,    99,   100,   101,   102,
     103,    90,    91,    92,    93,    94,    95,    96,    97,   119,
     118,   123,     0,    41,     0,    39,    48,     0,    43,     0,
      50,     0,     0,     0,     0,    57,     0,    27,     0,    25,
       0,     0,     0,     0,     0,    68,    74,     0,    78,     0,
      65,    64,    62,    63,     0,    59,     0,    38,     0,     0,
     128,   122,     0,   120,     0,     0,    46,     0,    44,     0,
      51,     0,    55,    56,    24,    26,     0,     0,    29,    35,
       0,     0,    66,    70,     0,    72,    76,    79,    58,    60,
       0,     0,     0,     0,   129,     0,   124,    42,    40,     0,
       0,    45,    49,     0,     0,     0,    31,    71,    69,    75,
      61,    46,   131,     0,   121,    47,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,    30,     0,   132,
      36,    52,     0,    33,     0,     0,    37,    54
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,   -57,   -15,  -162,  -162,    40,  -162,  -162,  -162,
    -118,    87,    78,   -89,    34,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,    94,  -162,  -162,  -162,  -161,  -162,
    -162,  -162,  -162,  -162,    -4,  -162,  -162,  -162,  -162,  -162,
      88,  -162,  -162,  -162,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    30,    31,    32,    33,   119,   171,   250,    34,    35,
      36,   154,   155,   159,   230,    37,    38,    39,    40,    41,
      42,    43,    44,   184,   185,   186,    45,   174,   175,    46,
     177,    47,   179,    48,    49,    50,    51,    52,    53,    54,
     152,    55,    80,    56,   189
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    61,    63,    64,     1,   178,   168,   116,   113,   117,
      66,   180,    73,   213,    57,   192,    82,   128,    76,    77,
      78,    79,   180,   157,   193,   158,     1,   169,    67,    20,
     129,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     238,    20,   161,   218,   163,   164,   181,   182,   118,   183,
     256,   217,    65,   172,   102,   103,   195,   181,   182,    58,
     183,   109,    59,   257,    74,   196,   106,   104,   216,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,    82,   107,
     151,   114,   156,   211,   160,   227,   162,   207,   231,   214,
      68,   223,    69,    70,   212,    81,   195,   173,   208,   115,
     215,   237,   224,   105,   190,   241,    71,    72,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    75,
     245,    96,    97,    98,    99,   120,    82,   108,    82,    82,
     110,   121,     1,     2,     3,     4,     5,    82,     6,     7,
       8,     9,   122,    10,    11,    12,    13,    14,    15,    16,
     192,    17,    18,    19,   123,   125,   126,    20,    21,   244,
      88,    89,    90,    91,    92,    93,    22,   151,   226,   253,
     254,   149,   150,   153,   166,   232,   167,   234,   170,   173,
     176,   264,   187,   188,    23,   265,    85,    86,    87,    88,
      89,    90,    91,    92,    93,   191,   240,   194,   242,   197,
     198,   199,   204,    24,   205,   206,   165,    25,   210,    26,
      27,    28,    29,   220,   222,   229,   233,   235,    82,    82,
     239,   207,   243,   249,   255,   246,   252,   236,   259,    82,
      82,     1,     2,     3,     4,     5,   263,     6,     7,     8,
       9,   247,    10,    11,    12,    13,    14,    15,    16,   258,
      17,    18,    19,   228,   221,   251,    20,    21,   219,   225,
       1,     2,     3,     4,     5,    22,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,    23,     0,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,   200,    25,     0,    26,    27,
      28,    29,    23,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    24,     0,     0,   202,    25,     0,    26,    27,    28,
      29,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,     0,     0,     0,    20,    21,     0,     0,
       1,     2,     3,     4,     5,    22,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,    23,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,   203,    25,     0,    26,    27,
      28,    29,    23,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
       0,    24,     0,     0,   209,    25,     0,    26,    27,    28,
      29,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,     0,     0,     0,    20,    21,     0,     0,
       1,     2,     3,     4,     5,    22,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,    23,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,   260,    25,     0,    26,    27,
      28,    29,    23,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    24,     0,     0,   261,    25,     0,    26,    27,    28,
      29,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,     0,     0,     0,    20,    21,     0,     0,
       1,     2,     3,     4,     5,    22,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,    23,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,   266,    25,     0,    26,    27,
      28,    29,    23,    17,    18,    19,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,     0,    22,     0,
       0,    24,     0,     0,   267,    25,     0,    26,    27,    28,
      29,     1,     2,     3,     4,     5,    23,     6,     7,     8,
       9,     0,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    18,    19,     0,     0,    24,    20,    21,     0,    25,
       0,    26,    27,    28,    29,    22,    17,    18,    19,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,    22,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,    24,     0,     0,     0,    25,     0,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,     0,    62,    27,    28,    29,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     0,    83,   111,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     0,   112,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     0,     0,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   262,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     0,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   201,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   248,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,     3,   123,    62,    25,    65,    27,
      62,    35,    16,   174,    80,    66,    31,    66,    22,    23,
      24,    25,    35,    78,    75,    80,     3,    83,    80,    28,
      79,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
     211,    28,   109,    77,   111,   112,    80,    81,    76,    83,
      66,   179,    76,   120,    61,    62,    66,    80,    81,    80,
      83,    76,    80,    79,     3,    75,    41,    74,    77,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   113,    64,
     104,    62,   106,    66,   108,   194,   110,    66,   197,    66,
      80,    66,    80,    80,    77,     0,    66,    80,    77,    80,
      77,   210,    77,    74,   128,    75,    80,    80,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    80,
     229,    49,    50,    51,    52,    76,   161,    41,   163,   164,
      41,    76,     3,     4,     5,     6,     7,   172,     9,    10,
      11,    12,    76,    14,    15,    16,    17,    18,    19,    20,
      66,    22,    23,    24,    76,    80,    76,    28,    29,    75,
      41,    42,    43,    44,    45,    46,    37,   191,   192,   246,
     247,    80,    80,    80,    62,   199,    80,   201,    31,    80,
      80,   258,    74,    80,    55,   262,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    74,   220,    64,   222,    79,
      70,    41,    80,    74,    80,    64,    77,    78,    64,    80,
      81,    82,    83,    68,    64,    64,     8,    78,   253,   254,
      80,    66,    80,    80,   248,    76,    64,   207,   252,   264,
     265,     3,     4,     5,     6,     7,    80,     9,    10,    11,
      12,    76,    14,    15,    16,    17,    18,    19,    20,    76,
      22,    23,    24,   195,   187,   241,    28,    29,   184,   191,
       3,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    55,    -1,    28,    29,    41,    42,    43,
      44,    45,    46,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    83,    55,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    74,    -1,    -1,    77,    78,    -1,    80,    81,    82,
      83,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    -1,    -1,
       3,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    55,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    83,    55,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,    82,
      83,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    -1,    -1,
       3,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    55,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    83,    55,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,    82,
      83,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    -1,    28,    29,    -1,    -1,
       3,     4,     5,     6,     7,    37,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    55,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,
      82,    83,    55,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    74,    -1,    -1,    77,    78,    -1,    80,    81,    82,
      83,     3,     4,     5,     6,     7,    55,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,    23,    24,    -1,    -1,    74,    28,    29,    -1,    78,
      -1,    80,    81,    82,    83,    37,    22,    23,    24,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    74,    -1,    -1,    -1,    78,    -1,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    78,    -1,    80,    81,    82,    83,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    36,    76,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    76,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    75,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      14,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      28,    29,    37,    55,    74,    78,    80,    81,    82,    83,
      85,    86,    87,    88,    92,    93,    94,    99,   100,   101,
     102,   103,   104,   105,   106,   110,   113,   115,   117,   118,
     119,   120,   121,   122,   123,   125,   127,    80,    80,    80,
     118,   118,    80,   118,   118,    76,    62,    80,    80,    80,
      80,    80,    80,   118,     3,    80,   118,   118,   118,   118,
     126,     0,    87,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    61,    62,    74,    74,    41,    64,    41,    76,
      41,    76,    76,    86,    62,    80,    25,    27,    76,    89,
      76,    76,    76,    76,    76,    80,    76,    75,    66,    79,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,    80,
      80,   118,   124,    80,    95,    96,   118,    78,    80,    97,
     118,    86,   118,    86,    86,    77,    62,    80,    62,    83,
      31,    90,    86,    80,   111,   112,    80,   114,    94,   116,
      35,    80,    81,    83,   107,   108,   109,    74,    80,   128,
     118,    74,    66,    75,    64,    66,    75,    79,    70,    41,
      77,    65,    77,    77,    80,    80,    64,    66,    77,    77,
      64,    66,    77,   112,    66,    77,    77,    94,    77,   108,
      68,    95,    64,    66,    77,   124,   118,    97,    96,    64,
      98,    97,   118,     8,   118,    78,    90,    97,   112,    80,
     118,    75,   118,    80,    75,    97,    76,    76,    65,    80,
      91,    98,    64,    86,    86,   118,    66,    79,    76,   118,
      77,    77,    76,    80,    86,    86,    77,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    88,    88,    88,    88,    88,    88,    88,    89,
      90,    90,    91,    91,    92,    93,    94,    94,    95,    95,
      95,    96,    96,    97,    97,    97,    98,    98,    99,    99,
     100,   101,   101,   102,   103,   103,   104,   105,   106,   107,
     107,   108,   109,   109,   109,   109,   110,   111,   111,   111,
     111,   112,   113,   114,   114,   114,   115,   116,   116,   116,
     117,   117,   118,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   120,   120,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   124,   125,   126,   126,   126,   127,
     128,   128,   128
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     5,     4,     5,     4,     3,     3,
       5,     3,     1,     3,     2,     5,     9,    10,     0,     1,
       3,     1,     3,     1,     2,     3,     0,     2,     4,     6,
       4,     5,     9,     1,    11,     5,     5,     4,     5,     1,
       2,     3,     1,     1,     1,     1,     5,     0,     1,     3,
       2,     3,     5,     0,     1,     3,     5,     0,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     3,
       4,     6,     0,     1,     3,     3,     0,     1,     3,     5,
       0,     3,     5
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
#line 92 "src/parser/parser.y"
                   {
        program_root = create_program_node((yyvsp[0].node_list));
    }
#line 1566 "parser.c"
    break;

  case 3: /* statement_list: statement  */
#line 98 "src/parser/parser.y"
              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1575 "parser.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 102 "src/parser/parser.y"
                               {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 1584 "parser.c"
    break;

  case 21: /* statement: expression  */
#line 125 "src/parser/parser.y"
                 {
        (yyval.node) = create_expr_statement((yyvsp[0].node));
    }
#line 1592 "parser.c"
    break;

  case 22: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER  */
#line 132 "src/parser/parser.y"
                                  {
        (yyval.node) = create_import_node((yyvsp[0].string), NULL, NULL);
    }
#line 1600 "parser.c"
    break;

  case 23: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 135 "src/parser/parser.y"
                                              {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1611 "parser.c"
    break;

  case 24: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_DOT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 141 "src/parser/parser.y"
                                                                  {
        char* path = malloc(strlen((yyvsp[0].string)) + 4);
        sprintf(path, "../%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1622 "parser.c"
    break;

  case 25: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_STRING  */
#line 147 "src/parser/parser.y"
                                                            {
        (yyval.node) = create_import_node((yyvsp[0].string), (yyvsp[-2].string), NULL);
    }
#line 1630 "parser.c"
    break;

  case 26: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_DOT TOKEN_IDENTIFIER  */
#line 151 "src/parser/parser.y"
                                                                          {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, (yyvsp[-3].string), NULL);
        free(path);
    }
#line 1641 "parser.c"
    break;

  case 27: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_AS TOKEN_IDENTIFIER  */
#line 157 "src/parser/parser.y"
                                                              {
        (yyval.node) = create_import_node((yyvsp[-2].string), (yyvsp[0].string), NULL);
    }
#line 1649 "parser.c"
    break;

  case 28: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER import_constraints  */
#line 160 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_import_node((yyvsp[-1].string), NULL, (yyvsp[0].node));
    }
#line 1657 "parser.c"
    break;

  case 29: /* import_constraints: TOKEN_LBRACE import_options TOKEN_RBRACE  */
#line 166 "src/parser/parser.y"
                                             {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1665 "parser.c"
    break;

  case 30: /* import_options: TOKEN_ONLY TOKEN_COLON TOKEN_LBRACKET name_list TOKEN_RBRACKET  */
#line 172 "src/parser/parser.y"
                                                                   {
        (yyval.node) = create_constraints_node("only", (yyvsp[-1].node_list));
    }
#line 1673 "parser.c"
    break;

  case 31: /* import_options: import_options TOKEN_COMMA import_options  */
#line 175 "src/parser/parser.y"
                                                {
        (yyval.node) = merge_constraints((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1681 "parser.c"
    break;

  case 32: /* name_list: TOKEN_IDENTIFIER  */
#line 181 "src/parser/parser.y"
                     {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 1690 "parser.c"
    break;

  case 33: /* name_list: name_list TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 185 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1699 "parser.c"
    break;

  case 34: /* export_statement: TOKEN_EXPORT TOKEN_IDENTIFIER  */
#line 192 "src/parser/parser.y"
                                  {
        (yyval.node) = create_export_node((yyvsp[0].string));
    }
#line 1707 "parser.c"
    break;

  case 35: /* packet_decl: TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 198 "src/parser/parser.y"
                                                                           {
        (yyval.node) = create_packet_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 1715 "parser.c"
    break;

  case 36: /* function_decl: TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 204 "src/parser/parser.y"
                                                                                                                        {
        (yyval.node) = create_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1723 "parser.c"
    break;

  case 37: /* function_decl: TOKEN_PUB TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 207 "src/parser/parser.y"
                                                                                                                                    {
        (yyval.node) = create_public_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1731 "parser.c"
    break;

  case 38: /* param_list: %empty  */
#line 213 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 1739 "parser.c"
    break;

  case 39: /* param_list: param  */
#line 216 "src/parser/parser.y"
            {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1748 "parser.c"
    break;

  case 40: /* param_list: param_list TOKEN_COMMA param  */
#line 220 "src/parser/parser.y"
                                   {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1757 "parser.c"
    break;

  case 41: /* param: TOKEN_IDENTIFIER  */
#line 227 "src/parser/parser.y"
                     {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 1765 "parser.c"
    break;

  case 42: /* param: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 230 "src/parser/parser.y"
                                        {
        (yyval.node) = create_param_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1773 "parser.c"
    break;

  case 43: /* type: TOKEN_IDENTIFIER  */
#line 236 "src/parser/parser.y"
                     {
        (yyval.node) = create_type_node((yyvsp[0].string));
    }
#line 1781 "parser.c"
    break;

  case 44: /* type: TOKEN_IDENTIFIER TOKEN_OPTIONAL  */
#line 239 "src/parser/parser.y"
                                      {
        (yyval.node) = create_optional_type_node((yyvsp[-1].string));
    }
#line 1789 "parser.c"
    break;

  case 45: /* type: TOKEN_LBRACKET TOKEN_RBRACKET type  */
#line 242 "src/parser/parser.y"
                                         {
        (yyval.node) = create_array_type_node((yyvsp[0].node));
    }
#line 1797 "parser.c"
    break;

  case 46: /* return_type: %empty  */
#line 248 "src/parser/parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1805 "parser.c"
    break;

  case 47: /* return_type: TOKEN_COLON type  */
#line 251 "src/parser/parser.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1813 "parser.c"
    break;

  case 48: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 257 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_let_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
    }
#line 1821 "parser.c"
    break;

  case 49: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expression  */
#line 260 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_let_node((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1829 "parser.c"
    break;

  case 50: /* const_decl: TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 266 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_const_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1837 "parser.c"
    break;

  case 51: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 272 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_if_node((yyvsp[-3].node), (yyvsp[-1].node_list), NULL);
    }
#line 1845 "parser.c"
    break;

  case 52: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 275 "src/parser/parser.y"
                                                                                                                       {
        (yyval.node) = create_if_node((yyvsp[-7].node), (yyvsp[-5].node_list), (yyvsp[-1].node_list));
    }
#line 1853 "parser.c"
    break;

  case 53: /* break_statement: TOKEN_BREAK  */
#line 280 "src/parser/parser.y"
                {
        (yyval.node) = create_break_node();
    }
#line 1861 "parser.c"
    break;

  case 54: /* for_statement: TOKEN_FOR TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON expression TOKEN_SEMICOLON expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 285 "src/parser/parser.y"
                                                                                                                                                      {
        ASTNode* init = create_let_node((yyvsp[-9].string), NULL, (yyvsp[-7].node));
        ASTNode* cond = (yyvsp[-5].node);
        ASTNode* inc = create_expr_statement((yyvsp[-3].node));
        (yyval.node) = create_for_node(init, cond, inc, (yyvsp[-1].node_list));
    }
#line 1872 "parser.c"
    break;

  case 55: /* for_statement: TOKEN_FOR expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 291 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1880 "parser.c"
    break;

  case 56: /* while_statement: TOKEN_WHILE expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 297 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1888 "parser.c"
    break;

  case 57: /* loop_statement: TOKEN_LOOP TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 303 "src/parser/parser.y"
                                                        {
        (yyval.node) = create_loop_node((yyvsp[-1].node_list));
    }
#line 1896 "parser.c"
    break;

  case 58: /* match_statement: TOKEN_MATCH expression TOKEN_LBRACE match_cases TOKEN_RBRACE  */
#line 309 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_match_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1904 "parser.c"
    break;

  case 59: /* match_cases: match_case  */
#line 315 "src/parser/parser.y"
               {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1913 "parser.c"
    break;

  case 60: /* match_cases: match_cases match_case  */
#line 319 "src/parser/parser.y"
                             {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 1922 "parser.c"
    break;

  case 61: /* match_case: pattern TOKEN_FAT_ARROW expression  */
#line 326 "src/parser/parser.y"
                                       {
        (yyval.node) = create_match_case_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1930 "parser.c"
    break;

  case 62: /* pattern: TOKEN_NUMBER  */
#line 332 "src/parser/parser.y"
                 {
        (yyval.node) = create_pattern_number((yyvsp[0].number));
    }
#line 1938 "parser.c"
    break;

  case 63: /* pattern: TOKEN_STRING  */
#line 335 "src/parser/parser.y"
                   {
        (yyval.node) = create_pattern_string((yyvsp[0].string));
    }
#line 1946 "parser.c"
    break;

  case 64: /* pattern: TOKEN_IDENTIFIER  */
#line 338 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_ident((yyvsp[0].string));
    }
#line 1954 "parser.c"
    break;

  case 65: /* pattern: TOKEN_UNDERSCORE  */
#line 341 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_wildcard();
    }
#line 1962 "parser.c"
    break;

  case 66: /* struct_decl: TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE  */
#line 347 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_struct_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 1970 "parser.c"
    break;

  case 67: /* struct_fields: %empty  */
#line 353 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 1978 "parser.c"
    break;

  case 68: /* struct_fields: struct_field  */
#line 356 "src/parser/parser.y"
                   {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1987 "parser.c"
    break;

  case 69: /* struct_fields: struct_fields TOKEN_COMMA struct_field  */
#line 360 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1996 "parser.c"
    break;

  case 70: /* struct_fields: struct_fields struct_field  */
#line 364 "src/parser/parser.y"
                                 {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2005 "parser.c"
    break;

  case 71: /* struct_field: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 371 "src/parser/parser.y"
                                      {
        (yyval.node) = create_field_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 2013 "parser.c"
    break;

  case 72: /* enum_decl: TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LBRACE enum_variants TOKEN_RBRACE  */
#line 377 "src/parser/parser.y"
                                                                        {
        (yyval.node) = create_enum_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2021 "parser.c"
    break;

  case 73: /* enum_variants: %empty  */
#line 383 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2029 "parser.c"
    break;

  case 74: /* enum_variants: TOKEN_IDENTIFIER  */
#line 386 "src/parser/parser.y"
                       {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 2038 "parser.c"
    break;

  case 75: /* enum_variants: enum_variants TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 390 "src/parser/parser.y"
                                                 {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2047 "parser.c"
    break;

  case 76: /* impl_decl: TOKEN_IMPL TOKEN_IDENTIFIER TOKEN_LBRACE function_decl_list TOKEN_RBRACE  */
#line 397 "src/parser/parser.y"
                                                                             {
        (yyval.node) = create_impl_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2055 "parser.c"
    break;

  case 77: /* function_decl_list: %empty  */
#line 403 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2063 "parser.c"
    break;

  case 78: /* function_decl_list: function_decl  */
#line 406 "src/parser/parser.y"
                    {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2072 "parser.c"
    break;

  case 79: /* function_decl_list: function_decl_list function_decl  */
#line 410 "src/parser/parser.y"
                                       {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2081 "parser.c"
    break;

  case 80: /* return_statement: TOKEN_RETURN expression  */
#line 417 "src/parser/parser.y"
                            {
        (yyval.node) = create_return_node((yyvsp[0].node));
    }
#line 2089 "parser.c"
    break;

  case 81: /* return_statement: TOKEN_RETURN  */
#line 420 "src/parser/parser.y"
                   {
        (yyval.node) = create_return_node(NULL);
    }
#line 2097 "parser.c"
    break;

  case 85: /* binary_expr: expression TOKEN_PLUS expression  */
#line 432 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_ADD, (yyvsp[0].node));
    }
#line 2105 "parser.c"
    break;

  case 86: /* binary_expr: expression TOKEN_MINUS expression  */
#line 435 "src/parser/parser.y"
                                        {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_SUB, (yyvsp[0].node));
    }
#line 2113 "parser.c"
    break;

  case 87: /* binary_expr: expression TOKEN_MULTIPLY expression  */
#line 438 "src/parser/parser.y"
                                           {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MUL, (yyvsp[0].node));
    }
#line 2121 "parser.c"
    break;

  case 88: /* binary_expr: expression TOKEN_DIVIDE expression  */
#line 441 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_DIV, (yyvsp[0].node));
    }
#line 2129 "parser.c"
    break;

  case 89: /* binary_expr: expression TOKEN_MODULO expression  */
#line 444 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MOD, (yyvsp[0].node));
    }
#line 2137 "parser.c"
    break;

  case 90: /* binary_expr: expression TOKEN_EQ expression  */
#line 447 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_EQ, (yyvsp[0].node));
    }
#line 2145 "parser.c"
    break;

  case 91: /* binary_expr: expression TOKEN_NEQ expression  */
#line 450 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_NEQ, (yyvsp[0].node));
    }
#line 2153 "parser.c"
    break;

  case 92: /* binary_expr: expression TOKEN_LT expression  */
#line 453 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LT, (yyvsp[0].node));
    }
#line 2161 "parser.c"
    break;

  case 93: /* binary_expr: expression TOKEN_LTE expression  */
#line 456 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LTE, (yyvsp[0].node));
    }
#line 2169 "parser.c"
    break;

  case 94: /* binary_expr: expression TOKEN_GT expression  */
#line 459 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GT, (yyvsp[0].node));
    }
#line 2177 "parser.c"
    break;

  case 95: /* binary_expr: expression TOKEN_GTE expression  */
#line 462 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GTE, (yyvsp[0].node));
    }
#line 2185 "parser.c"
    break;

  case 96: /* binary_expr: expression TOKEN_AND expression  */
#line 465 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_AND, (yyvsp[0].node));
    }
#line 2193 "parser.c"
    break;

  case 97: /* binary_expr: expression TOKEN_OR expression  */
#line 468 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_OR, (yyvsp[0].node));
    }
#line 2201 "parser.c"
    break;

  case 98: /* binary_expr: expression TOKEN_ASSIGN expression  */
#line 471 "src/parser/parser.y"
                                         {
        (yyval.node) = create_assign_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2209 "parser.c"
    break;

  case 99: /* binary_expr: expression TOKEN_PLUS_ASSIGN expression  */
#line 474 "src/parser/parser.y"
                                              {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_ADD_ASSIGN, (yyvsp[0].node));
    }
#line 2217 "parser.c"
    break;

  case 100: /* binary_expr: expression TOKEN_MINUS_ASSIGN expression  */
#line 477 "src/parser/parser.y"
                                               {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_SUB_ASSIGN, (yyvsp[0].node));
    }
#line 2225 "parser.c"
    break;

  case 101: /* binary_expr: expression TOKEN_MULTIPLY_ASSIGN expression  */
#line 480 "src/parser/parser.y"
                                                  {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MUL_ASSIGN, (yyvsp[0].node));
    }
#line 2233 "parser.c"
    break;

  case 102: /* binary_expr: expression TOKEN_DIVIDE_ASSIGN expression  */
#line 483 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_DIV_ASSIGN, (yyvsp[0].node));
    }
#line 2241 "parser.c"
    break;

  case 103: /* binary_expr: expression TOKEN_MODULO_ASSIGN expression  */
#line 486 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MOD_ASSIGN, (yyvsp[0].node));
    }
#line 2249 "parser.c"
    break;

  case 104: /* unary_expr: TOKEN_NOT expression  */
#line 492 "src/parser/parser.y"
                         {
        (yyval.node) = create_unary_op(OP_NOT, (yyvsp[0].node));
    }
#line 2257 "parser.c"
    break;

  case 105: /* unary_expr: TOKEN_MINUS expression  */
#line 495 "src/parser/parser.y"
                             {
        (yyval.node) = create_unary_op(OP_NEG, (yyvsp[0].node));
    }
#line 2265 "parser.c"
    break;

  case 106: /* primary_expr: TOKEN_NUMBER  */
#line 501 "src/parser/parser.y"
                 {
        (yyval.node) = create_number_node((yyvsp[0].number));
    }
#line 2273 "parser.c"
    break;

  case 107: /* primary_expr: TOKEN_FLOAT  */
#line 504 "src/parser/parser.y"
                  {
        (yyval.node) = create_float_node((yyvsp[0].float_val));
    }
#line 2281 "parser.c"
    break;

  case 108: /* primary_expr: TOKEN_STRING  */
#line 507 "src/parser/parser.y"
                   {
        (yyval.node) = create_string_node((yyvsp[0].string));
    }
#line 2289 "parser.c"
    break;

  case 109: /* primary_expr: TOKEN_TRUE  */
#line 510 "src/parser/parser.y"
                 {
        (yyval.node) = create_bool_node(1);
    }
#line 2297 "parser.c"
    break;

  case 110: /* primary_expr: TOKEN_FALSE  */
#line 513 "src/parser/parser.y"
                  {
        (yyval.node) = create_bool_node(0);
    }
#line 2305 "parser.c"
    break;

  case 111: /* primary_expr: TOKEN_NIL  */
#line 516 "src/parser/parser.y"
                {
        (yyval.node) = create_nil_node();
    }
#line 2313 "parser.c"
    break;

  case 112: /* primary_expr: TOKEN_IDENTIFIER  */
#line 519 "src/parser/parser.y"
                       {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 2321 "parser.c"
    break;

  case 113: /* primary_expr: TOKEN_LPAREN expression TOKEN_RPAREN  */
#line 522 "src/parser/parser.y"
                                           {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2329 "parser.c"
    break;

  case 118: /* member_access: primary_expr TOKEN_DOT TOKEN_IDENTIFIER  */
#line 532 "src/parser/parser.y"
                                            {
        (yyval.node) = create_member_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2337 "parser.c"
    break;

  case 119: /* member_access: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER  */
#line 535 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_static_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2345 "parser.c"
    break;

  case 120: /* call_expr: primary_expr TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 541 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_call_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2353 "parser.c"
    break;

  case 121: /* call_expr: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 544 "src/parser/parser.y"
                                                                                               {
        (yyval.node) = create_method_call_node((yyvsp[-5].node), (yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2361 "parser.c"
    break;

  case 122: /* argument_list: %empty  */
#line 550 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2369 "parser.c"
    break;

  case 123: /* argument_list: expression  */
#line 553 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_arg_list();
        add_arg((yyval.node_list), (yyvsp[0].node));
    }
#line 2378 "parser.c"
    break;

  case 124: /* argument_list: argument_list TOKEN_COMMA expression  */
#line 557 "src/parser/parser.y"
                                           {
        add_arg((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2387 "parser.c"
    break;

  case 125: /* array_expr: TOKEN_LBRACKET array_items TOKEN_RBRACKET  */
#line 564 "src/parser/parser.y"
                                              {
        (yyval.node) = create_array_node((yyvsp[-1].node_list));
    }
#line 2395 "parser.c"
    break;

  case 126: /* array_items: %empty  */
#line 570 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2403 "parser.c"
    break;

  case 127: /* array_items: expression  */
#line 573 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2412 "parser.c"
    break;

  case 128: /* array_items: array_items TOKEN_COMMA expression  */
#line 577 "src/parser/parser.y"
                                         {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2421 "parser.c"
    break;

  case 129: /* struct_expr: TOKEN_NEW TOKEN_IDENTIFIER TOKEN_LBRACE struct_init_fields TOKEN_RBRACE  */
#line 584 "src/parser/parser.y"
                                                                            {
        (yyval.node) = create_struct_init_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2429 "parser.c"
    break;

  case 130: /* struct_init_fields: %empty  */
#line 590 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2437 "parser.c"
    break;

  case 131: /* struct_init_fields: TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 593 "src/parser/parser.y"
                                              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
    }
#line 2446 "parser.c"
    break;

  case 132: /* struct_init_fields: struct_init_fields TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 597 "src/parser/parser.y"
                                                                             {
        add_to_node_list((yyvsp[-4].node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
        (yyval.node_list) = (yyvsp[-4].node_list);
    }
#line 2455 "parser.c"
    break;


#line 2459 "parser.c"

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

#line 609 "src/parser/parser.y"


void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, msg, yytext);
}
