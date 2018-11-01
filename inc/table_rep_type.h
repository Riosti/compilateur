#ifndef _TABLE_REP_TYPE_H
#define _TABLE_REP_TYPE_H
#include "hash.h"
#define TAILLE_TAB_REP_TYPE 1000


int Table_rep_type[TAILLE_TAB_REP_TYPE];
int Index_table_rep_type;

void init_table_rep_type();
void rp_ajoute_tableau();
void rp_ajoute_struct();
void rp_ajoute_proc();
void rp_ajoute_fonction();


#endif
