%{
  #include <stdio.h>
  #include "arbre.h"
  #include "tablexico.h"
  extern int numligne;
  extern char* yytext;
  extern int yylex() ;
  int yyerror() ;
%}
%union{
arbre typ1;
int typ2;
}
%token PLUS MOINS MULT DIV
%token PO PF
%token<type2>CSTE_ENTIERE
%type<type1> e1 e2 e
%%
e: e PLUS e1 {printf("+");}
 | e MOINS e1 {printf("-");}
 | e1
 ;
e1: e1 MULT e2 {printf("*");}
  | e1 DIV e2 {printf("/");concat_pere_fils(creer_noeud(C_DIV,-900),concat_pere_frere($1,$3));}
  | e2 {$$=$1;}
  ;
e2: PO e PF { $$=$1 ;}
  | c 
 ;
c : CSTE_ENTIERE {$$=creer_noeud(C_CSTE_ENTIERE,$1);}
%%
int yyerror()
{
  printf("Erreur de syntax en ligne %d\n",numligne);
}
int main(){ init_tab_lex(); yyparse(); }
