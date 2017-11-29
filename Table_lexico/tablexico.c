#include "tablexico.h"
#include "../Arbre/arbre.h"
lexeme table_lexico[LONGUEUR];

int longueur_int(int valeur){ //Calcule la longueur d'un entier
    int retour = 0;
    
    if(valeur < 0)
    {
        retour++;
        valeur = -1 * valeur;
    }
    
    while(valeur !=0)
    {
        retour++;
        valeur = valeur / 10;
    }
    return retour;
}


//ajoute un lexème dans la table lexicographique
int add_lexeme_char(char* lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt<LONGUEUR);
    if(table_lexico[cpt].longueur==0 && table_lexico[cpt].exp_lexeme_char!=lex){
        lexeme l;
        strcpy(l.exp_lexeme_char,lex);
        l.longueur = strlen(lex);
        l.suiv = &(table_lexico[cpt+1]);
        l.hash_code=cpt+1;
        table_lexico[cpt] = l;
        
        return l.hash_code;
    }
    else if(table_lexico[cpt].longueur==strlen(lex) && table_lexico[cpt].exp_lexeme_char==lex){
        //lexème déjà présent dans la table, aucune action n'est effectuée.
	return 9999;
    }
    else{
        cpt = cpt +1;
        add_lexeme_char(lex);
    }
    cpt=0;
    
}


//affiche le contenu de la table jusqu'à la j-ieme case
void affiche_table_lexico(int j){//Créé par Dan Robert Tsoumbou Moutimba
    assert(j<LONGUEUR);
    int i=0;
    for(i=0;i<j;i++){
        printf("CASE: %d, %s, \n",table_lexico[i].hash_code, table_lexico[i].exp_lexeme_char);
    }
}
void init_tab_lex(){
    
    printf("init\n");
}
