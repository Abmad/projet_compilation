#include "tablexico.h"

lexeme table_lexico[longueur];

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
    assert(cpt<longueur);
    if(table_lexico[cpt].longueur==0 && table_lexico[cpt].exp_lexeme_char!=lex){
        lexeme l;
        l.exp_lexeme_char = lex;
        l.exp_lexeme_int = 0;
        l.exp_lexeme_double = 0;
        l.longueur = strlen(lex);
        l.suiv = &table_lexico[cpt+1];
        l.hash_code=cpt+1;
        table_lexico[cpt] = l;
        
        return l.hash_code;
    }
    else if(table_lexico[cpt].longueur==strlen(lex) && table_lexico[cpt].exp_lexeme_char==lex){
        //lexème déjà présent dans la table, aucune action n'est effectuée.
    }
    else{
        cpt = cpt +1;
        add_lexeme_char(lex);
    }
    cpt=0;
}

int add_lexeme_int(int lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt2<longueur);
    if(table_lexico[cpt2].longueur==0 && table_lexico[cpt2].exp_lexeme_int!=lex){
        lexeme l;
        l.exp_lexeme_int = lex;
        l.exp_lexeme_char = NULL;
        l.exp_lexeme_double = 0;
        l.longueur = longueur_int(lex);
        l.suiv = &table_lexico[cpt2+1];
        l.hash_code = cpt2 +1;
        table_lexico[cpt2] = l;
        
        return l.hash_code;
    }
    else if(table_lexico[cpt2].longueur==longueur_int(lex) && table_lexico[cpt2].exp_lexeme_int==lex){
        //lexème déjà présent dans la table, aucune action n'est effectuée.
    }
    else{
        cpt2 = cpt2 +1;
        add_lexeme_int(lex);
    }
    cpt2=0;
}

int add_lexeme_double(double lex){//Créé par Dan Robert Tsoumbou Moutimba
    assert(cpt3<longueur);
    if(table_lexico[cpt3].longueur==0 && table_lexico[cpt3].exp_lexeme_int!=lex){
        lexeme l;
        l.exp_lexeme_double = lex;
        l.exp_lexeme_char = 0;
        l.exp_lexeme_int=0;
        l.longueur = longueur_int((int) lex);
        l.suiv = &table_lexico[cpt3+1];
        l.hash_code = cpt3 +1;
        table_lexico[cpt3] = l;
        
        return l.hash_code;
    }
    else if(table_lexico[cpt3].longueur==longueur_int(lex) && table_lexico[cpt3].exp_lexeme_double==lex){
        //lexème déjà présent dans la table, aucune action n'est effectuée.
    }
    else{
        cpt3 = cpt3 +1;
        add_lexeme_double(lex);
    }
    cpt3=0;
}

//affiche le contenu de la table jusqu'à la j-ieme case
void affiche_table_lexico(int j){//Créé par Dan Robert Tsoumbou Moutimba
    assert(j<longueur);
    int i=0;
    for(i=0;i<j;i++){
        printf("%d, %s, %d, %f\n",table_lexico[i].hash_code, table_lexico[i].exp_lexeme_char, table_lexico[i].exp_lexeme_int, table_lexico[i].exp_lexeme_double);
    }
}
