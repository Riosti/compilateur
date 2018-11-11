#include "../inc/table_region.h"


void init_table_region(){
  index_table_region=-1;
}

void nouvelle_region(){
  index_table_region++;
  empile(index_table_region);
}

int region_actu(){
  return sommet_pile(); /*avant c etait index_table_region;*/
}

void fin_region(){
  depile();
}

void ajoute_taille_region(int bc){
  if(index_table_region==TAILLE_TABLE_REGION){
    fprintf(stderr,"erreur plus de taille dans la table des regions \n");
    exit(-1);
  }
  table_region[sommet_pile()].taille=bc;
}

int ajoute_arbre_table_region(type_arbre *a ){
  if(index_table_region==TAILLE_TABLE_REGION){
    fprintf(stderr,"erreur plus de taille dans la table des regions \n");
    exit(-1);
  }
  table_region[sommet_pile()].nis=taille_pile()-1;
  table_region[sommet_pile()].a=a;
  return 1;
}
