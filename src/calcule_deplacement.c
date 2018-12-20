
#include "../inc/calcule_deplacement.h"



int num_dec_val_struct(int dep,int type_struct,int hash_code_champ){
  return dep+decalage_type_val(type_struct,hash_code_champ);
}

int decalage_type_val(int type_struct,int hash){
  int nbr = Tab_dec[type_struct].description;
  nbr++;
  while(Table_rep_type[nbr]!=hash){
    nbr+=3;
  }
  return Table_rep_type[nbr+2];
}


int dec_tab(int type,int nbr_param,int index){
  int n;
  test(index,type,nbr_param);
  n=taille_param(nbr_param+1,type);
  return n*index;
}

int taille_param(int nbr_p,int type){
  int n;
  if(nbr_p <= nbr_param_du_type(type)){
    n=taille_tableau(nbr_p,type);
    return n* taille_param(nbr_p+1,type);
  }
  return 1;
}

int nbr_param_du_type(int type){
  int nbr=Tab_dec[type].description;
  return Table_rep_type[nbr+1];
}

int taille_tableau(int nbr_p,int type){
  int trp= Tab_dec[type].description+2;
  int min,max;
  min=Table_rep_type[nbr_p*2+trp];
  max=Table_rep_type[nbr_p*2+trp+1];
  return max-min+1;
}

int test(int index,int type,int nbr_param){
  int trp=Tab_dec[type].description+2;
  int min,max;
  min=Table_rep_type[index*2+trp];
  max=Table_rep_type[index*2+trp+1];
  if(!(index>=min && index <= max)){
    change_color(KRED);
    print("! erreur ! index hors tableau\n");
    change_color(KNRM);
    exit(-1);
  }
  return 1;
}

