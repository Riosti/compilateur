#ifndef DEFINE_ARBRE_H
#define DEFINE_ARBRE_H
#include "file.h"


typedef struct arbre{
  int noeud;
  float noeudf;
  int type;
  int type_var;
  int type_final;
  int num_dec;
  int num_arg;
  struct arbre *frere;
  struct arbre *fils;
} type_arbre;/*structure type arbre*/

int arbre_vide(type_arbre * a);/*1 si l'arbre est vide*/

type_arbre * cree_noeud(int type,int num);/*cree un noeud avec un type et un numero de type entier et renvoie l'adresse du noeud*/


type_arbre * cree_noeud_type(int type,int num,int t_var);
type_arbre * cree_noeud_f_type(int type,float num, int t_val);

type_arbre * cree_noeud_f(int type,float num);/*cree un noeud avec un type et un numero de type reel et renvoie l'adresse du noeud*/
type_arbre * concat_pere_fils(type_arbre *p,type_arbre *f);/*prend 2 adresse d'arbre le premier est le pere et le deuxieme est le fils et renvoie l'adresse du pere mis a jours*/
type_arbre * concat_pere_frere(type_arbre *p,type_arbre *f);/*prend 2 adresse d'arbre le premier est le pere et le deuxieme est le frere et renvoie l'adresse du pere mis a jours*/
void supprime_noeud(type_arbre * a);/*supprime un noeud*/
void supprime_arbre(type_arbre * a);/*supprime un arbre privilegier cette utilisation*/
void afficher_arbre(type_arbre * a);

void ajoute_type_var(type_arbre *a , int type_var);

int donne_num_hash_arbre(type_arbre *a);

int donne_type_arbre(type_arbre *a);

int donne_type_final(type_arbre *a);

void ajoute_type_final(type_arbre *a , int type_f);

void ajoute_num_dec(type_arbre *a,int num_dec);

#endif
