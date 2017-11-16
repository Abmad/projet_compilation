#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tablexico.h"

typedef struct {
    char* exp_lexeme;//expression du lexème
    int longueur;//nombre de caractères du lexème
    struct lexeme * suiv;//lexème suivant

} lexeme;

lexeme table_lexico[100];

void add_lexeme(char* lex, int cpt){ //ajoute un lexeme dans la table lexicographique
                                     //Créé par Dan Robert Tsoumbou Moutimba
    //if(est_stocke(lex,cpt)==0){

        if(table_lexico[cpt].longueur==0){
            lexeme l;
            l.exp_lexeme = lex;
            l.longueur = strlen(lex);
            l.suiv = NULL;

            table_lexico[cpt] = l;

            if(table_lexico[cpt-1].longueur>0){
            table_lexico[cpt-1].suiv = &l;
            }

        }
        else{
            //printf("%d, %s\n",table_lexico[cpt-1].longueur,table_lexico[cpt-1].exp_lexeme);
            cpt = cpt +1;
            add_lexeme(lex,cpt);
        }
    //}

}

int est_stocke(char* lex, int i){//vérifie la présence d'un lexème dans la table
                                 //Crée par Dan Robert Tsoumbou Moutimba
    int k=0, lex_true=0;

    for(k=0;k<i;k++){
        if(table_lexico[k].longueur!=0){
            lex_true++;
        }
    }
    return lex_true;
}


int main()
{
    //Tests de fonctions
    int i=0;

    for(i=0;i<5;i++){
        printf("%d, %s\n", table_lexico[i].longueur, table_lexico[i].exp_lexeme);
    }

    printf("\n");
    add_lexeme("test",0);
    printf("%d, %s\n\n",table_lexico[0].longueur,table_lexico[0].exp_lexeme);

    add_lexeme("tester",0);
    printf("%s, %d\n", table_lexico[1].exp_lexeme,table_lexico[1].longueur);

    printf("\n");
    add_lexeme("tester",0);

    printf("%s, %d\n", table_lexico[0].exp_lexeme,table_lexico[0].longueur);
    printf("%s, %d\n", table_lexico[1].exp_lexeme,table_lexico[1].longueur);
    printf("%s, %d\n", table_lexico[2].exp_lexeme,table_lexico[2].longueur);

    return 0;
}
