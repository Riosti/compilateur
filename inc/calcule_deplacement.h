
#include <stdio.h>
#include <stdlib.h>
#include "table_region.h"
#include "table_rep_type.h"
#include "table_declaration.h"
#include "arbre.h"
#include "define_const.h"
#include "fileBC.h"
#include "charger.h"
#include "erreur.h"


int num_dec_val_struct(int dep,int type_struct,int hash_code_champ);
int decalage_type_val(int type_struct,int hash);
int dec_tab(int type,int nbr_param,int index);
int taille_param(int nbr_p,int type);
int taille_tableau(int nbr_p,int type);
int test(int index,int type,int nbr_param);
int nbr_param_du_type(int type);
int deplacement_idf(int num_dec);
