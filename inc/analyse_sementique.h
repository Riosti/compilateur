#ifndef _ANALYSE_SEMENTIQUE_H
#define _ANALYSE_SEMENTIQUE_H
#include "table_declaration.h"

int num_dec(int num_hash);
int type_var(int hash_num);
int type_dun_struct(int la_struct,int hash_champ);
int type_dun_tab(int le_tab);
int test_des_types_arbre(type_arbre *a,type_arbre *a2);
int test_type(type_arbre *a , int type_t);
#endif
