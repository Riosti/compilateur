#include <stdio.h>
#include <stdlib.h>


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
