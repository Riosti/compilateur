#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAILLE_TAB_HASH 500 /* taille de la table de structure list_lexem donc nombre max de lexem unique stockable */
#define TAILLE_MAX_LEXEM 100 /*taille max d'un lexem*/

#define NOMBRE_DE_HASH 33 /*taille de la table de hash et aussi nombre +1 de nombre de hash code different */


typedef struct {
  char chaine[TAILLE_MAX_LEXEM];
  int len;
  int suivant;
}list_lexem;/*structure de du stockage des lexem*/

int Table[NOMBRE_DE_HASH];
list_lexem List[TAILLE_TAB_HASH];

int hash_code(char *s);/*fonction de hash code pour transformer une chaine en sont code (int) */
void init_table_hash();/*on initialise la table de hash pour que les affectation sois corect apres*/

/*
cette fonction est definie dans le .c mais ne dois etre utiliser que par la focntion ajoute lexem 

int est_dans_list_lexem(char *lexem);
 */

int ajoute_lexem(char *lexem);/*ajoute un lexeme dans la table de hash et retourn l'indice de ce lexem dans le tableau*/
char * get_lexeme(int num);/*retourn le lexem a l'indice indiquer*/
  
  
