#include "arbre.h"
#include "../Table_lexico/tablexico.h"
#include <stdlib.h>

/*
 *Fonction de création d'un noeud
 */
arbre  creer_noeud(int _nature, int _val_noeud)
{
    arbre new_noeud = malloc(sizeof(struct noeud));
    if (new_noeud!=NULL){
        new_noeud->val_noeud = _val_noeud;
        new_noeud->nature = _nature;
        new_noeud->gauche = NULL;
        new_noeud->droite = NULL;
        //	printf("valnoeud:%d nature:%d\n",_val_noeud,_nature);
        return new_noeud;
    }else{
        exit-1;
    }
}

/*
 *Fonction de création d'un arbre vide
 */
arbre arbre_vide()
{
    return NULL;
}

/*
 *Fonction d'ajout d'un noeud fils à un noeud pere
 */
arbre concat_pere_fils(arbre _pere, arbre _fils)
{
//    afficher_arbre(_fils,0);
    if(_pere != NULL && _fils != NULL)
        _pere->gauche = _fils;
    return _pere;
}

/*
 *Fonction d'ajout d'un noeud frere à un noeud pere
 */
arbre concat_pere_frere(arbre _pere, arbre _frere)
{
    if(_pere != NULL && _frere != NULL)
       // afficher_arbre(_pere,0);
    _pere -> droite = _frere;

    return _pere;
}

/*
 *Fonction d'affichage d'un arbre
 */
void afficher_arbre(arbre _arbre, int indent)
{
    
    int i;
    if(_arbre == NULL) return ;
    
    char * type =malloc(sizeof(char));
    
    if(type != NULL){
        switch((*_arbre).nature)
        {
            case C_NOEUD_PRINCIPAL:
                type = "NOEUD_PRINCIPAL";
                break;
            case C_CSTE_ENTIERE:
                type = "CSTE_ENTIERE";
                break;
            case C_CSTE_REEL:
                type = "CSTE_REEL";
                break;
            case C_CSTE_STRING:
                type = "CSTE_STRING";
                break;
            case C_CSTE_CHAR:
                type = "CSTE_CHAR";
                break;
            case C_CSTE_BOOL:
                type = "CSTE_BOOL";
                break;
            case C_PLUS_PETIT:
                type = "PLUS_PETIT";
                break;
            case C_PLUS_GRAND:
                type = "PLUS_GRAND";
                break;
            case C_ET:
                type = "ET";
                break;
            case C_OU:
                type = "OU";
                break;
            case C_PLUS_PETIT_EGAL:
                type = "PLUS_PETIT_EGAL";
                break;
            case C_PLUS_GRAND_EGAL:
                type = "PLUS_GRAND_EGAL";
                break;
            case C_EGAL:
                type = "EGAL";
                break;
            case C_DIFFERENT:
                type = "DIFFERENT";
                break;
            case C_PLUS:
                type = "PLUS";
                break;
            case C_MOINS:
                type = "MOINS";
                break;
            case C_MULT:
                type = "MULT";
                break;
            case C_DIV:
                type = "DIV";
                break;
            case C_OPAFF: type = "OPAFF";
                break;
            case C_FAIRE: type = "FAIRE";
                break;
            case C_TANT_QUE: type = "TANT_QUE";
                break;
            case C_SI: type = "SI";
                break;
            case C_SINON: type = "SINON";
                break;
            case C_IDF:
                type = "IDF";
                break;
	    case C_RETOURNE:
		type = "RETOURNE";
		break;
	    case C_LIST:
		type = "LIST_INSTRUCTION";
		break;
        }
    }else{
        exit-1;
    }
    if(indent==0)printf("\n");
    printf( "|%*s%s:%d\n", indent * 2, "", type, (*_arbre).val_noeud);
    if(_arbre->gauche != NULL){
        afficher_arbre(_arbre->gauche, indent + 1);
    }
    if(_arbre->droite != NULL){
        afficher_arbre(_arbre->droite, indent);
    }
    
}



