/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




/* Copy the first part of user declarations.  */
#line 1 "Parser.y"


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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 206 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    13,    16,    19,    22,
      24,    28,    32,    35,    38,    45,    49,    52,    58,    64,
      71,    78,    85,    92,    94,    98,   102,   108,   119,   122,
     123,   126,   129,   131,   133,   137,   138,   142,   148,   150,
     154,   156,   158,   160,   162,   164,   168,   174,   176,   180,
     184,   188,   193,   195,   199,   201,   203,   205,   207,   209,
     211,   213,   215,   219,   225,   227,   229,   231,   235,   237,
     241,   243,   247,   249,   251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,    52,    53,    -1,    54,    35,    -1,
      55,    35,    -1,    56,    35,    -1,    57,    35,    -1,     7,
       4,    -1,    34,    -1,     8,     3,    78,    -1,     9,     3,
      78,    -1,    10,    78,    -1,     7,     6,    -1,     8,     5,
      79,    36,    58,    37,    -1,     9,     5,    79,    -1,    27,
      79,    -1,    15,    16,    79,    17,    63,    -1,    18,    19,
      79,    20,    68,    -1,    21,    79,    22,    73,    20,    68,
      -1,    23,    74,    19,    76,    20,    68,    -1,     8,    29,
      79,    36,    80,    37,    -1,     9,    29,    79,    36,    80,
      37,    -1,    59,    -1,    58,    38,    59,    -1,    80,    61,
      60,    -1,    11,    12,    36,    77,    37,    -1,    33,    12,
      36,    80,    37,    28,    79,    36,    80,    37,    -1,    13,
      14,    -1,    -1,    25,    62,    -1,    26,    62,    -1,    31,
      -1,    32,    -1,    36,    49,    37,    -1,    -1,    36,    64,
      37,    -1,    63,    38,    36,    64,    37,    -1,    65,    -1,
      64,    38,    65,    -1,    49,    -1,    48,    -1,    66,    -1,
      67,    -1,    14,    -1,    49,    39,    49,    -1,    49,    44,
      49,    44,    49,    -1,    69,    -1,    69,    30,    68,    -1,
      70,    71,    72,    -1,    70,    24,    14,    -1,    70,    24,
      13,    14,    -1,    80,    -1,    79,    39,    80,    -1,    40,
      -1,    45,    -1,    47,    -1,    46,    -1,    41,    -1,    42,
      -1,    65,    -1,    70,    -1,    80,    40,    65,    -1,    73,
      38,    80,    40,    65,    -1,    43,    -1,    75,    -1,    70,
      -1,    75,    38,    70,    -1,    79,    -1,    76,    38,    79,
      -1,    80,    -1,    77,    38,    80,    -1,    50,    -1,    50,
      -1,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    26,    26,    27,    30,    35,    40,    45,    52,    56,
      62,    66,    70,    74,    80,    84,    88,    92,    96,   100,
     104,   110,   114,   120,   125,   133,   140,   145,   154,   159,
     164,   169,   174,   178,   184,   189,   194,   199,   206,   211,
     218,   223,   228,   233,   238,   244,   252,   258,   263,   270,
     277,   282,   290,   295,   303,   307,   311,   315,   319,   323,
     329,   334,   341,   348,   357,   361,   368,   373,   382,   387,
     394,   399,   406,   412,   418
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "tableList", "columnList", "dbName", "tbName", "colName", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     1,
       3,     3,     2,     2,     6,     3,     2,     5,     5,     6,
       6,     6,     6,     1,     3,     3,     5,    10,     2,     0,
       2,     2,     1,     1,     3,     0,     3,     5,     1,     3,
       1,     1,     1,     1,     1,     3,     5,     1,     3,     3,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     1,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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
      24,     0,    30,    31,     0,    25,     0,     0,    36,     0,
       0,    48,     0,    50,    60,    61,    49,     0,     0,    70,
       0,     0,    28,    45,     0,    39,     0,    51,    63,    26,
       0,     0,    34,     0,    37,    71,     0,    46,     0,     0,
       0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    13,    14,    15,    16,    17,    70,    71,   125,
      93,   122,    76,    99,   100,   101,   102,    77,    78,    79,
     112,   136,    62,    35,    36,    64,   138,    27,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -75
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,    47,   -75,
     -75,    42,   -75,     6,   -74,   -75,   -75,   -62,   -75,    -7,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,    56,    -9,   -51
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -74
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 31 "Parser.y"
    {
        (yyvsp[(1) - (2)]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
    break;

  case 5:
#line 36 "Parser.y"
    {
        (yyvsp[(1) - (2)]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
    break;

  case 6:
#line 41 "Parser.y"
    {
        (yyvsp[(1) - (2)]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
    break;

  case 7:
#line 46 "Parser.y"
    {
        (yyvsp[(1) - (2)]).handler->accept();
        //printf("%s->",getdatabase().length()?getdatabase().c_str():"NULL");
      }
    break;

  case 8:
#line 53 "Parser.y"
    {
        (yyval).handler=new ShowDatabases();
      }
    break;

  case 9:
#line 57 "Parser.y"
    {
        (yyval).handler=new Exiter();
      }
    break;

  case 10:
#line 63 "Parser.y"
    {
        (yyval).handler=new CreateDatabase((yyvsp[(3) - (3)]).iden);
      }
    break;

  case 11:
#line 67 "Parser.y"
    {
        (yyval).handler=new DropDatabase((yyvsp[(3) - (3)]).iden);
      }
    break;

  case 12:
#line 71 "Parser.y"
    {
        (yyval).handler=new UseDatabase((yyvsp[(2) - (2)]).iden);
      }
    break;

  case 13:
#line 75 "Parser.y"
    {
        (yyval).handler=new ShowTables();
      }
    break;

  case 14:
#line 81 "Parser.y"
    {
        (yyval).handler=new CreateTable((yyvsp[(3) - (6)]).iden,(yyvsp[(5) - (6)]).fields);
      }
    break;

  case 15:
#line 85 "Parser.y"
    {
        (yyval).handler=new DropTable((yyvsp[(3) - (3)]).iden);
      }
    break;

  case 16:
#line 89 "Parser.y"
    {
        (yyval).handler=new DescTable((yyvsp[(2) - (2)]).iden);
      }
    break;

  case 17:
#line 93 "Parser.y"
    {
        (yyval).handler=new InsertValue((yyvsp[(3) - (5)]).iden,(yyvsp[(5) - (5)]).values);
      }
    break;

  case 18:
#line 97 "Parser.y"
    {
        (yyval).handler=new DeleteValues((yyvsp[(3) - (5)]).iden,(yyvsp[(5) - (5)]).wheres);
      }
    break;

  case 19:
#line 101 "Parser.y"
    {
        (yyval).handler=new UpdateValues((yyvsp[(2) - (6)]).iden,(yyvsp[(4) - (6)]).sets,(yyvsp[(6) - (6)]).wheres);
      }
    break;

  case 20:
#line 105 "Parser.y"
    {
        (yyval).handler=new SelectValues((yyvsp[(2) - (6)]).selector,(yyvsp[(4) - (6)]).tables,(yyvsp[(6) - (6)]).wheres);
      }
    break;

  case 21:
#line 111 "Parser.y"
    {
        (yyval).handler=new CreateIndex((yyvsp[(3) - (6)]).iden,(yyvsp[(5) - (6)]).iden);
      }
    break;

  case 22:
#line 115 "Parser.y"
    {
        (yyval).handler=new DropIndex((yyvsp[(3) - (6)]).iden,(yyvsp[(5) - (6)]).iden);
      }
    break;

  case 23:
#line 121 "Parser.y"
    {
        (yyval).fields.clear();
        (yyval).fields.push_back((yyvsp[(1) - (1)]).fielditem);
      }
    break;

  case 24:
#line 126 "Parser.y"
    {
        (yyval).fields.clear();
        (yyval).fields.swap((yyvsp[(1) - (3)]).fields);
        (yyval).fields.push_back((yyvsp[(3) - (3)]).fielditem);
      }
    break;

  case 25:
#line 134 "Parser.y"
    {
          (yyval).fielditem.type=Field::column;
          (yyval).fielditem.Nullable=(yyvsp[(3) - (3)]).Nullable;
          (yyval).fielditem.thetype=(yyvsp[(2) - (3)]).colType;
          (yyval).fielditem.colName=(yyvsp[(1) - (3)]).iden;
        }
    break;

  case 26:
#line 141 "Parser.y"
    {
          (yyval).fielditem.type=Field::primarykey;
          (yyval).fielditem.columns.swap((yyvsp[(4) - (5)]).columnlist);
        }
    break;

  case 27:
#line 146 "Parser.y"
    {
          (yyval).fielditem.type=Field::foreignkey;
          (yyval).fielditem.colName=(yyvsp[(4) - (10)]).iden;
          (yyval).fielditem.reftable=(yyvsp[(7) - (10)]).iden;
          (yyval).fielditem.refcolumn=(yyvsp[(9) - (10)]).iden;
        }
    break;

  case 28:
#line 155 "Parser.y"
    {
                    (yyval).Nullable=false;
                  }
    break;

  case 29:
#line 159 "Parser.y"
    {
                    (yyval).Nullable=true;
                  }
    break;

  case 30:
#line 165 "Parser.y"
    {
          (yyval).colType.typeId=Type::_INT;
          (yyval).colType.len=(yyvsp[(2) - (2)]).intValue;
        }
    break;

  case 31:
#line 170 "Parser.y"
    {
          (yyval).colType.typeId=Type::_CHAR;
          (yyval).colType.len=(yyvsp[(2) - (2)]).intValue;
        }
    break;

  case 32:
#line 175 "Parser.y"
    {
          (yyval).colType.typeId=Type::_DATE;
        }
    break;

  case 33:
#line 179 "Parser.y"
    {
          (yyval).colType.typeId=Type::_FLOAT;
        }
    break;

  case 34:
#line 185 "Parser.y"
    {
                    (yyval).intValue=(yyvsp[(2) - (3)]).intValue;
                  }
    break;

  case 35:
#line 189 "Parser.y"
    {
                    (yyval).intValue=0;
                  }
    break;

  case 36:
#line 195 "Parser.y"
    {
                (yyval).values.clear();
                (yyval).values.push_back((yyvsp[(2) - (3)]).valuelist);
              }
    break;

  case 37:
#line 200 "Parser.y"
    {
                (yyval).values.swap((yyvsp[(1) - (5)]).values);
                (yyval).values.push_back((yyvsp[(4) - (5)]).valuelist);
              }
    break;

  case 38:
#line 207 "Parser.y"
    {
              (yyval).valuelist.clear();
              (yyval).valuelist.push_back((yyvsp[(1) - (1)]).value);
            }
    break;

  case 39:
#line 212 "Parser.y"
    {
              (yyval).valuelist.swap((yyvsp[(1) - (3)]).valuelist);
              (yyval).valuelist.push_back((yyvsp[(3) - (3)]).value);
            }
    break;

  case 40:
#line 219 "Parser.y"
    {
          (yyval).value.type=Value::_INT;
          (yyval).value.intValue=(yyvsp[(1) - (1)]).intValue;
        }
    break;

  case 41:
#line 224 "Parser.y"
    {
          (yyval).value.type=Value::_STRING;
          (yyval).value.stringValue=(yyvsp[(1) - (1)]).stringValue;
        }
    break;

  case 42:
#line 229 "Parser.y"
    {
          (yyval).value.type=Value::_FLOAT;
          (yyval).value.floatValue=(yyvsp[(1) - (1)]).floatValue;
        }
    break;

  case 43:
#line 234 "Parser.y"
    {
          (yyval).value.type=Value::_DATE;
          (yyval).value.dateValue=(yyvsp[(1) - (1)]).dateValue;
        }
    break;

  case 44:
#line 239 "Parser.y"
    {
          (yyval).value.type=Value::_NULL;
        }
    break;

  case 45:
#line 245 "Parser.y"
    {
                float fl=(yyvsp[(3) - (3)]).intValue;
                while(fl>=1)fl/=10.0;
                (yyval).floatValue=(yyvsp[(1) - (3)]).intValue+fl;
              }
    break;

  case 46:
#line 253 "Parser.y"
    {
              (yyval).dateValue=(yyvsp[(1) - (5)]).intValue*10000+(yyvsp[(3) - (5)]).intValue*100+(yyvsp[(5) - (5)]).intValue;
            }
    break;

  case 47:
#line 259 "Parser.y"
    {
                (yyval).wheres.clear();
                (yyval).wheres.push_back((yyvsp[(1) - (1)]).whereitem);
              }
    break;

  case 48:
#line 264 "Parser.y"
    {
                (yyval).wheres.swap((yyvsp[(3) - (3)]).wheres);
                (yyval).wheres.push_back((yyvsp[(1) - (3)]).whereitem);
              }
    break;

  case 49:
#line 271 "Parser.y"
    {
                  (yyval).whereitem.type=WhereItem::OPERATION;
                  (yyval).whereitem.left=(yyvsp[(1) - (3)]).column;
                  (yyval).whereitem.Operator=(yyvsp[(2) - (3)]).Operator;
                  (yyval).whereitem.expr=(yyvsp[(3) - (3)]).expr;
                }
    break;

  case 50:
#line 278 "Parser.y"
    {
                  (yyval).whereitem.type=WhereItem::ISNULL;
                  (yyval).whereitem.left=(yyvsp[(1) - (3)]).column;
                }
    break;

  case 51:
#line 283 "Parser.y"
    {
                  (yyval).whereitem.type=WhereItem::ISNOTNULL;
                  (yyval).whereitem.left=(yyvsp[(1) - (4)]).column;
                }
    break;

  case 52:
#line 291 "Parser.y"
    {
        (yyval).column.hastable=false;
        (yyval).column.column=(yyvsp[(1) - (1)]).iden;
      }
    break;

  case 53:
#line 296 "Parser.y"
    {
        (yyval).column.hastable=true;
        (yyval).column.table=(yyvsp[(1) - (3)]).iden;
        (yyval).column.column=(yyvsp[(3) - (3)]).iden;
      }
    break;

  case 54:
#line 304 "Parser.y"
    {
        (yyval).Operator=WhereItem::_EQUAL;
      }
    break;

  case 55:
#line 308 "Parser.y"
    {
        (yyval).Operator=WhereItem::_NOT_EQUAL;
      }
    break;

  case 56:
#line 312 "Parser.y"
    {
        (yyval).Operator=WhereItem::_LESS_OR_EQUAL;
      }
    break;

  case 57:
#line 316 "Parser.y"
    {
        (yyval).Operator=WhereItem::_MORE_OR_EQUAL;
      }
    break;

  case 58:
#line 320 "Parser.y"
    {
        (yyval).Operator=WhereItem::_LESS;
      }
    break;

  case 59:
#line 324 "Parser.y"
    {
        (yyval).Operator=WhereItem::_MORE;
      }
    break;

  case 60:
#line 330 "Parser.y"
    {
          (yyval).expr.type=Expr::VALUE;
          (yyval).expr.value=(yyvsp[(1) - (1)]).value;
        }
    break;

  case 61:
#line 335 "Parser.y"
    {
          (yyval).expr.type=Expr::COL;
          (yyval).expr.column=(yyvsp[(1) - (1)]).column;
        }
    break;

  case 62:
#line 342 "Parser.y"
    {
              (yyval).set.column=(yyvsp[(1) - (3)]).iden;
              (yyval).set.value=(yyvsp[(3) - (3)]).value;
              (yyval).sets.clear();
              (yyval).sets.push_back((yyval).set);
            }
    break;

  case 63:
#line 349 "Parser.y"
    {
              (yyval).set.column=(yyvsp[(3) - (5)]).iden;
              (yyval).set.value=(yyvsp[(5) - (5)]).value;
              (yyval).sets.swap((yyvsp[(1) - (5)]).sets);
              (yyval).sets.push_back((yyval).set);
            }
    break;

  case 64:
#line 358 "Parser.y"
    {
              (yyval).selector.type=Selector::star;
            }
    break;

  case 65:
#line 362 "Parser.y"
    {
              (yyval).selector.type=Selector::cols;
              (yyval).selector.columns=(yyvsp[(1) - (1)]).columns;
            }
    break;

  case 66:
#line 369 "Parser.y"
    {
        (yyval).columns.clear();
        (yyval).columns.push_back((yyvsp[(1) - (1)]).column);
      }
    break;

  case 67:
#line 374 "Parser.y"
    {
        (yyval).columns.swap((yyvsp[(1) - (3)]).columns);
        (yyval).columns.push_back((yyvsp[(3) - (3)]).column);
      }
    break;

  case 68:
#line 383 "Parser.y"
    {
              (yyval).tables.clear();
              (yyval).tables.push_back((yyvsp[(1) - (1)]).iden);
            }
    break;

  case 69:
#line 388 "Parser.y"
    {
              (yyval).tables.swap((yyvsp[(1) - (3)]).tables);
              (yyval).tables.push_back((yyvsp[(3) - (3)]).iden);
            }
    break;

  case 70:
#line 395 "Parser.y"
    {
                (yyval).columnlist.clear();
                (yyval).columnlist.push_back((yyvsp[(1) - (1)]).iden);
              }
    break;

  case 71:
#line 400 "Parser.y"
    {
                (yyval).columnlist.swap((yyvsp[(1) - (3)]).columnlist);
                (yyval).columnlist.push_back((yyvsp[(3) - (3)]).iden);
              }
    break;

  case 72:
#line 407 "Parser.y"
    {
          (yyval).iden=(yyvsp[(1) - (1)]).iden;
        }
    break;

  case 73:
#line 413 "Parser.y"
    {
          (yyval).iden=(yyvsp[(1) - (1)]).iden;
        }
    break;

  case 74:
#line 419 "Parser.y"
    {
          (yyval).iden=(yyvsp[(1) - (1)]).iden;
        }
    break;


/* Line 1267 of yacc.c.  */
#line 2085 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 424 "Parser.y"


void yyerror(const char *s)
{
  cerr<<s<<endl;
}

