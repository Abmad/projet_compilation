%{
#include<stdio.h>
#include "./Arbre/arbre.h"
#include "./Table_lexico/tablexico.h"
#include "./Table_regions/table_regions.h"
#include "./Table_declarations/table_declaration.h"
#include "./Table_representation/representation_entetes_sous_programmes.h"
#include "./Associations_noms/association_noms.h"
extern int nbLignes;
extern char* yytext;
extern int yylex() ;
int yyerror() ;
int curr_region = 0;
FILE *f;
int num_declaration;
int idf;
int nbr_champs_struct;
int nbr_champs_tab;
int nbr_param;
int indice_repr;
%}

%union{
   arbre type1;
   int type2;
}
%token POINT_VIRGULE DEUX_POINTS CROCHET_OUVRANT CROCHET_FERMANT VIRGULE POINT PARENTHESE_OUVRANTE PARENTHESE_FERMANTE ACCOLADE_OUVRANTE ACCOLADE_FERMANTE
%token CSTE_ENTIERE CSTE_REEL CSTE_STRING CSTE_CHAR CSTE_BOOL
%token<type2> ENTIER REEL BOOLEEN CARACTERE CHAINE
%token PLUS_PETIT PLUS_GRAND ET OU PLUS_PETIT_EGAL PLUS_GRAND_EGAL EGAL DIFFERENT
%token PLUS MOINS MULT DIV
%token TANT_QUE FAIRE SI ALORS SINON
%token VARIABLE TYPE
%token STRUCT FSTRUCT TABLEAU DE
%token PROCEDURE FONCTION RETOURNE
%token OPAFF
%token PROG DEBUT FIN
%token IDF

%type<type1> liste_instructions suite_liste_inst instruction resultat_retourne appel liste_arguments liste_args un_arg condition tant_que repeter_tant_que affectation variable variable_suite variable_fin expression expression_calcul expression_suite expression_fin liste_expression constante expression_logique corps
%type<type2> IDF CSTE_ENTIERE CSTE_REEL CSTE_STRING CSTE_CHAR CSTE_BOOL nom_type type_simple


%%
programme             : PROG ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE{printf("\n");afficher_decl();printf("\n");afficherRepr();}
                      ;

corps                 : {region_empiler();} liste_declarations liste_instructions {curr_region = region_depiler();ajout_val_table_reg(10,curr_region,$3);}{/*afficher_arbre($3,0);*/}{enregistrer_arbre($3,0,f);}
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

liste_instructions    : DEBUT  suite_liste_inst FIN {$$=$2;}
                      ;

suite_liste_inst      : {$$=arbre_vide();}
                      | instruction {$$=$1;}
                      | suite_liste_inst POINT_VIRGULE instruction {$$= concat_pere_fils(creer_noeud(C_LIST,-1,-1),concat_pere_frere($3,$1));}
                      ;

declaration_type      : TYPE IDF{idf = $2;} DEUX_POINTS suite_declaration_type
                      ;

suite_declaration_type : STRUCT{nbr_champs_struct = 0; reserveElem();} liste_champs{indice_repr = ajoutNbr(nbr_champs_struct); num_declaration = add_champs(idf,TYPE_STRUCT,get_curr_region(),indice_repr,0); } FSTRUCT
                       | TABLEAU{nbr_champs_tab = 0; reserveElem();reserveElem();} dimension{ajoutNbr(nbr_champs_tab);} DE nom_type{indice_repr = ajoutNbr($6); num_declaration = add_champs(idf,TYPE_TABLEAU,get_curr_region(),indice_repr,0); }
                       ;

dimension             : CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT
                      ;

liste_dimensions      : une_dimension {nbr_champs_tab++;}
                      | liste_dimensions VIRGULE une_dimension {nbr_champs_tab++;}
                      ;

une_dimension         : CSTE_ENTIERE POINT POINT CSTE_ENTIERE{addElement($1);addElement($4);}
                      ;

liste_champs          : un_champ {nbr_champs_struct++;}
                      | liste_champs un_champ {nbr_champs_struct++;}
                      ;

un_champ              : IDF DEUX_POINTS nom_type POINT_VIRGULE {addElement($1);addElement($3);addElement(0);}
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

declaration_variable  : VARIABLE IDF DEUX_POINTS nom_type{ num_declaration = add_champs($2,TYPE_VARIABLE,get_curr_region(),$4,0); }
                      | VARIABLE IDF DEUX_POINTS nom_type{ num_declaration = add_champs($2,TYPE_VARIABLE,get_curr_region(),$4,0); } OPAFF expression
     		      ;

declaration_procedure : PROCEDURE{nbr_param = 0; reserveElem();} IDF liste_parametres{indice_repr = ajoutNbr(nbr_param); num_declaration = add_champs($3,TYPE_PROCEDURE,get_curr_region(),indice_repr,0); } ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE
                      ;

declaration_fonction  : FONCTION{nbr_param = 0; reserveElem();reserveElem();} IDF liste_parametres RETOURNE type_simple{indice_repr = ajoutNbr(0); ajoutNbr(nbr_param); num_declaration = add_champs($3,TYPE_FONCTION,get_curr_region(),$6,0); }  ACCOLADE_OUVRANTE corps ACCOLADE_FERMANTE
                      ;

liste_parametres      : PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE
                      ;

liste_param           : 
                      | un_param{nbr_param++;}
                      | liste_param POINT_VIRGULE un_param{nbr_param++;}
                      ;

un_param              : IDF DEUX_POINTS type_simple{ num_declaration = add_champs($1,TYPE_VARIABLE,get_curr_region(),$3,1); addElement($1);addElement($3);}
                      ;

instruction           : affectation {$$=$1;}
                      | condition {$$=$1;}
                      | tant_que {$$=$1;}
                      | repeter_tant_que {$$=$1;}
                      | appel {$$=$1;}
                      | RETOURNE resultat_retourne {$$=concat_pere_fils(creer_noeud(C_RETOURNE,-999,-1),$2);}
                      ;

resultat_retourne     : {$$=arbre_vide();}
                      | expression {$$=$1;}
                      ;

appel                 : IDF liste_arguments {$$= concat_pere_fils(creer_noeud(C_IDF,$1,get_num_declaration($1)),$2);}
                      ;

liste_arguments       : PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {$$=arbre_vide();}
                      | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE {$$=$2;}
                      ;

liste_args            : un_arg {$$=$1;}
                      | liste_args VIRGULE un_arg {$$= concat_pere_frere($1,$3);}
                      ;

un_arg                : expression {$$=$1;}
                      ;

condition             : SI PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE ALORS ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE {$$= concat_pere_frere (concat_pere_fils(creer_noeud(C_SI,-979,-1),concat_pere_frere($3,$7)),concat_pere_fils(creer_noeud(C_SINON,-976,-1),$11));}
                      ;

tant_que              : TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE {$$=concat_pere_fils(creer_noeud(C_TANT_QUE,-987,0),concat_pere_frere($3,$7));}
                      ;

repeter_tant_que      : FAIRE ACCOLADE_OUVRANTE liste_instructions ACCOLADE_FERMANTE TANT_QUE PARENTHESE_OUVRANTE expression PARENTHESE_FERMANTE  {$$=concat_pere_fils(creer_noeud(C_FAIRE,-976,-1),concat_pere_frere($3,$7));}
                      ;

affectation           : variable OPAFF expression {$$=concat_pere_fils(creer_noeud(C_OPAFF,-980,-1),concat_pere_frere($1,$3));}
                      ;

variable              : IDF {$$= creer_noeud(C_IDF,$1,get_num_declaration($1));}
	 	      | IDF variable_suite {$$=concat_pere_frere(creer_noeud(C_IDF,$1,get_num_declaration($1)),$2);}
		      ;

variable_suite        : CROCHET_OUVRANT liste_expression CROCHET_FERMANT variable_fin {$$=concat_pere_frere($2,$4);}
                      ;

variable_fin          : {$$=arbre_vide();}
		      | variable_suite {$$=$1;}
		      ;

expression            : expression_calcul {$$=$1;}
		      | expression expression_logique expression_calcul {$$= concat_pere_frere($1,concat_pere_frere($2,$3));} 
		      ;

expression_calcul     : expression_calcul PLUS expression_suite {$$=concat_pere_fils(creer_noeud(C_PLUS,-990,-1),concat_pere_frere($1,$3));}
                      | expression_calcul MOINS expression_suite {$$=concat_pere_fils(creer_noeud(C_MOINS,-991,-1),concat_pere_frere($1,$3));}
		      | expression_suite {$$=$1;}
                      ;

expression_suite      : expression_suite MULT expression_fin {$$=concat_pere_fils(creer_noeud(C_MULT,-989,-1),concat_pere_frere($1,$3));}
                      | expression_suite DIV expression_fin {$$=concat_pere_fils(creer_noeud(C_DIV,-988,-1),concat_pere_frere($1,$3));}
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

constante             : CSTE_ENTIERE {$$=creer_noeud(C_CSTE_ENTIERE, $1,-1);}
                      | CSTE_REEL {$$=creer_noeud(C_CSTE_REEL, $1,-1);}
                      | CSTE_STRING {$$=creer_noeud(C_CSTE_STRING, $1,-1);}
                      | CSTE_CHAR {$$=creer_noeud(C_CSTE_CHAR, $1,-1);}
                      | CSTE_BOOL {$$=creer_noeud(C_CSTE_BOOL, $1,-1);}
                      ;

expression_logique    : PLUS_PETIT {$$=creer_noeud(C_PLUS_PETIT,-992,0);}
		      | PLUS_GRAND {$$=creer_noeud(C_PLUS_GRAND,-993,0);}
		      | ET {$$=creer_noeud(ET,-994,0);}
		      | OU {$$=creer_noeud(OU,-995,0);}
		      | PLUS_PETIT_EGAL {$$=creer_noeud(C_PLUS_PETIT_EGAL,-996,0);}
		      | PLUS_GRAND_EGAL {$$=creer_noeud(C_PLUS_GRAND_EGAL,-997,0);}
		      | EGAL {$$=creer_noeud(C_EGAL,-998,0);}
		      | DIFFERENT {$$=creer_noeud(C_DIFFERENT,-999,0);}
		      ;

%%
int yyerror()
{
	printf("\nerreur de syntaxe %i\n", nbLignes);
}
int main(){ 
printf("\n");
init_errors_table();
init_tab_lexico();
init_decl();
initRepr();
init_table_regions();
f = openfile();
if(yyparse()==0){
if(cpt_errors > 0){
afficher_erreurs();
exit(-1);
}
//afficher_table_region();
affiche_table_lexico();

}
closefile(f);

 }
