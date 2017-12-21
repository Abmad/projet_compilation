#include "representation_entetes_sous_programmes.h"
#include <stdarg.h>

//table de représentation des types
//et des entêtes de sous-programmes

//ajoute un entier à la table
int addElement(int _elem)//Crée par Dan Robert Tsoumbou Moutimba
{
    tabRepr[indiceSuivant]=_elem;
    indiceSuivant++;
	return indiceSuivant-1;
}

/*Retourne un élément du tableau si il existe*/
int getElement(int _num)
{
	if(_num < LNG_REPRESENTATION) return tabRepr[_num];
	else return -1;
}

/*Initialise le tableau*/
void initRepr()
{
	/*Set à -1 de tous les champs du tableau*/
	memset(tabRepr, -1, (size_t)LNG_REPRESENTATION * sizeof(int));
}

/*Affichage Tableau*/
void afficherRepr()
{
	int itFor;
	printf_couleur(TXT_VERT,"==============================\n");
	printf(" > Table de representation : \n");
	printf_couleur(TXT_VERT,"==============================\n");
	printf("	");
	printf_couleur(BCK_BLEU,"+-----+-----+\n");
	printf("	");
	printf_couleur(BCK_BLEU,"|");
	printf_couleur(TXT_VERT,"INDEX");
	printf_couleur(BCK_BLEU,"|");
	printf_couleur(TXT_VERT," VAL ");
	printf_couleur(BCK_BLEU,"|\n");
	for( itFor = 0; itFor < indiceSuivant; itFor++)
	{
		printf("	");
		printf_couleur(BCK_BLEU,"+-----+-----+\n");
		printf("	");
		printf_couleur(BCK_BLEU,"|");
		if(itFor < 10) printf("  %d  ",itFor);
		else if(itFor < 100) printf(" %d  ",itFor);
		else printf("%d",itFor);
		
		printf_couleur(BCK_BLEU,"|");
		
		if(tabRepr[itFor] < 10) printf("  %d  ",tabRepr[itFor]);
		else if(tabRepr[itFor] < 100) printf(" %d  ",tabRepr[itFor]);
		else printf("%d",tabRepr[itFor]);
		printf_couleur(BCK_BLEU, "|");
		printf_couleur(BCK_NOIR,"\n");
	}
	printf("	");
	printf_couleur(BCK_BLEU,"+-----+-----+\n");
	printf_couleur(TXT_VERT,"==============================\n\n");
}

/*Reserve une place pour le nbr d'élements ou le type*/
void reserveElem()
{
	indiceSuivant++;
}

/*Ajoute un élement à sa place réservée (pour les tailles et les types)*/
int ajoutNbr(int _elem)
{
	int indice = indiceSuivant-1;
	while(tabRepr[indice] != -1) indice --;
	if(tabRepr[indice-1] == -1)
	{
		tabRepr[indice-1] = _elem;
		return indice-1;
	}
	else
	{
		tabRepr[indice] = _elem;
		return indice;
	}
}






void printf_couleur(char *_couleur, char *_texte, ...)
{
	va_list liste;
	char texte_local[2048];
	
	memset(texte_local, 0, sizeof(texte_local));
	va_start(liste, _texte);
	(void) vsprintf(texte_local, _texte, liste);
	va_end(liste);
	
	if (strlen(texte_local) > 0 && texte_local[strlen(texte_local) - 1] == '\n')
	{
		/* On a un retour a la ligne*/
		texte_local[strlen(texte_local) - 1] = 0;
		printf("%s%s%s", _couleur, texte_local, TXT_NORMAL);
		printf("\n");
	}
	else
	{
		printf("%s%s%s", _couleur, texte_local, TXT_NORMAL);
	}
}
