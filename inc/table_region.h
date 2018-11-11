#ifndef _TABLE_REGION
#define _TABLE_REGION
#include "table_rep_type.h"
#define TAILLE_TABLE_REGION 500

typedef struct{
  int taille;
  int nis;
  type_arbre * a;
}cellule_region;

cellule_region table_region[TAILLE_TABLE_REGION];
int index_table_region;


void init_table_region();
int ajoute_arbre_table_region(type_arbre *a );
void nouvelle_region();
int region_actu();
void fin_region();
void ajoute_taille_region(int bc);

#endif
