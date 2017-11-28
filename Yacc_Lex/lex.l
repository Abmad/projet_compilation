%{
#include <stdio.h>
#include "arbre.h"
#include "tablexico.h"
#include "y.tab.h"
int nbLignes = 0;

%}

%%

PROG {return (PROG);}
, {return (VIRGULE);}
: {return (DEUX_POINTS);}
\. {return (POINT);}
\[ {return (CROCHET_OUVRANT);}
\] {return (CROCHET_FERMANT);}
\{ {return (ACCOLADE_OUVRANTE);}
\} {return (ACCOLADE_FERMANTE);}
\( {return (PARENTHESE_OUVRANTE);}
\) {return (PARENTHESE_FERMANTE);}
= {return (OPAFF);}
; {return (POINT_VIRGULE);}

\+ {return (PLUS);}
- {return (MOINS);}
\* {return (MULT);}
\/ {return (DIV);}

\< {return (PLUS_PETIT);}
\> {return (PLUS_GRAND);}
\<= {return (PLUS_PETIT_EGAL);}
\>= {return (PLUS_GRAND_EGAL);}
== {return (EGAL);}
!= {return (DIFFERENT);}
&& {return (ET);}
\|\| {return (OU);}

true|false {yylval.type2=add_lexeme_char(yytext);return (CSTE_BOOL);}

Main {return (DEBUT);}
EndMain {return (FIN);}

var {return (VARIABLE);}
type {return (TYPE);}

int {yylval.type2=add_lexeme_char(yytext);return (ENTIER);}
float {yylval.type2=add_lexeme_char(yytext);return (REEL);}
bool {yylval.type2=add_lexeme_char(yytext);return (BOOLEEN);}
char {yylval.type2=add_lexeme_char(yytext);return (CARACTERE);}
string {yylval.type2=add_lexeme_char(yytext);return (CHAINE);}

tab {return (TABLEAU);}
of {return (DE);}
Struct {return (STRUCT);}
EndStruct {return (FSTRUCT);}
procedure {return (PROCEDURE);}
function {return (FONCTION);}
return {return (RETOURNE);}

if {return (SI);}
then {return (ALORS);}
else {return (SINON);}

while {return (TANT_QUE);}
do {return (FAIRE);}

\"[a-zA-Z0-9 ]*\" {yylval.type2=add_lexeme_char(yytext);return (CSTE_STRING);}
\'[a-zA-Z0-9 ]\' {yylval.type2=add_lexeme_char(yytext);return (CSTE_CHAR);}
[a-zA-Z][a-zA-Z0-9]* {yylval.type2=add_lexeme_char(yytext);return (IDF);}
[1-9][0-9]* {yylval.type2=atoi(yytext);return (CSTE_ENTIERE);}
[0-9]+\.[0-9]+ {yylval.type2=add_lexeme_char(yytext);return (CSTE_REEL);}

\n {nbLignes++;}

%%

