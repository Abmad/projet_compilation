%{
#include "y.tab.h"
#include <stdio.h>
int nbLignes = 0;
%}

%%

PROG {printf("%s", yytext);return (PROG);}
, {printf("%s", yytext);return (VIRGULE);}
: {printf("%s", yytext);return (DEUX_POINTS);}
\. {printf("%s", yytext);return (POINT);}
\[ {printf("%s", yytext);return (CROCHET_OUVRANT);}
\] {printf("%s", yytext);return (CROCHET_FERMANT);}
\{ {printf("%s", yytext);return (ACCOLADE_OUVRANTE);}
\} {printf("%s", yytext);return (ACCOLADE_FERMANTE);}
\( {printf("%s", yytext);return (PARENTHESE_OUVRANTE);}
\) {printf("%s", yytext);return (PARENTHESE_FERMANTE);}
= {printf("%s", yytext);return (OPAFF);}
; {printf("%s", yytext);return (POINT_VIRGULE);}

\+ {printf("%s", yytext);return (PLUS);}
- {printf("%s", yytext);return (MOINS);}
\* {printf("%s", yytext);return (MULT);}
\/ {printf("%s", yytext);return (DIV);}

\< {printf("%s", yytext);return (PLUS_PETIT);}
\> {printf("%s", yytext);return (PLUS_GRAND);}
\<= {printf("%s", yytext);return (PLUS_PETIT_EGAL);}
\>= {printf("%s", yytext);return (PLUS_GRAND_EGAL);}
== {printf("%s", yytext);return (EGAL);}
!= {printf("%s", yytext);return (DIFFERENT);}
&& {printf("%s", yytext);return (ET);}
\|\| {printf("%s", yytext);return (OU);}

true|false {printf("%s", yytext);return (CSTE_BOOL);}

Main {printf("%s", yytext);return (DEBUT);}
EndMain {printf("%s", yytext);return (FIN);}

var {printf("%s", yytext);return (VARIABLE);}
type {printf("%s", yytext);return (TYPE);}

int {printf("%s", yytext);return (ENTIER);}
float {printf("%s", yytext);return (REEL);}
bool {printf("%s", yytext);return (BOOLEEN);}
char {printf("%s", yytext);return (CARACTERE);}
string {printf("%s", yytext);return (CHAINE);}

tab {printf("%s", yytext);return (TABLEAU);}
of {printf("%s", yytext);return (DE);}
Struct {printf("%s", yytext);return (STRUCT);}
EndStruct {printf("%s", yytext);return (FSTRUCT);}
procedure {printf("%s", yytext);return (PROCEDURE);}
function {printf("%s", yytext);return (FONCTION);}
return {printf("%s", yytext);return (RETOURNE);}

if {printf("%s", yytext);return (SI);}
then {printf("%s", yytext);return (ALORS);}
else {printf("%s", yytext);return (SINON);}

while {printf("%s", yytext);return (TANT_QUE);}
do {printf("%s", yytext);return (FAIRE);}

\"[a-zA-Z0-9 ]*\" {printf("%s", yytext);return (CSTE_STRING);}
\'[a-zA-Z0-9 ]\' {printf("%s", yytext);return (CSTE_CHAR);}
[a-zA-Z][a-zA-Z0-9]* {printf("%s", yytext);return (IDF);}
[1-9][0-9]* {printf("%s", yytext);return (CSTE_ENTIERE);}
[0-9]+\.[0-9]+ {printf("%s", yytext);return (CSTE_REEL);}

\n {printf("%s", yytext);nbLignes++;}

%%
int yyerror()
{
	printf("\nerreur de syntaxe %i\n", nbLignes);
}

