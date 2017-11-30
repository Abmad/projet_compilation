#include "representation_entetes_sous_programmes.h"

//table de représentation des types
//et des entêtes de sous-programmes

//ajoute un entier à la table
void addElement(int _elem)//Crée par Dan Robert Tsoumbou Moutimba
{
    tabRepr[indiceSuivant]=_elem;
    indiceSuivant++;
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
	for( itFor = 0; itFor < indiceSuivant; itFor++)
	{
		printf("%d, ",tabRepr[itFor]);
	}

/*
	int itFor, itRepr;
	
	for( itFor = 0; itFor < indiceSuivant; itFor++)
	{
		printf("|");
		for(itRepr = itFor; itRepr <= (itFor+tabRepr[itFor]*3); itRepr++)
		{
			printf("%d  ",tabRepr[itRepr]);
		}
		printf("|\n");
		itFor = itRepr-1;
	}
	*/
}

/*Reserve une place pour le nbr d'élements*/
void reserveElem()
{
	indiceSuivant++;
}

/*Ajoute un élement à sa place réservée (uniquement pour les tailles)*/
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

/*
int main(int argc, char * argv[], char * envp[])
{
	//TEST
	initRepr();
	
	printf("Test ajouts\n");
	
	addElement(3);
	addElement(0);
	addElement(1);
	addElement(2);
	addElement(0);
	addElement(1);
	addElement(2);
	addElement(0);
	addElement(1);
	addElement(2);
	
	addElement(2);
	addElement(0);
	addElement(1);
	addElement(2);
	addElement(0);
	addElement(1);
	addElement(2);
	
	printf("Test affichage du tableau\n");
	afficherRepr();
	
	return 0;
}
*/
