#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char* exp_lexeme;//expression du lexème
    int longueur;//nombre de caractères du lexème
    struct lexeme * suiv;//lexème suivant

} lexeme;

lexeme table_lexico[100];

void add_lexeme(char* lex, int cpt);
int est_stocke(char* lex, int i);