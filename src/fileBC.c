#include "../inc/fileBC.h"

FileBC initialise(){
    return NULL;
}

int est_vide(FileBC f){
    return f==NULL;
}

FileBC enfile(int BC, FileBC f){
    FileBC p = malloc(sizeof(struct_file));
    if( p == NULL){
	fprintf(stderr, "Erreur d'allocation mémoire\n");
	exit(-1);
    }
    p->bc = BC;
    p->suivant = f;
    return p;
}

int defile(FileBC f){
    int val;
    FileBC p = f;
    while ( !est_vide(p->suivant) )
	p = p->suivant;
    val = p->bc;
    free(p);
    return val;
}
