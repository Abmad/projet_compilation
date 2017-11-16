#include<stdio.h>
#include<stdlib.h>
#include "arbre.h"

/*
 *Fonction de création d'un noeud
 */
noeud creer_noeud(int _typeNoeud)
{
    noeud *new_noeud = malloc(sizeof(new_noeud));
    new_noeud->noeud = _typeNoeud;
    new_noeud->gauche = NULL;
    new_noeud->droite = NULL;
    
    return *new_noeud;
}

/*
 *Fonction de création d'un arbre (noeud le plus haut)
 */
noeud arbre_vide()
{
    noeud *newArbre = malloc(sizeof(newArbre));
    newArbre->noeud = NOEUD_PRINCIPAL;
    newArbre->gauche = NULL;
    newArbre->droite = NULL;
    
    return *newArbre;
}

/*
 *Fonction d'ajout d'un noeud fils à un noeud pere
 */
noeud concat_pere_fils(noeud *_pere, noeud *_fils)
{
    if(_pere != NULL && _fils != NULL)
        _pere->gauche = _fils;
    return *_pere;
}

/*
 *Fonction d'ajout d'un noeud frere à un noeud pere
 */
noeud concat_pere_frere(noeud *_pere, noeud *_frere)
{
    if(_pere != NULL && _frere != NULL)
        _pere -> droite = _frere;
    return *_pere;
}

/*
*Fonction d'affichage d'un arbre
*/
void afficher_arbre(noeud _arbre)
{
	int itFor;
	char * type;
	
	switch(_arbre.noeud)
	{
	case "NOEUD_PRINCIPAL":
	type = "NOEUD_PRINCIPAL";
	break;
	case "CSTE_ENTIERE":
	type = "CSTE_ENTIERE";
	break;
	case "CSTE_REEL":
	type = "CSTE_REEL";
	break;
	case "CSTE_STRING":
	type = "CSTE_STRING";
	break;
	case "CSTE_CHAR":
	type = "CSTE_CHAR";
	break;
	case "CSTE_BOOL":
	type = "CSTE_BOOL";
	break;
	case "PLUS_PETIT":
	type = "PLUS_PETIT";
	break;
	case "PLUS_GRAND":
	type = "PLUS_GRAND";
	break;
	case "ET":
	type = "ET";
	break;
	case "OU":
	type = "OU";
	break;
	case "PLUS_PETIT_EGAL":
	type = "PLUS_PETIT_EGAL";
	break;
	case "PLUS_GRAND_EGAL":
	type = "PLUS_GRAND_EGAL";
	break;
	case "EGAL":
	type = "EGAL";
	break;
	case "DIFFERENT":
	type = "DIFFERENT";
	break;
	case "PLUS":
	type = "PLUS";
	break;
	case "MOINS":
	type = "MOINS";
	break;
	case "MULT":
	type = "MULT";
	break;
	case "DIV":
	type = "DIV";
	break;
	}
	
	printf("Nom type : %s\n",type);
	
	if(_arbre.gauche) afficher_arbre(_arbre.gauche);
	if(_arbre.droite) afficher_arbre(_arbre.droite);
}

