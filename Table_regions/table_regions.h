//
//  table_region.h
//  Compilation
//
//  Created by Abdelmoghit MADIH on 11/17/17.
//  Copyright © 2017 Abdelmoghit MADIH. All rights reserved.
//
#ifndef table_regions_h
#define table_regions_h

#include <stdio.h>
#include "../Arbre/arbre.h"

#define SIZE_TABLE_REG 1000
/* table des regions */
typedef struct tableRegion{
    int taille;
    int nis;
    arbre arbre;
}tableRegion;
tableRegion table_region[SIZE_TABLE_REG];
int num_regions;
/* pile des regions */
struct region{
    int num_region;
    struct region *previous;
};
typedef struct region* pile_region;
pile_region *p_region;
int table_index;
void init_table_regions();
void ajout_val_table_reg(int taille, int nis, arbre arbre);
void region_empiler();
int region_depiler();
void afficher_table_region();
void afficher_pile_reg();
int get_curr_region();
//tableRegion get_val_regtable();
#endif /* table_regions_h */


