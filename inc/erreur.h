#include <stdio.h>
#include <stdlib.h>
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

void print_color(char *msg,char * color);
void change_color(char * color);
void ajoute_chaine_color(char *final,char *msg,char * color);
void print(char *m);
void sous_chaine_color(char *final,char *msg,char *color,int begin,int end);
