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
void arbre_to_tab(arbre _arbre){

   tab_exp[count_tab_exp].nature = (*_arbre).nature;
   tab_exp[count_tab_exp].numlex = (*_arbre).val_noeud;
	count_tab_exp++;
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
printf("dec2 %d",dec2);
if(count_tab_exp == 1){
  if(tabDeclaration[dec2].type != TYPE_VARIABLE )
  {
    printf("erreur syntax ligne %d\n",nbLignes);
  }
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
	printf("Erreur semantique ligne: %d, %s est de type %d et %s est de type %d",nbLignes,get_lexeme(numlex_dec),tabDeclaration[dec2].description,get_lexeme(tab_exp[0].numlex),tab_exp[0].nature);
    }   

  }
}else{


}
//afficher_arbre(dec1,0);

}
void afficher_tab_exp(){
int i;
for(i=0;i<count_tab_exp;i++)
printf("%d\n",tab_exp[i].nature);
}
