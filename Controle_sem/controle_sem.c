#include <stdio.h>
#include <stdlib.h>
#include "controle_sem.h"
#include "../Table_declarations/table_declaration.h"
#include "../Table_lexico/tablexico.h"
extern int nbLignes;

struct exp{
int nature;
int numlex;

};
typedef struct exp exp;
exp tab_exp[250];
int count_tab_exp = 0;
int cpt_tab_exp = 0;
void arbre_to_tab(arbre _arbre){

   tab_exp[count_tab_exp].nature = (*_arbre).nature;
   tab_exp[count_tab_exp].numlex = (*_arbre).val_noeud;
	count_tab_exp++;
	cpt_tab_exp++;
    if(_arbre->gauche != NULL){
        arbre_to_tab(_arbre->gauche);
    }
    if(_arbre->droite != NULL){
        arbre_to_tab(_arbre->droite);
    }
}

void verification_type(arbre dec1,int dec2,int isDec){
count_tab_exp = 0;
arbre_to_tab(dec1);
if(count_tab_exp == 1){
  if(tab_exp[0].nature >=C_CSTE_ENTIERE && tab_exp[0].nature <= C_CSTE_BOOL){
    if(tabDeclaration[dec2].description != tab_exp[0].nature)
    {
	int numlex_dec = dec2;
	   int i;
	   for(i=4;i<LNG_DECL;i++){
	    if(tabDeclaration[i].type != -1){
		if(tabDeclaration[i].suivant == numlex_dec){
		numlex_dec = i;i=4;
	    }
	    }
	}
	char * msg = malloc(sizeof(char));
	sprintf(msg,"Erreur semantique ligne: %d, %s est de type %s et %s est de type %s",nbLignes,get_lexeme(numlex_dec),get_nom_type(tabDeclaration[dec2].description),get_lexeme(tab_exp[0].numlex),get_nom_type(tab_exp[0].nature));
	ajouter_tab_error(msg);
    }   

  }
}else{
afficher_tab_exp();

}
//afficher_arbre(dec1,0);

}


void ajouter_tab_error(char * msg){

tab_error_sem[cpt_error_sem] = msg;
cpt_error_sem++;

}
void afficher_tab_exp(){
int i;
for(i=0;i<cpt_tab_exp;i++)
//printf("nature:%s  numlex %d \n",get_nom_type(tab_exp[i].nature),tab_exp[i].numlex);
if(tab_exp[i].numlex>=0)
printf(" lex: %s nature: %s \n", get_lexeme(tab_exp[i].numlex),get_nom_type(tab_exp[i].nature));
}

char * get_nom_type(int nature){
	char * type = malloc(sizeof(char));
        switch(nature)
        {
            case C_NOEUD_PRINCIPAL:
                type = "NOEUD_PRINCIPAL";
                break;
            case C_CSTE_ENTIERE:
                type = "entier";
                break;
            case C_CSTE_REEL:
                type = "reel";
                break;
            case C_CSTE_STRING:
                type = "string";
                break;
            case C_CSTE_CHAR:
                type = "char";
                break;
            case C_CSTE_BOOL:
                type = "bool";
                break;
            case C_PLUS_PETIT:
                type = "plus petit";
                break;
            case C_PLUS_GRAND:
                type = "plus grand";
                break;
            case C_ET:
                type = "et";
                break;
            case C_OU:
                type = "ou";
                break;
            case C_PLUS_PETIT_EGAL:
                type = "inferieur ou egal";
                break;
            case C_PLUS_GRAND_EGAL:
                type = "superieur ou egal";
                break;
            case C_EGAL:
                type = "egal";
                break;
            case C_DIFFERENT:
                type = "different";
                break;
            case C_PLUS:
                type = "plus";
                break;
            case C_MOINS:
                type = "moin";
                break;
	    default:
                type = "null";
		break;
return type;

}
}

void afficher_erreur_sem(){
int i;
for(int i=0;i<cpt_error_sem;i++)
printf("%s \n",tab_error_sem[i]);

}
void init_sem(){
cpt_error_sem = 0;

memset(tab_exp, -1, (size_t)250 * sizeof(exp));

memset(tab_error_sem, -1, (size_t)500 * sizeof(char));
}
