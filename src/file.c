#include "../inc/file.h"

void init_file(){
  File_region=NULL;
}

int file_vide(){
  return File_region==NULL;
}

void enfile(int num){
  file *f,*s;
  f=malloc(sizeof(file)*1);
  if(f==NULL){
    fprintf(stderr,"erreur allocation\n");
    return;
  }
  f->num=num;
  f->suivant=NULL;
  if(file_vide()){
    File_region=f;
  }
  else{
    s=File_region;
    while(s->suivant!=NULL){
      s=s->suivant;
    }
    s->suivant=f;
  }
}

int sommet_file(){
  if(file_vide()){
    fprintf(stderr,"impossible file_vide\n");
    return -1;
  }
  return File_region->num;
}

int defile(){
  int res;
  file *s;
  if(file_vide()){
    fprintf(stderr,"impossible file_vide\n");
    return -1;
  }
  res=File_region->num;
  s=File_region;
  File_region=File_region->suivant;
  free(s);
  return res;
}
