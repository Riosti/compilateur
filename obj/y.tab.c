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
#line 1 "yacc.y" /* yacc.c:339  */

  #include "inc/sauv.h"
  #include "inc/html.h"
  #include "inc/analyse_sementique.h"
  #include "inc/erreur.h"
  //extern int Num_lignes;
  //extern int Num_inst;
  int yylex();
  int yyerror();
  

#line 78 "y.tab.c" /* yacc.c:339  */

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
    DEBUT_PROG = 258,
    DEBUT = 259,
    FIN = 260,
    POINT_VIRGULE = 261,
    TYPE = 262,
    DEUX_POINTS = 263,
    STRUCT = 264,
    FSTRUCT = 265,
    TABLEAU = 266,
    CO = 267,
    CF = 268,
    VIRGULE = 269,
    POINT = 270,
    VARIABLE = 271,
    PROCEDURE = 272,
    FONCTION = 273,
    PO = 274,
    PF = 275,
    VIDE = 276,
    TANT_QUE = 277,
    FAIRE = 278,
    OPAFF = 279,
    PLUS = 280,
    MOINS = 281,
    DIV = 282,
    MULT = 283,
    VRAI = 284,
    FAUX = 285,
    INF = 286,
    SUP = 287,
    INFEGAL = 288,
    SUPEGAL = 289,
    EGAL = 290,
    DIFF = 291,
    RETOURNE = 292,
    SI = 293,
    ALORS = 294,
    SINON = 295,
    ET = 296,
    OU = 297,
    DE = 298,
    INCREMENTE = 299,
    DECREMENTE = 300,
    DIEZ = 301,
    NON = 302,
    READ = 303,
    WRITE = 304,
    ERREUR = 305,
    CSTE_ENTIERE = 306,
    IDF = 307,
    CSTE_CARACTERE = 308,
    CSTE_CHAINE = 309,
    ENTIER = 310,
    REEL = 311,
    CHAINE = 312,
    BOOLEEN = 313,
    CARACTERE = 314,
    CSTE_REEL = 315
  };
#endif
/* Tokens.  */
#define DEBUT_PROG 258
#define DEBUT 259
#define FIN 260
#define POINT_VIRGULE 261
#define TYPE 262
#define DEUX_POINTS 263
#define STRUCT 264
#define FSTRUCT 265
#define TABLEAU 266
#define CO 267
#define CF 268
#define VIRGULE 269
#define POINT 270
#define VARIABLE 271
#define PROCEDURE 272
#define FONCTION 273
#define PO 274
#define PF 275
#define VIDE 276
#define TANT_QUE 277
#define FAIRE 278
#define OPAFF 279
#define PLUS 280
#define MOINS 281
#define DIV 282
#define MULT 283
#define VRAI 284
#define FAUX 285
#define INF 286
#define SUP 287
#define INFEGAL 288
#define SUPEGAL 289
#define EGAL 290
#define DIFF 291
#define RETOURNE 292
#define SI 293
#define ALORS 294
#define SINON 295
#define ET 296
#define OU 297
#define DE 298
#define INCREMENTE 299
#define DECREMENTE 300
#define DIEZ 301
#define NON 302
#define READ 303
#define WRITE 304
#define ERREUR 305
#define CSTE_ENTIERE 306
#define IDF 307
#define CSTE_CARACTERE 308
#define CSTE_CHAINE 309
#define ENTIER 310
#define REEL 311
#define CHAINE 312
#define BOOLEEN 313
#define CARACTERE 314
#define CSTE_REEL 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "yacc.y" /* yacc.c:355  */

  struct arbre * arbre;
  int type_int;
  float type_float;
  

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   220

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    30,    33,    34,    37,    40,    43,    44,
      48,    49,    50,    53,    54,    55,    58,    59,    60,    61,
      64,    65,    68,    71,    74,    77,    78,    81,    84,    85,
      88,    89,    92,    95,    96,    99,   100,   101,   102,   103,
     106,   109,   109,   112,   112,   127,   128,   131,   136,   139,
     153,   154,   155,   156,   157,   158,   159,   160,   163,   166,
     169,   170,   171,   174,   190,   191,   194,   195,   203,   206,
     218,   229,   238,   247,   260,   268,   276,   283,   291,   294,
     297,   298,   300,   309,   312,   313,   316,   319,   331,   334,
     346,   349,   360,   363,   364,   365,   368,   369,   372,   390,
     391,   392,   393,   394,   395,   398,   401,   402,   419,   438,
     439,   456,   474,   485,   488,   489,   490,   491,   492,   493,
     496,   497,   510,   511
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEBUT_PROG", "DEBUT", "FIN",
  "POINT_VIRGULE", "TYPE", "DEUX_POINTS", "STRUCT", "FSTRUCT", "TABLEAU",
  "CO", "CF", "VIRGULE", "POINT", "VARIABLE", "PROCEDURE", "FONCTION",
  "PO", "PF", "VIDE", "TANT_QUE", "FAIRE", "OPAFF", "PLUS", "MOINS", "DIV",
  "MULT", "VRAI", "FAUX", "INF", "SUP", "INFEGAL", "SUPEGAL", "EGAL",
  "DIFF", "RETOURNE", "SI", "ALORS", "SINON", "ET", "OU", "DE",
  "INCREMENTE", "DECREMENTE", "DIEZ", "NON", "READ", "WRITE", "ERREUR",
  "CSTE_ENTIERE", "IDF", "CSTE_CARACTERE", "CSTE_CHAINE", "ENTIER", "REEL",
  "CHAINE", "BOOLEEN", "CARACTERE", "CSTE_REEL", "$accept", "all",
  "programme", "corps", "liste_declarations", "liste_instructions",
  "suite_liste_inst", "dec1", "dec2", "dec3", "declaration_type",
  "suite_declaration_type_s", "suite_declaration_type_t", "dimension",
  "liste_dimensions", "une_dimension", "const_entier", "liste_champs",
  "un_champ", "nom_type", "type_simple", "declaration_variable",
  "declaration_procedure", "$@1", "declaration_fonction", "$@2",
  "liste_parametres", "liste_param", "un_param", "instruction", "lire",
  "ecrire", "resultat_retourne", "appel", "liste_arguments", "liste_args",
  "un_arg", "condition", "tant_que", "affectation", "variable",
  "variable_idf", "tableau", "liste_param_tab", "param_du_tab",
  "expression_chaine", "expression", "expression_et", "expression_ou",
  "expression_neg", "expression_bcn", "cste_bool", "expression_cmp",
  "opcomp", "expression_num", "e1", "e2", "e3", "e4", "e5", "plus_moins", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -144

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-144)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   118,    14,  -144,    -9,   -34,   -30,   -26,   -17,  -144,
      45,  -144,  -144,  -144,  -144,    51,    65,    83,    94,  -144,
    -144,    58,    15,    58,    79,    84,    -3,    -1,   102,  -144,
    -144,  -144,  -144,  -144,  -144,    57,  -144,  -144,   115,   131,
     101,   101,  -144,   112,    43,    13,    13,    58,    61,  -144,
    -144,    64,  -144,  -144,  -144,  -144,    10,   120,   122,   126,
    -144,  -144,  -144,  -144,   121,    53,    99,  -144,  -144,  -144,
    -144,  -144,   147,  -144,   134,   103,    58,    58,    44,  -144,
     162,  -144,   169,  -144,   125,    15,  -144,  -144,  -144,     8,
      92,   127,  -144,   139,  -144,  -144,  -144,  -144,   158,  -144,
    -144,  -144,    45,    58,    58,  -144,  -144,  -144,  -144,  -144,
    -144,    80,    80,    80,    80,    80,   129,    45,  -144,  -144,
     168,  -144,  -144,   161,   164,    72,  -144,  -144,    62,  -144,
    -144,    58,  -144,   170,  -144,  -144,   147,  -144,   133,   174,
    -144,  -144,  -144,  -144,  -144,   179,     4,  -144,   118,    92,
    -144,  -144,   126,  -144,  -144,    99,    99,  -144,  -144,  -144,
     148,   138,  -144,  -144,  -144,    58,    58,  -144,   124,   182,
       1,  -144,   -18,   149,    92,   127,  -144,  -144,  -144,    45,
     178,  -144,  -144,  -144,    92,  -144,  -144,   142,  -144,   128,
    -144,   150,    92,  -144,  -144,   118,  -144,  -144,   188,  -144,
    -144,   -18,   -18,  -144,  -144,  -144,  -144,  -144
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     0,     0,     0,     3,
       0,     5,     6,    12,    15,     0,     0,     0,     0,     1,
      54,     0,    60,     0,     0,     0,    78,     0,     0,    56,
      57,    53,    51,    52,    50,     0,    74,    75,     0,     0,
      45,    45,     4,    10,    13,    16,    17,     0,     0,    96,
      97,     0,   115,   117,   116,   118,   120,     0,    86,    88,
      90,    92,    93,    94,    95,   105,   106,   109,   113,   119,
      85,    55,    62,    61,     0,     0,     0,     0,     0,    63,
      79,     7,     0,     8,     0,     0,   122,   123,    73,     0,
       0,     0,    41,     0,    11,    14,    18,    19,     0,   112,
      91,   121,     0,     0,     0,    99,   101,   100,   102,   103,
     104,     0,     0,     0,     0,     0,     0,     0,    35,    36,
       0,    37,    38,     0,     0,     0,    82,    64,     0,    66,
      68,     0,     9,    78,    77,    76,    72,    71,     0,     0,
      21,    20,    34,    40,    33,     0,     0,    47,     0,     0,
     114,    70,    87,    89,    98,   107,   108,   111,   110,    84,
       0,     0,    58,    59,    80,     0,     0,    65,     0,     0,
       0,    30,     0,     0,     0,     0,    46,    42,    43,     0,
       0,    83,    67,    81,     0,    22,    31,     0,    28,     0,
      25,     0,     0,    49,    48,     0,    69,    39,     0,    29,
      24,     0,     0,    23,    44,    32,    26,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -144,  -144,  -144,  -143,  -144,   -10,  -144,   152,   153,   119,
    -144,  -144,  -144,  -144,  -144,    -2,    -4,  -144,    30,  -142,
     130,  -144,  -144,  -144,  -144,  -144,   160,  -144,    27,   176,
    -144,  -144,  -144,    11,  -144,  -144,    38,  -144,  -144,  -144,
      19,   123,   132,  -144,    75,   135,   -20,  -144,   105,   106,
     163,  -144,  -144,  -144,    98,  -144,    54,    56,   165,  -144,
     155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    27,    12,    13,    14,
      15,   140,   141,   173,   189,   190,   191,   170,   171,   143,
     144,    16,    17,   148,    18,   195,    92,   146,   147,    28,
      29,    30,    71,    55,    79,   128,   129,    32,    33,    34,
      56,    36,    37,    80,   125,    72,   126,    58,    59,    60,
      61,    62,    63,   111,    64,    65,    66,    67,    68,    69,
      88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,    57,    73,    74,    81,   177,     1,   178,   187,    77,
     175,   185,    20,    21,    19,    31,    78,   138,    38,   139,
      20,    21,    39,    35,   176,    84,    40,    98,    22,    23,
       7,     8,   193,   188,    47,    41,    22,    23,    31,    24,
      25,    48,   198,    26,    49,    50,    35,    24,    25,     4,
     203,    26,   204,   169,    86,    87,   124,    43,   130,     6,
       7,     8,    51,    47,   127,   137,    52,    26,    53,    70,
      48,    44,    84,    49,    50,    54,   166,    47,   112,   113,
      47,    85,   167,    47,    48,   164,   165,    49,    50,    45,
      48,    51,   151,    49,    50,    52,    26,    53,    75,    47,
      46,    86,    87,    76,    54,    51,    48,   160,    83,    52,
      26,    53,    52,    26,    53,    52,    26,    53,    54,     5,
      91,    54,     4,    89,    54,     5,   114,   115,     6,     7,
       8,    52,    26,    53,     6,     7,     8,   183,   165,    90,
      54,   200,   201,   102,   142,   181,   130,   118,   119,   120,
     121,   122,   105,   106,   107,   108,   109,   110,   118,   119,
     120,   121,   122,   103,    96,    97,   155,   156,   104,   196,
     157,   158,   116,   117,   131,   132,   149,   133,   150,   145,
     161,   162,    77,   159,   163,   169,   172,   174,   179,   180,
     184,   197,   192,   199,   205,    94,   202,    95,   207,   206,
     186,    93,   194,    82,   182,   123,   168,   134,   152,   154,
     153,   101,     0,    99,   100,     0,   135,     0,     0,     0,
     136
};

static const yytype_int16 yycheck[] =
{
      10,    21,    22,    23,     5,   148,     3,   149,    26,    12,
       6,    10,    21,    22,     0,     4,    19,     9,    52,    11,
      21,    22,    52,     4,    20,    15,    52,    47,    37,    38,
      17,    18,   174,    51,    19,    52,    37,    38,    27,    48,
      49,    26,   184,    52,    29,    30,    27,    48,    49,     4,
     192,    52,   195,    52,    44,    45,    76,     6,    78,    16,
      17,    18,    47,    19,    20,    85,    51,    52,    53,    54,
      26,     6,    15,    29,    30,    60,    14,    19,    25,    26,
      19,    24,    20,    19,    26,    13,    14,    29,    30,     6,
      26,    47,   102,    29,    30,    51,    52,    53,    19,    19,
       6,    44,    45,    19,    60,    47,    26,   117,     6,    51,
      52,    53,    51,    52,    53,    51,    52,    53,    60,     7,
      19,    60,     4,     8,    60,     7,    27,    28,    16,    17,
      18,    51,    52,    53,    16,    17,    18,    13,    14,     8,
      60,    13,    14,    23,    52,   165,   166,    55,    56,    57,
      58,    59,    31,    32,    33,    34,    35,    36,    55,    56,
      57,    58,    59,    41,    45,    46,   112,   113,    42,   179,
     114,   115,    25,    39,    12,     6,    37,    52,    20,    52,
      12,    20,    12,    54,    20,    52,    12,     8,    40,    51,
       8,    13,    43,    51,     6,    43,    46,    44,   202,   201,
     170,    41,   175,    27,   166,    75,   131,    84,   103,   111,
     104,    56,    -1,    48,    51,    -1,    84,    -1,    -1,    -1,
      85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    62,    63,     4,     7,    16,    17,    18,    64,
      65,    66,    68,    69,    70,    71,    82,    83,    85,     0,
      21,    22,    37,    38,    48,    49,    52,    67,    90,    91,
      92,    94,    98,    99,   100,   101,   102,   103,    52,    52,
      52,    52,    66,     6,     6,     6,     6,    19,    26,    29,
      30,    47,    51,    53,    60,    94,   101,   107,   108,   109,
     110,   111,   112,   113,   115,   116,   117,   118,   119,   120,
      54,    93,   106,   107,   107,    19,    19,    12,    19,    95,
     104,     5,    90,     6,    15,    24,    44,    45,   121,     8,
       8,    19,    87,    87,    68,    69,    70,    70,   107,   119,
     111,   121,    23,    41,    42,    31,    32,    33,    34,    35,
      36,   114,    25,    26,    27,    28,    25,    39,    55,    56,
      57,    58,    59,    81,   107,   105,   107,    20,    96,    97,
     107,    12,     6,    52,   102,   103,   106,   107,     9,    11,
      72,    73,    52,    80,    81,    52,    88,    89,    84,    37,
      20,    66,   109,   110,   115,   117,   117,   118,   118,    54,
      66,    12,    20,    20,    13,    14,    14,    20,   105,    52,
      78,    79,    12,    74,     8,     6,    20,    64,    80,    40,
      51,   107,    97,    13,     8,    10,    79,    26,    51,    75,
      76,    77,    43,    80,    89,    86,    66,    13,    80,    51,
      13,    14,    46,    80,    64,     6,    76,    77
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    64,    64,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    70,    70,    70,    70,
      71,    71,    72,    73,    74,    75,    75,    76,    77,    77,
      78,    78,    79,    80,    80,    81,    81,    81,    81,    81,
      82,    84,    83,    86,    85,    87,    87,    88,    88,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    92,
      93,    93,    93,    94,    95,    95,    96,    96,    97,    98,
      99,   100,   100,   100,   101,   101,   101,   101,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   111,   112,   112,   113,   114,
     114,   114,   114,   114,   114,   115,   116,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   121
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     3,     2,     3,
       2,     3,     1,     2,     3,     1,     2,     2,     3,     3,
       4,     4,     3,     4,     3,     1,     3,     3,     1,     2,
       1,     2,     4,     1,     1,     1,     1,     1,     1,     4,
       4,     0,     5,     0,     7,     0,     3,     1,     3,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     4,     4,
       0,     1,     1,     2,     2,     3,     1,     3,     1,     6,
       4,     3,     3,     2,     1,     1,     3,     3,     1,     2,
       3,     4,     1,     3,     3,     1,     1,     3,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     3,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1
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
        case 2:
#line 28 "yacc.y" /* yacc.c:1646  */
    {sauvegarde_tables("table_prog");}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 30 "yacc.y" /* yacc.c:1646  */
    {fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),(yyvsp[0].arbre)));}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 33 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 34 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 40 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 43 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 44 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a;a=(yyvsp[-2].arbre);while(a->frere!=NULL){a=a->frere;a=a->fils;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_LIST,-1),(yyvsp[-1].arbre)));(yyval.arbre)=(yyvsp[-2].arbre);}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 64 "yacc.y" /* yacc.c:1646  */
    {ajoute_tableau((yyvsp[-2].type_int));}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 65 "yacc.y" /* yacc.c:1646  */
    {ajoute_struct((yyvsp[-2].type_int));}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 71 "yacc.y" /* yacc.c:1646  */
    {enfile((yyvsp[0].arbre)->noeud);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 84 "yacc.y" /* yacc.c:1646  */
    {enfile((yyvsp[0].type_int));}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 85 "yacc.y" /* yacc.c:1646  */
    {enfile(-1*(yyvsp[0].type_int));}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 92 "yacc.y" /* yacc.c:1646  */
    {enfile((yyvsp[-3].type_int));enfile((yyvsp[-1].arbre)->noeud);enfile(taille_type((yyvsp[-1].arbre)->noeud));}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 95 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 96 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a ;a=cree_noeud(A_IDF,(yyvsp[0].type_int));ajoute_type_final(a,num_dec((yyvsp[0].type_int)));(yyval.arbre)=a; }
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 99 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud(A_INT,(yyvsp[0].type_int)); ajoute_type_final(a,0);(yyval.arbre)=a;}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 100 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud(A_FLOAT,(yyvsp[0].type_int));ajoute_type_final(a,1);(yyval.arbre)=a;}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 101 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud(A_BOOL,(yyvsp[0].type_int));ajoute_type_final(a,3);(yyval.arbre)=a;}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 102 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud(A_CHAR,(yyvsp[0].type_int));ajoute_type_final(a,2);(yyval.arbre)=a;}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 103 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=concat_pere_fils(cree_noeud(A_CHAINE,(yyvsp[-3].type_int)),cree_noeud(A_CSTE_E,(yyvsp[-1].type_int)));ajoute_type_final(a,4);(yyval.arbre)=a;}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 106 "yacc.y" /* yacc.c:1646  */
    {ajoute_variable((yyvsp[-2].type_int),(yyvsp[0].arbre)->noeud);{taille_de_la_region();}}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 109 "yacc.y" /* yacc.c:1646  */
    {ajoute_proc((yyvsp[-1].type_int));}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 109 "yacc.y" /* yacc.c:1646  */
    {test_corp_procedure((yyvsp[0].arbre));fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_PROC,(yyvsp[-3].type_int)),concat_pere_frere((yyvsp[-2].arbre),concat_pere_fils(cree_noeud(A_LIST,-1),(yyvsp[0].arbre))))));}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 112 "yacc.y" /* yacc.c:1646  */
    {enfile((yyvsp[0].arbre)->noeud);ajoute_fonction((yyvsp[-3].type_int));
   if(!(test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1) || test_type((yyvsp[0].arbre),2) || test_type((yyvsp[0].arbre),3) || test_type((yyvsp[0].arbre),4))){
     fprintf(stderr,"erreur le return de la fonction %s ne peux etre que un type de base\n",get_lexeme((yyvsp[-3].type_int)));
    erreur_affiche();
   }
 }
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 117 "yacc.y" /* yacc.c:1646  */
    {
    test_corp_fonction(num_dec((yyvsp[-5].type_int)),(yyvsp[0].arbre));
    fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_FONCTION,(yyvsp[-5].type_int)),concat_pere_frere((yyvsp[-4].arbre),concat_pere_frere(concat_pere_fils(cree_noeud(A_RETURN,-1),(yyvsp[-2].arbre)),concat_pere_fils(cree_noeud(A_LIST,-1),(yyvsp[0].arbre)))))));
    
  

 }
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_VIDE,-1);}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a ;
   a=concat_pere_fils(cree_noeud(A_PARAM,-1),(yyvsp[0].arbre));
   ajoute_type_final(a,donne_type_final((yyvsp[0].arbre)));
   (yyval.arbre)=a;
 }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 136 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a,*b;a=(yyvsp[-2].arbre);b=concat_pere_fils(cree_noeud(A_PARAM,-1),(yyvsp[0].arbre));while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,b);(yyval.arbre)=a;ajoute_type_final(b,donne_type_final((yyvsp[0].arbre)));}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 139 "yacc.y" /* yacc.c:1646  */
    {
  type_arbre * a;
  a=cree_noeud(A_IDF,(yyvsp[-2].type_int));
  enfile((yyvsp[-2].type_int));
  enfile((yyvsp[0].arbre)->noeud);
  ajoute_type_final(a,donne_type_final((yyvsp[0].arbre)));
  (yyval.arbre)=a;
  if(!(test_type(a,0) || test_type(a,1) || test_type(a,2) || test_type(a,3) || test_type(a,4))){
    fprintf(stderr,"erreur le parametre %s ne peux etre que un type de base\n",get_lexeme((yyvsp[-2].type_int)));
    erreur_affiche();
  }
 }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 153 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 154 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 155 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 156 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 157 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_VIDE,-1);}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 158 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=concat_pere_fils(cree_noeud(A_RETURN,-1),(yyvsp[0].arbre));ajoute_type_final(a,donne_type_final((yyvsp[0].arbre)));(yyval.arbre)=a;}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 159 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 160 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 163 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a =concat_pere_fils(cree_noeud(A_LIRE,-1),(yyvsp[-1].arbre));ajoute_type_final(a,donne_type_final((yyvsp[-1].arbre)));(yyval.arbre)=a;}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 166 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;if(test_type((yyvsp[-1].arbre),0) || test_type((yyvsp[-1].arbre),1) || test_type((yyvsp[-1].arbre),2) || test_type((yyvsp[-1].arbre),3) || test_type((yyvsp[-1].arbre),4)){a = concat_pere_fils(cree_noeud(A_ECRIRE,-1),(yyvsp[-1].arbre));ajoute_type_final(a,donne_type_final((yyvsp[-1].arbre)));(yyval.arbre)=a;}else{ fprintf(stderr,"erreur de type on ne peux ecrire que des type de bases \n");erreur_affiche();}}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 169 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_VIDE,-1);}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 170 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 171 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 174 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
   if(est_une_fonction(num_dec((yyvsp[-1].type_int)))){
     a=concat_pere_fils(cree_noeud(A_APPEL_F,-1),concat_pere_frere(cree_noeud(A_IDF,(yyvsp[-1].type_int)),(yyvsp[0].arbre)));ajoute_type_final(a,donne_type_fonction(num_dec((yyvsp[-1].type_int))));verif_arg_fonction(num_dec((yyvsp[-1].type_int)),(yyvsp[0].arbre));a->num_dec=num_dec((yyvsp[-1].type_int));(yyval.arbre)=a;
   }
   else{
     if(est_une_procedure(num_dec((yyvsp[-1].type_int)))){
       a=concat_pere_fils(cree_noeud(A_APPEL_P,-1),concat_pere_frere(cree_noeud(A_IDF,(yyvsp[-1].type_int)),(yyvsp[0].arbre)));verif_arg_procedure(num_dec((yyvsp[-1].type_int)),(yyvsp[0].arbre));a->num_dec=num_dec((yyvsp[-1].type_int));(yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"%s n'est pas une fonction ou une procedure donc appelle impossible\n",get_lexeme((yyvsp[-1].type_int)));
       erreur_affiche();
     }
   }
 }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 190 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=NULL;}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 191 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 194 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=concat_pere_fils(cree_noeud(A_ARG,-1),(yyvsp[0].arbre));ajoute_type_final(a,donne_type_final((yyvsp[0].arbre)));(yyval.arbre)=a;}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 195 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a, *b;
   a=(yyvsp[-2].arbre);
   b=concat_pere_fils(cree_noeud(A_ARG,-1),(yyvsp[0].arbre));
   ajoute_type_final(b,donne_type_final((yyvsp[0].arbre)));
   while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,b);
   (yyval.arbre)=(yyvsp[-2].arbre);}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 203 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 208 "yacc.y" /* yacc.c:1646  */
    {
  if(test_type((yyvsp[-4].arbre),3)){
    (yyval.arbre)=concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(concat_pere_fils(cree_noeud(A_SI,-1),(yyvsp[-4].arbre)),concat_pere_frere(concat_pere_fils(cree_noeud(A_ALORS,-1),(yyvsp[-2].arbre)),concat_pere_fils(cree_noeud(A_SINON,-1),(yyvsp[0].arbre)))));
  }
  else{
    fprintf(stderr,"apres un if il faut une expression boolean \n");
    erreur_affiche();
  }}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 218 "yacc.y" /* yacc.c:1646  */
    {
  if(test_type((yyvsp[-2].arbre),3)){
    (yyval.arbre)=concat_pere_fils(cree_noeud(A_TQ,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
  }
  else{
    fprintf(stderr,"apres un tant que le type de l'expression dois etre un boolean \n");
    erreur_affiche();
  }
}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
  if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
     (yyval.arbre)=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
   }
   else{
     fprintf(stderr,"affectaion de impossible types diffents \n");
     erreur_affiche();
   }
 }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 238 "yacc.y" /* yacc.c:1646  */
    {
	      if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
		(yyval.arbre)=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
	      }
	      else{
		fprintf(stderr,"affectaion de impossible types diffents \n");
		erreur_affiche();
	      }
 }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 247 "yacc.y" /* yacc.c:1646  */
    {
	      type_arbre *a ;
	      a=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_fils((yyvsp[0].arbre),concat_pere_frere((yyvsp[-1].arbre),cree_noeud(A_CSTE_E,1))));
	      if(test_type((yyvsp[-1].arbre),0) || test_type((yyvsp[-1].arbre),1) || test_type((yyvsp[-1].arbre),2)){
		ajoute_type_final(a,donne_type_final((yyvsp[-1].arbre)));
	      }
	      else{
		fprintf(stderr,"erreur type pour le ++ ou -- n'est pas respecter \n");
		erreur_affiche();
	      }
	      (yyval.arbre)=a;}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 260 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);
   ajoute_type_var((yyvsp[0].arbre),type_var(num_dec(donne_num_hash_arbre((yyvsp[0].arbre)))));
   ajoute_type_final((yyvsp[0].arbre),type_var(num_dec(donne_num_hash_arbre((yyvsp[0].arbre)))));
   ajoute_num_dec((yyvsp[0].arbre),num_dec(donne_num_hash_arbre((yyvsp[0].arbre))));
 }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 268 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);
   ajoute_type_final((yyvsp[0].arbre),type_dun_tab(num_dec(donne_num_hash_arbre((yyvsp[0].arbre)->fils))));
   ajoute_num_dec((yyvsp[0].arbre),num_dec(donne_num_hash_arbre((yyvsp[0].arbre)->fils)));
  }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 276 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a;a=(yyvsp[-2].arbre);while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_STRUCT,-1),(yyvsp[0].arbre)));
   ajoute_type_var((yyvsp[0].arbre),type_dun_tab(type_dun_struct(donne_type_arbre(a),donne_num_hash_arbre((yyvsp[0].arbre)->fils))));
   ajoute_type_final((yyvsp[-2].arbre),donne_type_arbre((yyvsp[0].arbre)->fils));
   (yyval.arbre)=(yyvsp[-2].arbre);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 283 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a;a=(yyvsp[-2].arbre);while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_STRUCT,-1),(yyvsp[0].arbre)));

   ajoute_type_var((yyvsp[0].arbre),type_dun_struct(donne_type_final((yyvsp[-2].arbre)),donne_num_hash_arbre((yyvsp[0].arbre))));

   ajoute_type_final((yyvsp[-2].arbre),donne_type_arbre((yyvsp[0].arbre)));
   (yyval.arbre)=(yyvsp[-2].arbre); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 291 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_IDF,(yyvsp[0].type_int));}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 294 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a ; a=concat_pere_fils(cree_noeud(A_TABLEAU,-1),concat_pere_frere(cree_noeud(A_IDF,(yyvsp[-1].type_int)),(yyvsp[0].arbre)));(yyval.arbre)=a;}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 297 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 298 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a;a=(yyvsp[-3].arbre);while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_PARAM,-1),(yyvsp[-1].arbre)));;(yyval.arbre)=(yyvsp[-3].arbre);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 300 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
   if(test_type((yyvsp[0].arbre),0)){
     (yyval.arbre)=(yyvsp[0].arbre);
   }
   else{
     fprintf(stderr,"un tableau ne peux prendre que des entier en parametre\n");
     erreur_affiche();
   }
 }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 309 "yacc.y" /* yacc.c:1646  */
    {type_arbre * a;a=(yyvsp[-2].arbre);while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_VIRGULE,-1),(yyvsp[0].arbre)));;(yyval.arbre)=(yyvsp[-2].arbre);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 312 "yacc.y" /* yacc.c:1646  */
    {concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere((yyvsp[-2].arbre),cree_noeud(A_CHAINE,(yyvsp[0].type_int))));}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 313 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_CHAINE,(yyvsp[0].type_int));}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 316 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 319 "yacc.y" /* yacc.c:1646  */
    {
type_arbre *a;
   if(test_type((yyvsp[0].arbre),3) && test_type((yyvsp[-2].arbre),3)){
     a=concat_pere_fils(cree_noeud(A_ET,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,3);
       (yyval.arbre)=a;
     }
   else{
     fprintf(stderr,"seul les expressions booleen ou les booleans peuvent avoir un et entre elles\n");
     erreur_affiche();
   }
 }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 331 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 334 "yacc.y" /* yacc.c:1646  */
    {
 type_arbre *a;
   if(test_type((yyvsp[0].arbre),3) && test_type((yyvsp[-2].arbre),3)){
     a=concat_pere_fils(cree_noeud(A_OU,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,3);
       (yyval.arbre)=a;
     }
   else{
     fprintf(stderr,"seul les expressions booleen ou les booleans peuvent avoir un ou entre elles\n");
     erreur_affiche();
   }
 }
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 346 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 349 "yacc.y" /* yacc.c:1646  */
    {
 type_arbre *a;
   if(test_type((yyvsp[0].arbre),3)){
     a=concat_pere_fils(cree_noeud(A_NON,-1),(yyvsp[0].arbre));
       ajoute_type_final(a,3);
       (yyval.arbre)=a;
     }
   else{
     fprintf(stderr,"seul les expression booleen ou les boolean peuvente avoir un non davant eux\n");
     erreur_affiche();
   }}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 360 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 363 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 364 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 365 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 368 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud_type(A_BOOL,1,3); ajoute_type_final(a,3);(yyval.arbre)=a;}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 369 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud_type(A_BOOL,-1,3); ajoute_type_final(a,3);(yyval.arbre)=a;}
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 372 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
   if((test_type((yyvsp[-2].arbre),0) || test_type((yyvsp[-2].arbre),1) || test_type((yyvsp[-2].arbre),3) || test_type((yyvsp[-2].arbre),4)) && (test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1) || test_type((yyvsp[0].arbre),3) || test_type((yyvsp[0].arbre),4))){
     if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
       a=concat_pere_fils((yyvsp[-1].arbre),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,3);
       (yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc imposible de les comparer\n");
       erreur_affiche();
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int des reels des boolean ou des character imposible de comparer d'autres types\n");
     erreur_affiche();
   }}
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 390 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_INF,-1);}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 391 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_INFEGAL,-1);}
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 392 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_SUP,-1);}
#line 2152 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 393 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_SUPEGAL,-1);}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 394 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_EGAL,-1);}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 395 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_DIFF,-1);}
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 398 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)==(yyvsp[0].arbre);}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 401 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 402 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
  if((test_type((yyvsp[-2].arbre),0) || test_type((yyvsp[-2].arbre),1)) && (test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1))){
     if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
       a=concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,donne_type_final((yyvsp[-2].arbre)));
       (yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc + imposible\n");
       erreur_affiche();
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels + imposible\n");
     erreur_affiche();
   }
 }
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 419 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
     if((test_type((yyvsp[-2].arbre),0) || test_type((yyvsp[-2].arbre),1)) && (test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1))){
     if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
       a=concat_pere_fils(cree_noeud(A_MOINS,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,donne_type_final((yyvsp[-2].arbre)));
       (yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc - impossible\n");
       erreur_affiche();
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels - imposible\n");
     erreur_affiche();
   }
 }
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 438 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 439 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
   if((test_type((yyvsp[-2].arbre),0) || test_type((yyvsp[-2].arbre),1)) && (test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1))){
     if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
       a=concat_pere_fils(cree_noeud(A_MULT,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,donne_type_final((yyvsp[-2].arbre)));
       (yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc multiplication imposible\n");
       erreur_affiche();
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels multiplication imposible\n");
     erreur_affiche();
   }
 }
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 456 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;
   if((test_type((yyvsp[-2].arbre),0) || test_type((yyvsp[-2].arbre),1)) && (test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1))){
     if(test_des_types_arbre((yyvsp[-2].arbre),(yyvsp[0].arbre))){
       a=concat_pere_fils(cree_noeud(A_DIV,-1),concat_pere_frere((yyvsp[-2].arbre),(yyvsp[0].arbre)));
       ajoute_type_final(a,donne_type_final((yyvsp[-2].arbre)));
       (yyval.arbre)=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc division imposible\n");
       erreur_affiche();
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels division imposible\n");
     erreur_affiche();
   }}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 474 "yacc.y" /* yacc.c:1646  */
    {
  if(test_type((yyvsp[0].arbre),0) || test_type((yyvsp[0].arbre),1)){
  (yyvsp[0].arbre)->noeud*=-1;
   (yyvsp[0].arbre)->noeudf*=-1;
   (yyval.arbre)=(yyvsp[0].arbre);
      }
      else{
	fprintf(stderr,"erreur - var mais la variable n'est pas un entier ou un reel \n");
	erreur_affiche();
      }
      }
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 485 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 488 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[-1].arbre);}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 489 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a; a=cree_noeud_type(A_CSTE_E,(yyvsp[0].type_int),0); ajoute_type_final(a,0);(yyval.arbre)=a;}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 490 "yacc.y" /* yacc.c:1646  */
    { type_arbre *a; a=cree_noeud_f_type(A_CSTE_R,(yyvsp[0].type_float),1); ajoute_type_final(a,1); (yyval.arbre)=a;}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 491 "yacc.y" /* yacc.c:1646  */
    {type_arbre *a;a=cree_noeud_type(A_CSTE_E,(yyvsp[0].type_int),2); ajoute_type_final(a,2);(yyval.arbre)=a;}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 492 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 493 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 496 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=(yyvsp[0].arbre);}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 497 "yacc.y" /* yacc.c:1646  */
    {
   type_arbre *a ;
   a=concat_pere_fils((yyvsp[0].arbre),concat_pere_frere((yyvsp[-1].arbre),cree_noeud(A_CSTE_E,1)));
   if(test_type((yyvsp[-1].arbre),0) || test_type((yyvsp[-1].arbre),1) || test_type((yyvsp[-1].arbre),2)){
       ajoute_type_final(a,donne_type_final((yyvsp[-1].arbre)));
     }
     else{
       fprintf(stderr,"erreur type pour le ++ ou -- n'est pas respecter \n");
       erreur_affiche();
     }
     (yyval.arbre)=a;}
#line 2355 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 510 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_INCR,-1);}
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 511 "yacc.y" /* yacc.c:1646  */
    {(yyval.arbre)=cree_noeud(A_DEC,-1);}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2371 "y.tab.c" /* yacc.c:1646  */
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
#line 522 "yacc.y" /* yacc.c:1906  */


int yyerror(){fprintf(stderr,"erreur syntaxique \n");erreur_affiche();}


int main(int argc ,char * argv[]){
  strcpy(Fichier_ouvert,argv[1]);
  init_html();
  init_table_hash();
  init_table_decla();
  init_table_rep_type();
  init_table_region();
  init_file();
  nouvelle_region();
  ajoute_type_base(ajoute_lexem("Int"));
  ajoute_type_base(ajoute_lexem("Float"));
  ajoute_type_base(ajoute_lexem("Char"));
  ajoute_type_base(ajoute_lexem("Bool"));
  ajoute_type_base(ajoute_lexem("String"));
  yyparse();
  end_html();
}


