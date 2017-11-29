#include <stdio.h>
#include <stdlib.h>

#include "TableRegions.h"



void add_val_regtable(int taille, int nis, noeud arbre){
    tab[cpt].taille = taille;
    tab[cpt].nis = nis;
    tab[cpt].arbre = arbre;
    cpt++;
}

void region_push(region **p_region, int num_region)
{
    region *new_region = malloc(sizeof *new_region);
    if (new_region)
    {
        new_region->num_region = num_region;
        new_region->previous = *p_region;
        *p_region = new_region;
    }
}

int region_pop(region **p_region){
    int ret = -1;
    if(*p_region){
        region *temporaire = (*p_region)->previous;
        ret = (*p_region)->num_region;
        free(*p_region), *p_region = NULL;
        *p_region = temporaire;
    }
    return ret;
}

int region_head(region **region){
    int ret =-1;
    
    if(region){
        ret = (*region)->num_region;
    }
    
    return ret;
}
void afficher_table_region(){
    int i;
    for(i=0;i< SIZE_TABLE_REG ;i++){
        printf("%i",tab[i].nis);
        printf("%i",tab[i].taille);
       
    }
}

