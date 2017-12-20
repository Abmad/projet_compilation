
#ifndef controle_sem_h
#define controle_sem_h
#include <stdio.h>
#include "../Arbre/arbre.h"



int cpt_error_sem;

char *tab_error_sem[500];
void init_sem();
void verification_type(arbre dec1,int dec2,int isDec);
void afficher_tab_exp();
void arbre_to_tab(arbre _arbre);
void ajouter_tab_error(char * msg);
void afficher_erreur_sem();
char* get_nom_type(int nature);

#endif
