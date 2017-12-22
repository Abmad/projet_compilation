#include<stdio.h>
#include<stdlib.h>
#include <stdarg.h>

/* All attributes off */
#define TXT_NORMAL	"\x1B[0m"

#define TXT_NOIR	"\x1B[30m"
#define TXT_ROUGE	"\x1B[31m"
#define TXT_VERT	"\x1B[32m"
#define TXT_JAUNE	"\x1B[33m"
#define TXT_BLEU	"\x1B[34m"
#define TXT_MAGENTA	"\x1B[35m"
#define TXT_CYAN	"\x1B[36m"
#define TXT_BLANC	"\x1B[37m"

#define BCK_NOIR	"\x1B[40m"
#define BCK_ROUGE	"\x1B[41m"
#define BCK_VERT	"\x1B[42m"
#define BCK_JAUNE	"\x1B[43m"
#define BCK_BLEU	"\x1B[44m"
#define BCK_MAGENTA	"\x1B[45m"
#define BCK_CYAN	"\x1B[46m"
#define BCK_BLANC	"\x1B[47m"

#define MIX_COULEUR(x,y) (x y)

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

typedef struct pile
{
    int donnee; /* La donnée que notre pile stockera. */
    struct pile *precedent; /* Pointeur vers l'élément précédent de la pile. */
} Pile;

champsdeclaration tabDeclaration[LNG_DECL];

/*
 * Fonctions
 */
int add_champs(int _index, int _type, int _region, int _description, int _execution);
void afficher_decl();
void init_decl();
int getDecalage(int _index);
void printf_couleur_decl(char *_couleur, char *_texte, ...);

