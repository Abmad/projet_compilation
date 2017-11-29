/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "Yacc_Lex/gram.y"
#include<stdio.h>
#include "./Arbre/arbre.h"
#include "./Table_lexico/tablexico.h"
extern int nbLignes;
extern char* yytext;
extern int yylex() ;
int yyerror() ;
arbre type1;
#line 12 "Yacc_Lex/gram.y"
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
#line 42 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   23,   24,   25,   25,   25,   26,   26,   26,   27,
   27,   27,   28,   28,   28,    1,    2,    2,    2,   30,
   33,   33,   35,   37,   37,   38,   34,   34,   39,   36,
   36,   40,   40,   40,   40,   40,   29,   29,   31,   32,
   41,   42,   42,   42,   43,    3,    3,    3,    3,    3,
    3,    4,    4,    5,    6,    6,    7,    7,    8,    9,
   10,   11,   12,   13,   13,   14,   15,   15,   16,   16,
   17,   17,   17,   18,   18,   18,   19,   19,   19,   19,
   20,   20,   21,   21,   21,   21,   21,   22,   22,   22,
   22,   22,   22,   22,   22,
};
static const YYINT yylen[] = {                            2,
    4,    2,    4,    0,    1,    3,    0,    1,    3,    0,
    1,    3,    0,    1,    3,    3,    0,    1,    3,    4,
    3,    4,    3,    1,    3,    4,    1,    2,    4,    1,
    1,    1,    1,    1,    1,    4,    4,    6,    6,    8,
    3,    0,    1,    3,    3,    1,    1,    1,    1,    1,
    2,    0,    1,    2,    2,    3,    1,    3,    1,   12,
    8,    8,    3,    1,    2,    4,    0,    1,    1,    3,
    3,    3,    1,    3,    3,    1,    3,    1,    1,    1,
    3,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    0,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   18,   50,   47,   48,   49,   46,    0,
    0,    0,    0,    0,    0,    6,   32,   33,   34,   35,
    0,   31,    0,   30,    0,    0,    0,    0,   83,   84,
   85,   86,   87,   51,   80,   79,    0,    0,    0,   76,
   78,    0,    0,   54,   65,    0,   16,    0,    0,    0,
    0,    3,    0,    0,    9,    0,    0,    0,    0,    0,
    0,   88,   89,   90,   91,   92,   93,   94,   95,    0,
    0,    0,    0,    0,    0,    0,   55,    0,   57,    0,
   19,    0,    0,    0,   20,    0,    0,    0,    0,   12,
    0,    0,    0,    0,    0,   77,    0,    0,    0,   74,
   75,    0,    0,    0,   56,    0,    0,   27,    0,    0,
    0,    0,   43,    0,    0,   15,   36,    0,    0,    0,
   68,   66,    0,   58,    0,   21,   28,    0,    0,   24,
    0,    0,    0,   41,    0,    0,    0,    0,    0,    0,
    0,   23,    0,   22,   45,   44,   39,    0,    0,    0,
    0,   29,    0,   25,    0,   61,   62,    0,    0,    0,
    0,   40,    0,    0,   60,
};
static const YYINT yydgoto[] = {                          2,
   12,   23,   24,   54,   55,   64,   98,   99,   26,   27,
   28,   29,   56,   65,  142,  100,   58,   59,   60,   96,
   61,   90,    5,    6,    7,   14,   33,   72,    8,   15,
   34,   73,  105,  127,  130,   43,  149,  150,  128,   44,
  107,  132,  133,
};
static const YYINT yysindex[] = {                      -228,
 -187,    0, -213, -212, -173, -207, -170, -112, -110,    0,
   -2,    0, -129, -147,  -71, -213, -255,  -64,  -50,  -24,
   23, -214, -253,    0,    0,    0,    0,    0,    0,  -69,
  -18,  -62,  -44,   -1, -170,    0,    0,    0,    0,    0,
    5,    0,  -43,    0,   23, -207,   23,   23,    0,    0,
    0,    0,    0,    0,    0,    0,   76, -181, -164,    0,
    0,   23, -256,    0,    0,   -2,    0,   23, -223,   -4,
  -40,    0,   11, -147,    0,    2,   23,   31,    4,   39,
   60,    0,    0,    0,    0,    0,    0,    0,    0,   23,
   23,   23,   23,   23,   76,  -91,    0, -232,    0,   76,
    0,   76,  -34,   15,    0,  -32,   32,   -4,  -44,    0,
   38,   76,    9,   42,   12,    0, -181, -164, -164,    0,
    0,   74,   23,   23,    0,   77, -208,    0,   23,   35,
   78, -167,    0, -213,   59,    0,    0,   97,  100,   99,
    0,    0,   76,    0, -255,    0,    0, -162,  -53,    0,
 -255,   53,  -32,    0,  101,   53, -207,   23, -207,  108,
  104,    0,   23,    0,    0,    0,    0,  103,  105,   68,
  106,    0,   23,    0, -213,    0,    0,   80,   76,  109,
  111,    0, -207,  112,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0, -270,    0,    0,    0, -154, -267,    0,    0,
 -252,    0,    0, -198, -124, -270,    0,    0,    0,    0,
 -251, -218,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   64, -118, -154,    0,    0,    0,    0,    0,
    0,    0, -221,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -235,  -29, -151,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   65, -198,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -51,    0,    0,    0,    0, -224,
    0, -234,    0,    0,    0, -163,    0,    0,   64,    0,
    0, -209,    0,    0,    0,    0,    1,  -89,  -59,    0,
    0, -121,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -270,    0,    0,    0,    0,    0,    0,
    0,    0,  -47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -270,    0,    0,    0,  -31,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -45,    0,  308,    0,   -9,    0,    0,  253,    0,    0,
    0,    0,   -8,  257,    0,  -21,  290,  146,  150,    0,
    0,    0, -125,    0,  365,  347,  309,  275,    0,    0,
    0,    0,    0,    0,    0, -135,    0,  222,  259,   48,
  279,    0,  235,
};
#define YYTABLESIZE 388
static const YYINT yytable[] = {                         57,
   79,   25,   30,   66,   17,   52,   48,   97,  155,  160,
   49,   50,   51,   52,   53,  164,   37,   38,   39,   40,
   41,   53,   63,   78,    4,   80,   81,    5,  124,    4,
    4,  125,    5,    5,    4,   37,   59,    5,   64,   59,
   95,   64,   64,   64,   62,   64,  102,   38,   63,  180,
   22,   42,   67,   17,   52,  112,   25,   30,   64,   64,
   64,   64,   64,   64,   64,   64,   64,   64,   64,   64,
   53,   63,  103,   37,  104,    1,   64,    3,   37,   37,
    4,   64,   64,   37,   64,   38,   64,   64,  146,  153,
   38,   38,   10,   42,    9,   38,  154,   11,  126,  161,
   42,  143,   10,   91,   92,   73,   10,  148,   73,   73,
   73,  169,   73,  171,   82,   83,   84,   85,   86,   87,
   88,   89,   93,   94,   13,   73,   73,   73,   73,   73,
   73,   73,   73,   73,   73,   67,  170,  184,   67,   67,
   67,  148,   67,   73,   16,    7,    7,   17,   73,   73,
    7,  179,   32,   73,   73,   67,   67,   67,   67,   67,
   67,   67,   67,   67,   67,   67,   67,   71,  122,  123,
   71,   71,   71,   67,   71,    8,    8,   31,   67,   67,
    8,   67,   11,   67,   67,   35,   11,   71,   71,   71,
   71,   71,   71,   71,   71,   71,   71,   72,   45,  165,
   72,   72,   72,  168,   72,   71,  162,  163,   82,   82,
   71,   71,   81,   81,   46,   71,   71,   72,   72,   72,
   72,   72,   72,   72,   72,   72,   72,   69,   26,   26,
   69,   69,   69,   68,   69,   72,  118,  119,   47,   69,
   72,   72,  120,  121,   70,   72,   72,   69,   69,   69,
   69,   69,   69,   69,   69,   74,   71,   70,  106,   77,
   70,   70,   70,   76,   70,   69,  108,  109,  111,  114,
   69,   69,  126,  129,  131,   69,   69,   70,   70,   70,
   70,   70,   70,   70,   70,   48,   18,   19,   20,   49,
   50,   51,   52,   53,  113,   70,  134,  137,  138,   21,
   70,   70,  115,  140,   22,   70,   70,   82,   83,   84,
   85,   86,   87,   88,   89,   82,   83,   84,   85,   86,
   87,   88,   89,  116,   37,   38,   39,   40,   41,   22,
  139,  177,   62,  151,  145,  152,   82,   83,   84,   85,
   86,   87,   88,   89,   82,   83,   84,   85,   86,   87,
   88,   89,   82,   83,   84,   85,   86,   87,   88,   89,
  156,  157,  158,  159,  172,  173,  167,  175,   13,   14,
  176,  178,  181,  101,  182,  183,  144,  185,  141,  117,
   36,   75,  110,  136,  174,  147,  135,  166,
};
static const YYINT yycheck[] = {                         21,
   46,   11,   11,  257,  257,  257,  263,  264,  134,  145,
  267,  268,  269,  270,  271,  151,  272,  273,  274,  275,
  276,  257,  257,   45,  295,   47,   48,  295,  261,  300,
  301,  264,  300,  301,  305,  257,  261,  305,  257,  264,
   62,  260,  261,  262,  259,  264,   68,  257,  263,  175,
  307,  307,  306,  306,  306,   77,   66,   66,  277,  278,
  279,  280,  281,  282,  283,  284,  285,  286,  287,  288,
  306,  306,  296,  295,  298,  304,  295,  265,  300,  301,
  294,  300,  301,  305,  303,  295,  305,  306,  297,  257,
  300,  301,  266,  257,  307,  305,  264,  305,  307,  262,
  264,  123,  301,  285,  286,  257,  305,  129,  260,  261,
  262,  157,  264,  159,  277,  278,  279,  280,  281,  282,
  283,  284,  287,  288,  295,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  257,  158,  183,  260,  261,
  262,  163,  264,  295,  257,  300,  301,  258,  300,  301,
  305,  173,  300,  305,  306,  277,  278,  279,  280,  281,
  282,  283,  284,  285,  286,  287,  288,  257,  260,  261,
  260,  261,  262,  295,  264,  300,  301,  307,  300,  301,
  305,  303,  301,  305,  306,  257,  305,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  257,  263,  152,
  260,  261,  262,  156,  264,  295,  260,  261,  260,  261,
  300,  301,  260,  261,  265,  305,  306,  277,  278,  279,
  280,  281,  282,  283,  284,  285,  286,  257,  260,  261,
  260,  261,  262,  303,  264,  295,   91,   92,  263,  258,
  300,  301,   93,   94,  307,  305,  306,  277,  278,  279,
  280,  281,  282,  283,  284,  257,  301,  257,  263,  303,
  260,  261,  262,  259,  264,  295,  307,  257,  267,  266,
  300,  301,  307,  259,  307,  305,  306,  277,  278,  279,
  280,  281,  282,  283,  284,  263,  289,  290,  291,  267,
  268,  269,  270,  271,  264,  295,  265,  260,  290,  302,
  300,  301,  264,  292,  307,  305,  306,  277,  278,  279,
  280,  281,  282,  283,  284,  277,  278,  279,  280,  281,
  282,  283,  284,  264,  272,  273,  274,  275,  276,  307,
  289,  264,  259,  299,  258,  258,  277,  278,  279,  280,
  281,  282,  283,  284,  277,  278,  279,  280,  281,  282,
  283,  284,  277,  278,  279,  280,  281,  282,  283,  284,
  302,  265,  263,  265,  257,  262,  266,  265,  305,  305,
  266,  266,  293,   66,  266,  265,  124,  266,  122,   90,
   16,   35,   74,  109,  163,  127,  108,  153,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 353
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"POINT_VIRGULE","DEUX_POINTS",
"CROCHET_OUVRANT","CROCHET_FERMANT","VIRGULE","POINT","PARENTHESE_OUVRANTE",
"PARENTHESE_FERMANTE","ACCOLADE_OUVRANTE","ACCOLADE_FERMANTE","CSTE_ENTIERE",
"CSTE_REEL","CSTE_STRING","CSTE_CHAR","CSTE_BOOL","ENTIER","REEL","BOOLEEN",
"CARACTERE","CHAINE","PLUS_PETIT","PLUS_GRAND","ET","OU","PLUS_PETIT_EGAL",
"PLUS_GRAND_EGAL","EGAL","DIFFERENT","PLUS","MOINS","MULT","DIV","TANT_QUE",
"FAIRE","SI","ALORS","SINON","VARIABLE","TYPE","STRUCT","FSTRUCT","TABLEAU",
"DE","PROCEDURE","FONCTION","RETOURNE","OPAFF","PROG","DEBUT","FIN","IDF",0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programme",
"programme : PROG ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE",
"corps : liste_declarations liste_instructions",
"liste_declarations : liste_declaration_var liste_declaration_type liste_declaration_proc liste_declaration_fct",
"liste_declaration_var :",
"liste_declaration_var : declaration_variable",
"liste_declaration_var : declaration_variable POINT_VIRGULE liste_declaration_var",
"liste_declaration_type :",
"liste_declaration_type : declaration_type",
"liste_declaration_type : declaration_type POINT_VIRGULE liste_declaration_type",
"liste_declaration_proc :",
"liste_declaration_proc : declaration_procedure",
"liste_declaration_proc : declaration_procedure POINT_VIRGULE liste_declaration_proc",
"liste_declaration_fct :",
"liste_declaration_fct : declaration_fonction",
"liste_declaration_fct : declaration_fonction POINT_VIRGULE liste_declaration_fct",
"liste_instructions : DEBUT suite_liste_inst FIN",
"suite_liste_inst :",
"suite_liste_inst : instruction",
"suite_liste_inst : suite_liste_inst POINT_VIRGULE instruction",
"declaration_type : TYPE IDF DEUX_POINTS suite_declaration_type",
"suite_declaration_type : STRUCT liste_champs FSTRUCT",
"suite_declaration_type : TABLEAU dimension DE nom_type",
"dimension : CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT",
"liste_dimensions : une_dimension",
"liste_dimensions : liste_dimensions VIRGULE une_dimension",
"une_dimension : expression POINT POINT expression",
"liste_champs : un_champ",
"liste_champs : liste_champs un_champ",
"un_champ : IDF DEUX_POINTS nom_type POINT_VIRGULE",
"nom_type : type_simple",
"nom_type : IDF",
"type_simple : ENTIER",
"type_simple : REEL",
"type_simple : BOOLEEN",
"type_simple : CARACTERE",
"type_simple : CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT",
"declaration_variable : VARIABLE IDF DEUX_POINTS nom_type",
"declaration_variable : VARIABLE IDF DEUX_POINTS nom_type OPAFF expression",
"declaration_procedure : PROCEDURE IDF liste_parametres ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE",
"declaration_fonction : FONCTION IDF liste_parametres RETOURNE type_simple ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE",
"liste_parametres : PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE",
"liste_param :",
"liste_param : un_param",
"liste_param : liste_param POINT_VIRGULE un_param",
"un_param : IDF DEUX_POINTS type_simple",
"instruction : affectation",
"instruction : condition",
"instruction : tant_que",
"instruction : repeter_tant_que",
"instruction : appel",
"instruction : RETOURNE resultat_retourne",
"resultat_retourne :",
"resultat_retourne : expression",
"appel : IDF liste_arguments",
"liste_arguments : PARENTHESE_OUVRANTE PARENTHESE_FERMANTE",
"liste_arguments : PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE",
"liste_args : un_arg",
"liste_args : liste_args VIRGULE un_arg",
"un_arg : expression",
"condition : SI PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE ALORS ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE",
"tant_que : TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE",
"repeter_tant_que : FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE",
"affectation : variable OPAFF expression",
"variable : IDF",
"variable : IDF variable_suite",
"variable_suite : CROCHET_OUVRANT liste_expression CROCHET_FERMANT variable_fin",
"variable_fin :",
"variable_fin : variable_suite",
"expression : expression_calcul",
"expression : expression expression_logique expression_calcul",
"expression_calcul : expression_calcul PLUS expression_suite",
"expression_calcul : expression_calcul MOINS expression_suite",
"expression_calcul : expression_suite",
"expression_suite : expression_suite MULT expression_fin",
"expression_suite : expression_suite DIV expression_fin",
"expression_suite : expression_fin",
"expression_fin : PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE",
"expression_fin : constante",
"expression_fin : variable",
"expression_fin : appel",
"liste_expression : liste_expression VIRGULE expression",
"liste_expression : expression",
"constante : CSTE_ENTIERE",
"constante : CSTE_REEL",
"constante : CSTE_STRING",
"constante : CSTE_CHAR",
"constante : CSTE_BOOL",
"expression_logique : PLUS_PETIT",
"expression_logique : PLUS_GRAND",
"expression_logique : ET",
"expression_logique : OU",
"expression_logique : PLUS_PETIT_EGAL",
"expression_logique : PLUS_GRAND_EGAL",
"expression_logique : EGAL",
"expression_logique : DIFFERENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 219 "Yacc_Lex/gram.y"
int yyerror()
{
	printf("\nerreur de syntaxe %i\n", nbLignes);
}
int main(){ //init_tab_lex(); 
yyparse();
afficher_arbre(type1,0);
//affiche_table_lexico(7);
 }
#line 483 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 34 "Yacc_Lex/gram.y"
	{afficher_arbre(yystack.l_mark[-1].type1,0);}
break;
case 2:
#line 37 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 16:
#line 64 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[-1].type1;}
break;
case 17:
#line 67 "Yacc_Lex/gram.y"
	{yyval.type1=arbre_vide();}
break;
case 18:
#line 68 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 19:
#line 69 "Yacc_Lex/gram.y"
	{yyval.type1= concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1);}
break;
case 46:
#line 128 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 47:
#line 129 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 48:
#line 130 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 49:
#line 131 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 50:
#line 132 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 51:
#line 133 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 52:
#line 136 "Yacc_Lex/gram.y"
	{yyval.type1=arbre_vide();}
break;
case 53:
#line 137 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 54:
#line 140 "Yacc_Lex/gram.y"
	{yyval.type1= concat_pere_fils(creer_noeud(C_IDF,yystack.l_mark[-1].type2),yystack.l_mark[0].type1);}
break;
case 55:
#line 143 "Yacc_Lex/gram.y"
	{yyval.type1=arbre_vide();}
break;
case 56:
#line 144 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[-1].type1;}
break;
case 57:
#line 147 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 58:
#line 148 "Yacc_Lex/gram.y"
	{yyval.type1= concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1);}
break;
case 59:
#line 151 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 60:
#line 154 "Yacc_Lex/gram.y"
	{yyval.type1= concat_pere_frere (concat_pere_fils(creer_noeud(C_SI,-979),concat_pere_frere(yystack.l_mark[-9].type1,yystack.l_mark[-5].type1)),concat_pere_fils(creer_noeud(C_SINON,-976),yystack.l_mark[-1].type1));}
break;
case 61:
#line 157 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_TANT_QUE,-987),concat_pere_frere(yystack.l_mark[-5].type1,yystack.l_mark[-1].type1));}
break;
case 62:
#line 160 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_FAIRE,-976),concat_pere_frere(yystack.l_mark[-5].type1,yystack.l_mark[-1].type1));}
break;
case 63:
#line 163 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_OPAFF,-980),concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1));}
break;
case 64:
#line 166 "Yacc_Lex/gram.y"
	{yyval.type1= creer_noeud(C_IDF,yystack.l_mark[0].type2);}
break;
case 65:
#line 167 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_frere(creer_noeud(C_IDF,yystack.l_mark[-1].type2),yystack.l_mark[0].type1);}
break;
case 66:
#line 170 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1);}
break;
case 67:
#line 173 "Yacc_Lex/gram.y"
	{yyval.type1=arbre_vide();}
break;
case 68:
#line 174 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 69:
#line 177 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 70:
#line 178 "Yacc_Lex/gram.y"
	{yyval.type1= concat_pere_frere(yystack.l_mark[-2].type1,concat_pere_frere(yystack.l_mark[-1].type1,yystack.l_mark[0].type1));}
break;
case 71:
#line 181 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_PLUS,-990),concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1));}
break;
case 72:
#line 182 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_MOINS,-991),concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1));}
break;
case 73:
#line 183 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 74:
#line 186 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_MULT,-989),concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1));}
break;
case 75:
#line 187 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_fils(creer_noeud(C_DIV,-988),concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1));}
break;
case 76:
#line 188 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 77:
#line 191 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[-1].type1;}
break;
case 78:
#line 192 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 79:
#line 193 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 80:
#line 194 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 81:
#line 197 "Yacc_Lex/gram.y"
	{yyval.type1=concat_pere_frere(yystack.l_mark[-2].type1,yystack.l_mark[0].type1);}
break;
case 82:
#line 198 "Yacc_Lex/gram.y"
	{yyval.type1=yystack.l_mark[0].type1;}
break;
case 83:
#line 201 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_CSTE_ENTIERE, yystack.l_mark[0].type2);}
break;
case 84:
#line 202 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_CSTE_REEL, yystack.l_mark[0].type2);}
break;
case 85:
#line 203 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_CSTE_STRING, yystack.l_mark[0].type2);}
break;
case 86:
#line 204 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_CSTE_CHAR, yystack.l_mark[0].type2);}
break;
case 87:
#line 205 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_CSTE_BOOL, yystack.l_mark[0].type2);}
break;
case 88:
#line 208 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_PLUS_PETIT,-992);}
break;
case 89:
#line 209 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_PLUS_GRAND,-993);}
break;
case 90:
#line 210 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(ET,-994);}
break;
case 91:
#line 211 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(OU,-995);}
break;
case 92:
#line 212 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_PLUS_PETIT_EGAL,-996);}
break;
case 93:
#line 213 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_PLUS_GRAND_EGAL,-997);}
break;
case 94:
#line 214 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_EGAL,-998);}
break;
case 95:
#line 215 "Yacc_Lex/gram.y"
	{yyval.type1=creer_noeud(C_DIFFERENT,-999);}
break;
#line 909 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
