%{
extern int yylex();
extern int yyerror();
%}

%token PROG DEBUT FIN
%token TYPE POINT_VIRGULE IDF DEUX_POINTS
%token STRUCT FSTRUCT TABLEAU DE
%token CROCHET_OUVRANT CROCHET_FERMANT
%token VIRGULE POINT ENTIER REEL BOOLEEN CARACTERE CHAINE
%token VARIABLE PROCEDURE RETOURNE 
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token VIDE SI ALORS SINON TANT_QUE FAIRE OPAFF
%token PLUS MOINS MUTL DIV SUP INF SUP_EGAL INF_EGAL EGAL

programme             : PROG corps;

corps                 : liste_declarations liste_instructions
                      | liste_instructions;

liste_declarations    : declaration 
		      | liste_declarations POINT_VIRGULE declaration;

liste_instructions    : DEBUT suite_liste_inst FIN;

suite_liste_inst      : instruction
	              | suite_liste_inst POINT_VIRGULE instruction;

declaration           : declaration_type
	              | declaration_variable
        	      | declaration_procedure
        	      | declaration_fonction;

declaration_type      : TYPE IDF DEUX_POINTS suite_declaration_type;

suite_declaration_type : STRUCT liste_champs FSTRUCT
		       | TABLEAU dimension DE nom_type;

dimension             : CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT;

liste_dimensions      : une_dimension
		      | liste_dimensions VIRGULE une_dimension;

une_dimension         : expression POINT POINT expression;

liste_champs          : un_champ
	              | liste_champs POINT_VIRGULE un_champ;

un_champ              : IDF DEUX_POINTS nom_type;

nom_type              : type_simple
	              | IDF;

type_simple           : ENTIER
	              | REEL
	              | BOOLEEN
	              | CARACTERE
	              | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT;

declaration_variable  : VARIABLE IDF DEUX_POINTS nom_type;

declaration_procedure : PROCEDURE IDF liste_parametres corps;

declaration_fonction  : FONCTION IDF liste_parametres RETOURNE type_simple corps;

liste_parametres      :
		      | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE;

liste_param           : un_param
liste_param           | liste_param POINT_VIRGULE un_param;


un_param              | IDF DEUX_POINTS type_simple;

instruction           : affectation
	              | condition
           	      | tant_que
           	      | appel
           	      | VIDE
           	      | RETOURNE resultat_retourne;

resultat_retourne     :
		      | expression;

appel                 : IDF liste_arguments;

liste_arguments       :
	              |  PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE;

liste_args            : un_arg
	              | liste_args VIRGULE un_arg;

un_arg                | expression;

condition             :  SI expression
                         ALORS liste_instructions
                         SINON liste_instructions;

tant_que              : TANT_QUE expression FAIRE liste_instructions;

affectation           : variable OPAFF expression;

variable              : IDF
		      | CARACTERE
		      | CHAINE 
		      | CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT;

expression            : variable 
		      | variable PLUS variable1
		      | variable MOINS variable1
		      | variable MULT variable1
		      | variable DIV variable1
		      | variable EGAL variable1
		      | variable SUP variable1
		      | variable INF variable1
		      | variable SUP_EGAL variable1
		      | variable INF_EGAL variable1;




