/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp" /* yacc.c:339  */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <fstream>
#include <map>
#include <limits>
#include <set>


using namespace std;

#include <string>

extern int yylex();
//extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);
vector<double> values;
vector<int>    postfixee;
vector<int> indice;
vector<string> nom;
map<string,double> constante ;
map<string,double>::iterator it;
double assembleur(string test);
std::string debug_file("debug");
ofstream debug(debug_file.c_str());
ofstream colorStream("color");
ofstream titleStream("title");
ofstream yaxisStream("yaxis");
ofstream errorStream("error");
ofstream xStream("x");
ofstream yStream("y");
double xinf=0;
double xsup=20;
bool yaxisDefined = false;
double ymin=-10, ymax=10;
vector<string> dessine;
int nbrline;
std::set<std::string>outputs;
std::set<std::string>::iterator output;

#line 114 "parser.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FLOAT = 258,
    COLOR = 259,
    VARIABLE = 260,
    PLUS = 261,
    MINUS = 262,
    MULTIPLY = 263,
    DIVIDE = 264,
    LEFT = 265,
    RIGHT = 266,
    EQUAL = 267,
    MINUSALONE = 268,
    NEWLINE = 269,
    QUIT = 270,
    X = 271,
    NEG_X = 272,
    Y = 273,
    MPI = 274,
    EXP = 275,
    LN = 276,
    LOG = 277,
    SIN = 278,
    COS = 279,
    TAN = 280,
    ARCTAN = 281,
    ARCSIN = 282,
    ARCOS = 283,
    SQRT = 284,
    POW = 285,
    DRAW = 286,
    BRACKETR = 287,
    BRACKETL = 288,
    COMA = 289,
    ABS = 290
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 51 "parser.ypp" /* yacc.c:355  */

	int ival;
	double fval;
	char* sval;

#line 196 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "parser.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   210

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    76,    84,    86,    97,   105,   106,   108,
     109,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   149
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FLOAT", "COLOR", "VARIABLE", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "LEFT", "RIGHT", "EQUAL", "MINUSALONE",
  "NEWLINE", "QUIT", "X", "NEG_X", "Y", "MPI", "EXP", "LN", "LOG", "SIN",
  "COS", "TAN", "ARCTAN", "ARCSIN", "ARCOS", "SQRT", "POW", "DRAW",
  "BRACKETR", "BRACKETL", "COMA", "ABS", "$accept", "calculation", "line",
  "mixed_expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

#define YYPACT_NINF -7

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-7)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,    45,    -7,    -7,     1,    72,    72,    -7,    -6,     0,
       2,    -7,    12,    14,    47,    52,    68,    73,    74,    76,
      77,    92,   108,   118,    -7,    -4,    40,   116,   144,    -2,
       9,    -7,   145,   147,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,   172,    72,    72,    72,    72,    72,
      -7,    72,   114,   137,   168,    -7,    18,    20,    97,   103,
     109,   115,   123,   129,   135,   141,   149,   155,   170,   161,
      -2,    -2,   153,   153,    -7,   165,    -7,   176,   154,   186,
     156,   189,    -7,    -7,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,   182,    -7,    72,    -7,    44,   160,    46,   162,
       5,   167,   163,   195,    51,   169,   196,    78,   188,    -7,
      -7,    -7,   171,   173,   197,    -7,   174,   175,   201,    -7,
      -7,    -7,   177,    -7,    -7,   178,    -7,    -7
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    40,    41,     0,     0,     4,     0,    39,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,    41,    16,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,     0,     0,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      13,    15,    17,    18,    14,    12,    10,     0,     0,     0,
       0,     0,    34,    35,    36,    28,    29,    30,    33,    31,
      32,    37,     0,    38,     0,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       8,    22,     0,     0,     0,    26,     0,     0,     0,     6,
      20,    19,     0,    24,    23,     0,    21,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
      -7,    -7,    -7,    -5
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      29,    30,    46,    47,    48,    49,    48,    49,    31,   108,
      50,    26,    32,    27,    33,    46,    47,    48,    49,   109,
      55,    78,    34,    80,    35,    79,    51,    81,    51,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    51,
      69,    70,    71,    72,    73,     2,    74,   102,     3,   105,
       4,   103,     5,   106,   113,     6,    52,    36,   114,     7,
       8,     9,    37,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     3,    22,    28,    38,     5,
      23,   117,     6,    39,    40,   118,    41,    42,     9,   101,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    43,    46,    47,    48,    49,    23,    82,    46,
      47,    48,    49,    44,    83,    46,    47,    48,    49,    53,
      84,    46,    47,    48,    49,    75,    85,    51,    45,    46,
      47,    48,    49,    51,    86,    46,    47,    48,    49,    51,
      87,    46,    47,    48,    49,    51,    88,    46,    47,    48,
      49,    76,    89,    51,    54,    46,    47,    48,    49,    51,
      90,    46,    47,    48,    49,    51,    91,    46,    47,    48,
      49,    51,    93,    46,    47,    48,    49,    94,    56,    51,
      57,   110,    68,    51,    77,    51,    92,    95,    96,    97,
      98,    51,    99,   100,   104,   111,   107,    51,   112,   116,
     122,   115,   119,   120,   125,   121,   123,   124,     0,   126,
     127
};

static const yytype_int8 yycheck[] =
{
       5,     6,     6,     7,     8,     9,     8,     9,    14,     4,
      14,    10,    12,    12,    12,     6,     7,     8,     9,    14,
      11,     3,    10,     3,    10,     7,    30,     7,    30,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    30,
      45,    46,    47,    48,    49,     0,    51,     3,     3,     3,
       5,     7,     7,     7,     3,    10,    16,    10,     7,    14,
      15,    16,    10,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     3,    31,     5,    10,     7,
      35,     3,    10,    10,    10,     7,    10,    10,    16,    94,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    10,     6,     7,     8,     9,    35,    11,     6,
       7,     8,     9,     5,    11,     6,     7,     8,     9,     3,
      11,     6,     7,     8,     9,    11,    11,    30,    10,     6,
       7,     8,     9,    30,    11,     6,     7,     8,     9,    30,
      11,     6,     7,     8,     9,    30,    11,     6,     7,     8,
       9,    14,    11,    30,    10,     6,     7,     8,     9,    30,
      11,     6,     7,     8,     9,    30,    11,     6,     7,     8,
       9,    30,    11,     6,     7,     8,     9,    12,    33,    30,
      33,    14,    10,    30,    16,    30,    16,    11,    34,     3,
      34,    30,     3,    11,    34,    32,    34,    30,     3,     3,
       3,    32,    14,    32,     3,    32,    32,    32,    -1,    32,
      32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,     0,     3,     5,     7,    10,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    31,    35,    38,    39,    10,    12,     5,    39,
      39,    14,    12,    12,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,     5,    10,     6,     7,     8,     9,
      14,    30,    16,     3,    10,    11,    33,    33,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    10,    39,
      39,    39,    39,    39,    39,    11,    14,    16,     3,     7,
       3,     7,    11,    11,    11,    11,    11,    11,    11,    11,
      11,    11,    16,    11,    12,    11,    34,     3,    34,     3,
      11,    39,     3,     7,    34,     3,     7,    34,     4,    14,
      14,    32,     3,     3,     7,    32,     3,     3,     7,    14,
      32,    32,     3,    32,    32,     3,    32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     6,     7,     2,     7,     2,
       4,     1,     4,     3,     3,     3,     2,     3,     3,     8,
       8,     9,     7,     8,     8,     9,     7,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 3:
#line 76 "parser.ypp" /* yacc.c:1646  */
    {
		nbrline++;
		if(indice.size()==0){
			indice.push_back(0);
		}
		indice.push_back(values.size());cout<<indice[0]<<endl;
}
#line 1385 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 86 "parser.ypp" /* yacc.c:1646  */
    {
			string a1= (yyvsp[-4].sval);
			string a2="blue";
			nom.push_back("nul");
			dessine.push_back(a1);
			colorStream <<a2 << endl;
			titleStream << a1;
			if(!yaxisDefined) {
				yaxisStream << ymin << " " << ymax;
			}
		}
#line 1401 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "parser.ypp" /* yacc.c:1646  */
    {
			string a1= (yyvsp[-5].sval); string a2=(yyvsp[-1].sval);colorStream << a2 << endl;
			nom.push_back("nul");
			dessine.push_back(a1);
			if(!yaxisDefined) {
				yaxisStream << ymin << " " << ymax;
			}
		}
#line 1414 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "parser.ypp" /* yacc.c:1646  */
    { printf("bye!\n"); exit(0); }
#line 1420 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "parser.ypp" /* yacc.c:1646  */
    {string a1=(yyvsp[-6].sval);nom.push_back(a1);cout<<"ypp: "<< nom[nbrline] <<endl<<endl;}
#line 1426 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 108 "parser.ypp" /* yacc.c:1646  */
    {nom.push_back("nul");cout<<nom[nbrline]<<endl;}
#line 1432 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "parser.ypp" /* yacc.c:1646  */
    {nom.push_back("nul");string a= (yyvsp[-3].sval);constante[a]=(yyvsp[-1].fval);}
#line 1438 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(FLOAT); values.push_back(M_PI); }
#line 1444 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 114 "parser.ypp" /* yacc.c:1646  */
    {string a=(yyvsp[-3].sval);assembleur(a);}
#line 1450 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 115 "parser.ypp" /* yacc.c:1646  */
    {cout<<nbrline<<endl; postfixee.push_back(PLUS); values.push_back(0); }
#line 1456 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 116 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(POW); values.push_back(0); }
#line 1462 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 117 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(MINUS); values.push_back(0);}
#line 1468 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 118 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(MINUSALONE); values.push_back(0);}
#line 1474 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "parser.ypp" /* yacc.c:1646  */
    {postfixee.push_back(MULTIPLY); values.push_back(0); }
#line 1480 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(DIVIDE); values.push_back(0); }
#line 1486 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "parser.ypp" /* yacc.c:1646  */
    {
			xinf=(-(yyvsp[-3].fval)); xsup=(yyvsp[-1].fval);
		}
#line 1494 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 124 "parser.ypp" /* yacc.c:1646  */
    {xinf=(yyvsp[-4].fval); xsup=(-(yyvsp[-1].fval));}
#line 1500 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 125 "parser.ypp" /* yacc.c:1646  */
    {xinf=(-(yyvsp[-4].fval)); xsup=(-(yyvsp[-1].fval));}
#line 1506 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 126 "parser.ypp" /* yacc.c:1646  */
    {xinf=(yyvsp[-3].fval); xsup=(yyvsp[-1].fval);}
#line 1512 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 127 "parser.ypp" /* yacc.c:1646  */
    { yaxisStream << -(yyvsp[-3].fval) << " " << (yyvsp[-1].fval); yaxisDefined = true;}
#line 1518 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 128 "parser.ypp" /* yacc.c:1646  */
    { yaxisStream << (yyvsp[-4].fval) << " " << -(yyvsp[-1].fval); yaxisDefined = true;}
#line 1524 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 129 "parser.ypp" /* yacc.c:1646  */
    { yaxisStream << -(yyvsp[-4].fval) << " " << -(yyvsp[-1].fval); yaxisDefined = true;}
#line 1530 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 130 "parser.ypp" /* yacc.c:1646  */
    {yaxisStream << (yyvsp[-3].fval) << " " << (yyvsp[-1].fval);yaxisDefined = true;}
#line 1536 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 131 "parser.ypp" /* yacc.c:1646  */
    { }
#line 1542 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(SIN); values.push_back(0); }
#line 1548 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(COS); values.push_back(0); }
#line 1554 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(TAN); values.push_back(0); }
#line 1560 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(ARCSIN); values.push_back(0); }
#line 1566 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(ARCOS); values.push_back(0); }
#line 1572 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(ARCTAN); values.push_back(0); }
#line 1578 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 138 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(EXP); values.push_back(0); }
#line 1584 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(LOG); values.push_back(0); }
#line 1590 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(LOG); values.push_back(0); }
#line 1596 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 141 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(SQRT); values.push_back(0); }
#line 1602 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 142 "parser.ypp" /* yacc.c:1646  */
    { postfixee.push_back(ABS); values.push_back(0); }
#line 1608 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 143 "parser.ypp" /* yacc.c:1646  */
    { cout<<nbrline<<endl; postfixee.push_back(X); values.push_back(0); }
#line 1614 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 144 "parser.ypp" /* yacc.c:1646  */
    {
			cout<<nbrline<<endl;
		postfixee.push_back(FLOAT);
		values.push_back((yyvsp[0].fval));
		}
#line 1624 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 149 "parser.ypp" /* yacc.c:1646  */
    {string a=(yyvsp[0].sval);it=constante.find(a);if(it!=constante.end()){postfixee.push_back(FLOAT);double v=it->second;values.push_back(v); }else{postfixee.push_back(FLOAT);values.push_back(0);
			errorStream << "<em style=\"color:orange;\">warning: the constant "<<a<<" is not defined(remplaced by 0)</em>" << endl;}}
#line 1631 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1635 "parser.tab.cpp" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 158 "parser.ypp" /* yacc.c:1906  */




double Evaluation(double x,int ind){

	stack <double> pile;

	double a, b;
	for (int i = indice[ind]; i < indice[ind+1]; i++) {
		switch (postfixee[i]) {
			case PLUS :
			     a = pile.top(); pile.pop();
					 b = pile.top(); pile.pop();
					 pile.push(a+b);
			break;
			case FLOAT:
			     pile.push(values[i]);
			break;
			case X :
				pile.push(x);
				break;
			case NEG_X :
				pile.push(-x);
				break;
			case MULTIPLY:
					a = pile.top(); pile.pop();
					b = pile.top(); pile.pop();
					pile.push(a*b);
			break;
			case MINUS:
					a = pile.top(); pile.pop();
					b = pile.top(); pile.pop();
					pile.push(b-a);
			break;
			case MINUSALONE:
					a = pile.top(); pile.pop();
					pile.push(-a);
			break;
			case DIVIDE:
				a = pile.top(); pile.pop();
				b = pile.top(); pile.pop();
				if(a <= 0.005 && a >= -0.005 ) {
					debug << "division by zero" << endl;
					/*errorStream << "<em style=\"color:orange;\">warning: division by zero</em>" << endl;*/
					outputs.insert(string("<em style=\"color:orange;\">warning: division by zero</em>"));
					return std::numeric_limits<double>::quiet_NaN();
				}
				pile.push(b/a);
			break;
			case SIN:
				a = pile.top(); pile.pop();
				b=sin(a);
				pile.push(b);
			break;
			case COS:
				a = pile.top(); pile.pop();
				b=cos(a);
				pile.push(b);
			break;
			case TAN:
				a = pile.top(); pile.pop();
				b=tan(a);
				pile.push(b);
			break;
			case EXP:
				a = pile.top(); pile.pop();
				b=exp(a);
				pile.push(b);
			break;
			case LN:
				a = pile.top(); pile.pop();
				if(a <= 0) {
					/*errorStream << "<em style=\"color:orange;\">warning: ln is not defined in this area</em>" << endl;*/
					outputs.insert(string("<em style=\"color:orange;\">warning: ln is not defined in this area</em>"));
					return std::numeric_limits<double>::quiet_NaN();
				}
				b=log(a);
				pile.push(b);
			break;
			case LOG:
				a = pile.top(); pile.pop();
				if(a <= 0) {
					/*errorStream << "<em style=\"color:orange;\">warning: log is not defined in this area</em>" << endl;*/
					outputs.insert(string("<em style=\"color:orange;\">warning: log is not defined in this area</em>"));
					return std::numeric_limits<double>::quiet_NaN();
				}
				b=log10(a);
				pile.push(b);
			break;
			case SQRT:
				a = pile.top(); pile.pop();
				b=sqrt(a);
				pile.push(b);
			break;
			case POW :
			     a = pile.top(); pile.pop();
					 b = pile.top(); pile.pop();
					 pile.push(pow(b, a));
			break;
			case ABS :
				a = pile.top(); pile.pop();
				b=abs(a);
				pile.push(b);
			break;
			case ARCSIN:
				a = pile.top(); pile.pop();
				b=asin(a);
				pile.push(b);
			break;
			case ARCOS:
				a = pile.top(); pile.pop();
				b=acos(a);
				pile.push(b);
			break;
			case ARCTAN:
				a = pile.top(); pile.pop();
				b=atan(a);
				pile.push(b);
			break;
		}
	}
	return pile.top();
}

double assembleur(string test){
	for(int i=0;i<nom.size();i++){
		if(test.compare(nom[i])==0){
			for(int h=indice[i];h<indice[i+1];h++){
				values.push_back(values[h]);
				postfixee.push_back(postfixee[h]);
			}
			return 0;
		}
	}
	postfixee.push_back(FLOAT);
	values.push_back(0);
	errorStream << "<em style=\"color:orange;\">warning: the function "<<test<<"(x) is not defined(remplaced by 0)</em>" << endl;

	return (-1);

}



int main() {
	yyin = stdin;
	yyparse();
	cout<<dessine.size()<<endl;

	if(dessine.size()>0){
		for(double h=0;h<dessine.size();h++){
			int print=0;
			for(double k=0;k<nom.size();k++){
				if(dessine[h].compare(nom[k])==0){
					print=1;
					cout<<"je suis dans l'evaluation"<<endl;
					for (double i = xinf; i < xsup; i+=0.05) {
						if (!isnan(Evaluation(i,k))) {
							yStream << Evaluation(i,k) << " ";
							xStream << i << " ";
						} else {
							debug << "NAN" << endl;
							xStream << i << " ";
							yStream << "nan" << " ";
						}

					}
					//xStream << endl;
					yStream << endl;
				}
			}
			if(print==0){
				ofstream colorStream("color");
				errorStream << "<em style=\"color:red;\">ERROR: "<<dessine[h]<<"(x) can't be draw, because is not defined</em>" << endl;

			}
		}
	}
	for(output=outputs.begin(); output!=outputs.end(); output++) {
		errorStream << *output << endl;
	}
	return 0;
}

void yyerror(const char* s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(1);
}
