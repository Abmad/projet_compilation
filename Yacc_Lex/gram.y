%{
#include<stdio.h>
%}

%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token CSTE_ENTIERE CSTE_REEL CSTE_STRING CSTE_CHAR CSTE_BOOL
%token ENTIER REEL BOOLEEN CARACTERE CHAINE
%token PLUS_PETIT PLUS_GRAND ET OU PLUS_PETIT_EGAL PLUS_GRAND_EGAL EGAL DIFFERENT
%token PLUS MOINS MULT DIV
%token TANT_QUE FAIRE SI ALORS SINON
%token VARIABLE TYPE
%token STRUCT FSTRUCT TABLEAU DE
%token PROCEDURE FONCTION RETOURNE
%token OPAFF
%token PROG DEBUT FIN
%token IDF

%%
programme             : PROG ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE
                      ;

corps                 : liste_declarations liste_instructions
                      | liste_instructions
                      ;

liste_declarations    : declaration 
                      | liste_declarations POINT_VIRGULE declaration
                      ;

liste_instructions    : DEBUT suite_liste_inst FIN
                      ;

suite_liste_inst      :
                      | instruction
                      | suite_liste_inst POINT_VIRGULE instruction
                      ;

declaration           : declaration_type
                      | declaration_variable
                      | declaration_procedure
                      | declaration_fonction
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

instruction           : affectation
                      | condition
                      | tant_que
                      | repeter_tant_que
                      | appel
                      | RETOURNE resultat_retourne
                      ;

resultat_retourne     :
                      | expression
                      ;

appel                 : IDF liste_arguments
                      ;

liste_arguments       : PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
                      | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
                      ;

liste_args            : un_arg
                      | liste_args VIRGULE un_arg
                      ;

un_arg                : expression
                      ;

condition             : SI PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE ALORS ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE
                      ;

tant_que              : TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE
                      ;

repeter_tant_que      : FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE
                      ;

affectation           : variable OPAFF expression
                      ;

variable              : IDF
	 	      | IDF variable_suite
		      ;

variable_suite        : CROCHET_OUVRANT liste_expression CROCHET_FERMANT variable_fin
                      ;

variable_fin          : 
		      | variable_suite
		      ;

expression            : expression_calcul
		      | expression expression_logique expression_calcul                     
		      ;

expression_calcul     : expression_calcul PLUS expression_suite
                      | expression_calcul MOINS expression_suite
		      | expression_suite
                      ;

expression_suite      : expression_suite MULT expression_fin
                      | expression_suite DIV expression_fin
                      | expression_fin
                      ;

expression_fin        : PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE
                      | constante
		      | variable
		      | appel 
                      ;

liste_expression      : liste_expression VIRGULE expression
		      | expression
		      ;

constante             : CSTE_ENTIERE
                      | CSTE_REEL
                      | CSTE_STRING
                      | CSTE_CHAR
                      | CSTE_BOOL
                      ;

expression_logique    : PLUS_PETIT
		      | PLUS_GRAND
		      | ET
		      | OU
		      | PLUS_PETIT_EGAL
		      | PLUS_GRAND_EGAL
		      | EGAL
		      | DIFFERENT
		      ;

%%
