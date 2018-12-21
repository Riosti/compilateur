#ifndef HTML_H
#define HTML_H

#include "../inc/arbre.h"
#include "../inc/define_const.h"
#include "../inc/table_declaration.h"
#include "../inc/table_region.h"
#include "../inc/table_rep_type.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_html();
void end_html();
void genere_html(type_arbre* a);
void new_arbre_html(int t);
void genere_table_d(int x, int n, int s, int r, int d, int e);
void genere_table_r(int x, int taille, int nis, type_arbre* a);
void genere_table_t(int a, int tt);
void genere_table_h(int x, char* c, int a, int b);

#endif