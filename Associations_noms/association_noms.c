//
//  association_noms.c
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/30/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#include <stdlib.h>
#include "association_noms.h"
#include "../Table_declarations/table_declaration.h"
#include "../Table_lexico/tablexico.h"
#include "../Table_regions/table_regions.h"
void init_errors_table(){
cpt_errors = 0;
}
extern int nbLignes;
int get_num_declaration(int numlexico){
    int i ,top_region = 0, num_dec = 0,check_region = -1;
    if (numlexico <= 4)
        return numlexico;
    if(tabDeclaration[numlexico].type != -1){
        if(tabDeclaration[numlexico].suivant == -1){
            if(tabDeclaration[numlexico].region == get_curr_region())
            return numlexico;
            else{
	ajouter_error(nbLignes,get_lexeme(numlexico),ERR_REGION);
       return -1;
}
		
        }else{
            i = tabDeclaration[numlexico].suivant;
            top_region = tabDeclaration[i].region;
            do{
                if(tabDeclaration[i].region<=get_curr_region())
                    check_region = 1;
                if(top_region < tabDeclaration[tabDeclaration[i].suivant].region)
                    top_region = tabDeclaration[tabDeclaration[i].suivant].region;
                else
                    num_dec = i;
                
                i = tabDeclaration[i].suivant;
            }while(i != -1);
            
        }
    }else{
	ajouter_error(nbLignes,get_lexeme(numlexico),ERR_NON_DECLARED);
       return -1;
    }
    if(check_region == -1){
	ajouter_error(nbLignes,get_lexeme(numlexico),ERR_REGION);
        return -1;
    }
        
    return num_dec;
}

void ajouter_error(int _ligne,char * _lexeme,int _ertype){
    error erreur = malloc(sizeof(struct error));
    erreur->ligne = _ligne;
    erreur->lexeme = _lexeme;
    erreur->type = _ertype;
    tab_errors[cpt_errors] = erreur;
    cpt_errors++;
}
void afficher_erreurs(){
int i;   
    for(i=0;i<cpt_errors;i++){
      if(tab_errors[i]->type == ERR_REGION)
        printf("\nErreur de declaration :  L'element << %s >> a la ligne %d n'est pas declare dans cette region.\n",tab_errors[i]->lexeme,tab_errors[i]->ligne);
else if(tab_errors[i]->type == ERR_NON_DECLARED)
        printf("\nErreur de declaration :  L'element << %s >> a la ligne %d n'est pas declare.\n",tab_errors[i]->lexeme,tab_errors[i]->ligne);
}
}


