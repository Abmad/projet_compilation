//
//  association_noms.h
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/30/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//

#ifndef association_noms_h
#define association_noms_h

#include <stdio.h>
#define MAX_TAB_ERRORS 500
#define ERR_REGION 1
#define ERR_NON_DECLARED 2
struct error{
    int ligne;
    char * lexeme;
   int type; 
};
typedef struct error * error;
error tab_errors[MAX_TAB_ERRORS];
int cpt_errors;
void ajouter_error(int ligne,char * lexeme, int _ertype);
void afficher_erreurs();
int get_num_declaration(int numlexico);
void init_errors_table();
#endif /* association_noms_h */
