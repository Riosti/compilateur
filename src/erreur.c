#include "../inc/erreur.h"


void print_color(char *msg,char * color){
  fprintf(stderr,"%s %s",color,msg);
  fprintf(stderr,"%s",KNRM);
}

void change_color(char * color){
  fprintf(stderr,"%s",color);
}

void ajoute_chaine_color(char *final,char *msg,char * color){
  strcat(final,color);
  strcat(final,msg);
  strcat(final,KNRM);
}

void print(char * m){
  fprintf(stderr,"%s",m);
  fprintf(stderr,KNRM);
}

char * chaine_partielle(char*chaine,int begin,int end){
  char *tab;
  tab=malloc(sizeof(char)*500);
  int i=begin;
  int j=0;
  if(begin >= 0 && begin < strlen(chaine) && begin < end){
    while(chaine[i]!='\0' && i<end){
      tab[j]=chaine[i];
      i++;
      j++;
    }
  }
  tab[j]='\0';
  printf("j: %d\n",j);
  return tab;
}

void sous_chaine_color(char *final,char *msg,char *color,int begin,int end){
  char mem[500];
  char *c1,*c2,*c3;
  c1=chaine_partielle(msg,0,begin);
  c2=chaine_partielle(msg,begin,end);
  c3=chaine_partielle(msg,end,500);
  printf("%s\n",c1);
  printf("%s\n",c2);
  printf("%s\n",c3);
  sprintf(mem,"%s%s%s%s%s",c1,color,c2,KNRM,c3);
  free(c1);
  free(c2);
  free(c3);
  strcat(final,mem);
}

int erreur_affiche(){
  FILE* f1;
  int i,j;
  char inst[1000];
  char c='a';
  change_color(KRED);
  if ((f1 = fopen(Fichier_ouvert, "r")) == NULL) {
    fprintf(stderr, "erreur ouverture fichier : %s", Fichier_ouvert);
    fclose(f1);
    return -1;
  }

  print(" ! erreur ! ");
  fprintf(stderr," ligne %d instruction %d\n",Num_lignes,Num_inst);
  i=1;
  while(i!=Num_lignes){
    fscanf(f1,"%c",&c);
    if(c=='\n'){
      i++;
    }
  }
  i=0;
  j=0;
  while(i<Num_inst){
    fscanf(f1,"%c",&c);
    if(c==' '){
      i++;
      inst[j]='\0';
      fprintf(stderr,"%s ",inst);
      j=0;
    }else{
      inst[j]=c;
      j++;
    }
  }
  fscanf(f1,"%s",inst);
  change_color(KRED);
  print(inst);

  fscanf(f1,"%c",&c);
  j=0;
  while(c!='\n'){
    inst[j]=c;
    fscanf(f1,"%c",&c);
    j++;
  }
  inst[j]='\0';
  fprintf(stderr,"%s \n",inst);
    

  fclose(f1);
  exit(-1);
}
