%{
#include <stdio.h>
#include "arbre.h"
#include "tablexico.h"
#include "y.tab.h"
int nbLignes = 0;

%}

%%

PROG {printf(yytext);return (PROG);}
, {printf(yytext);return (VIRGULE);}
: {printf(yytext);return (DEUX_POINTS);}
\. {printf(yytext);return (POINT);}
\[ {printf(yytext);return (CROCHET_OUVRANT);}
\] {printf(yytext);return (CROCHET_FERMANT);}
\{ {printf(yytext);return (ACCOLADE_OUVRANTE);}
\} {printf(yytext);return (ACCOLADE_FERMANTE);}
\( {printf(yytext);return (PARENTHESE_OUVRANTE);}
\) {printf(yytext);return (PARENTHESE_FERMANTE);}
= {printf(yytext);return (OPAFF);}
; {printf(yytext);return (POINT_VIRGULE);}

\+ {printf(yytext);return (PLUS);}
- {printf(yytext);return (MOINS);}
\* {printf(yytext);return (MULT);}
\/ {printf(yytext);return (DIV);}

\< {printf(yytext);return (PLUS_PETIT);}
\> {printf(yytext);return (PLUS_GRAND);}
\<= {printf(yytext);return (PLUS_PETIT_EGAL);}
\>= {printf(yytext);return (PLUS_GRAND_EGAL);}
== {printf(yytext);return (EGAL);}
!= {printf(yytext);return (DIFFERENT);}
&& {printf(yytext);return (ET);}
\|\| {printf(yytext);return (OU);}

true|false {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CSTE_BOOL);}

Main {printf(yytext);return (DEBUT);}
EndMain {printf(yytext);return (FIN);}

var {printf(yytext);return (VARIABLE);}
type {printf(yytext);return (TYPE);}

int {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (ENTIER);}
float {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (REEL);}
bool {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (BOOLEEN);}
char {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CARACTERE);}
string {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CHAINE);}

tab {printf(yytext);return (TABLEAU);}
of {printf(yytext);return (DE);}
Struct {printf(yytext);return (STRUCT);}
EndStruct {printf(yytext);return (FSTRUCT);}
procedure {printf(yytext);return (PROCEDURE);}
function {printf(yytext);return (FONCTION);}
printf(yytext);return {printf(yytext);return (RETOURNE);}

if {printf(yytext);return (SI);}
then {printf(yytext);return (ALORS);}
else {printf(yytext);return (SINON);}

while {printf(yytext);return (TANT_QUE);}
do {printf(yytext);return (FAIRE);}

\"[a-zA-Z0-9 ]*\" {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CSTE_STRING);}
\'[a-zA-Z0-9 ]\' {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CSTE_CHAR);}
[a-zA-Z][a-zA-Z0-9]* {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (IDF);}
[1-9][0-9]* {yylval.type2=atoi(yytext);printf(yytext);return (CSTE_ENTIERE);}
[0-9]+\.[0-9]+ {yylval.type2=add_lexeme_char(yytext);printf(yytext);return (CSTE_REEL);}

\n {nbLignes++;}

%%

