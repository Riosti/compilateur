#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "hash.h"
#include "erreur.h"
#define TAILLE_TABLE_DECLARATION 5000
#define TYPE_B 1
#define VAR 2
#define TYPE_S 3
#define TYPE_T 4
#define PROC 5
#define FUNC 6

typedef struct{
  int nature;
  int suivant;
  int region;
  int description;
  int execution;
}table_des_declaration;

table_des_declaration Tab_dec[TAILLE_TABLE_DECLARATION];
int next_place_libre=TAILLE_TAB_HASH;


void init_table_decla();
void ajoute_type_base(int lexem);
int test_place_libre();
int taille_type(int type);
