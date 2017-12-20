#include<stdio.h>
#include<stdlib.h>
#include "../Arbre/arbre.h"
#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_BOOL 2
#define TYPE_CHAR 3
#define TYPE_STRING 4

#define TYPE_STRUCT 5
#define TYPE_TABLEAU 6
#define TYPE_FONCTION C_FUNC_PROC
#define TYPE_PROCEDURE C_FUNC_PROC
#define TYPE_VARIABLE 9

#define LNG_DECL 1000

/*
 * Structure d'un noeud
 */
struct champs
{
    int type;
    int suivant;
    int region;
    int description;
    int execution;
};
typedef struct champs champsdeclaration;
champsdeclaration tabDeclaration[LNG_DECL];

/*
 * Fonctions
 */
int add_champs(int _index, int _type, int _region, int _description, int _execution);
void afficher_decl();
void init_decl();

