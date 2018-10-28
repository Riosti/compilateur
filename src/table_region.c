#include "../inc/table_region.h"


void init_table_region(){
  index_table_region=0;
}

void nouvelle_region(){
  index_table_region++;
  empile(index_table_region);
}

int region_actu(){
  return index_table_region;
}

void fin_region(){
  depile();
}

int ajoue_arbre_table_region(type_arbre *a ){
  if(index_table_region==TAILLE_TABLE_REGION){
    fprintf(stderr,"erreur plus de taille dans la table des regions \n");
    exit(-1);
  }
  table_region[index_table_region].taille=0;/*il faut ajouter la taille et le nis !!!! */
  table_region[index_table_region].nis=taille_pile();
  table_region[index_table_region].a=a;
  return 1;
}
