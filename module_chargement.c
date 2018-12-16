#include "inc/charger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *s){
    fprintf(stderr, "Usage: %s <nom du fichier>\n",s);
}

int main(int argc, char *argv[]){
    //initialisation des variables
    FILE* f = NULL; int i;
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
    for(i=0;i<TAILLE_TABLE_DECLARATION;i++){
	if(Tab_dec[i].nature!=-1){
	    fprintf(stdout,"%d %d %d %d %d %d\n",i,Tab_dec[i].nature,Tab_dec[i].suivant,Tab_dec[i].region,Tab_dec[i].description,Tab_dec[i].execution);
	}
    }
    charger_TabRep(f);
    charger_TabReg(f);
    fclose(f);
    return 1;
}
