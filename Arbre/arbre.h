//
//  arbre.h
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/17/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#ifndef arbre_h
#define arbre_h

#include<stdio.h>
#include<stdlib.h>

#define C_NOEUD_PRINCIPAL 0
#define C_CSTE_ENTIERE 1
#define C_CSTE_REEL 2
#define C_CSTE_STRING 3
#define C_CSTE_CHAR 4
#define C_CSTE_BOOL 5
#define C_PLUS_PETIT 6
#define C_PLUS_GRAND 7
#define C_ET 8
#define C_OU 9
#define C_PLUS_PETIT_EGAL 10
#define C_PLUS_GRAND_EGAL 11
#define C_EGAL 12
#define C_DIFFERENT 13
#define C_PLUS 14
#define C_MOINS 15
#define C_MULT 16
#define C_DIV 17
#define C_OPAFF 18
#define C_FAIRE 19
#define C_TANT_QUE 20
#define C_SI 21
#define C_SINON 22
#define C_IDF 23
#define C_LIST 24
#define C_RETOURNE 25
#define C_FUNC_PROC 26
/*
 * Structure d'un noeud
 */
struct noeud
{
    int nature;
    int val_noeud;
    int num_declaration;
    struct noeud * gauche;
    struct noeud * droite;
};
typedef struct noeud * arbre;
arbre  concat_pere_fils(arbre _pere, arbre _fils);
arbre  concat_pere_frere(arbre _pere, arbre _frere);
arbre  creer_noeud(int _nature, int _val_noeud,int num_declaration);
arbre arbre_vide();
void afficher_arbre(arbre _arbre, int indent);
FILE * openfile();
void closefile(FILE *f);
void enregistrer_arbre(arbre _arbre,int indent,FILE *f );
#endif /* arbre_h */

