#ifndef _TABLE_REP_TYPE_H
#define _TABLE_REP_TYPE_H
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#define TAILLE_TAB_REP_TYPE 1000


int Table_rep_type[TAILLE_TAB_REP_TYPE];
int Index_table_rep_type;

void init_table_rep_type();
void ajoute_tableau();
void ajoute_struct();
void ajoute_proc();
void ajoute_fonction();


#endif
