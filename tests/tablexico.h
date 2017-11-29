#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    char* exp_lexeme_char;//expression du lexème
    int exp_lexeme_int;
    double exp_lexeme_double;
    int longueur;//nombre de caractères du lexème
    struct lexeme * suiv;//lexème suivant
    int hash_code;
} lexeme;

#define LONGUEUR 250

int cpt, cpt2, cpt3;

lexeme table_lexico[LONGUEUR];

int longueur_int(int valeur);

int add_lexeme_char(char* lex);

void affiche_table_lexico(int j);

void init_tab_lex();


