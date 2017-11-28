%{
#include <stdio.h>
#include "arbre.h"
#include "tablexico.h"
#include "y.tab.h"
int nbLignes = 0;

%}

%%

PROG {printf("%s\n",yytext);return (PROG);}
, {printf("%s\n",yytext);return (VIRGULE);}
: {printf("%s\n",yytext);return (DEUX_POINTS);}
\. {printf("%s\n",yytext);return (POINT);}
\[ {printf("%s\n",yytext);return (CROCHET_OUVRANT);}
\] {printf("%s\n",yytext);return (CROCHET_FERMANT);}
\{ {printf("%s\n",yytext);return (ACCOLADE_OUVRANTE);}
\} {printf("%s\n",yytext);return (ACCOLADE_FERMANTE);}
\( {printf("%s\n",yytext);return (PARENTHESE_OUVRANTE);}
\) {printf("%s\n",yytext);return (PARENTHESE_FERMANTE);}
= {printf("%s\n",yytext);return (OPAFF);}
; {printf("%s\n",yytext);return (POINT_VIRGULE);}

\+ {printf("%s\n",yytext);return (PLUS);}
- {printf("%s\n",yytext);return (MOINS);}
\* {printf("%s\n",yytext);return (MULT);}
\/ {printf("%s\n",yytext);return (DIV);}

\< {printf("%s\n",yytext);return (PLUS_PETIT);}
\> {printf("%s\n",yytext);return (PLUS_GRAND);}
\<= {printf("%s\n",yytext);return (PLUS_PETIT_EGAL);}
\>= {printf("%s\n",yytext);return (PLUS_GRAND_EGAL);}
== {printf("%s\n",yytext);return (EGAL);}
!= {printf("%s\n",yytext);return (DIFFERENT);}
&& {printf("%s\n",yytext);return (ET);}
\|\| {printf("%s\n",yytext);return (OU);}

true|false {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CSTE_BOOL);}

Main {printf("%s\n",yytext);return (DEBUT);}
EndMain {printf("%s\n",yytext);return (FIN);}

var {printf("%s\n",yytext);return (VARIABLE);}
type {printf("%s\n",yytext);return (TYPE);}

int {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (ENTIER);}
float {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (REEL);}
bool {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (BOOLEEN);}
char {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CARACTERE);}
string {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CHAINE);}

tab {printf("%s\n",yytext);return (TABLEAU);}
of {printf("%s\n",yytext);return (DE);}
Struct {printf("%s\n",yytext);return (STRUCT);}
EndStruct {printf("%s\n",yytext);return (FSTRUCT);}
procedure {printf("%s\n",yytext);return (PROCEDURE);}
function {printf("%s\n",yytext);return (FONCTION);}
printf("%s\n",yytext);return {printf("%s\n",yytext);return (RETOURNE);}

if {printf("%s\n",yytext);return (SI);}
then {printf("%s\n",yytext);return (ALORS);}
else {printf("%s\n",yytext);return (SINON);}

while {printf("%s\n",yytext);return (TANT_QUE);}
do {printf("%s\n",yytext);return (FAIRE);}

\"[a-zA-Z0-9 ]*\" {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CSTE_STRING);}
\'[a-zA-Z0-9 ]\' {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CSTE_CHAR);}
[a-zA-Z][a-zA-Z0-9]* {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (IDF);}
[1-9][0-9]* {yylval.type2=atoi(yytext);printf("%s\n",yytext);return (CSTE_ENTIERE);}
[0-9]+\.[0-9]+ {yylval.type2=add_lexeme_char(yytext);printf("%s\n",yytext);return (CSTE_REEL);}

\n {nbLignes++;}

%%

