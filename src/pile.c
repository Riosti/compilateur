#include "../inc/pile.h"


void init_pile(){
  Pile_region=NULL;
}

int pile_vide(){
  return Pile_region==NULL;
}

void empile(int num){
  pile *p;
  p=malloc(sizeof(pile)*1);
  if(p==NULL){
    fprintf(stderr,"erreur allocation\n");
    return;
  }
  p->num=num;
  p->suivant=Pile_region;
  Pile_region=p;
}

int sommet_pile(){
  if(Pile_region!=NULL){
    return Pile_region->num;
  }
  fprintf(stderr,"erreur sommet_pile car la pile est vide\n");
  return -1;
}

int depile(){
  int n;
  pile *p;
  if(Pile_region==NULL){
    fprintf(stderr,"erreur depile car la pile est vide\n");
    return -1;
  }
  n=sommet_pile();
  p=Pile_region;
  Pile_region=Pile_region->suivant;
  free(p);
  return n;  
}

int taille_pile(){
  int i=0;
  pile *p;
  p=Pile_region;
  while(p!=NULL){
    i++;
    p=p->suivant;
  }
  return i;
}

int est_dans_pile(int n){
  pile *p;
  p=Pile_region;
  
  while (p!=NULL){
    if(p->num==n){
      return 1;
    }
    p=p->suivant;
  }
  return 0;
}
