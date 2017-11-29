//
	
//  main.c
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/16/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define C_NOEUD_PRINCIPAL 0
#define C_CSTE_ENTIERE 1
#define C_CSTE_REEL 2
#define C_CSTE_STRING 3
#define C_CSTE_CHAR 4
#define C_CSTE_BOOL 5
#define C_PLUS_PETIT 6
#define C_PLUS_GRAND 7
#define C_ET 8
#define C_OU 9
#define C_PLUS_PETIT_EGAL 10
#define C_PLUS_GRAND_EGAL 11
#define C_EGAL 12
#define C_DIFFERENT 13
#define C_PLUS 14
#define C_MOINS 15
#define C_MULT 16
#define C_DIV 17
#define C_OPAFF 18
#define C_FAIRE 19
#define C_TANT_QUE 20
#define C_SI 21
#define C_SINON 22
#define C_IDF 23
#define C_LIST 24
#define C_RETOURNE 25
/*
 * Structure d'un noeud
 */
struct noeud
{
    int nature;
    int val_noeud;
    int num_declaration;
    struct noeud * gauche;
    struct noeud * droite;
};
typedef struct noeud * arbre;
arbre  concat_pere_fils(arbre _pere, arbre _fils);
arbre  concat_pere_frere(arbre _pere, arbre _frere);
arbre  creer_noeud(int _nature, int _val_noeud);
arbre arbre_vide();
void afficher_arbre(arbre _arbre, int indent);


/*
 *Fonction de création d'un noeud
 */
arbre  creer_noeud(int _nature, int _val_noeud)
{
    arbre new_noeud = malloc(sizeof(struct noeud));
    if (new_noeud!=NULL){
        new_noeud->val_noeud = _val_noeud;
        new_noeud->nature = _nature;
        new_noeud->gauche = NULL;
        new_noeud->droite = NULL;
        return new_noeud;
    }else{
        exit-1;
    }
    return NULL;
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
    //    afficher_arbre(_fils,0);
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
        // afficher_arbre(_pere,0);
        _pere -> droite = _frere;
    
    return _pere;
}

/*
 *Fonction d'affichage d'un arbre
 */
void afficher_arbre(arbre _arbre, int indent)
{
    
    int i;
    if(_arbre == NULL) return ;
    
    char * type =malloc(sizeof(char));
    
    if(type != NULL){
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
            case C_IDF:
                type = "IDF";
                break;
            case C_RETOURNE:
                type = "RETOURNE";
                break;
            case C_LIST:
                type = "LIST_INSTRUCTION";
                break;
        }
    }else{
        exit-1;
    }
    if(indent==0)printf("\n");
    printf( "|%*s%s:%d\n", indent * 2, "", type, (*_arbre).val_noeud);
    if(_arbre->gauche != NULL){
        afficher_arbre(_arbre->gauche, indent + 1);
    }
    if(_arbre->droite != NULL){
        afficher_arbre(_arbre->droite, indent);
    }
    
}










#define SIZE_TABLE_REG 1000
/* table des regions */
typedef struct tableRegion{
    int taille;
    int nis;
    arbre arbre;
}tableRegion;
tableRegion table_region[SIZE_TABLE_REG];
int num_regions = 0;
/* pile des regions */
struct region{
    int num_region;
    struct region *previous;
};
typedef struct region* pile_region;

int cpt = 0;
void init_table_region();
void ajout_val_table_reg(int taille, int nis, arbre arbre);
void region_empiler(pile_region *p_region);
int region_deipler(pile_region *p_region);
void afficher_table_region();
void afficher_pile_reg(pile_region *pile);

void init_table_region(){
    int i;
    for(i=0;i< SIZE_TABLE_REG ;i++){
        table_region[i].nis = -1;
        table_region[i].taille = -1;
        table_region[i].arbre = NULL;
    }
}
void ajout_val_table_reg(int taille, int nis, arbre arbre){
    
    table_region[cpt].taille = taille;
    table_region[cpt].nis = nis;
    table_region[cpt].arbre = arbre;
    cpt++;
}

void region_empiler(pile_region *p_region)
{
    pile_region new_region = malloc(sizeof(struct region));
    if (new_region)
    {
        new_region->num_region = num_regions;
        new_region->previous = *p_region;
        *p_region = new_region;
        num_regions++;
    }
}

int region_depiler(pile_region *p_region){
    int ret = -1;
    if(*p_region){
        pile_region temporaire = (*p_region)->previous;
        ret = (*p_region)->num_region;
        free(*p_region), *p_region = NULL;
        *p_region = temporaire;
    }
    return ret;
}

int region_top(pile_region *region){
    int ret =-1;
    
    if(region){
        ret = (*region)->num_region;
    }
    
    return ret;
}
void afficher_table_region(){
    int i;
    for(i=0;i< SIZE_TABLE_REG ;i++){
        if(table_region[i].nis == -1 && table_region[i].taille == -1)
            break;
        printf("NIS: %d ",table_region[i].nis);
        printf(" TAILLE: %d ",table_region[i].taille);
        afficher_arbre(table_region[i].arbre, 0);
    }
}
void afficher_pile_reg(pile_region *pile){
	while(*pile!=NULL)
	printf("Num Region: %d\n",region_depiler(pile));    

}


int main(int argc, const char * argv[]) {
    // insert code here...
    init_table_region();
    pile_region * pile = malloc(sizeof(struct region));
    arbre a1 = creer_noeud(C_CSTE_REEL,12);
    arbre a2 = creer_noeud(C_CSTE_ENTIERE,12);
    arbre a3 = creer_noeud(C_PLUS,-999);
    arbre a4 = creer_noeud(C_CSTE_ENTIERE,10);
    arbre a5 = creer_noeud(C_CSTE_ENTIERE,15);
    arbre a6 = creer_noeud(C_MOINS,-998);
    arbre op1 = concat_pere_fils(a3,concat_pere_frere(a1,a2));
    arbre op2 = concat_pere_fils(a6,concat_pere_frere(a4,a5));
    arbre main= concat_pere_frere(op1, op2);
    
    region_empiler(pile);
    region_empiler(pile);
    //afficher_pile_reg(pile);

//void ajout_val_table_reg(int taille, int nis, arbre arbre);
    ajout_val_table_reg(-1,region_depiler(pile),op1);
    ajout_val_table_reg(-1,region_depiler(pile),op2);
    afficher_table_region();	
    //printf("%d\n",(a2).val_noeud);
    //afficher_arbre(main,0);
    printf("Hello, World!\n");
    return 0;
}

