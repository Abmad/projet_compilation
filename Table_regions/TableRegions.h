
#include <stdio.h>
#include "arbre.h"

#define SIZE_TABLE_REG 1000
typedef struct tableRegion{
    int taille;
    int nis;
    noeud arbre;
}tableRegion;

typedef struct region{
    int num_region;
    struct region *previous;
} region;
tableRegion tab[SIZE_TABLE_REG];
int cpt = 0;
//il faut ajouter l'allocation dynamique
void add_val_regtable(int taille, int nis, noeud arbre);
void region_push(region **p_region, int num_region);
int region_pop(region **p_region);
void afficher_table_region();
//tableRegion get_val_regtable();


