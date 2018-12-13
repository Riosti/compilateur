#ifndef _ANALYSE_SEMENTIQUE_C
#define _ANALYSE_SEMENTIQUE_C
#include "../inc/analyse_sementique.h"


int num_dec(int num_hash){
  int num_declaration;
  int indice_a_regarder= num_hash;
  if(Tab_dec[indice_a_regarder].nature==-1){
    fprintf(stderr,"%s n'est pas declarer ! ", get_lexem(num_hash));
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




#endif
