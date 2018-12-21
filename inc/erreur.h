#ifndef DEFINE_ERREUR_H
#define DEFINE_ERREUR_H
#include "define_const.h"
#include <string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define CLI "\33[5m"

int Num_lignes;
int Num_inst;
int Num_mots_lu;
char Fichier_ouvert[1000];

void print_color(char *msg,char * color);
void change_color(char * color);
void ajoute_chaine_color(char *final,char *msg,char * color);
void print(char *m);
void sous_chaine_color(char *final,char *msg,char *color,int begin,int end);
int erreur_affiche();
#endif
