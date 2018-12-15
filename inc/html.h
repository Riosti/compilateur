#ifndef HTML_H
#define HTML_H

#include "../inc/define_const.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_html();
void end_html();
void genere_html(type_arbre* a);
void new_arbre_html(int t);
void genere_table_d(int n, int s, int r, int d, int e);
void genere_table_r(int taille, int nis);
void genere_table_t(int a, int tt);

#endif