#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"table_declaration.h"

champsdeclaration tabDeclaration[LNG_DECL];
int suivantDebut = 500;

int add_champs(int _index, int _type, int _region, int _description, int _execution)
{	
	if(tabDeclaration[_index].type == -1)
	{
		tabDeclaration[_index].type = _type;
		tabDeclaration[_index].region = _region;
		tabDeclaration[_index].description = _description;
		tabDeclaration[_index].execution = _execution;
		return _index;
	}
	else
	{
		if(tabDeclaration[_index].suivant == -1)
		{
			tabDeclaration[_index].suivant = suivantDebut;
			add_champs(suivantDebut, _type, _region, _description, _execution);
			suivantDebut++;
		}
		else
		{
			add_champs(tabDeclaration[_index].suivant, _type, _region, _description, _execution);
		}
	}
}

/*
int main(int argc, char * argv[], char * envp[])
{
	//TEST
	init_decl();
	
	printf("Test ajout INT, FLOAT, BOOL, CHAR, STRING\n");
	
	printf("Test ajout TYPE_STRUCT\n");
	add_champs(5,TYPE_STRUCT,-1,0,10,20);
	
	printf("Test ajout TYPE_TABLEAU au meme indice que le precedent (5)\n");
	add_champs(5,TYPE_TABLEAU,-1,0,10,20);
	
	printf("Test ajout TYPE_FONCTION\n");
	add_champs(7,TYPE_FONCTION,-1,0,10,20);
	
	printf("Test ajout TYPE_PROCEDURE\n");
	add_champs(8,TYPE_PROCEDURE,-1,0,10,20);
	
	printf("Test ajout TYPE_VARIABLE\n");
	add_champs(9,TYPE_VARIABLE,-1,0,10,20);
	
	printf("Test affichage du tableau\n");
	afficher_decl();
	
	return 0;
}*/


void init_decl()
{
	//Set à -1 de tous les champs tu tableau de structures
	memset(tabDeclaration, -1, (size_t)LNG_DECL * sizeof(champsdeclaration));
	
	//Ajout des 5 types de bases
	add_champs(0,TYPE_INT,-1,-1,1);
	add_champs(1,TYPE_FLOAT,-1,-1,1);
	add_champs(2,TYPE_BOOL,-1,-1,1);
	add_champs(3,TYPE_CHAR,-1,-1,1);
	add_champs(4,TYPE_STRING,-1,-1,1);
}


void afficher_decl()
{
	int it = 0;
	char * type;
	
	
	for( it = 0; it < LNG_DECL; it++)
	{
		if(tabDeclaration[it].type != -1)
		{
			switch(tabDeclaration[it].type)
			{
				case 0: 
					type = "TYPE_INT";
					break;
				case 1: 
					type = "TYPE_FLOAT";
					break;
				case 2: 
					type = "TYPE_BOOL";
					break;
				case 3: 
					type = "TYPE_CHAR";
					break;
				case 4: 
					type = "TYPE_STRING";
					break;
				case 5: 
					type = "TYPE_STRUCT";
					break;
				case 6: 
					type = "TYPE_TABLEAU";
					break;
				case 7: 
					type = "TYPE_FONCTION";
					break;
				case 8: 
					type = "TYPE_PROCEDURE";
					break;
				case 9: 
					type = "TYPE_VARIABLE";
					break;
			}
		
			printf("%d, %s, %d, %d, %d, %d\n", it, type, tabDeclaration[it].suivant, tabDeclaration[it].region, tabDeclaration[it].description, tabDeclaration[it].execution);
		}
	}
}
