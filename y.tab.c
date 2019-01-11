/* A Bison parser, made by GNU Bison 3.2.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Parser.y" /* yacc.c:338  */


#include <iostream>
#include <string>
#include <stdio.h>
#include "defs.h"

using namespace std;


extern "C"
{
  void yyerror(const char *s);
  int yyparse();
  extern int yylex(void);
}
std::string getdatabase();


#line 89 "y.tab.c" /* yacc.c:338  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    DATABASE = 258,
    DATABASES = 259,
    TABLE = 260,
    TABLES = 261,
    SHOW = 262,
    CREATE = 263,
    DROP = 264,
    USE = 265,
    PRIMARY = 266,
    KEY = 267,
    NOT = 268,
    NULL_ = 269,
    INSERT = 270,
    INTO = 271,
    VALUES = 272,
    DELETE = 273,
    FROM = 274,
    WHERE = 275,
    UPDATE = 276,
    SET = 277,
    SELECT = 278,
    IS = 279,
    INT = 280,
    VARCHAR = 281,
    DESC = 282,
    REFERENCES = 283,
    INDEX = 284,
    AND = 285,
    DATE = 286,
    FLOAT = 287,
    FOREIGN = 288,
    EXIT = 289,
    NOT_EQUAL = 290,
    MORE_OR_EQUAL = 291,
    LESS_OR_EQUAL = 292,
    VALUE_STRING = 293,
    VALUE_INT = 294,
    IDENTIFIER = 295
  };
#endif
/* Tokens.  */
#define DATABASE 258
#define DATABASES 259
#define TABLE 260
#define TABLES 261
#define SHOW 262
#define CREATE 263
#define DROP 264
#define USE 265
#define PRIMARY 266
#define KEY 267
#define NOT 268
#define NULL_ 269
#define INSERT 270
#define INTO 271
#define VALUES 272
#define DELETE 273
#define FROM 274
#define WHERE 275
#define UPDATE 276
#define SET 277
#define SELECT 278
#define IS 279
#define INT 280
#define VARCHAR 281
#define DESC 282
#define REFERENCES 283
#define INDEX 284
#define AND 285
#define DATE 286
#define FLOAT 287
#define FOREIGN 288
#define EXIT 289
#define NOT_EQUAL 290
#define MORE_OR_EQUAL 291
#define LESS_OR_EQUAL 292
#define VALUE_STRING 293
#define VALUE_INT 294
#define IDENTIFIER 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,    43,     2,    38,    44,    39,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      41,    40,    42,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    27,    27,    28,    31,    36,    41,    46,    53,    57,
      63,    67,    71,    75,    81,    85,    89,    93,    97,   101,
     105,   111,   115,   121,   126,   134,   141,   146,   155,   160,
     165,   170,   175,   179,   185,   190,   195,   200,   208,   213,
     220,   225,   230,   235,   240,   246,   254,   260,   265,   272,
     279,   284,   292,   297,   305,   309,   313,   317,   321,   325,
     331,   336,   343,   350,   359,   363,   370,   375,   384,   389,
     396,   401,   408,   414,   420
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATABASE", "DATABASES", "TABLE",
  "TABLES", "SHOW", "CREATE", "DROP", "USE", "PRIMARY", "KEY", "NOT",
  "NULL_", "INSERT", "INTO", "VALUES", "DELETE", "FROM", "WHERE", "UPDATE",
  "SET", "SELECT", "IS", "INT", "VARCHAR", "DESC", "REFERENCES", "INDEX",
  "AND", "DATE", "FLOAT", "FOREIGN", "EXIT", "';'", "'('", "')'", "','",
  "'.'", "'='", "'<'", "'>'", "'*'", "'-'", "NOT_EQUAL", "MORE_OR_EQUAL",
  "LESS_OR_EQUAL", "VALUE_STRING", "VALUE_INT", "IDENTIFIER", "$accept",
  "program", "stmt", "sysStmt", "dbStmt", "tbStmt", "idxStmt", "fieldList",
  "field", "notNullOrEmpty", "type", "valueIntOrEmpty", "valueLists",
  "valueList", "value", "VALUE_FLOAT", "VALUE_DATE", "whereClause",
  "whereClauseItem", "col", "op", "expr", "setClause", "selector", "cols",
  "tableList", "columnList", "dbName", "tbName", "colName", YY_NULLPTR
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
     285,   286,   287,   288,   289,    59,    40,    41,    44,    46,
      61,    60,    62,    42,    45,   290,   291,   292,   293,   294,
     295
};
# endif

#define YYPACT_NINF -75

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-75)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -75,    62,   -75,    50,    20,    21,   -23,    25,    38,    24,
     -21,    24,   -75,   -75,    23,    59,    60,    63,   -75,   -75,
     -23,    24,    24,   -23,    24,    24,   -75,   -75,    24,    24,
     -75,    66,   -75,    45,   -75,    78,    64,    61,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,    65,    67,   -75,   -75,    68,
      89,    87,    69,    24,    70,    69,    -2,    69,    69,    73,
      70,   -75,   -10,    71,    -6,   -75,   -75,   -75,    98,   100,
      44,   -75,     8,    76,    77,    -3,    79,   -75,    85,    19,
      70,    69,    -3,    70,    24,    80,    82,   -75,    -2,    86,
      86,   -75,   -75,   108,   -75,   -75,   -75,   -75,    34,    49,
     -75,   -75,   -75,    88,    70,    22,   -75,   -75,   -75,   -75,
     -75,   -75,     3,   -75,    83,   -75,   -75,   -75,    69,    69,
     -75,    81,   -75,   -75,   111,   -75,    84,    90,   -75,    -3,
      -3,   -75,   112,   -75,   -75,   -75,   -75,    -3,    53,   -75,
      91,    92,   -75,   -75,    93,   -75,    55,   -75,   -75,   -75,
      69,    99,   -75,    94,   -75,   -75,    24,   -75,    95,    69,
      97,   -75
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     3,     0,     0,     0,     0,     8,    13,
       0,     0,     0,     0,     0,     0,    72,    12,     0,     0,
      73,     0,    64,    74,    66,     0,    65,     0,    52,    16,
       4,     5,     6,     7,    10,     0,     0,    11,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,     0,    68,    67,    53,     0,     0,
       0,    23,     0,     0,     0,     0,    17,    18,    47,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    35,
      35,    32,    33,    29,    21,    22,    44,    41,    40,     0,
      38,    42,    43,     0,     0,     0,    54,    58,    59,    55,
      57,    56,     0,    19,     0,    62,    20,    69,     0,     0,
      24,     0,    30,    31,     0,    25,     0,     0,    37,     0,
       0,    48,     0,    50,    60,    61,    49,     0,     0,    70,
       0,     0,    28,    45,     0,    39,     0,    51,    63,    26,
       0,     0,    34,     0,    36,    71,     0,    46,     0,     0,
       0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    47,   -75,
     -75,    42,   -75,     6,   -74,   -75,   -75,   -62,   -75,    -7,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,    56,    -9,   -51
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    13,    14,    15,    16,    17,    70,    71,   125,
      93,   122,    76,    99,   100,   101,   102,    77,    78,    79,
     112,   136,    62,    35,    36,    64,   138,    27,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    63,    39,    34,    67,    72,    73,    74,   115,    68,
      80,    96,    45,    46,    83,    48,    49,    96,   113,    50,
      51,   116,    32,    20,    23,    21,    24,    26,    81,    33,
     114,    69,    84,    89,    90,   132,   133,    72,   134,    91,
      92,    28,   131,   105,    65,    97,    98,    66,    61,    22,
      25,    97,    98,    33,    18,   145,    19,    29,    40,   106,
     107,   108,     2,   148,   109,   110,   111,   139,   140,     3,
       4,     5,     6,   126,    30,   117,    44,     7,   127,    47,
       8,    87,    88,     9,   -73,    10,   128,   129,    52,    11,
     149,   150,   154,   129,    41,    42,    12,    53,    43,   155,
      55,    56,    54,    57,    58,   135,    59,    60,   160,    75,
      85,    82,    86,    94,    95,   104,   118,   103,   119,    61,
      33,   124,   121,   137,   130,   142,   147,   156,   151,   152,
     141,   159,   123,   143,   161,   120,   146,   153,     0,   144,
       0,     0,     0,   157,     0,     0,     0,   158
};

static const yytype_int16 yycheck[] =
{
       9,    52,    11,    10,    55,    56,    57,    58,    82,    11,
      20,    14,    21,    22,    20,    24,    25,    14,    80,    28,
      29,    83,    43,     3,     3,     5,     5,    50,    38,    50,
      81,    33,    38,    25,    26,    13,    14,    88,   112,    31,
      32,    16,   104,    24,    53,    48,    49,    54,    50,    29,
      29,    48,    49,    50,     4,   129,     6,    19,    35,    40,
      41,    42,     0,   137,    45,    46,    47,   118,   119,     7,
       8,     9,    10,    39,    50,    84,    20,    15,    44,    23,
      18,    37,    38,    21,    39,    23,    37,    38,    22,    27,
      37,    38,    37,    38,    35,    35,    34,    19,    35,   150,
      39,    36,    38,    36,    36,   112,    17,    20,   159,    36,
      12,    40,    12,    37,    37,    30,    36,    38,    36,    50,
      50,    13,    36,    40,    36,    14,    14,    28,    37,    37,
      49,    36,    90,    49,    37,    88,   130,    44,    -1,    49,
      -1,    -1,    -1,    49,    -1,    -1,    -1,   156
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,     0,     7,     8,     9,    10,    15,    18,    21,
      23,    27,    34,    53,    54,    55,    56,    57,     4,     6,
       3,     5,    29,     3,     5,    29,    50,    78,    16,    19,
      50,    79,    43,    50,    70,    74,    75,    79,    80,    79,
      35,    35,    35,    35,    78,    79,    79,    78,    79,    79,
      79,    79,    22,    19,    38,    39,    36,    36,    36,    17,
      20,    50,    73,    80,    76,    79,    70,    80,    11,    33,
      58,    59,    80,    80,    80,    36,    63,    68,    69,    70,
      20,    38,    40,    20,    38,    12,    12,    37,    38,    25,
      26,    31,    32,    61,    37,    37,    14,    48,    49,    64,
      65,    66,    67,    38,    30,    24,    40,    41,    42,    45,
      46,    47,    71,    68,    80,    65,    68,    79,    36,    36,
      59,    36,    62,    62,    13,    60,    39,    44,    37,    38,
      36,    68,    13,    14,    65,    70,    72,    40,    77,    80,
      80,    49,    14,    49,    49,    65,    64,    14,    65,    37,
      38,    37,    37,    44,    37,    80,    28,    49,    79,    36,
      80,    37
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    66,    67,    68,    68,    69,
      69,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    79,    80
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     2,     2,     6,     3,     2,     5,     5,     6,
       6,     6,     6,     1,     3,     3,     5,    10,     2,     0,
       2,     2,     1,     1,     3,     0,     5,     3,     1,     3,
       1,     1,     1,     1,     1,     3,     5,     1,     3,     3,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
        case 4:
#line 32 "Parser.y" /* yacc.c:1660  */
    {
        (yyvsp[-1]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
#line 1400 "y.tab.c" /* yacc.c:1660  */
    break;

  case 5:
#line 37 "Parser.y" /* yacc.c:1660  */
    {
        (yyvsp[-1]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
#line 1409 "y.tab.c" /* yacc.c:1660  */
    break;

  case 6:
#line 42 "Parser.y" /* yacc.c:1660  */
    {
        (yyvsp[-1]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
#line 1418 "y.tab.c" /* yacc.c:1660  */
    break;

  case 7:
#line 47 "Parser.y" /* yacc.c:1660  */
    {
        (yyvsp[-1]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
#line 1427 "y.tab.c" /* yacc.c:1660  */
    break;

  case 8:
#line 54 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new ShowDatabases();
      }
#line 1435 "y.tab.c" /* yacc.c:1660  */
    break;

  case 9:
#line 58 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new Exiter();
      }
#line 1443 "y.tab.c" /* yacc.c:1660  */
    break;

  case 10:
#line 64 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new CreateDatabase((yyvsp[0]).iden);
      }
#line 1451 "y.tab.c" /* yacc.c:1660  */
    break;

  case 11:
#line 68 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new DropDatabase((yyvsp[0]).iden);
      }
#line 1459 "y.tab.c" /* yacc.c:1660  */
    break;

  case 12:
#line 72 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new UseDatabase((yyvsp[0]).iden);
      }
#line 1467 "y.tab.c" /* yacc.c:1660  */
    break;

  case 13:
#line 76 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new ShowTables();
      }
#line 1475 "y.tab.c" /* yacc.c:1660  */
    break;

  case 14:
#line 82 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new CreateTable((yyvsp[-3]).iden,(yyvsp[-1]).fields);
      }
#line 1483 "y.tab.c" /* yacc.c:1660  */
    break;

  case 15:
#line 86 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new DropTable((yyvsp[0]).iden);
      }
#line 1491 "y.tab.c" /* yacc.c:1660  */
    break;

  case 16:
#line 90 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new DescTable((yyvsp[0]).iden);
      }
#line 1499 "y.tab.c" /* yacc.c:1660  */
    break;

  case 17:
#line 94 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new InsertValue((yyvsp[-2]).iden,(yyvsp[0]).values);
      }
#line 1507 "y.tab.c" /* yacc.c:1660  */
    break;

  case 18:
#line 98 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new DeleteValues((yyvsp[-2]).iden,(yyvsp[0]).wheres);
      }
#line 1515 "y.tab.c" /* yacc.c:1660  */
    break;

  case 19:
#line 102 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new UpdateValues((yyvsp[-4]).iden,(yyvsp[-2]).sets,(yyvsp[0]).wheres);
      }
#line 1523 "y.tab.c" /* yacc.c:1660  */
    break;

  case 20:
#line 106 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new SelectValues((yyvsp[-4]).selector,(yyvsp[-2]).tables,(yyvsp[0]).wheres);
      }
#line 1531 "y.tab.c" /* yacc.c:1660  */
    break;

  case 21:
#line 112 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new CreateIndex((yyvsp[-3]).iden,(yyvsp[-1]).iden);
      }
#line 1539 "y.tab.c" /* yacc.c:1660  */
    break;

  case 22:
#line 116 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).handler=new DropIndex((yyvsp[-3]).iden,(yyvsp[-1]).iden);
      }
#line 1547 "y.tab.c" /* yacc.c:1660  */
    break;

  case 23:
#line 122 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).fields.clear();
        (yyval).fields.push_back((yyvsp[0]).fielditem);
      }
#line 1556 "y.tab.c" /* yacc.c:1660  */
    break;

  case 24:
#line 127 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).fields.clear();
        (yyval).fields.swap((yyvsp[-2]).fields);
        (yyval).fields.push_back((yyvsp[0]).fielditem);
      }
#line 1566 "y.tab.c" /* yacc.c:1660  */
    break;

  case 25:
#line 135 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).fielditem.type=Field::column;
          (yyval).fielditem.Nullable=(yyvsp[0]).Nullable;
          (yyval).fielditem.thetype=(yyvsp[-1]).colType;
          (yyval).fielditem.colName=(yyvsp[-2]).iden;
        }
#line 1577 "y.tab.c" /* yacc.c:1660  */
    break;

  case 26:
#line 142 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).fielditem.type=Field::primarykey;
          (yyval).fielditem.columns.swap((yyvsp[-1]).columnlist);
        }
#line 1586 "y.tab.c" /* yacc.c:1660  */
    break;

  case 27:
#line 147 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).fielditem.type=Field::foreignkey;
          (yyval).fielditem.colName=(yyvsp[-6]).iden;
          (yyval).fielditem.reftable=(yyvsp[-3]).iden;
          (yyval).fielditem.refcolumn=(yyvsp[-1]).iden;
        }
#line 1597 "y.tab.c" /* yacc.c:1660  */
    break;

  case 28:
#line 156 "Parser.y" /* yacc.c:1660  */
    {
                    (yyval).Nullable=false;
                  }
#line 1605 "y.tab.c" /* yacc.c:1660  */
    break;

  case 29:
#line 160 "Parser.y" /* yacc.c:1660  */
    {
                    (yyval).Nullable=true;
                  }
#line 1613 "y.tab.c" /* yacc.c:1660  */
    break;

  case 30:
#line 166 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).colType.typeId=Type::_INT;
          (yyval).colType.len=(yyvsp[0]).intValue;
        }
#line 1622 "y.tab.c" /* yacc.c:1660  */
    break;

  case 31:
#line 171 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).colType.typeId=Type::_CHAR;
          (yyval).colType.len=(yyvsp[0]).intValue;
        }
#line 1631 "y.tab.c" /* yacc.c:1660  */
    break;

  case 32:
#line 176 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).colType.typeId=Type::_DATE;
        }
#line 1639 "y.tab.c" /* yacc.c:1660  */
    break;

  case 33:
#line 180 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).colType.typeId=Type::_FLOAT;
        }
#line 1647 "y.tab.c" /* yacc.c:1660  */
    break;

  case 34:
#line 186 "Parser.y" /* yacc.c:1660  */
    {
                    (yyval).intValue=(yyvsp[-1]).intValue;
                  }
#line 1655 "y.tab.c" /* yacc.c:1660  */
    break;

  case 35:
#line 190 "Parser.y" /* yacc.c:1660  */
    {
                    (yyval).intValue=0;
                  }
#line 1663 "y.tab.c" /* yacc.c:1660  */
    break;

  case 36:
#line 196 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).values.swap((yyvsp[-4]).values);
                (yyval).values.push_back((yyvsp[-1]).valuelist);
              }
#line 1672 "y.tab.c" /* yacc.c:1660  */
    break;

  case 37:
#line 201 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).values.clear();
                (yyval).values.push_back((yyvsp[-1]).valuelist);
              }
#line 1681 "y.tab.c" /* yacc.c:1660  */
    break;

  case 38:
#line 209 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).valuelist.clear();
              (yyval).valuelist.push_back((yyvsp[0]).value);
            }
#line 1690 "y.tab.c" /* yacc.c:1660  */
    break;

  case 39:
#line 214 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).valuelist.swap((yyvsp[-2]).valuelist);
              (yyval).valuelist.push_back((yyvsp[0]).value);
            }
#line 1699 "y.tab.c" /* yacc.c:1660  */
    break;

  case 40:
#line 221 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).value.type=Value::_INT;
          (yyval).value.intValue=(yyvsp[0]).intValue;
        }
#line 1708 "y.tab.c" /* yacc.c:1660  */
    break;

  case 41:
#line 226 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).value.type=Value::_STRING;
          (yyval).value.stringValue=(yyvsp[0]).stringValue;
        }
#line 1717 "y.tab.c" /* yacc.c:1660  */
    break;

  case 42:
#line 231 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).value.type=Value::_FLOAT;
          (yyval).value.floatValue=(yyvsp[0]).floatValue;
        }
#line 1726 "y.tab.c" /* yacc.c:1660  */
    break;

  case 43:
#line 236 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).value.type=Value::_DATE;
          (yyval).value.dateValue=(yyvsp[0]).dateValue;
        }
#line 1735 "y.tab.c" /* yacc.c:1660  */
    break;

  case 44:
#line 241 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).value.type=Value::_NULL;
        }
#line 1743 "y.tab.c" /* yacc.c:1660  */
    break;

  case 45:
#line 247 "Parser.y" /* yacc.c:1660  */
    {
                float fl=(yyvsp[0]).intValue;
                while(fl>=1)fl/=10.0;
                (yyval).floatValue=(yyvsp[-2]).intValue+fl;
              }
#line 1753 "y.tab.c" /* yacc.c:1660  */
    break;

  case 46:
#line 255 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).dateValue=(yyvsp[-4]).intValue*10000+(yyvsp[-2]).intValue*100+(yyvsp[0]).intValue;
            }
#line 1761 "y.tab.c" /* yacc.c:1660  */
    break;

  case 47:
#line 261 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).wheres.clear();
                (yyval).wheres.push_back((yyvsp[0]).whereitem);
              }
#line 1770 "y.tab.c" /* yacc.c:1660  */
    break;

  case 48:
#line 266 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).wheres.swap((yyvsp[0]).wheres);
                (yyval).wheres.push_back((yyvsp[-2]).whereitem);
              }
#line 1779 "y.tab.c" /* yacc.c:1660  */
    break;

  case 49:
#line 273 "Parser.y" /* yacc.c:1660  */
    {
                  (yyval).whereitem.type=WhereItem::OPERATION;
                  (yyval).whereitem.left=(yyvsp[-2]).column;
                  (yyval).whereitem.Operator=(yyvsp[-1]).Operator;
                  (yyval).whereitem.expr=(yyvsp[0]).expr;
                }
#line 1790 "y.tab.c" /* yacc.c:1660  */
    break;

  case 50:
#line 280 "Parser.y" /* yacc.c:1660  */
    {
                  (yyval).whereitem.type=WhereItem::ISNULL;
                  (yyval).whereitem.left=(yyvsp[-2]).column;
                }
#line 1799 "y.tab.c" /* yacc.c:1660  */
    break;

  case 51:
#line 285 "Parser.y" /* yacc.c:1660  */
    {
                  (yyval).whereitem.type=WhereItem::ISNOTNULL;
                  (yyval).whereitem.left=(yyvsp[-3]).column;
                }
#line 1808 "y.tab.c" /* yacc.c:1660  */
    break;

  case 52:
#line 293 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).column.hastable=false;
        (yyval).column.column=(yyvsp[0]).iden;
      }
#line 1817 "y.tab.c" /* yacc.c:1660  */
    break;

  case 53:
#line 298 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).column.hastable=true;
        (yyval).column.table=(yyvsp[-2]).iden;
        (yyval).column.column=(yyvsp[0]).iden;
      }
#line 1827 "y.tab.c" /* yacc.c:1660  */
    break;

  case 54:
#line 306 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_EQUAL;
      }
#line 1835 "y.tab.c" /* yacc.c:1660  */
    break;

  case 55:
#line 310 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_NOT_EQUAL;
      }
#line 1843 "y.tab.c" /* yacc.c:1660  */
    break;

  case 56:
#line 314 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_LESS_OR_EQUAL;
      }
#line 1851 "y.tab.c" /* yacc.c:1660  */
    break;

  case 57:
#line 318 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_MORE_OR_EQUAL;
      }
#line 1859 "y.tab.c" /* yacc.c:1660  */
    break;

  case 58:
#line 322 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_LESS;
      }
#line 1867 "y.tab.c" /* yacc.c:1660  */
    break;

  case 59:
#line 326 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).Operator=WhereItem::_MORE;
      }
#line 1875 "y.tab.c" /* yacc.c:1660  */
    break;

  case 60:
#line 332 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).expr.type=Expr::VALUE;
          (yyval).expr.value=(yyvsp[0]).value;
        }
#line 1884 "y.tab.c" /* yacc.c:1660  */
    break;

  case 61:
#line 337 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).expr.type=Expr::COL;
          (yyval).expr.column=(yyvsp[0]).column;
        }
#line 1893 "y.tab.c" /* yacc.c:1660  */
    break;

  case 62:
#line 344 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).set.column=(yyvsp[-2]).iden;
              (yyval).set.value=(yyvsp[0]).value;
              (yyval).sets.clear();
              (yyval).sets.push_back((yyval).set);
            }
#line 1904 "y.tab.c" /* yacc.c:1660  */
    break;

  case 63:
#line 351 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).set.column=(yyvsp[-2]).iden;
              (yyval).set.value=(yyvsp[0]).value;
              (yyval).sets.swap((yyvsp[-4]).sets);
              (yyval).sets.push_back((yyval).set);
            }
#line 1915 "y.tab.c" /* yacc.c:1660  */
    break;

  case 64:
#line 360 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).selector.type=Selector::star;
            }
#line 1923 "y.tab.c" /* yacc.c:1660  */
    break;

  case 65:
#line 364 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).selector.type=Selector::cols;
              (yyval).selector.columns=(yyvsp[0]).columns;
            }
#line 1932 "y.tab.c" /* yacc.c:1660  */
    break;

  case 66:
#line 371 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).columns.clear();
        (yyval).columns.push_back((yyvsp[0]).column);
      }
#line 1941 "y.tab.c" /* yacc.c:1660  */
    break;

  case 67:
#line 376 "Parser.y" /* yacc.c:1660  */
    {
        (yyval).columns.swap((yyvsp[-2]).columns);
        (yyval).columns.push_back((yyvsp[0]).column);
      }
#line 1950 "y.tab.c" /* yacc.c:1660  */
    break;

  case 68:
#line 385 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).tables.clear();
              (yyval).tables.push_back((yyvsp[0]).iden);
            }
#line 1959 "y.tab.c" /* yacc.c:1660  */
    break;

  case 69:
#line 390 "Parser.y" /* yacc.c:1660  */
    {
              (yyval).tables.swap((yyvsp[-2]).tables);
              (yyval).tables.push_back((yyvsp[0]).iden);
            }
#line 1968 "y.tab.c" /* yacc.c:1660  */
    break;

  case 70:
#line 397 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).columnlist.clear();
                (yyval).columnlist.push_back((yyvsp[0]).iden);
              }
#line 1977 "y.tab.c" /* yacc.c:1660  */
    break;

  case 71:
#line 402 "Parser.y" /* yacc.c:1660  */
    {
                (yyval).columnlist.swap((yyvsp[-2]).columnlist);
                (yyval).columnlist.push_back((yyvsp[0]).iden);
              }
#line 1986 "y.tab.c" /* yacc.c:1660  */
    break;

  case 72:
#line 409 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).iden=(yyvsp[0]).iden;
        }
#line 1994 "y.tab.c" /* yacc.c:1660  */
    break;

  case 73:
#line 415 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).iden=(yyvsp[0]).iden;
        }
#line 2002 "y.tab.c" /* yacc.c:1660  */
    break;

  case 74:
#line 421 "Parser.y" /* yacc.c:1660  */
    {
          (yyval).iden=(yyvsp[0]).iden;
        }
#line 2010 "y.tab.c" /* yacc.c:1660  */
    break;


#line 2014 "y.tab.c" /* yacc.c:1660  */
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
#line 426 "Parser.y" /* yacc.c:1903  */


void yyerror(const char *s)
{
  cerr<<s<<endl;
}
