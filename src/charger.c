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
	    printf("erreur charger Tablex1\n");
	    erreur_fichier();
	}
    }
    else{
	printf("erreur charger Tablex2\n");
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
	printf("erreur charger TabDec1\n");
      erreur_fichier();
    }
  }
  else{
      printf("erreur charger Tabdec2\n");
    erreur_fichier();
  }
}



type_arbre * lire_arbre(FILE *f){
  char chaine[100];
  type_arbre *a;
  int type,noeud;
  float noeud_f;
  int type_final,num_dec;
  if(fscanf(f,"%s\n",chaine)==1){
     if( strcmp(chaine,"debut") == 0){
       a=malloc(sizeof(type_arbre));
       fscanf(f," %d %d %f %d %d\n",&type,&noeud,&noeud_f,&type_final,&num_dec);
       a->type=type;
       a->noeud=noeud;
       a->noeudf=noeud_f;
       a->type_final=type_final;
       a->num_dec=num_dec;
       fscanf(f,"%s\n",chaine);
       a->fils=lire_arbre(f);
       fscanf(f,"%s\n",chaine);
       a->frere=lire_arbre(f);
     }
     else{
       a=NULL;
     }
  }
  return a;
}

void charger_TabReg(FILE *f){
  char chaine[100];
  int i;
  i=0;
  if(fscanf(f,"%s\n",chaine)==1){
    if(strcmp(chaine,"table_region:")==0){
      while(fscanf(f," %d ",&i)==1){
	fscanf(f,"%d %d ",&table_region[i].taille,&table_region[i].nis);
	table_region[i].a=lire_arbre(f);
	afficher_arbre(table_region[i].a);
      }
    }
    else{
	printf("erreur charger TabReg1 %s\n", chaine);
      erreur_fichier();
    }
  }
  else{
      printf("erreur charger TabReg2\n");
    erreur_fichier();
  }
}

void charger_TabRep(FILE *f){
  char chaine[100];
  int i,nbr;
  i=0;
  if(fscanf(f,"%s\n",chaine)==1){
    if(strcmp(chaine,"table_rep_type:")==0){
      while(fscanf(f," %d ",&nbr)==1){
	Table_rep_type[i]=nbr;
	i++;
      }
    }
    else{
	printf("erreur charger Tabrep1\n");
      erreur_fichier();
    }
  }
  else{
      printf("erreur charger Tabrep2\n");
    erreur_fichier();
  }
}
