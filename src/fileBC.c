#include "../inc/fileBC.h"

FileBC init(){
    return NULL;
}

int est_vide(FileBC f){
    return f==NULL;
}

FileBC enfile(int BC, FileBC f){
    FileBC p = malloc(sizeof(struct_file));
    if( p == NULL){
	fprintf(stderr, "Erreur d'allocation mémoire\n");
	return EXIT_FAILURE;
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
}
