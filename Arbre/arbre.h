#include<stdio.h>
#include<stdlib.h>


#define NOEUD_PRINCIPAL 0
#define CSTE_ENTIERE 1
#define CSTE_REEL 2
#define CSTE_STRING 3
#define CSTE_CHAR 4
#define CSTE_BOOL 5
#define PLUS_PETIT 6
#define PLUS_GRAND 7
#define ET 8
#define OU 9
#define PLUS_PETIT_EGAL 10
#define PLUS_GRAND_EGAL 11
#define EGAL 12
#define DIFFERENT 13
#define PLUS 14
#define MOINS 15
#define MULT 16
#define DIV 17



/*
 * Structure d'un noeud
 */
struct arbre
{
    int noeud;
    struct arbre * gauche;
    struct arbre * droite;
};
typedef struct arbre noeud;

/*
 * Fonctions
 */
noeud concat_pere_fils(noeud *_pere, noeud *_fils);
noeud concat_pere_frere(noeud *_pere, noeud *_frere);
noeud creer_noeud(int _typeNoeud);
noeud arbre_vide();
void afficher_arbre(noeud _arbre);

