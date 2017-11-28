//
//  arbre.h
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/17/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
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
#define OPAFF 18
#define FAIRE 19
#define TANT_QUE 20
#define SI 21
#define SINON 22
#define IDF 23
/*
 * Structure d'un noeud
 */
type def struct noeud
{
    int nature;
    int val_noeud;
    int num_declaration;//fonction assossiation de noms
    struct noeud * gauche;
    struct noeud * droite;
}noeud;
typedef struct noeud * arbre;
arbre * concat_pere_fils(arbre _pere, arbre _fils);
arbre * concat_pere_frere(arbre _pere, arbre _frere);
arbre * creer_noeud(int _nature, int _val_noeud);
arbre* arbre_vide();
void afficher_arbre(arbre _arbre, int indent);

