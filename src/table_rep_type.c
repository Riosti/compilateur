#ifndef _TABLE_REP_TYPE_C
#define _TABLE_REP_TYPE_C
#include "../inc/table_rep_type.h"

void init_table_rep_type(){
  Index_table_rep_type=0;
}

void rp_ajoute_tableau(){/*ici on va utiliser la pile et on sais que la pile a ete corectement utiliser par le yacc */
  int index_actuel=Index_table_rep_type+2;
  int num;
  while(!file_vide()){
    num=defile();
    if(file_vide()){
      Table_rep_type[Index_table_rep_type]=num;
      Table_rep_type[Index_table_rep_type+1]=(index_actuel-(Index_table_rep_type+1))/2;
    }
    else{
      Table_rep_type[index_actuel]=num;
      index_actuel++;
    }
  }
  Index_table_rep_type=index_actuel;
}

void rp_ajoute_struct(){
  int index_actuel=Index_table_rep_type+1;
  int num;
  while(!file_vide()){
    num=defile();
    if(!file_vide()){
      Table_rep_type[index_actuel]=num;
      num=defile();
      Table_rep_type[index_actuel+1]=num;
      num=defile();
      Table_rep_type[index_actuel+2]=num;
      index_actuel+=3;
    }
    else{
      fprintf(stdout,"erreur formatage de la file \n");
    }
  }
  Table_rep_type[Index_table_rep_type]=(index_actuel-(Index_table_rep_type))/3;
  Index_table_rep_type=index_actuel;
}

void rp_ajoute_proc(){
  int index_actuel=Index_table_rep_type+1;
  int num;
  while(!file_vide()){
    num=defile();
    if(!file_vide()){
      Table_rep_type[index_actuel]=num;
      num=defile();
      Table_rep_type[index_actuel+1]=num;
      index_actuel+=2;
    }
    else{
      fprintf(stdout,"erreur formatage de la file \n");
    }
  }
  Table_rep_type[Index_table_rep_type]=(index_actuel-(Index_table_rep_type+1))/2;
  Index_table_rep_type=index_actuel;
}

void rp_ajoute_fonction(){
  int index_actuel=Index_table_rep_type+2;
  int num;
  while(!file_vide()){
    num=defile();
    if(!file_vide()){
      Table_rep_type[index_actuel]=num;
      num=defile();
      Table_rep_type[index_actuel+1]=num;
      index_actuel+=2;
    }
    else{
      Table_rep_type[Index_table_rep_type+1]=num;
    }
  }
  Table_rep_type[Index_table_rep_type]=(index_actuel-(Index_table_rep_type+2))/2;
  Index_table_rep_type=index_actuel;
}




#endif
