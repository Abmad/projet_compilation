//
//  association_noms.c
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/30/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#include <stdlib.h>
#include "association_noms.h"
#include "table_declaration.h"

typedef struct {
    char* exp_lexeme_char;//expression du lexème
    int longueur;//nombre de caractères du lexème
    struct lexeme * suiv;//lexème suivant
    int hash_code;
} lexeme;

lexeme tab_lexico[500];

int nb_lignes = 0;
//extern int nb_lignes;
int get_num_declaration(int numlexico){
    int i ,top_region = 0, num_dec = 0;
    
    if (numlexico <= 4)
        return numlexico;
    if(tabDeclaration[numlexico].type != -1){
        if(tabDeclaration[numlexico].suivant == -1){
            return numlexico;
            
        }else{
            i = tabDeclaration[numlexico].suivant;
            top_region = tabDeclaration[i].region;
            do{
                if(top_region < tabDeclaration[tabDeclaration[i].suivant].region)
                    top_region = tabDeclaration[tabDeclaration[i].suivant].region;
                else
                    num_dec = i;
                
                i = tabDeclaration[i].suivant;
            }while(i != -1);
            
        }
    }else{
        printf("Erreur de declaration :  L'element << %s >> n'est pas declare a la ligne %d .\n", tab_lexico[numlexico].exp_lexeme_char,nb_lignes);
        exit(-1);
    }
    
    return num_dec;
}

