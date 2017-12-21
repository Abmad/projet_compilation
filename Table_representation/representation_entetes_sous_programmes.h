#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
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

#define LNG_REPRESENTATION 200

int tabRepr[LNG_REPRESENTATION];
int indiceSuivant;
void printf_couleur(char *_couleur, char *_texte, ...);


/*Ajout d'un élément dans le tableau*/
int addElement(int _elem);

int getElement(int _num);
void initRepr();
void afficherRepr();
void reserveElem();
int ajoutNbr(int _elem);
