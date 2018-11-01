#include "../inc/table_declaration.h"


void init_table_decla(){
  int i;
  prochaine_place_libre=TAILLE_TAB_HASH;
  for(i=0;i<TAILLE_TABLE_DECLARATION;i++){
    Tab_dec[i].nature=-1;
    Tab_dec[i].suivant=-1;
  }
}

int test_place_libre(){
  if(prochaine_place_libre >= TAILLE_TABLE_DECLARATION){
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
  if(Tab_dec[type].nature!=TYPE_B && Tab_dec[type].nature!=TYPE_T && Tab_dec[type].nature!=TYPE_S){
    fprintf(stderr,"erreur declaration le type %s n'est pas un type  \n",get_lexeme(type));
    exit(-1);
  }
  return Tab_dec[type].execution;/*ici ca risque d etre modif*/
}

int indice_pour_lexem(int lexem){
  int index=lexem;
  while(Tab_dec[index].suivant!=-1){
    index=Tab_dec[index].suivant=-1;
  }
  if(Tab_dec[index].nature!=-1){
    Tab_dec[index].suivant=prochaine_place_libre;
    index=prochaine_place_libre;
    prochaine_place_libre++;
    test_place_libre();
  }
  return index;
}

void ajoute_type_base(int lexem){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=TYPE_B;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description=-1;
  Tab_dec[index].execution=1;
}

void ajoute_variable(int lexem,int type){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=VAR;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description=type;
  Tab_dec[index].execution=taille_type(type);/*c'est pas sa car c'est la decalage en fonction de BC*/
}


/*il faut regarder pour les deux tab et struct car j'utilise la file de donner donc il faut voir l'ordre et tout et l'implementer */
int nbr_case_tableau(int index){/*hein ?*/
  int nbr_dim;
  int i;
  int res=1;
  int prem,deux;
  index++;
  nbr_dim=Table_rep_type[index];
  for(i=0;i<nbr_dim;i++){
    index++;
    prem=Table_rep_type[index];
    index++;
    deux=Table_rep_type[index];
    res*=deux-(prem-1);
  }
  return res;
}

void ajoute_tableau(int lexem){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=TYPE_T;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description= Index_table_rep_type;
  rp_ajoute_tableau();
  Tab_dec[index].execution=taille_type(Table_rep_type[Tab_dec[index].description])*nbr_case_tableau(Tab_dec[index].description);
}

int calcule_taille_struct(int index){/*probleme ici pour le calcule du champ exec*/
  int res=0;
  int nbr_var=Table_rep_type[index];
  int i;
  index+=2;
  for(i=0;i<nbr_var;i++){
    res+=taille_type(Table_rep_type[index]);
    index+=3;
  }
  return res;
}

void ajoute_struct(int lexem){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=TYPE_S;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description= Index_table_rep_type;
  rp_ajoute_struct();
  Tab_dec[index].execution=calcule_taille_struct(Tab_dec[index].description);
}
/*jen suis ici pour le yacc il faut verif*/

void ajoute_fonction(int lexem){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=FUNC;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description= Index_table_rep_type;
  rp_ajoute_fonction();
  nouvelle_region();
  Tab_dec[index].execution=region_actu();
}

void ajoute_proc(int lexem){
  int index=indice_pour_lexem(lexem);
  Tab_dec[index].nature=PROC;
  Tab_dec[index].suivant=-1;
  Tab_dec[index].region=region_actu();
  Tab_dec[index].description= Index_table_rep_type;
  rp_ajoute_fonction();
  nouvelle_region();
  Tab_dec[index].execution=region_actu();
}




