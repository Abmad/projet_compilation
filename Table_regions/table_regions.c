//
//  table_region.c
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/17/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include "table_regions.h"
#include "../Table_lexico/tablexico.h"
#include "../Arbre/arbre.h"
void init_table_regions(){
    table_index = 0;
    num_regions = 0;
    p_region = malloc(sizeof(struct region));
    if(p_region == NULL)exit-1;
    int i;
    for(i=0;i< SIZE_TABLE_REG ;i++){
        table_region[i].nis = -1;
        table_region[i].taille = -1;
        table_region[i].arbre = NULL;
    }
}
int taille = 0;
void calcule_taille(arbre _arbre){
    if((*_arbre).val_noeud >= 0)
    taille += table_lexico[(*_arbre).val_noeud].longueur;
    if(_arbre->gauche != NULL){
        calcule_taille(_arbre->gauche);
    }
    if(_arbre->droite != NULL){
        calcule_taille(_arbre->droite);
    }
}
void ajout_val_table_reg(int nis, arbre arbre){
    taille = 0;
    calcule_taille(arbre);
    table_region[table_index].taille = taille;
    table_region[table_index].nis = nis;
    table_region[table_index].arbre = arbre;
    table_index++;
}

void region_empiler()
{
    pile_region new_region = malloc(sizeof(struct region));
    if (new_region != NULL)
    {
        new_region->num_region = num_regions;
        new_region->previous = *p_region;
        *p_region = new_region;
        num_regions++;
    }else
    exit-1;
}

int region_depiler(){
    int ret = -1;
    if(*p_region != NULL){
        pile_region temporaire = (*p_region)->previous;
        ret = (*p_region)->num_region;
        free(*p_region), *p_region = NULL;
        *p_region = temporaire;
        num_regions--;
    }
    return ret;
}

int get_curr_region(){
    int ret =-1;
    if(*p_region != NULL){
        ret = (*p_region)->num_region;
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
void afficher_pile_reg(){
    while(*p_region!=NULL)
        printf("Num Region: %d\n",region_depiler());
    
}

