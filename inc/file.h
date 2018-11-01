#ifndef DEFINE_FILE_H
#define DEFINE_FILE_H
#include "pile.h"

typedef struct file{
  int num;
  struct file *suivant;
}file;

file *File_region;

void init_file();
int file_vide();
void enfile(int num);
int sommet_file();
int defile();

#endif
