#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LNG_REPRESENTATION 200

int tabRepr[LNG_REPRESENTATION];
int indiceSuivant;

int addElement(int _elem);
int getElement(int _num);
void initRepr();
void afficherRepr();
void reserveElem();
int ajoutNbr(int _elem);
