/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 13 "yacc.y" /* yacc.c:1909  */

  struct arbre * arbre;
  int type_int;
  float type_float;
  

#line 181 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
