#include "../inc/sauv.h"

void ecrire_noeud(FILE *f,type_arbre *a ){
  if(!arbre_vide(a)){
    fprintf(f,"%d %d %f",a->type,a->noeud,a->noeudf);
    fprintf(f,"fils:\n");
    ecrire_noeud(f,a->fils);
    fprintf(f,"frere:\n");
    ecrire_noeud(f,a->frere);
  }
}

int sauvegarder_arbre(type_arbre *a,char * chemin){
  FILE *f1;
  
  if ((f1=fopen(chemin,"a"))==NULL){
    fprintf(stderr,"erreur ouverture fichier : %s",chemin);
    fclose(f1);
    return -1;
  }

  ecrire_noeud(f1,a);

  fclose(f1);
  return 1;
}
