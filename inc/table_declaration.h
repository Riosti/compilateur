#ifndef _TABLE_DECLARATION_H
#define _TABLE_DECLARATION_H
#include "table_region.h"
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
int prochaine_place_libre;
int decalage_bc;


void init_table_decla();
void ajoute_type_base(int lexem);
void ajoute_variable(int lexem,int type);
int test_place_libre();
int taille_type(int type);
void ajoute_tableau(int lexem);
void ajoute_struct(int lexem);
void ajoute_fonction(int lexem);
void ajoute_proc(int lexem);
void fin_proc_fonc_region(type_arbre * a);
void taille_de_la_region();

#endif
