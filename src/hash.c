#include "../inc/hash.h"

/*fonction de hash code pour transformer une chaine en sont code (int) */
int hash_code(char *s){
  int i=0,somme=0;
  while(s[i]!='\0'){
    somme+=s[i];
    i++;
  }
  return (somme%NOMBRE_DE_HASH-1)+1;// le hash 0 n'est pas autoriser
}

void init_table_hash(){/*on initialise la table de hash pour que les affectation sois corect apres*/
  int i;
  Table[0]=0;
  for(i=1;i<=NOMBRE_DE_HASH;i++){
    Table[i]=-1;
  }
}

int est_dans_list_lexem(char *lexem){/*test si un lexem est dans la table de hash retourn -1 si le lexem n'est pas dans la table et retourn sa position dans la table si il y est */
  int len,hash,suivant;
  hash=hash_code(lexem);
  len=strlen(lexem);
  suivant=Table[hash];
  if(suivant==-1){
    return -1;
  }
  else{
    while(suivant!=-1){
      if(List[suivant].len==len){
	if(strcmp(List[suivant].chaine,lexem)==0){
	  return suivant;
	}
      }
      suivant=List[suivant].suivant;
    }
    return -1;
  }
}

int ajoute_lexem(char *lexem){/*ajoute un lexeme dans la table de hash et retourn l'indice de ce lexem dans le tableau*/
  int len,hash,prochain,suivant,indice;
  hash=hash_code(lexem);
  len=strlen(lexem);
  prochain=Table[0];
  indice=est_dans_list_lexem(lexem);
  if(indice==-1){
    if(Table[hash]==-1){
      Table[hash]=prochain;
    }
    else{
      suivant=Table[hash];
      while(List[suivant].suivant!=-1){
	suivant=List[suivant].suivant;
      }
      List[suivant].suivant=prochain;
    }
    List[prochain].len=len;
    List[prochain].suivant=-1;
    memcpy(List[prochain].chaine,lexem,len+1);
    Table[0]++;
    return Table[0]-1;
  }
  return indice;
}

char * get_lexeme(int num){/*retourn le lexem a l'indice indiquer*/
  return List[num].chaine;
}
