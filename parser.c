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
  YYSYMBOL_TOKEN_UNDERSCORE = 36,          /* TOKEN_UNDERSCORE  */
  YYSYMBOL_TOKEN_PLUS = 37,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 38,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLY = 39,            /* TOKEN_MULTIPLY  */
  YYSYMBOL_TOKEN_DIVIDE = 40,              /* TOKEN_DIVIDE  */
  YYSYMBOL_TOKEN_MODULO = 41,              /* TOKEN_MODULO  */
  YYSYMBOL_TOKEN_ASSIGN = 42,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 43,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 44,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULTIPLY_ASSIGN = 45,     /* TOKEN_MULTIPLY_ASSIGN  */
  YYSYMBOL_TOKEN_DIVIDE_ASSIGN = 46,       /* TOKEN_DIVIDE_ASSIGN  */
  YYSYMBOL_TOKEN_MODULO_ASSIGN = 47,       /* TOKEN_MODULO_ASSIGN  */
  YYSYMBOL_TOKEN_EQ = 48,                  /* TOKEN_EQ  */
  YYSYMBOL_TOKEN_NEQ = 49,                 /* TOKEN_NEQ  */
  YYSYMBOL_TOKEN_LT = 50,                  /* TOKEN_LT  */
  YYSYMBOL_TOKEN_LTE = 51,                 /* TOKEN_LTE  */
  YYSYMBOL_TOKEN_GT = 52,                  /* TOKEN_GT  */
  YYSYMBOL_TOKEN_GTE = 53,                 /* TOKEN_GTE  */
  YYSYMBOL_TOKEN_AND = 54,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 55,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 56,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_AMP = 57,                 /* TOKEN_AMP  */
  YYSYMBOL_TOKEN_PIPE = 58,                /* TOKEN_PIPE  */
  YYSYMBOL_TOKEN_XOR = 59,                 /* TOKEN_XOR  */
  YYSYMBOL_TOKEN_LSHIFT = 60,              /* TOKEN_LSHIFT  */
  YYSYMBOL_TOKEN_RSHIFT = 61,              /* TOKEN_RSHIFT  */
  YYSYMBOL_TOKEN_DOUBLE_COLON = 62,        /* TOKEN_DOUBLE_COLON  */
  YYSYMBOL_TOKEN_DOT = 63,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_SECURITY = 64,            /* TOKEN_SECURITY  */
  YYSYMBOL_TOKEN_COLON = 65,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_SEMICOLON = 66,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_COMMA = 67,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_ARROW = 68,               /* TOKEN_ARROW  */
  YYSYMBOL_TOKEN_FAT_ARROW = 69,           /* TOKEN_FAT_ARROW  */
  YYSYMBOL_TOKEN_PIPE_FORWARD = 70,        /* TOKEN_PIPE_FORWARD  */
  YYSYMBOL_TOKEN_OPTIONAL = 71,            /* TOKEN_OPTIONAL  */
  YYSYMBOL_TOKEN_COALESCE = 72,            /* TOKEN_COALESCE  */
  YYSYMBOL_TOKEN_RANGE = 73,               /* TOKEN_RANGE  */
  YYSYMBOL_TOKEN_RANGE_INC = 74,           /* TOKEN_RANGE_INC  */
  YYSYMBOL_TOKEN_MUTS = 75,                /* TOKEN_MUTS  */
  YYSYMBOL_TOKEN_LPAREN = 76,              /* TOKEN_LPAREN  */
  YYSYMBOL_TOKEN_RPAREN = 77,              /* TOKEN_RPAREN  */
  YYSYMBOL_TOKEN_LBRACE = 78,              /* TOKEN_LBRACE  */
  YYSYMBOL_TOKEN_RBRACE = 79,              /* TOKEN_RBRACE  */
  YYSYMBOL_TOKEN_LBRACKET = 80,            /* TOKEN_LBRACKET  */
  YYSYMBOL_TOKEN_RBRACKET = 81,            /* TOKEN_RBRACKET  */
  YYSYMBOL_TOKEN_IDENTIFIER = 82,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_NUMBER = 83,              /* TOKEN_NUMBER  */
  YYSYMBOL_TOKEN_FLOAT = 84,               /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_STRING = 85,              /* TOKEN_STRING  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_program = 87,                   /* program  */
  YYSYMBOL_statement_list = 88,            /* statement_list  */
  YYSYMBOL_unsafe_stmt = 89,               /* unsafe_stmt  */
  YYSYMBOL_statement = 90,                 /* statement  */
  YYSYMBOL_import_statement = 91,          /* import_statement  */
  YYSYMBOL_import_constraints = 92,        /* import_constraints  */
  YYSYMBOL_import_options = 93,            /* import_options  */
  YYSYMBOL_name_list = 94,                 /* name_list  */
  YYSYMBOL_export_statement = 95,          /* export_statement  */
  YYSYMBOL_packet_decl = 96,               /* packet_decl  */
  YYSYMBOL_function_decl = 97,             /* function_decl  */
  YYSYMBOL_param_list = 98,                /* param_list  */
  YYSYMBOL_param = 99,                     /* param  */
  YYSYMBOL_type = 100,                     /* type  */
  YYSYMBOL_return_type = 101,              /* return_type  */
  YYSYMBOL_let_decl = 102,                 /* let_decl  */
  YYSYMBOL_const_decl = 103,               /* const_decl  */
  YYSYMBOL_if_statement = 104,             /* if_statement  */
  YYSYMBOL_break_statement = 105,          /* break_statement  */
  YYSYMBOL_for_statement = 106,            /* for_statement  */
  YYSYMBOL_while_statement = 107,          /* while_statement  */
  YYSYMBOL_loop_statement = 108,           /* loop_statement  */
  YYSYMBOL_match_statement = 109,          /* match_statement  */
  YYSYMBOL_match_cases = 110,              /* match_cases  */
  YYSYMBOL_match_case = 111,               /* match_case  */
  YYSYMBOL_pattern = 112,                  /* pattern  */
  YYSYMBOL_struct_decl = 113,              /* struct_decl  */
  YYSYMBOL_struct_fields = 114,            /* struct_fields  */
  YYSYMBOL_struct_field = 115,             /* struct_field  */
  YYSYMBOL_enum_decl = 116,                /* enum_decl  */
  YYSYMBOL_enum_variants = 117,            /* enum_variants  */
  YYSYMBOL_module_decl = 118,              /* module_decl  */
  YYSYMBOL_impl_decl = 119,                /* impl_decl  */
  YYSYMBOL_function_decl_list = 120,       /* function_decl_list  */
  YYSYMBOL_return_statement = 121,         /* return_statement  */
  YYSYMBOL_expression = 122,               /* expression  */
  YYSYMBOL_binary_expr = 123,              /* binary_expr  */
  YYSYMBOL_unary_expr = 124,               /* unary_expr  */
  YYSYMBOL_primary_expr = 125,             /* primary_expr  */
  YYSYMBOL_member_access = 126,            /* member_access  */
  YYSYMBOL_call_expr = 127,                /* call_expr  */
  YYSYMBOL_argument_list = 128,            /* argument_list  */
  YYSYMBOL_array_expr = 129,               /* array_expr  */
  YYSYMBOL_array_items = 130,              /* array_items  */
  YYSYMBOL_struct_expr = 131,              /* struct_expr  */
  YYSYMBOL_struct_init_fields = 132        /* struct_init_fields  */
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
#define YYLAST   1147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   340


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
      85
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    99,   103,   109,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   140,   143,   149,   155,   159,
     165,   168,   174,   180,   183,   189,   193,   200,   206,   212,
     215,   219,   228,   231,   235,   242,   245,   251,   254,   257,
     263,   266,   269,   276,   279,   282,   288,   291,   296,   299,
     308,   311,   316,   321,   327,   333,   339,   346,   352,   356,
     363,   369,   372,   375,   378,   384,   390,   393,   397,   401,
     408,   414,   420,   423,   427,   434,   441,   447,   450,   454,
     461,   464,   470,   471,   472,   476,   479,   482,   485,   488,
     491,   494,   497,   500,   503,   506,   509,   512,   515,   518,
     521,   524,   527,   530,   536,   539,   545,   548,   551,   554,
     557,   560,   563,   566,   569,   570,   571,   572,   576,   579,
     585,   588,   594,   597,   601,   608,   614,   617,   621,   628,
     634,   637,   641
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
  "TOKEN_UNDERSCORE", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULTIPLY",
  "TOKEN_DIVIDE", "TOKEN_MODULO", "TOKEN_ASSIGN", "TOKEN_PLUS_ASSIGN",
  "TOKEN_MINUS_ASSIGN", "TOKEN_MULTIPLY_ASSIGN", "TOKEN_DIVIDE_ASSIGN",
  "TOKEN_MODULO_ASSIGN", "TOKEN_EQ", "TOKEN_NEQ", "TOKEN_LT", "TOKEN_LTE",
  "TOKEN_GT", "TOKEN_GTE", "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT",
  "TOKEN_AMP", "TOKEN_PIPE", "TOKEN_XOR", "TOKEN_LSHIFT", "TOKEN_RSHIFT",
  "TOKEN_DOUBLE_COLON", "TOKEN_DOT", "TOKEN_SECURITY", "TOKEN_COLON",
  "TOKEN_SEMICOLON", "TOKEN_COMMA", "TOKEN_ARROW", "TOKEN_FAT_ARROW",
  "TOKEN_PIPE_FORWARD", "TOKEN_OPTIONAL", "TOKEN_COALESCE", "TOKEN_RANGE",
  "TOKEN_RANGE_INC", "TOKEN_MUTS", "TOKEN_LPAREN", "TOKEN_RPAREN",
  "TOKEN_LBRACE", "TOKEN_RBRACE", "TOKEN_LBRACKET", "TOKEN_RBRACKET",
  "TOKEN_IDENTIFIER", "TOKEN_NUMBER", "TOKEN_FLOAT", "TOKEN_STRING",
  "$accept", "program", "statement_list", "unsafe_stmt", "statement",
  "import_statement", "import_constraints", "import_options", "name_list",
  "export_statement", "packet_decl", "function_decl", "param_list",
  "param", "type", "return_type", "let_decl", "const_decl", "if_statement",
  "break_statement", "for_statement", "while_statement", "loop_statement",
  "match_statement", "match_cases", "match_case", "pattern", "struct_decl",
  "struct_fields", "struct_field", "enum_decl", "enum_variants",
  "module_decl", "impl_decl", "function_decl_list", "return_statement",
  "expression", "binary_expr", "unary_expr", "primary_expr",
  "member_access", "call_expr", "argument_list", "array_expr",
  "array_items", "struct_expr", "struct_init_fields", YY_NULLPTR
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
     335,   336,   337,   338,   339,   340
};
#endif

#define YYPACT_NINF (-176)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     842,   -69,   -49,   -42,    99,    99,   111,    99,   -34,  -176,
     -45,   -33,   -30,   -14,    -5,    31,    99,  -176,  -176,  -176,
      70,    45,   -23,    48,    99,    99,    59,    99,    99,  -176,
    -176,  -176,  -176,    81,   842,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  1092,  -176,  -176,     8,  -176,  -176,
    -176,  -176,    74,   -31,    84,  1092,   891,   109,   910,   952,
     842,   -35,   -19,  -176,    78,    79,    80,    82,   971,    77,
      83,    86,    88,   842,  -176,   777,   100,   -27,   208,  1092,
      -3,  -176,  -176,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    87,    89,    99,    91,    99,    72,    99,   842,
      99,   842,   842,   277,   107,  -176,    92,   -46,   130,  -176,
     842,    94,    95,     7,   -20,   102,   138,   143,   104,   307,
      99,    72,  -176,    99,  -176,   777,   777,   100,   100,   100,
     160,   160,   160,   160,   160,   160,   553,   553,   666,   666,
     666,   666,   440,   327,   112,  -176,  1092,    -1,   124,     5,
    -176,   860,   116,   119,   150,   860,   390,  1032,   420,   503,
    -176,   117,  -176,   128,  -176,   133,   -36,   533,   146,   -37,
    -176,  -176,    50,   209,  -176,     1,  -176,  -176,  -176,  -176,
     -29,  -176,   148,    91,    99,    99,   154,    53,  -176,   860,
     173,  1092,    99,    99,  -176,    72,    91,   -17,    72,  -176,
      99,   212,    99,  -176,  -176,  -176,  -176,   141,   130,  -176,
    -176,    72,    94,  -176,  -176,   140,  -176,  -176,  -176,  -176,
    -176,    99,    42,   860,   860,    99,   142,  -176,    99,    71,
    1092,  -176,  -176,    72,     3,   -32,  -176,   860,   145,  1062,
     147,   158,  -176,  -176,  -176,  1092,   -17,  1092,   162,   860,
    -176,  -176,     8,    99,   842,   842,    99,  -176,    44,   153,
      99,  1092,   616,   646,  1013,   151,  -176,   842,  1092,  -176,
    -176,   842,  -176,   729,   759,  -176,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    91,     0,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   122,
     116,   117,   118,     0,     2,    19,     3,     6,     7,     9,
      10,    14,    16,    17,    15,    18,    20,    21,    22,    11,
      12,     8,    13,    23,    24,    92,    93,    94,   127,   124,
     125,   126,     0,     0,     0,    90,     0,   122,     0,     0,
       0,     0,    25,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,   115,   114,     0,     0,   137,
       0,     1,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,     0,     0,     0,    31,
       0,    76,    82,    87,     0,     0,     0,     0,   140,     0,
       0,     0,   123,     0,   135,    95,    96,    97,    98,    99,
     108,   109,   110,   111,   112,   113,   100,   101,   102,   103,
     104,   105,   106,   107,   129,   128,   133,     0,    45,     0,
      43,    53,     0,    47,     0,    58,     0,     0,     0,     0,
      66,     0,    30,     0,    28,     0,     0,     0,     0,     0,
      77,    83,     0,     0,    88,     0,    74,    73,    71,    72,
       0,    68,     0,    42,     0,     0,     0,     0,     5,    56,
       0,   138,   132,     0,   130,     0,     0,    50,     0,    48,
       0,    60,     0,    64,    65,    27,    29,     0,     0,    32,
      38,     0,     0,    75,    79,     0,    81,    86,    89,    67,
      69,     0,     0,    55,    59,     0,     0,   139,     0,     0,
     134,    46,    44,     0,     0,     0,    49,    54,     0,     0,
       0,    34,    80,    78,    84,    70,    50,   141,     0,    57,
     131,    51,    52,     0,     0,     0,     0,    35,     0,     0,
       0,    41,     0,     0,     0,     0,    33,     0,   142,    39,
      61,     0,    36,     0,     0,    40,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,   -61,  -176,   -15,  -176,  -176,     0,  -176,  -176,
    -176,  -128,    29,    18,  -100,   -28,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,    35,  -176,  -176,  -176,  -175,
    -176,  -176,  -176,  -176,  -176,  -176,    -4,  -176,  -176,   -18,
    -176,  -176,    27,  -176,  -176,  -176,  -176
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    33,    34,    35,    36,    37,   129,   186,   278,    38,
      39,    40,   169,   170,   174,   255,    41,    42,    43,    44,
      45,    46,    47,    48,   200,   201,   202,    49,   189,   190,
      50,   192,    51,    52,   195,    53,    54,    55,    56,    57,
      58,    59,   167,    60,    90,    61,   207
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    66,    68,    69,     1,   194,   126,   196,   127,   123,
       1,   116,    78,    62,   234,   140,   196,   183,    71,    92,
      85,    86,   139,    88,    89,    17,    18,    19,   124,   193,
     232,   228,    21,    63,   117,   193,   273,    72,   141,   184,
      64,   210,   233,   229,    70,   188,   274,   125,   253,    73,
     239,   254,    74,   197,   198,    83,   199,   263,   176,   128,
     178,   179,   197,   198,   143,   199,   213,   238,    75,   187,
     112,   113,   216,    79,    80,    81,   214,    76,   144,    27,
     237,    91,   217,    28,   114,    29,    30,    31,    32,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,    92,   216,
     166,   285,   171,    77,   175,   251,   177,   235,   256,   266,
     246,    17,    18,    19,    92,   286,   118,    82,    21,   236,
      84,   262,   247,    17,    18,    19,   209,    24,   213,   211,
      21,    87,    98,    99,   100,   101,   102,   103,   270,    24,
     115,   120,   172,   271,   173,    25,   130,   131,   132,   135,
     133,    92,   185,    92,    92,   136,   138,    25,   137,   164,
     181,   165,    92,   168,   182,    27,   188,   191,   203,    28,
     204,    29,    30,    31,    32,   205,   206,    27,   212,   215,
     219,    28,   220,    67,    30,    31,    32,   218,   227,   225,
     243,   244,    -1,    -1,    -1,    -1,    -1,    -1,   166,   250,
     226,   231,    79,   282,   283,   248,   257,   241,   259,   245,
     258,   260,   264,   275,   268,   228,   293,   280,   261,   277,
     294,   287,   242,   292,   252,   240,   272,   265,   279,   249,
       0,   267,     0,     0,   269,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,     0,     0,    92,    92,   281,
       0,     0,   284,     0,     0,     0,   288,     0,    92,    92,
       1,     2,     3,     4,     5,   142,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,     0,     0,    20,    21,    22,    23,     0,
       1,     2,     3,     4,     5,    24,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,    15,    16,     0,    17,
      18,    19,     0,    25,     0,    20,    21,    22,    23,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,    26,    27,     0,     0,   180,    28,     0,    29,
      30,    31,    32,    25,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,    26,    27,     0,     0,   208,    28,     0,    29,
      30,    31,    32,     1,     2,     3,     4,     5,     0,     6,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,     0,     0,     0,    20,    21,
      22,    23,     0,     1,     2,     3,     4,     5,    24,     6,
       7,     8,     9,     0,    10,    11,    12,    13,    14,    15,
      16,     0,    17,    18,    19,     0,    25,     0,    20,    21,
      22,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,    26,    27,     0,     0,   221,
      28,     0,    29,    30,    31,    32,    25,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,    26,    27,     0,     0,   223,
      28,     0,    29,    30,    31,    32,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,     0,    17,    18,    19,     0,     0,
       0,    20,    21,    22,    23,     0,     1,     2,     3,     4,
       5,    24,     6,     7,     8,     9,     0,    10,    11,    12,
      13,    14,    15,    16,     0,    17,    18,    19,     0,    25,
       0,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,    26,    27,
       0,     0,   224,    28,     0,    29,    30,    31,    32,    25,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,     0,   106,   107,   108,   109,     0,    26,    27,
       0,     0,   230,    28,     0,    29,    30,    31,    32,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,    16,     0,    17,    18,
      19,     0,     0,     0,    20,    21,    22,    23,     0,     1,
       2,     3,     4,     5,    24,     6,     7,     8,     9,     0,
      10,    11,    12,    13,    14,    15,    16,     0,    17,    18,
      19,     0,    25,     0,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    24,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,   289,    28,     0,    29,    30,
      31,    32,    25,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,     0,     0,     0,     0,     0,     0,
       0,    26,    27,     0,     0,   290,    28,     0,    29,    30,
      31,    32,     1,     2,     3,     4,     5,     0,     6,     7,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,     0,     0,     0,    20,    21,    22,
      23,     0,     1,     2,     3,     4,     5,    24,     6,     7,
       8,     9,     0,    10,    11,    12,    13,    14,    15,    16,
       0,    17,    18,    19,     0,    25,     0,    20,    21,    22,
      23,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,   295,    28,
       0,    29,    30,    31,    32,    25,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,     0,     0,   296,    28,
       0,    29,    30,    31,    32,     1,     2,     3,     4,     5,
       0,     6,     7,     8,     9,     0,    10,    11,    12,    13,
      14,    15,    16,     0,    17,    18,    19,     0,     0,     0,
      20,    21,    22,    23,     0,     0,     0,     0,     0,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    25,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,    26,    27,     0,
       0,     0,    28,     0,    29,    30,    31,    32,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     0,     0,     0,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   291,     0,     0,     0,     0,     0,     0,   222,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   276,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
       4,     5,     6,     7,     3,   133,    25,    36,    27,    70,
       3,    42,    16,    82,   189,    42,    36,    63,    63,    34,
      24,    25,    83,    27,    28,    22,    23,    24,    63,    28,
      67,    67,    29,    82,    65,    28,    68,    82,    65,    85,
      82,   141,    79,    79,    78,    82,    78,    82,    65,    82,
      79,    68,    82,    82,    83,    78,    85,   232,   119,    78,
     121,   122,    82,    83,    67,    85,    67,   195,    82,   130,
      62,    63,    67,     3,     4,     5,    77,    82,    81,    76,
      79,     0,    77,    80,    76,    82,    83,    84,    85,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   123,    67,
     114,    67,   116,    82,   118,   215,   120,    67,   218,    77,
      67,    22,    23,    24,   139,    81,    42,    82,    29,    79,
      82,   231,    79,    22,    23,    24,   140,    38,    67,   143,
      29,    82,    42,    43,    44,    45,    46,    47,    77,    38,
      76,    42,    80,   253,    82,    56,    78,    78,    78,    82,
      78,   176,    32,   178,   179,    82,    78,    56,    82,    82,
      63,    82,   187,    82,    82,    76,    82,    82,    76,    80,
      42,    82,    83,    84,    85,    42,    82,    76,    76,    65,
      71,    80,    42,    82,    83,    84,    85,    81,    65,    82,
     204,   205,    42,    43,    44,    45,    46,    47,   212,   213,
      82,    65,     3,   274,   275,    42,   220,    69,   222,    65,
       8,    80,    82,    78,    82,    67,   287,    65,   228,    82,
     291,    78,   203,    82,   216,   200,   254,   241,   266,   212,
      -1,   245,    -1,    -1,   248,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,   282,   283,   273,
      -1,    -1,   276,    -1,    -1,    -1,   280,    -1,   293,   294,
       3,     4,     5,     6,     7,    77,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    -1,    -1,    28,    29,    30,    31,    -1,
       3,     4,     5,     6,     7,    38,     9,    10,    11,    12,
      -1,    14,    15,    16,    17,    18,    19,    20,    -1,    22,
      23,    24,    -1,    56,    -1,    28,    29,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    79,    80,    -1,    82,
      83,    84,    85,    56,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    75,    76,    -1,    -1,    79,    80,    -1,    82,
      83,    84,    85,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    -1,    -1,    28,    29,
      30,    31,    -1,     3,     4,     5,     6,     7,    38,     9,
      10,    11,    12,    -1,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,    23,    24,    -1,    56,    -1,    28,    29,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,
      80,    -1,    82,    83,    84,    85,    56,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    75,    76,    -1,    -1,    79,
      80,    -1,    82,    83,    84,    85,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    -1,
      -1,    28,    29,    30,    31,    -1,     3,     4,     5,     6,
       7,    38,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    -1,    22,    23,    24,    -1,    56,
      -1,    28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    79,    80,    -1,    82,    83,    84,    85,    56,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    -1,    -1,    50,    51,    52,    53,    -1,    75,    76,
      -1,    -1,    79,    80,    -1,    82,    83,    84,    85,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    -1,    -1,    -1,    28,    29,    30,    31,    -1,     3,
       4,     5,     6,     7,    38,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      24,    -1,    56,    -1,    28,    29,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    79,    80,    -1,    82,    83,
      84,    85,    56,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    -1,    -1,    79,    80,    -1,    82,    83,
      84,    85,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    28,    29,    30,
      31,    -1,     3,     4,     5,     6,     7,    38,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    24,    -1,    56,    -1,    28,    29,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,
      -1,    82,    83,    84,    85,    56,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    79,    80,
      -1,    82,    83,    84,    85,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,    24,    -1,    -1,    -1,
      28,    29,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    56,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    75,    76,    -1,
      -1,    -1,    80,    -1,    82,    83,    84,    85,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    66,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      14,    15,    16,    17,    18,    19,    20,    22,    23,    24,
      28,    29,    30,    31,    38,    56,    75,    76,    80,    82,
      83,    84,    85,    87,    88,    89,    90,    91,    95,    96,
      97,   102,   103,   104,   105,   106,   107,   108,   109,   113,
     116,   118,   119,   121,   122,   123,   124,   125,   126,   127,
     129,   131,    82,    82,    82,   122,   122,    82,   122,   122,
      78,    63,    82,    82,    82,    82,    82,    82,   122,     3,
       4,     5,    82,    78,    82,   122,   122,    82,   122,   122,
     130,     0,    90,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    62,    63,    76,    76,    42,    65,    42,    78,
      42,    78,    78,    88,    63,    82,    25,    27,    78,    92,
      78,    78,    78,    78,    78,    82,    82,    82,    78,    88,
      42,    65,    77,    67,    81,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,    82,    82,   122,   128,    82,    98,
      99,   122,    80,    82,   100,   122,    88,   122,    88,    88,
      79,    63,    82,    63,    85,    32,    93,    88,    82,   114,
     115,    82,   117,    28,    97,   120,    36,    82,    83,    85,
     110,   111,   112,    76,    42,    42,    82,   132,    79,   122,
     100,   122,    76,    67,    77,    65,    67,    77,    81,    71,
      42,    79,    66,    79,    79,    82,    82,    65,    67,    79,
      79,    65,    67,    79,   115,    67,    79,    79,    97,    79,
     111,    69,    98,   122,   122,    65,    67,    79,    42,   128,
     122,   100,    99,    65,    68,   101,   100,   122,     8,   122,
      80,    93,   100,   115,    82,   122,    77,   122,    82,   122,
      77,   100,   125,    68,    78,    78,    66,    82,    94,   101,
      65,   122,    88,    88,   122,    67,    81,    78,   122,    79,
      79,    78,    82,    88,    88,    79,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    94,    94,    95,    96,    97,
      97,    97,    98,    98,    98,    99,    99,   100,   100,   100,
     101,   101,   101,   102,   102,   102,   102,   102,   103,   103,
     104,   104,   105,   106,   106,   107,   108,   109,   110,   110,
     111,   112,   112,   112,   112,   113,   114,   114,   114,   114,
     115,   116,   117,   117,   117,   118,   119,   120,   120,   120,
     121,   121,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   128,   128,   128,   129,   130,   130,   130,   131,
     132,   132,   132
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
       3,     1,     1,     1,     1,     5,     0,     1,     3,     2,
       3,     5,     0,     1,     3,     2,     5,     0,     1,     2,
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
#line 93 "src/parser/parser.y"
                   {
        program_root = create_program_node((yyvsp[0].node_list));
    }
#line 1611 "parser.c"
    break;

  case 3: /* statement_list: statement  */
#line 99 "src/parser/parser.y"
              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1620 "parser.c"
    break;

  case 4: /* statement_list: statement_list statement  */
#line 103 "src/parser/parser.y"
                               {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 1629 "parser.c"
    break;

  case 5: /* unsafe_stmt: TOKEN_UNSAFE TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 109 "src/parser/parser.y"
                                                          {
        (yyval.node) = create_unsafe_node((yyvsp[-1].node_list));
    }
#line 1637 "parser.c"
    break;

  case 24: /* statement: expression  */
#line 133 "src/parser/parser.y"
                 {
        (yyval.node) = create_expr_statement((yyvsp[0].node));
    }
#line 1645 "parser.c"
    break;

  case 25: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER  */
#line 140 "src/parser/parser.y"
                                  {
        (yyval.node) = create_import_node((yyvsp[0].string), NULL, NULL);
    }
#line 1653 "parser.c"
    break;

  case 26: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 143 "src/parser/parser.y"
                                              {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1664 "parser.c"
    break;

  case 27: /* import_statement: TOKEN_IMPORT TOKEN_DOT TOKEN_DOT TOKEN_DOT TOKEN_IDENTIFIER  */
#line 149 "src/parser/parser.y"
                                                                  {
        char* path = malloc(strlen((yyvsp[0].string)) + 4);
        sprintf(path, "../%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, NULL, NULL);
        free(path);
    }
#line 1675 "parser.c"
    break;

  case 28: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_STRING  */
#line 155 "src/parser/parser.y"
                                                            {
        (yyval.node) = create_import_node((yyvsp[0].string), (yyvsp[-2].string), NULL);
    }
#line 1683 "parser.c"
    break;

  case 29: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_FROM TOKEN_DOT TOKEN_IDENTIFIER  */
#line 159 "src/parser/parser.y"
                                                                          {
        char* path = malloc(strlen((yyvsp[0].string)) + 3);
        sprintf(path, "./%s", (yyvsp[0].string));
        (yyval.node) = create_import_node(path, (yyvsp[-3].string), NULL);
        free(path);
    }
#line 1694 "parser.c"
    break;

  case 30: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER TOKEN_AS TOKEN_IDENTIFIER  */
#line 165 "src/parser/parser.y"
                                                              {
        (yyval.node) = create_import_node((yyvsp[-2].string), (yyvsp[0].string), NULL);
    }
#line 1702 "parser.c"
    break;

  case 31: /* import_statement: TOKEN_IMPORT TOKEN_IDENTIFIER import_constraints  */
#line 168 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_import_node((yyvsp[-1].string), NULL, (yyvsp[0].node));
    }
#line 1710 "parser.c"
    break;

  case 32: /* import_constraints: TOKEN_LBRACE import_options TOKEN_RBRACE  */
#line 174 "src/parser/parser.y"
                                             {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1718 "parser.c"
    break;

  case 33: /* import_options: TOKEN_ONLY TOKEN_COLON TOKEN_LBRACKET name_list TOKEN_RBRACKET  */
#line 180 "src/parser/parser.y"
                                                                   {
        (yyval.node) = create_constraints_node("only", (yyvsp[-1].node_list));
    }
#line 1726 "parser.c"
    break;

  case 34: /* import_options: import_options TOKEN_COMMA import_options  */
#line 183 "src/parser/parser.y"
                                                {
        (yyval.node) = merge_constraints((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1734 "parser.c"
    break;

  case 35: /* name_list: TOKEN_IDENTIFIER  */
#line 189 "src/parser/parser.y"
                     {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 1743 "parser.c"
    break;

  case 36: /* name_list: name_list TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 193 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1752 "parser.c"
    break;

  case 37: /* export_statement: TOKEN_EXPORT TOKEN_IDENTIFIER  */
#line 200 "src/parser/parser.y"
                                  {
        (yyval.node) = create_export_node((yyvsp[0].string));
    }
#line 1760 "parser.c"
    break;

  case 38: /* packet_decl: TOKEN_PACKET TOKEN_IDENTIFIER TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 206 "src/parser/parser.y"
                                                                           {
        (yyval.node) = create_packet_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 1768 "parser.c"
    break;

  case 39: /* function_decl: TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 212 "src/parser/parser.y"
                                                                                                                        {
        (yyval.node) = create_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1776 "parser.c"
    break;

  case 40: /* function_decl: TOKEN_PUB TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 215 "src/parser/parser.y"
                                                                                                                                    {
        (yyval.node) = create_public_function_node((yyvsp[-7].string), (yyvsp[-5].node_list), (yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1784 "parser.c"
    break;

  case 41: /* function_decl: TOKEN_FN TOKEN_IDENTIFIER TOKEN_LPAREN param_list TOKEN_RPAREN return_type TOKEN_ARROW expression  */
#line 219 "src/parser/parser.y"
                                                                                                        {
        ASTNodeList* body = create_node_list();
        ASTNode* return_stmt = create_return_node((yyvsp[0].node));
        add_to_node_list(body, return_stmt);
        (yyval.node) = create_function_node((yyvsp[-6].string), (yyvsp[-4].node_list), (yyvsp[-2].node), body);
    }
#line 1795 "parser.c"
    break;

  case 42: /* param_list: %empty  */
#line 228 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 1803 "parser.c"
    break;

  case 43: /* param_list: param  */
#line 231 "src/parser/parser.y"
            {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 1812 "parser.c"
    break;

  case 44: /* param_list: param_list TOKEN_COMMA param  */
#line 235 "src/parser/parser.y"
                                   {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 1821 "parser.c"
    break;

  case 45: /* param: TOKEN_IDENTIFIER  */
#line 242 "src/parser/parser.y"
                     {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 1829 "parser.c"
    break;

  case 46: /* param: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 245 "src/parser/parser.y"
                                        {
        (yyval.node) = create_param_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1837 "parser.c"
    break;

  case 47: /* type: TOKEN_IDENTIFIER  */
#line 251 "src/parser/parser.y"
                     {
        (yyval.node) = create_type_node((yyvsp[0].string));
    }
#line 1845 "parser.c"
    break;

  case 48: /* type: TOKEN_IDENTIFIER TOKEN_OPTIONAL  */
#line 254 "src/parser/parser.y"
                                      {
        (yyval.node) = create_optional_type_node((yyvsp[-1].string));
    }
#line 1853 "parser.c"
    break;

  case 49: /* type: TOKEN_LBRACKET TOKEN_RBRACKET type  */
#line 257 "src/parser/parser.y"
                                         {
        (yyval.node) = create_array_type_node((yyvsp[0].node));
    }
#line 1861 "parser.c"
    break;

  case 50: /* return_type: %empty  */
#line 263 "src/parser/parser.y"
                {
        (yyval.node) = NULL;
    }
#line 1869 "parser.c"
    break;

  case 51: /* return_type: TOKEN_COLON type  */
#line 266 "src/parser/parser.y"
                       {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1877 "parser.c"
    break;

  case 52: /* return_type: TOKEN_ARROW primary_expr  */
#line 269 "src/parser/parser.y"
                               {
        // Pour les retours directs: -> expr
        (yyval.node) = create_return_direct_node((yyvsp[0].node));
    }
#line 1886 "parser.c"
    break;

  case 53: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 276 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_let_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
    }
#line 1894 "parser.c"
    break;

  case 54: /* let_decl: TOKEN_LET TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expression  */
#line 279 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_let_node((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1902 "parser.c"
    break;

  case 55: /* let_decl: TOKEN_PUB TOKEN_LET TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 282 "src/parser/parser.y"
                                                                   {
        ASTNode* node = create_let_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
        node->var_decl.is_public = 1;
        (yyval.node) = node;
    }
#line 1912 "parser.c"
    break;

  case 56: /* let_decl: TOKEN_MUTS TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 288 "src/parser/parser.y"
                                                          {
        (yyval.node) = create_muts_node((yyvsp[-2].string), NULL, (yyvsp[0].node));
    }
#line 1920 "parser.c"
    break;

  case 57: /* let_decl: TOKEN_MUTS TOKEN_IDENTIFIER TOKEN_COLON type TOKEN_ASSIGN expression  */
#line 291 "src/parser/parser.y"
                                                                           {
        (yyval.node) = create_muts_node((yyvsp[-4].string), (yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1928 "parser.c"
    break;

  case 58: /* const_decl: TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 296 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_const_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 1936 "parser.c"
    break;

  case 59: /* const_decl: TOKEN_PUB TOKEN_CONST TOKEN_IDENTIFIER TOKEN_ASSIGN expression  */
#line 299 "src/parser/parser.y"
                                                                     {
        // Créer une constante publique
        ASTNode* node = create_const_node((yyvsp[-2].string), (yyvsp[0].node));
        node->var_decl.is_public = 1;
        (yyval.node) = node;
    }
#line 1947 "parser.c"
    break;

  case 60: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 308 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_if_node((yyvsp[-3].node), (yyvsp[-1].node_list), NULL);
    }
#line 1955 "parser.c"
    break;

  case 61: /* if_statement: TOKEN_IF expression TOKEN_LBRACE statement_list TOKEN_RBRACE TOKEN_ELSE TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 311 "src/parser/parser.y"
                                                                                                                       {
        (yyval.node) = create_if_node((yyvsp[-7].node), (yyvsp[-5].node_list), (yyvsp[-1].node_list));
    }
#line 1963 "parser.c"
    break;

  case 62: /* break_statement: TOKEN_BREAK  */
#line 316 "src/parser/parser.y"
                {
        (yyval.node) = create_break_node();
    }
#line 1971 "parser.c"
    break;

  case 63: /* for_statement: TOKEN_FOR TOKEN_IDENTIFIER TOKEN_ASSIGN expression TOKEN_SEMICOLON expression TOKEN_SEMICOLON expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 321 "src/parser/parser.y"
                                                                                                                                                      {
        ASTNode* init = create_let_node((yyvsp[-9].string), NULL, (yyvsp[-7].node));
        ASTNode* cond = (yyvsp[-5].node);
        ASTNode* inc = create_expr_statement((yyvsp[-3].node));
        (yyval.node) = create_for_node(init, cond, inc, (yyvsp[-1].node_list));
    }
#line 1982 "parser.c"
    break;

  case 64: /* for_statement: TOKEN_FOR expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 327 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1990 "parser.c"
    break;

  case 65: /* while_statement: TOKEN_WHILE expression TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 333 "src/parser/parser.y"
                                                                    {
        (yyval.node) = create_while_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 1998 "parser.c"
    break;

  case 66: /* loop_statement: TOKEN_LOOP TOKEN_LBRACE statement_list TOKEN_RBRACE  */
#line 339 "src/parser/parser.y"
                                                        {
        (yyval.node) = create_loop_node((yyvsp[-1].node_list));
    }
#line 2006 "parser.c"
    break;

  case 67: /* match_statement: TOKEN_MATCH expression TOKEN_LBRACE match_cases TOKEN_RBRACE  */
#line 346 "src/parser/parser.y"
                                                                 {
        (yyval.node) = create_match_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2014 "parser.c"
    break;

  case 68: /* match_cases: match_case  */
#line 352 "src/parser/parser.y"
               {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2023 "parser.c"
    break;

  case 69: /* match_cases: match_cases match_case  */
#line 356 "src/parser/parser.y"
                             {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2032 "parser.c"
    break;

  case 70: /* match_case: pattern TOKEN_FAT_ARROW expression  */
#line 363 "src/parser/parser.y"
                                       {
        (yyval.node) = create_match_case_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2040 "parser.c"
    break;

  case 71: /* pattern: TOKEN_NUMBER  */
#line 369 "src/parser/parser.y"
                 {
        (yyval.node) = create_pattern_number((yyvsp[0].number));
    }
#line 2048 "parser.c"
    break;

  case 72: /* pattern: TOKEN_STRING  */
#line 372 "src/parser/parser.y"
                   {
        (yyval.node) = create_pattern_string((yyvsp[0].string));
    }
#line 2056 "parser.c"
    break;

  case 73: /* pattern: TOKEN_IDENTIFIER  */
#line 375 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_ident((yyvsp[0].string));
    }
#line 2064 "parser.c"
    break;

  case 74: /* pattern: TOKEN_UNDERSCORE  */
#line 378 "src/parser/parser.y"
                       {
        (yyval.node) = create_pattern_wildcard();
    }
#line 2072 "parser.c"
    break;

  case 75: /* struct_decl: TOKEN_STRUCT TOKEN_IDENTIFIER TOKEN_LBRACE struct_fields TOKEN_RBRACE  */
#line 384 "src/parser/parser.y"
                                                                          {
        (yyval.node) = create_struct_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2080 "parser.c"
    break;

  case 76: /* struct_fields: %empty  */
#line 390 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2088 "parser.c"
    break;

  case 77: /* struct_fields: struct_field  */
#line 393 "src/parser/parser.y"
                   {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2097 "parser.c"
    break;

  case 78: /* struct_fields: struct_fields TOKEN_COMMA struct_field  */
#line 397 "src/parser/parser.y"
                                             {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2106 "parser.c"
    break;

  case 79: /* struct_fields: struct_fields struct_field  */
#line 401 "src/parser/parser.y"
                                 {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2115 "parser.c"
    break;

  case 80: /* struct_field: TOKEN_IDENTIFIER TOKEN_COLON type  */
#line 408 "src/parser/parser.y"
                                      {
        (yyval.node) = create_field_node((yyvsp[-2].string), (yyvsp[0].node));
    }
#line 2123 "parser.c"
    break;

  case 81: /* enum_decl: TOKEN_ENUM TOKEN_IDENTIFIER TOKEN_LBRACE enum_variants TOKEN_RBRACE  */
#line 414 "src/parser/parser.y"
                                                                        {
        (yyval.node) = create_enum_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2131 "parser.c"
    break;

  case 82: /* enum_variants: %empty  */
#line 420 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2139 "parser.c"
    break;

  case 83: /* enum_variants: TOKEN_IDENTIFIER  */
#line 423 "src/parser/parser.y"
                       {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_identifier_node((yyvsp[0].string)));
    }
#line 2148 "parser.c"
    break;

  case 84: /* enum_variants: enum_variants TOKEN_COMMA TOKEN_IDENTIFIER  */
#line 427 "src/parser/parser.y"
                                                 {
        add_to_node_list((yyvsp[-2].node_list), create_identifier_node((yyvsp[0].string)));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2157 "parser.c"
    break;

  case 85: /* module_decl: TOKEN_MODULE TOKEN_IDENTIFIER  */
#line 434 "src/parser/parser.y"
                                  {
        // Créer un nœud nil pour éviter l'erreur
        (yyval.node) = create_expr_statement(create_nil_node());
    }
#line 2166 "parser.c"
    break;

  case 86: /* impl_decl: TOKEN_IMPL TOKEN_IDENTIFIER TOKEN_LBRACE function_decl_list TOKEN_RBRACE  */
#line 441 "src/parser/parser.y"
                                                                             {
        (yyval.node) = create_impl_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2174 "parser.c"
    break;

  case 87: /* function_decl_list: %empty  */
#line 447 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2182 "parser.c"
    break;

  case 88: /* function_decl_list: function_decl  */
#line 450 "src/parser/parser.y"
                    {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2191 "parser.c"
    break;

  case 89: /* function_decl_list: function_decl_list function_decl  */
#line 454 "src/parser/parser.y"
                                       {
        add_to_node_list((yyvsp[-1].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-1].node_list);
    }
#line 2200 "parser.c"
    break;

  case 90: /* return_statement: TOKEN_RETURN expression  */
#line 461 "src/parser/parser.y"
                            {
        (yyval.node) = create_return_node((yyvsp[0].node));
    }
#line 2208 "parser.c"
    break;

  case 91: /* return_statement: TOKEN_RETURN  */
#line 464 "src/parser/parser.y"
                   {
        (yyval.node) = create_return_node(NULL);
    }
#line 2216 "parser.c"
    break;

  case 95: /* binary_expr: expression TOKEN_PLUS expression  */
#line 476 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_ADD, (yyvsp[0].node));
    }
#line 2224 "parser.c"
    break;

  case 96: /* binary_expr: expression TOKEN_MINUS expression  */
#line 479 "src/parser/parser.y"
                                        {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_SUB, (yyvsp[0].node));
    }
#line 2232 "parser.c"
    break;

  case 97: /* binary_expr: expression TOKEN_MULTIPLY expression  */
#line 482 "src/parser/parser.y"
                                           {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MUL, (yyvsp[0].node));
    }
#line 2240 "parser.c"
    break;

  case 98: /* binary_expr: expression TOKEN_DIVIDE expression  */
#line 485 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_DIV, (yyvsp[0].node));
    }
#line 2248 "parser.c"
    break;

  case 99: /* binary_expr: expression TOKEN_MODULO expression  */
#line 488 "src/parser/parser.y"
                                         {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_MOD, (yyvsp[0].node));
    }
#line 2256 "parser.c"
    break;

  case 100: /* binary_expr: expression TOKEN_EQ expression  */
#line 491 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_EQ, (yyvsp[0].node));
    }
#line 2264 "parser.c"
    break;

  case 101: /* binary_expr: expression TOKEN_NEQ expression  */
#line 494 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_NEQ, (yyvsp[0].node));
    }
#line 2272 "parser.c"
    break;

  case 102: /* binary_expr: expression TOKEN_LT expression  */
#line 497 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LT, (yyvsp[0].node));
    }
#line 2280 "parser.c"
    break;

  case 103: /* binary_expr: expression TOKEN_LTE expression  */
#line 500 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_LTE, (yyvsp[0].node));
    }
#line 2288 "parser.c"
    break;

  case 104: /* binary_expr: expression TOKEN_GT expression  */
#line 503 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GT, (yyvsp[0].node));
    }
#line 2296 "parser.c"
    break;

  case 105: /* binary_expr: expression TOKEN_GTE expression  */
#line 506 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_GTE, (yyvsp[0].node));
    }
#line 2304 "parser.c"
    break;

  case 106: /* binary_expr: expression TOKEN_AND expression  */
#line 509 "src/parser/parser.y"
                                      {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_AND, (yyvsp[0].node));
    }
#line 2312 "parser.c"
    break;

  case 107: /* binary_expr: expression TOKEN_OR expression  */
#line 512 "src/parser/parser.y"
                                     {
        (yyval.node) = create_binary_op((yyvsp[-2].node), OP_OR, (yyvsp[0].node));
    }
#line 2320 "parser.c"
    break;

  case 108: /* binary_expr: expression TOKEN_ASSIGN expression  */
#line 515 "src/parser/parser.y"
                                         {
        (yyval.node) = create_assign_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2328 "parser.c"
    break;

  case 109: /* binary_expr: expression TOKEN_PLUS_ASSIGN expression  */
#line 518 "src/parser/parser.y"
                                              {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_ADD_ASSIGN, (yyvsp[0].node));
    }
#line 2336 "parser.c"
    break;

  case 110: /* binary_expr: expression TOKEN_MINUS_ASSIGN expression  */
#line 521 "src/parser/parser.y"
                                               {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_SUB_ASSIGN, (yyvsp[0].node));
    }
#line 2344 "parser.c"
    break;

  case 111: /* binary_expr: expression TOKEN_MULTIPLY_ASSIGN expression  */
#line 524 "src/parser/parser.y"
                                                  {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MUL_ASSIGN, (yyvsp[0].node));
    }
#line 2352 "parser.c"
    break;

  case 112: /* binary_expr: expression TOKEN_DIVIDE_ASSIGN expression  */
#line 527 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_DIV_ASSIGN, (yyvsp[0].node));
    }
#line 2360 "parser.c"
    break;

  case 113: /* binary_expr: expression TOKEN_MODULO_ASSIGN expression  */
#line 530 "src/parser/parser.y"
                                                {
        (yyval.node) = create_assign_op_node((yyvsp[-2].node), OP_MOD_ASSIGN, (yyvsp[0].node));
    }
#line 2368 "parser.c"
    break;

  case 114: /* unary_expr: TOKEN_NOT expression  */
#line 536 "src/parser/parser.y"
                         {
        (yyval.node) = create_unary_op(OP_NOT, (yyvsp[0].node));
    }
#line 2376 "parser.c"
    break;

  case 115: /* unary_expr: TOKEN_MINUS expression  */
#line 539 "src/parser/parser.y"
                             {
        (yyval.node) = create_unary_op(OP_NEG, (yyvsp[0].node));
    }
#line 2384 "parser.c"
    break;

  case 116: /* primary_expr: TOKEN_NUMBER  */
#line 545 "src/parser/parser.y"
                 {
        (yyval.node) = create_number_node((yyvsp[0].number));
    }
#line 2392 "parser.c"
    break;

  case 117: /* primary_expr: TOKEN_FLOAT  */
#line 548 "src/parser/parser.y"
                  {
        (yyval.node) = create_float_node((yyvsp[0].float_val));
    }
#line 2400 "parser.c"
    break;

  case 118: /* primary_expr: TOKEN_STRING  */
#line 551 "src/parser/parser.y"
                   {
        (yyval.node) = create_string_node((yyvsp[0].string));
    }
#line 2408 "parser.c"
    break;

  case 119: /* primary_expr: TOKEN_TRUE  */
#line 554 "src/parser/parser.y"
                 {
        (yyval.node) = create_bool_node(1);
    }
#line 2416 "parser.c"
    break;

  case 120: /* primary_expr: TOKEN_FALSE  */
#line 557 "src/parser/parser.y"
                  {
        (yyval.node) = create_bool_node(0);
    }
#line 2424 "parser.c"
    break;

  case 121: /* primary_expr: TOKEN_NIL  */
#line 560 "src/parser/parser.y"
                {
        (yyval.node) = create_nil_node();
    }
#line 2432 "parser.c"
    break;

  case 122: /* primary_expr: TOKEN_IDENTIFIER  */
#line 563 "src/parser/parser.y"
                       {
        (yyval.node) = create_identifier_node((yyvsp[0].string));
    }
#line 2440 "parser.c"
    break;

  case 123: /* primary_expr: TOKEN_LPAREN expression TOKEN_RPAREN  */
#line 566 "src/parser/parser.y"
                                           {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2448 "parser.c"
    break;

  case 128: /* member_access: primary_expr TOKEN_DOT TOKEN_IDENTIFIER  */
#line 576 "src/parser/parser.y"
                                            {
        (yyval.node) = create_member_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2456 "parser.c"
    break;

  case 129: /* member_access: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER  */
#line 579 "src/parser/parser.y"
                                                       {
        (yyval.node) = create_static_access((yyvsp[-2].node), (yyvsp[0].string));
    }
#line 2464 "parser.c"
    break;

  case 130: /* call_expr: primary_expr TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 585 "src/parser/parser.y"
                                                         {
        (yyval.node) = create_call_node((yyvsp[-3].node), (yyvsp[-1].node_list));
    }
#line 2472 "parser.c"
    break;

  case 131: /* call_expr: primary_expr TOKEN_DOUBLE_COLON TOKEN_IDENTIFIER TOKEN_LPAREN argument_list TOKEN_RPAREN  */
#line 588 "src/parser/parser.y"
                                                                                               {
        (yyval.node) = create_method_call_node((yyvsp[-5].node), (yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2480 "parser.c"
    break;

  case 132: /* argument_list: %empty  */
#line 594 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2488 "parser.c"
    break;

  case 133: /* argument_list: expression  */
#line 597 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_arg_list();
        add_arg((yyval.node_list), (yyvsp[0].node));
    }
#line 2497 "parser.c"
    break;

  case 134: /* argument_list: argument_list TOKEN_COMMA expression  */
#line 601 "src/parser/parser.y"
                                           {
        add_arg((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2506 "parser.c"
    break;

  case 135: /* array_expr: TOKEN_LBRACKET array_items TOKEN_RBRACKET  */
#line 608 "src/parser/parser.y"
                                              {
        (yyval.node) = create_array_node((yyvsp[-1].node_list));
    }
#line 2514 "parser.c"
    break;

  case 136: /* array_items: %empty  */
#line 614 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2522 "parser.c"
    break;

  case 137: /* array_items: expression  */
#line 617 "src/parser/parser.y"
                 {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), (yyvsp[0].node));
    }
#line 2531 "parser.c"
    break;

  case 138: /* array_items: array_items TOKEN_COMMA expression  */
#line 621 "src/parser/parser.y"
                                         {
        add_to_node_list((yyvsp[-2].node_list), (yyvsp[0].node));
        (yyval.node_list) = (yyvsp[-2].node_list);
    }
#line 2540 "parser.c"
    break;

  case 139: /* struct_expr: TOKEN_NEW TOKEN_IDENTIFIER TOKEN_LBRACE struct_init_fields TOKEN_RBRACE  */
#line 628 "src/parser/parser.y"
                                                                            {
        (yyval.node) = create_struct_init_node((yyvsp[-3].string), (yyvsp[-1].node_list));
    }
#line 2548 "parser.c"
    break;

  case 140: /* struct_init_fields: %empty  */
#line 634 "src/parser/parser.y"
                {
        (yyval.node_list) = NULL;
    }
#line 2556 "parser.c"
    break;

  case 141: /* struct_init_fields: TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 637 "src/parser/parser.y"
                                              {
        (yyval.node_list) = create_node_list();
        add_to_node_list((yyval.node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
    }
#line 2565 "parser.c"
    break;

  case 142: /* struct_init_fields: struct_init_fields TOKEN_COMMA TOKEN_IDENTIFIER TOKEN_COLON expression  */
#line 641 "src/parser/parser.y"
                                                                             {
        add_to_node_list((yyvsp[-4].node_list), create_field_init_node((yyvsp[-2].string), (yyvsp[0].node)));
        (yyval.node_list) = (yyvsp[-4].node_list);
    }
#line 2574 "parser.c"
    break;


#line 2578 "parser.c"

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

#line 653 "src/parser/parser.y"


void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s near '%s'\n", yylineno, msg, yytext);
}
