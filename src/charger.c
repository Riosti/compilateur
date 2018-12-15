#include "../inc/charger.h"

int erreur_fichier(){
    fprintf(stderr,"erreur formatage du fichier de sauvegarde \n");
    exit(-1);
}

void charger_TabLex(FILE *f){
    char chaine[100];
    int i;
    if(fscanf(f,"%s\n",chaine)==1){
	if(strcmp(chaine,"hash:")==0){
	    while(fscanf(f," %d ",&i)==1){
		fscanf(f,"%s %d %d \n",List[i].chaine,&List[i].len,&List[i].suivant);
	    }
	}
	else{
	    erreur_fichier();
	}
    }
    else{
	printf("ici\n");
	erreur_fichier();
    }
}

void charger_TabDec(FILE *f){
  char chaine[100];
  int i;
  if(fscanf(f,"%s\n",chaine)==1){
    if(strcmp(chaine,"table_dec:")==0){
      while(fscanf(f," %d ",&i)==1){
	fscanf(f,"%d %d %d %d %d \n",&Tab_dec[i].nature,&Tab_dec[i].suivant,&Tab_dec[i].region,&Tab_dec[i].description,&Tab_dec[i].execution);
      }
    }
    else{
      erreur_fichier();
    }
  }
  else{
    erreur_fichier();
  }
}


type_arbre * lire_arbre(FILE *f){
  char chaine[100];
  type_arbre *a;
  int type,noeud;
  float noeud_f;
  if(fscanf(f,"%s",chaine)==1){
    if(!strcmp(chaine,"vide")){
      a=malloc(sizeof(type_arbre));
      fscanf(f," %d %d %f ",&type,&noeud,&noeud_f);
      a->type=type;
      a->noeud=noeud;
      a->noeudf=noeud_f;
      fscanf(f," %s ",chaine);
      a->frere=lire_arbre(f);
      fscanf(f," %s ",chaine);
      a->fils=lire_arbre(f);
    }
  }
  return a;
}

void charger_TabReg(FILE *f){
  char chaine[100];
  int i;
  i=0;
  if(fscanf(f,"%s\n",chaine)==1){
    if(strcmp(chaine,"table_region")==0){
      while(fscanf(f," %d ",&i)==1){
	fscanf(f,"%d %d ",&table_region[i].taille,&table_region[i].nis);
	table_region[i].a=lire_arbre(f);
      }
    }
    else{
      erreur_fichier();
    }
  }
  else{
    erreur_fichier();
  }
}

void charger_TabRep(FILE *f){
  char chaine[100];
  int i,nbr;
  i=0;
  if(fscanf(f,"%s\n",chaine)==1){
    if(strcmp(chaine,"table_rep_type")==0){
      while(fscanf(f," %d ",&nbr)==1){
	Table_rep_type[i]=nbr;
	i++;
      }
    }
    else{
      erreur_fichier();
    }
  }
  else{
    erreur_fichier();
  }
}
