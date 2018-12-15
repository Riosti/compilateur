#include "inc/charger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *s){
    fprintf(stderr, "Usage: %s <nom du fichier>\n",s);
}

int main(int argc, char *argv[]){
    //initialisation des variables
    FILE* f = NULL;
    //verification des arguments
    if(argc != 2){
	usage(argv[0]);
	return EXIT_FAILURE;
    }
    f = fopen(argv[1], "r");
    if (f == NULL){
	fprintf(stderr, "Erreur d'ouverture du fichier\n");
	return EXIT_FAILURE;
    }
    charger_TabLex(f);
    charger_TabDec(f);
    charger_TabRep(f);
    charger_TabReg(f);
    fclose(f);
    return 1;
}
