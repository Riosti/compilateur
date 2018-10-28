#include "../inc/table_declaration.h"


void init_table_decla(){
  int i;
  for(i=0;i<TAILLE_TABLE_DECLARATION;i++){
    Tab_dec[i].nature=-1;
    Tab_dec[i].suivant=-1;
  }
}

int test_place_libre(){
  if(next_place_libre >= TAILLE_TABLE_DECLARATION){
    fprintf(stderr,"erreur memoire trop de declaration \n");
    exit(-1);
  }
  return 0;
}

int taille_type(int type){
  if(Tab_dec[type].nature==-1){
    /*erreur*/
    fprintf(stderr,"erreur declaration le type %s n'est pas declare\n",get_lexeme(type));
    exit(-1);
  }
  if(Tab_dec[type].nature!=TYPE_B && Tab_dec[type].nature!=TYPE_T && Tab_dec[type].nature!=TYPE_T ){
    fprintf(stderr,"erreur declaration le type %s n'est pas un type \n",get_lexeme(type));
    exit(-1);
  }
  return Tab_dec[type].description;
}

void ajoute_type_base(int lexem){
  int index=lexem;
  while(Tab_dec[index].suivant!=-1){
    index=Tab_dec[index].suivant=-1;
  }
  if(Tab_dec[index].nature!=-1){
    Tab_dec[index].suivant=next_place_libre;
    index=next_place_libre;
    next_place_libre++;
    test_place_libre();
  }
  Tab_dec[index].nature=TYPE_B;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=sommet_pile();
  Tab_dec[index].description=-1;
  Tab_dec[index].execution=1;
}

void ajoute_variable(int lexem,int type){
  int index=lexem;
  while(Tab_dec[index].suivant!=-1){
    index=Tab_dec[index].suivant=-1;
  }
  if(Tab_dec[index].nature!=-1){
    Tab_dec[index].suivant=next_place_libre;
    index=next_place_libre;
    next_place_libre++;
    test_place_libre();
  }
  Tab_dec[index].nature=VAR;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=sommet_pile();
  Tab_dec[index].description=type;
  Tab_dec[index].execution=taille_type(type);/*je sais pas*/
}


/*il faut regarder pour les deux tab et struct car j'utilise la file de donner donc il faut voir l'ordre et tout et l'implementer */
void ajoute_tableau(){
  
}

void ajoute_struct(){

}


