#ifndef _ANALYSE_SEMENTIQUE_H
#define _ANALYSE_SEMENTIQUE_H
#include "table_declaration.h"

int num_dec(int num_hash);
int type_var(int hash_num);
int type_dun_struct(int la_struct, int hash_champ);
int type_dun_tab(int le_tab);
int test_des_types_arbre(type_arbre* a, type_arbre* a2);
int test_type(type_arbre* a, int type_t);
int donne_type_fonction(int num);
int verif_arg_fonction(int num_f, type_arbre* param);
int verif_arg_procedure(int num_f, type_arbre* param);
int est_une_fonction(int num);
int est_une_procedure(int num);
int test_corp_procedure(type_arbre* a);
int test_corp_fonction(int num_hash, type_arbre* a);
int test_return_dans_si(type_arbre* a, int type_return);
int test_return_dans_liste_instruction(type_arbre* a, int type_return);
#endif
