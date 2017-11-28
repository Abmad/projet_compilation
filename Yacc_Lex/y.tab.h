/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     POINT_VIRGULE = 258,
     DEUX_POINTS = 259,
     CROCHET_OUVRANT = 260,
     CROCHET_FERMANT = 261,
     VIRGULE = 262,
     POINT = 263,
     PARENTHESE_OUVRANTE = 264,
     PARENTHESE_FERMANTE = 265,
     ACCOLADE_OUVRANTE = 266,
     ACCOLADE_FERMANTE = 267,
     CSTE_ENTIERE = 268,
     CSTE_REEL = 269,
     CSTE_STRING = 270,
     CSTE_CHAR = 271,
     CSTE_BOOL = 272,
     ENTIER = 273,
     REEL = 274,
     BOOLEEN = 275,
     CARACTERE = 276,
     CHAINE = 277,
     PLUS_PETIT = 278,
     PLUS_GRAND = 279,
     ET = 280,
     OU = 281,
     PLUS_PETIT_EGAL = 282,
     PLUS_GRAND_EGAL = 283,
     EGAL = 284,
     DIFFERENT = 285,
     PLUS = 286,
     MOINS = 287,
     MULT = 288,
     DIV = 289,
     TANT_QUE = 290,
     FAIRE = 291,
     SI = 292,
     ALORS = 293,
     SINON = 294,
     VARIABLE = 295,
     TYPE = 296,
     STRUCT = 297,
     FSTRUCT = 298,
     TABLEAU = 299,
     DE = 300,
     PROCEDURE = 301,
     FONCTION = 302,
     RETOURNE = 303,
     OPAFF = 304,
     PROG = 305,
     DEBUT = 306,
     FIN = 307,
     IDF = 308
   };
#endif
/* Tokens.  */
#define POINT_VIRGULE 258
#define DEUX_POINTS 259
#define CROCHET_OUVRANT 260
#define CROCHET_FERMANT 261
#define VIRGULE 262
#define POINT 263
#define PARENTHESE_OUVRANTE 264
#define PARENTHESE_FERMANTE 265
#define ACCOLADE_OUVRANTE 266
#define ACCOLADE_FERMANTE 267
#define CSTE_ENTIERE 268
#define CSTE_REEL 269
#define CSTE_STRING 270
#define CSTE_CHAR 271
#define CSTE_BOOL 272
#define ENTIER 273
#define REEL 274
#define BOOLEEN 275
#define CARACTERE 276
#define CHAINE 277
#define PLUS_PETIT 278
#define PLUS_GRAND 279
#define ET 280
#define OU 281
#define PLUS_PETIT_EGAL 282
#define PLUS_GRAND_EGAL 283
#define EGAL 284
#define DIFFERENT 285
#define PLUS 286
#define MOINS 287
#define MULT 288
#define DIV 289
#define TANT_QUE 290
#define FAIRE 291
#define SI 292
#define ALORS 293
#define SINON 294
#define VARIABLE 295
#define TYPE 296
#define STRUCT 297
#define FSTRUCT 298
#define TABLEAU 299
#define DE 300
#define PROCEDURE 301
#define FONCTION 302
#define RETOURNE 303
#define OPAFF 304
#define PROG 305
#define DEBUT 306
#define FIN 307
#define IDF 308




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "gram.y"
{
   arbre type1;
   int type2;
}
/* Line 1529 of yacc.c.  */
#line 160 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

