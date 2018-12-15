#ifndef _ANALYSE_SEMENTIQUE_C
#define _ANALYSE_SEMENTIQUE_C
#include "../inc/analyse_sementique.h"


int num_dec(int num_hash){
  int num_declaration;
  int indice_a_regarder= num_hash;
  if(Tab_dec[indice_a_regarder].nature==-1){
    fprintf(stderr,"%s n'est pas declarer ! ", get_lexeme(num_hash));
    exit(-1);
  }
  num_declaration=num_hash;
  indice_a_regarder=Tab_dec[indice_a_regarder].suivant;
    
    
  while(indice_a_regarder!=-1){
    if(est_dans_pile(Tab_dec[indice_a_regarder].region)){
      num_declaration=indice_a_regarder;
    }
    indice_a_regarder=Tab_dec[indice_a_regarder].suivant;
  }
  return  num_declaration;
}


int type_var(int hash_num){
  int num_declaration;
  int indice_a_regarder=hash_num;
  if(Tab_dec[indice_a_regarder].nature==-1){
    fprintf(stderr,"%s n'est pas declarer ! ", get_lexeme(hash_num));
    exit(-1);
  }
  num_declaration=hash_num;
  indice_a_regarder=Tab_dec[indice_a_regarder].suivant;
    
    
  while(indice_a_regarder!=-1){
    if(est_dans_pile(Tab_dec[indice_a_regarder].region)){
      num_declaration=indice_a_regarder;
    }
    indice_a_regarder=Tab_dec[indice_a_regarder].suivant;
  }
  return Tab_dec[num_declaration].description;
}

int type_dun_struct(int la_struct,int hash_champ){
  int num_dans_tab_rep_type=Tab_dec[la_struct].description;
  int nbr_champ=Table_rep_type[num_dans_tab_rep_type];
  int i=0;
  while(i<nbr_champ){
    if(Table_rep_type[num_dans_tab_rep_type+1+i*3]==hash_champ){
      return Table_rep_type[num_dans_tab_rep_type+2+i*3];
    }
    i++;
  }

  fprintf(stderr,"le champ %s n'existe pas dans la structure %s\n",get_lexeme(hash_champ),get_lexeme(la_struct));

  exit(-1);
}

int type_dun_tab(int le_tab){
  return Table_rep_type[Tab_dec[le_tab].description];
}


int test_des_types_arbre(type_arbre *a,type_arbre *a2){
  if(donne_type_final(a)!= donne_type_final(a2)){
    fprintf(stderr,"type differents\n");
    return 0;
  }
  return 1;
}

int test_type(type_arbre *a , int type_t){
  if(donne_type_final(a)!=type_t){
    fprintf(stderr,"type diff\n");
    return 0;
  }
  return 1;
}






#endif
