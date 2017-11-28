%{
#include<stdio.h>
#include "arbre.h"
#include "tablexico.h"
extern int nbLignes;
extern char* yytext;
extern int yylex() ;
int yyerror() ;
%}

%union{
arbre type1;
int type2;
}
%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token<type2> CSTE_ENTIERE CSTE_REEL CSTE_STRING CSTE_CHAR CSTE_BOOL
%token<type2> ENTIER REEL BOOLEEN CARACTERE CHAINE
%token PLUS_PETIT PLUS_GRAND ET OU PLUS_PETIT_EGAL PLUS_GRAND_EGAL EGAL DIFFERENT
%token PLUS MOINS MULT DIV
%token TANT_QUE FAIRE SI ALORS SINON
%token VARIABLE TYPE
%token STRUCT FSTRUCT TABLEAU DE
%token PROCEDURE FONCTION RETOURNE
%token OPAFF
%token PROG DEBUT FIN
%token<type2> IDF

%type<type1> liste_instructions suite_liste_inst instruction resultat_retourne appel liste_arguments liste_args un_arg condition tant_que repeter_tant_que affectation variable variable_suite variable_fin expression expression_calcul expression_suite expression_fin liste_expression constante expression_logique corps



%%
programme             : PROG ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE {afficher_arbre($3,0);}
                      ;

corps                 : liste_declarations liste_instructions {$$=$2;}
                      ;

liste_declarations    : liste_declaration_var liste_declaration_type liste_declaration_proc liste_declaration_fct
		      ;


liste_declaration_var :	
		      | declaration_variable
                      | declaration_variable POINT_VIRGULE liste_declaration_var
                      ;

liste_declaration_type : 
		       | declaration_type
                       | declaration_type POINT_VIRGULE liste_declaration_type
                       ;

liste_declaration_proc :	
  		       | declaration_procedure 
                       | declaration_procedure POINT_VIRGULE liste_declaration_proc
                       ;

liste_declaration_fct :
		      | declaration_fonction
                      | declaration_fonction POINT_VIRGULE liste_declaration_fct
                      ;

liste_instructions    : DEBUT suite_liste_inst FIN {$$=$2;}
                      ;

suite_liste_inst      : {$$=arbre_vide();}
                      | instruction {$$=$1;}
                      | suite_liste_inst POINT_VIRGULE instruction {$$= concat_pere_frere($1,$3);}
                      ;

declaration_type      : TYPE IDF DEUX_POINTS suite_declaration_type
                      ;

suite_declaration_type : STRUCT liste_champs FSTRUCT
                       | TABLEAU dimension DE nom_type
                       ;

dimension             : CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
                      ;

liste_dimensions      : une_dimension
                      | liste_dimensions VIRGULE une_dimension
                      ;

une_dimension         : expression POINT POINT expression
                      ;

liste_champs          : un_champ
                      | liste_champs un_champ
                      ;

un_champ              : IDF DEUX_POINTS nom_type POINT_VIRGULE
                      ;

nom_type              : type_simple
                      | IDF
                      ;

type_simple           : ENTIER 
                      | REEL
                      | BOOLEEN
                      | CARACTERE
                      | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
                      ;

declaration_variable  : VARIABLE IDF DEUX_POINTS nom_type
                      | VARIABLE IDF DEUX_POINTS nom_type OPAFF expression
     		      ;

declaration_procedure : PROCEDURE IDF liste_parametres ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE
                      ;

declaration_fonction  : FONCTION IDF liste_parametres RETOURNE type_simple ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE
                      ;

liste_parametres      : PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
                      ;

liste_param           : 
                      | un_param
                      | liste_param POINT_VIRGULE un_param
                      ;

un_param              : IDF DEUX_POINTS type_simple
                      ;

instruction           : affectation {$$=$1;}
                      | condition {$$=$1;}
                      | tant_que {$$=$1;}
                      | repeter_tant_que {$$=$1;}
                      | appel {$$=$1;}
                      | RETOURNE resultat_retourne {$$=$2;}
                      ;

resultat_retourne     : {$$=arbre_vide();}
                      | expression {$$=$1;}
                      ;

appel                 : IDF liste_arguments {$$= concat_pere_fils(creer_noeud(IDF,$1),$2);}
                      ;

liste_arguments       : PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=arbre_vide();}
                      | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
                      ;

liste_args            : un_arg {$$=$1;}
                      | liste_args VIRGULE un_arg {$$= concat_pere_frere($1,$3);}
                      ;

un_arg                : expression {$$=$1;}
                      ;

condition             : SI PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE ALORS ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE {$$= concat_pere_frere (concat_pere_fils(creer_noeud(SI,-979),concat_pere_frere($3,$7)),concat_pere_fils(creer_noeud(SINON,-976),$11));}
                      ;

tant_que              : TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE {$$=concat_pere_fils(creer_noeud(TANT_QUE,-987),concat_pere_frere($3,$7));}
                      ;

repeter_tant_que      : FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE  {$$=concat_pere_fils(creer_noeud(FAIRE,-976),concat_pere_frere($3,$7));}
                      ;

affectation           : variable OPAFF expression {$$=concat_pere_fils(creer_noeud(OPAFF,-980),concat_pere_frere($1,$3));}
                      ;

variable              : IDF {$$= creer_noeud(IDF,$1);}
	 	      | IDF variable_suite {$$=concat_pere_frere(creer_noeud(IDF,$1),$2);}
		      ;

variable_suite        : CROCHET_OUVRANT liste_expression CROCHET_FERMANT variable_fin {$$=concat_pere_frere($2,$4);}
                      ;

variable_fin          : {$$=arbre_vide();}
		      | variable_suite {$$=$1;}
		      ;

expression            : expression_calcul {$$=$1;}
		      | expression expression_logique expression_calcul {$$= concat_pere_frere($1,concat_pere_frere($2,$3));} 
		      ;

expression_calcul     : expression_calcul PLUS expression_suite {$$=concat_pere_fils(creer_noeud(PLUS,-990),concat_pere_frere($1,$3));}
                      | expression_calcul MOINS expression_suite {$$=concat_pere_fils(creer_noeud(MOINS,-991),concat_pere_frere($1,$3));}
		      | expression_suite {$$=$1;}
                      ;

expression_suite      : expression_suite MULT expression_fin {$$=concat_pere_fils(creer_noeud(MULT,-989),concat_pere_frere($1,$3));}
                      | expression_suite DIV expression_fin {$$=concat_pere_fils(creer_noeud(DIV,-988),concat_pere_frere($1,$3));}
                      | expression_fin {$$=$1;}
                      ;

expression_fin        : PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE {$$=$2;}
                      | constante {$$=$1;}
		      | variable {$$=$1;}
		      | appel {$$=$1;}
                      ;

liste_expression      : liste_expression VIRGULE expression {$$=concat_pere_frere($1,$3);}
		      | expression {$$=$1;}
		      ;

constante             : CSTE_ENTIERE {$$=creer_noeud(CSTE_ENTIERE, $1);}
                      | CSTE_REEL {$$=creer_noeud(CSTE_REEL, $1);}
                      | CSTE_STRING {$$=creer_noeud(CSTE_STRING, $1);}
                      | CSTE_CHAR {$$=creer_noeud(CSTE_CHAR, $1);}
                      | CSTE_BOOL {$$=creer_noeud(CSTE_BOOL, $1);}
                      ;

expression_logique    : PLUS_PETIT {$$=creer_noeud(PLUS_PETIT,-992);}
		      | PLUS_GRAND {$$=creer_noeud(PLUS_GRAND,-993);}
		      | ET {$$=creer_noeud(ET,-994);}
		      | OU {$$=creer_noeud(OU,-995);}
		      | PLUS_PETIT_EGAL {$$=creer_noeud(PLUS_PETIT_EGAL,-996);}
		      | PLUS_GRAND_EGAL {$$=creer_noeud(PLUS_GRAND_EGAL,-997);}
		      | EGAL {$$=creer_noeud(EGAL,-998);}
		      | DIFFERENT {$$=creer_noeud(DIFFERENT,-999);}
		      ;

%%
int yyerror()
{
	printf("\nerreur de syntaxe %i\n", nbLignes);
}
int main(){ init_tab_lex(); yyparse(); }
