#include "../inc/arbre.h"

int arbre_vide(type_arbre * a){
  return a==NULL;
}

type_arbre * cree_noeud(int type,int num){/*cree un noeud avec un type et un numero de type entier et renvoie l'adresse du noeud*/
  type_arbre* a;
  a=malloc(sizeof(type_arbre)*1);
  if(a==NULL){
    fprintf(stderr,"erreur allocation mem \n");
  }
  else{
    a->noeud=num;
    a->type=type;
    a->type_final=-1;
    a->type_var=-1;
    a->num_dec=-1;
    a->frere=NULL;
    a->fils=NULL;
  }
  return a;
}

type_arbre * cree_noeud_type(int type,int num,int t_var){/*cree un noeud avec un type et un numero de type entier et renvoie l'adresse du noeud*/
  type_arbre* a;
  a=malloc(sizeof(type_arbre)*1);
  if(a==NULL){
    fprintf(stderr,"erreur allocation mem \n");
  }
  else{
    a->noeud=num;
    a->type=type;
    a->type_var=t_var;
    a->type_final=-1;
    a->num_dec=-1;
    a->frere=NULL;
    a->fils=NULL;
  }
  return a;
}

type_arbre * cree_noeud_f(int type,float num){/*cree un noeud avec un type et un numero de type reel et renvoie l'adresse du noeud*/
  type_arbre* a;
  a=malloc(sizeof(type_arbre)*1);
  if(a==NULL){
    fprintf(stderr,"erreur allocation mem \n");
  }
  else{
    a->noeudf=num;
    a->type=type;
    a->type_final=-1;
    a->type_var=-1;
    a->num_dec=-1;
    a->frere=NULL;
    a->fils=NULL;
  }
  return a;
}

type_arbre * cree_noeud_f_type(int type,float num, int t_val){/*cree un noeud avec un type et un numero de type reel et renvoie l'adresse du noeud*/
  type_arbre* a;
  a=malloc(sizeof(type_arbre)*1);
  if(a==NULL){
    fprintf(stderr,"erreur allocation mem \n");
  }
  else{
    a->noeudf=num;
    a->type=type;
    a->type_var=t_val;
    a->type_final=-1;
    a->num_dec=-1;
    a->frere=NULL;
    a->fils=NULL;
  }
  return a;
}

type_arbre * concat_pere_fils(type_arbre *p,type_arbre *f){/*prend 2 adresse d'arbre le premier est le pere et le deuxieme est le fils et renvoie l'adresse du pere mis a jours*/
  if(p==NULL ){
    fprintf(stderr,"erreur pere est NULL \n");
  }
  else{
    p->fils=f;
  }
  return p;
}

type_arbre * concat_pere_frere(type_arbre *p,type_arbre *f){/*prend 2 adresse d'arbre le premier est le pere et le deuxieme est le frere et renvoie l'adresse du pere mis a jours*/
  if(p==NULL ){
    fprintf(stderr,"erreur pere est NULL \n");
  }
  else{
    p->frere=f;
  }
  return p;
}

void supprime_noeud(type_arbre * a){/*supprime un noeud*/
  free(a);
  a=NULL;
}

void supprime_arbre(type_arbre * a){/*supprime un arbre privilegier cette utilisation*/
  if(a!=NULL){
    supprime_arbre(a->frere);
    supprime_arbre(a->fils);
    supprime_noeud(a);
  }
}

void afficher_arbre(type_arbre * a){
  if(a!=NULL){
    printf("type : %d int :%d float :%f\n",a->type,a->noeud,a->noeudf);
    printf("frere :");
    afficher_arbre(a->frere);
    printf("fils :");
    afficher_arbre(a->fils);
  }
}

void ajoute_type_var(type_arbre *a , int type_var){
  a->type_var=type_var;
}

void ajoute_type_final(type_arbre *a , int type_f){
  a->type_final=type_f;
}

int donne_type_final(type_arbre *a){
  return a->type_final;
}

int donne_num_hash_arbre(type_arbre *a){
  return a->noeud;
}

int donne_type_arbre(type_arbre *a){
  return a->type_var;
}

void ajoute_num_dec(type_arbre *a,int num_dec){
  a->num_dec=num_dec;
}



