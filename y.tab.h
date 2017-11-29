#define POINT_VIRGULE 257
#define DEUX_POINTS 258
#define CROCHET_OUVRANT 259
#define CROCHET_FERMANT 260
#define VIRGULE 261
#define POINT 262
#define PARENTHESE_OUVRANTE 263
#define PARENTHESE_FERMANTE 264
#define ACCOLADE_OUVRANTE 265
#define ACCOLADE_FERMANTE 266
#define CSTE_ENTIERE 267
#define CSTE_REEL 268
#define CSTE_STRING 269
#define CSTE_CHAR 270
#define CSTE_BOOL 271
#define ENTIER 272
#define REEL 273
#define BOOLEEN 274
#define CARACTERE 275
#define CHAINE 276
#define PLUS_PETIT 277
#define PLUS_GRAND 278
#define ET 279
#define OU 280
#define PLUS_PETIT_EGAL 281
#define PLUS_GRAND_EGAL 282
#define EGAL 283
#define DIFFERENT 284
#define PLUS 285
#define MOINS 286
#define MULT 287
#define DIV 288
#define TANT_QUE 289
#define FAIRE 290
#define SI 291
#define ALORS 292
#define SINON 293
#define VARIABLE 294
#define TYPE 295
#define STRUCT 296
#define FSTRUCT 297
#define TABLEAU 298
#define DE 299
#define PROCEDURE 300
#define FONCTION 301
#define RETOURNE 302
#define OPAFF 303
#define PROG 304
#define DEBUT 305
#define FIN 306
#define IDF 307
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
   arbre type1;
   int type2;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
