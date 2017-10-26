%{
#include<stdio.h>
%}
%token PROG POINT_VIRGULE DEBUT FIN
%token IDF DEUX_POINTS
%token CROCHET_OUVRANT CROCHET_FERMANT
%token ENTIER REEL BOOLEEN
%token CARACTERE CHAINE CSTE_ENTIERE VARIABLE
%token TYPE STRUCT FSTRUCT TABLEAU DE VIRGULE POINT
%token PROCEDURE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token FONCTION RETOURNE
%token OPAFF
%token SI ALORS SINON
%token TANT_QUE FAIRE
%token POUR
%%
programme             : PROG BEGIN corps END
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
                      | pour
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
repeter_tant_que      : FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE POINT_VIRGULE
                      ;
pour                  : POUR PARENTHESE_OUVRANTE declaration_variable POINT_VIRGULE expression POINT_VIRGULE affectation PARENTHESE_FERMANTE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE
                      | POUR PARENTHESE_OUVRANTE affectation POINT_VIRGULE expression POINT_VIRGULE affectation PARENTHESE_FERMANTE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE
                      ;

affectation           : variable OPAFF expression
                      ;

variable              : IDF
                      | IDF CROCHET_OUVRANT expression CROCHET_FERMANT
                      ;

expression            : CSTE_ENTIERE
                      | variable
                      ;

%%
