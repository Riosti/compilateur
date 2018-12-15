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
void genere_table();
#endif