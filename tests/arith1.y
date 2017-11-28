%{
  #include <stdio.h>
  extern int numligne;
  extern char* yytext;
  extern int yylex() ;
  int yyerror() ;
%}
%token PLUS MOINS MULT DIV
%token PO PF
%token CSTE_ENTIERE
%%
e: e PLUS e1 {printf("+");}
 | e MOINS e1 {printf("-");}
 | e1
 ;
e1: e1 MULT e2 {printf("*");}
  | e1 DIV e2 {printf("/");}
  | e2
  ;
e2: PO e PF
  | CSTE_ENTIERE {printf("%s",yytext);}
  ;
%%
int yyerror()
{
  printf("Erreur de syntax en ligne %d\n",numligne);
}
