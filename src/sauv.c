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

void ecrire_tables(FILE *f1){
  int i;
  fprintf(f1,"hash:\n");
  for(i=0;i<Table[0];i++){
    fprintf(f1,"%s %d %d\n",List[i].chaine,List[i].len,List[i].suivant);
  }

  fprintf(f1,"\ntable_dec:\n");
  for(i=0;i<TAILLE_TABLE_DECLARATION;i++){
    if(Tab_dec[i].nature!=-1){
      fprintf(f1,"%d %d %d %d %d %d\n",i,Tab_dec[i].nature,Tab_dec[i].suivant,Tab_dec[i].region,Tab_dec[i].description,Tab_dec[i].execution);
    }
  }

  fprintf(f1,"\ntable_rep_type\n");
  for(i=0;i<Index_table_rep_type;i++){
    fprintf(f1,"%d ",Table_rep_type[i]);
  }
}

int sauvegarde_tables(char *chemin){
  FILE *f1;
  if((f1=fopen(chemin,"a"))==NULL){
    fprintf(stderr,"erreur ouverture fichier : %s",chemin);
    fclose(f1);
    return -1;
  }

  ecrire_tables(f1);

  fclose(f1);
  return 1;
}
