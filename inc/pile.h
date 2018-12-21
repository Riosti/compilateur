#ifndef DEFINE_PILE
#define DEFINE_PILE
#include "erreur.h"


typedef struct pile{
  int num;
  struct pile * suivant;
}pile;


pile *Pile_region;

void init_pile();
int pile_vide();
void empile(int num);
int sommet_pile();
int depile();
int taille_pile();
int est_dans_pile(int n);
#endif
