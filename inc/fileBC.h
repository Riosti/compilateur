#ifndef _FILE_BC_
#define _FILE_BC_
//MODULE QUI ME SERA UTILE POUR LE CHAINAGE DYNAMIQUE (BC des régions engobantes)
#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int bc;
    struct elem *suivant;
}struct_file;

typedef struct_file *FileBC;

//initialiser la file
FileBC initialiase();

//Est-elle vide?
int est_vide(FileBC f);

//enfiler
FileBC enfile(int BC, FileBC f);

//defiler (me renvoie l'élément retiré)
//Précondition : la file n'est pas vide
int defile(FileBC f);

#endif
