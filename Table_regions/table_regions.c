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

void init_table_region(){
    table_index = 0;
    num_regions = 0;
    int i;
    for(i=0;i< SIZE_TABLE_REG ;i++){
        table_region[i].nis = -1;
        table_region[i].taille = -1;
        table_region[i].arbre = NULL;
    }
}
void ajout_val_table_reg(int taille, int nis, arbre arbre){
    
    table_region[table_index].taille = taille;
    table_region[table_index].nis = nis;
    table_region[table_index].arbre = arbre;
    table_index++;
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

int get_curr_region(pile_region *region){
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

