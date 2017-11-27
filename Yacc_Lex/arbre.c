#include "arbre.h"


/*
 *Fonction de création d'un noeud
 */
arbre * creer_noeud(int _nature, int _val_noeud)
{
    arbre *new_noeud = malloc(sizeof(new_noeud));
    new_noeud->val_noeud = _val_noeud;
    new_noeud->nature = _nature;
    new_noeud->gauche = NULL;
    new_noeud->droite = NULL;
    
    return new_noeud;
}

/*
 *Fonction de création d'un arbre vide
 */
arbre* arbre_vide()
{
    return NULL;
}

/*
 *Fonction d'ajout d'un noeud fils à un noeud pere
 */
arbre * concat_pere_fils(arbre *_pere, arbre *_fils)
{
    if(_pere != NULL && _fils != NULL)
        _pere->gauche = _fils;
    return _pere;
}

/*
 *Fonction d'ajout d'un noeud frere à un noeud pere
 */
arbre * concat_pere_frere(arbre *_pere, arbre *_frere)
{
    if(_pere != NULL && _frere != NULL)
        _pere -> droite = _frere;
    return _pere;
}

/*
 *Fonction d'affichage d'un arbre
 */
void afficher_arbre(arbre * _arbre, int indent)
{
    char * type = malloc(sizeof(char));
    if(type){
        switch((*_arbre).nature)
        {
            case NOEUD_PRINCIPAL:
                type = "NOEUD_PRINCIPAL";
                break;
            case CSTE_ENTIERE:
                type = "CSTE_ENTIERE";
                break;
            case CSTE_REEL:
                type = "CSTE_REEL";
                break;
            case CSTE_STRING:
                type = "CSTE_STRING";
                break;
            case CSTE_CHAR:
                type = "CSTE_CHAR";
                break;
            case CSTE_BOOL:
                type = "CSTE_BOOL";
                break;
            case PLUS_PETIT:
                type = "PLUS_PETIT";
                break;
            case PLUS_GRAND:
                type = "PLUS_GRAND";
                break;
            case ET:
                type = "ET";
                break;
            case OU:
                type = "OU";
                break;
            case PLUS_PETIT_EGAL:
                type = "PLUS_PETIT_EGAL";
                break;
            case PLUS_GRAND_EGAL:
                type = "PLUS_GRAND_EGAL";
                break;
            case EGAL:
                type = "EGAL";
                break;
            case DIFFERENT:
                type = "DIFFERENT";
                break;
            case PLUS:
                type = "PLUS";
                break;
            case MOINS:
                type = "MOINS";
                break;
            case MULT:
                type = "MULT";
                break;
            case DIV:
                type = "DIV";
                break;
        }
    }else{
        type = "ERROR MALLOC";
    }
    printf( "%*s%s:%s\n", indent * 2, "", type, (*_arbre).val_noeud);
    if(_arbre->gauche){
        afficher_arbre(_arbre->gauche, indent + 1);
    }
    if(_arbre->droite){
        afficher_arbre(_arbre->droite, indent);
    }
}



