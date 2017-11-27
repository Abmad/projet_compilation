//
//  arbre.h
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/17/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>

/*
 * Structure d'un noeud
 */
struct noeud
{
    int val_noeud;
    struct noeud * gauche;
    struct noeud * droite;
};
typedef struct noeud arbre;
arbre * concat_pere_fils(arbre *_pere, arbre *_fils);
arbre * concat_pere_frere(arbre *_pere, arbre *_frere);
arbre * creer_noeud(int _typeNoeud);
arbre* arbre_vide();
void afficher_arbre(arbre * _arbre, int indent);
