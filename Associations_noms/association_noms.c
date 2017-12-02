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

extern int nbLignes;
int get_num_declaration(int numlexico){
    int i ,top_region = 0, num_dec = 0,check_region = -1;
    if (numlexico <= 4)
        return numlexico;
    if(tabDeclaration[numlexico].type != -1){
        if(tabDeclaration[numlexico].suivant == -1){
            if(tabDeclaration[numlexico].region == get_curr_region())
            return numlexico;
            
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
        printf("Erreur de declaration :  L'element << %s >> a la ligne %d n'est pas declare.\n",get_lexeme(numlexico),nbLignes);
        exit(-1);
    }
    if(check_region == -1)
        printf("Erreur de declaration :  L'element << %s >> a la ligne %d n'est pas declare.\n",get_lexeme(numlexico),nbLignes);
    exit(-1);
        
    return num_dec;
}

