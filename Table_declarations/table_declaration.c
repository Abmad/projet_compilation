#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"table_declaration.h"


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
	memset(tabDeclaration, -1, (int)LNG_DECL * sizeof(champsdeclaration));
	
	//Ajout des 5 types de bases
	add_champs(0,TYPE_INT,-1,-1,1);
	add_champs(1,TYPE_FLOAT,-1,-1,1);
	add_champs(2,TYPE_BOOL,-1,-1,1);
	add_champs(3,TYPE_CHAR,-1,-1,1);
	add_champs(4,TYPE_STRING,-1,-1,1);
}


void afficher_decl()
{
	int it, itFor;
	char * type;
	
	printf_couleur_decl(TXT_VERT,"==============================\n");
	printf(" > Table des declarations : \n");
	printf_couleur_decl(TXT_VERT,"==============================\n");
	printf_couleur_decl(BCK_BLEU,"+-----+---------------+-----+-----+-----+-----+\n");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"INDEX");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"TYPE           ");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"SUIV ");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"REG  ");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"DESC ");
	printf_couleur_decl(BCK_BLEU,"|");
	printf_couleur_decl(TXT_VERT,"EXEC ");
	printf_couleur_decl(BCK_BLEU,"|\n");
	printf_couleur_decl(BCK_BLEU,"+-----+---------------+-----+-----+-----+-----+\n");
	
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
			printf_couleur_decl(BCK_BLEU,"|");
			if(it < 10) printf("  %d  ",it);
			else if(it < 100) printf(" %d  ",it);
			else printf(" %d ",it);
			printf_couleur_decl(BCK_BLEU,"|");
			printf("%s",type);
			for(itFor = 0; itFor < 15-strlen(type);itFor++) printf(" ");
			printf_couleur_decl(BCK_BLEU,"|");
			
			if(tabDeclaration[it].suivant == -1) printf("  -1 ");
			else if(tabDeclaration[it].suivant < 10) printf("  %d  ",tabDeclaration[it].suivant);
			else if(tabDeclaration[it].suivant < 100) printf(" %d  ",tabDeclaration[it].suivant);
			else printf(" %d ",tabDeclaration[it].suivant);
			printf_couleur_decl(BCK_BLEU,"|");
			
			if(tabDeclaration[it].region == -1) printf("  -1 ");
			else if(tabDeclaration[it].region < 10) printf("  %d  ",tabDeclaration[it].region);
			else if(tabDeclaration[it].region < 100) printf(" %d  ",tabDeclaration[it].region);
			else printf(" %d ",tabDeclaration[it].region);
			printf_couleur_decl(BCK_BLEU,"|");
			
			if(tabDeclaration[it].description == -1) printf("  -1 ");
			else if(tabDeclaration[it].description < 10) printf("  %d  ",tabDeclaration[it].description);
			else if(tabDeclaration[it].description < 100) printf(" %d  ",tabDeclaration[it].description);
			else printf(" %d ",tabDeclaration[it].description);
			printf_couleur_decl(BCK_BLEU,"|");
			
			if(tabDeclaration[it].execution == -1) printf("  -1 ");
			else if(tabDeclaration[it].execution < 10) printf("  %d  ",tabDeclaration[it].execution);
			else if(tabDeclaration[it].execution < 100) printf(" %d  ",tabDeclaration[it].execution);
			else printf(" %d ",tabDeclaration[it].execution);
			printf_couleur_decl(BCK_BLEU,"|\n");
			
			printf_couleur_decl(BCK_BLEU,"+-----+---------------+-----+-----+-----+-----+\n");
		}
	}
	printf_couleur_decl(TXT_VERT,"==============================\n\n");
}

int getDecalage(int _index)
{
	int retour = 0;
	switch(tabDeclaration[_index].type)
	{
		case 9: 
			if(tabDeclaration[_index].description <= 4) retour = 1;
	}
	return retour;
}





void printf_couleur_decl(char *_couleur, char *_texte, ...)
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
