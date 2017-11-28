#include "arbre.h"


/*
 *Fonction de création d'un noeud
 */
arbre  creer_noeud(int _nature, int _val_noeud)
{
    
    arbre new_noeud = malloc(sizeof(new_noeud));
    if(new_noeud){
        new_noeud->val_noeud = _val_noeud;
        new_noeud->nature = _nature;
        new_noeud->gauche = NULL;
        new_noeud->droite = NULL;
        return new_noeud;
    }
    return arbre_vide();
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
        _pere -> droite = _frere;
    return _pere;
}

/*
 *Fonction d'affichage d'un arbre
 */
void afficher_arbre(arbre _arbre, int indent)
{
    char * type = malloc(sizeof(char));
    if(type){
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

                type = "IDF";
                break;
        }
    }else{
        type = "ERROR MALLOC";
    }
    printf( "%*s%s:%d\n", indent * 2, "", type, (*_arbre).val_noeud);
    if(_arbre->gauche){
        afficher_arbre(_arbre->gauche, indent + 1);
    }
    if(_arbre->droite){
        afficher_arbre(_arbre->droite, indent);
    }
}



