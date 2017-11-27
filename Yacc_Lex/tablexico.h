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

#define longueur 250;

int cpt, cpt2, cpt3;

lexeme table_lexico[longueur];

int longueur_int(int valeur);

int add_lexeme_char(char* lex);

int add_lexeme_int(int lex);

int add_lexeme_double(double lex);

void affiche_table_lexico(int j);



