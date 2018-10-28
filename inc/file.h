#include <stdio.h>
#include <stdlib.h>

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
