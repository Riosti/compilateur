#ifndef _SAUV_H
#define _SAUV_H
#include "analyse_sementique.h"
/*il faut onner les autres */

int sauvegarder_arbre(type_arbre *a,char * chemin);
int sauvegarde_tables(char *chemin);
void charger_table_hash(FILE *f1);
type_arbre * lire_arbre(FILE *f1);
int erreur_fichier();


#endif
