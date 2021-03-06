#include "../inc/sauv.h"
#include "../inc/html.h"

void ecrire_noeud(FILE* f, type_arbre* a)
{
  if (!arbre_vide(a)) {
    fprintf(f, "debut \n");
    fprintf(f, "%d %d %f %d %d \n", a->type, a->noeud, a->noeudf,a->type_final,a->num_dec);
    fprintf(f, "fils: \n");
    ecrire_noeud(f, a->fils);
    fprintf(f, "frere: \n");
    ecrire_noeud(f, a->frere);
  } else {
    fprintf(f, "vide \n");
  }
}

int sauvegarder_arbre(type_arbre* a, char* chemin)
{
    FILE* f1;

    if ((f1 = fopen(chemin, "a")) == NULL) {
        fprintf(stderr, "erreur ouverture fichier : %s", chemin);
        fclose(f1);
        return -1;
    }
    ecrire_noeud(f1, a);

    fclose(f1);
    return 1;
}

void ecrire_tables(FILE* f1)
{
    int i;
    fprintf(f1, "hash:\n");
    for (i = 0; i < Table[0]; i++) {
        fprintf(f1, "%d %s %d %d\n", i, List[i].chaine, List[i].len, List[i].suivant);
        genere_table_h(i, List[i].chaine, List[i].len, List[i].suivant);
    }

    fprintf(f1, "\ntable_dec:\n");
    for (i = 0; i < TAILLE_TABLE_DECLARATION; i++) {
        if (Tab_dec[i].nature != -1) {
            fprintf(f1, "%d %d %d %d %d %d\n", i, Tab_dec[i].nature, Tab_dec[i].suivant, Tab_dec[i].region, Tab_dec[i].description, Tab_dec[i].execution);
            genere_table_d(i, Tab_dec[i].nature, Tab_dec[i].suivant, Tab_dec[i].region, Tab_dec[i].description, Tab_dec[i].execution);
        }
    }

    fprintf(f1, "\ntable_rep_type:\n");
    for (i = 0; i < Index_table_rep_type; i++) {
        fprintf(f1, "%d\n", Table_rep_type[i]);
        genere_table_t(i, Table_rep_type[i]);
    }

    fprintf(f1, "\ntable_region:\n");
    for (i = 0; i <= index_table_region; i++) {
        fprintf(f1, "%d %d %d ", i, table_region[i].taille, table_region[i].nis);
        ecrire_noeud(f1, table_region[i].a);
        genere_table_r(i, table_region[i].taille, table_region[i].nis, table_region[i].a);
        fprintf(f1, "\n");
    }
}

int sauvegarde_tables(char* chemin)
{
    FILE* f1;
    if ((f1 = fopen(chemin, "a")) == NULL) {
        fprintf(stderr, "erreur ouverture fichier : %s", chemin);
        fclose(f1);
        return -1;
    }

    ecrire_tables(f1);

    fclose(f1);
    return 1;
}

void charger_table_hash(FILE* f1)
{
    char chaine[100];
    int i;
    if (fscanf(f1, "%s\n", chaine) == 1) {
        if (strcmp(chaine, "hash") == 0) {
            while (fscanf(f1, " %d ", &i) == 1) {
                fscanf(f1, "%s %d %d \n", List[i].chaine, &List[i].len, &List[i].suivant);
            }
        } else {
            erreur_fichier();
        }
    } else {
        erreur_fichier();
    }
}

void charger_table_dec(FILE* f1)
{
    char chaine[100];
    int i;
    if (fscanf(f1, "%s\n", chaine) == 1) {
        if (strcmp(chaine, "table_dec") == 0) {
            while (fscanf(f1, " %d ", &i) == 1) {
                fscanf(f1, "%d %d %d %d %d \n", &Tab_dec[i].nature, &Tab_dec[i].suivant, &Tab_dec[i].region, &Tab_dec[i].description, &Tab_dec[i].execution);
            }
        } else {
            erreur_fichier();
        }
    } else {
        erreur_fichier();
    }
}

void charger_table_rep_type(FILE* f1)
{
    char chaine[100];
    int i, nbr;
    i = 0;
    if (fscanf(f1, "%s\n", chaine) == 1) {
        if (strcmp(chaine, "table_rep_type") == 0) {
            while (fscanf(f1, " %d ", &nbr) == 1) {
                Table_rep_type[i] = nbr;
                i++;
            }
        } else {
            erreur_fichier();
        }
    } else {
        erreur_fichier();
    }
}

void charger_table_region(FILE* f1)
{
    char chaine[100];
    int i;
    i = 0;
    if (fscanf(f1, "%s\n", chaine) == 1) {
        if (strcmp(chaine, "table_region") == 0) {
            while (fscanf(f1, " %d ", &i) == 1) {
                fscanf(f1, "%d %d ", &table_region[i].taille, &table_region[i].nis);
                table_region[i].a = lire_arbre(f1);
            }
        } else {
            erreur_fichier();
        }
    } else {
        erreur_fichier();
    }
}

int erreur_fichier()
{
    fprintf(stderr, "erreur formatage du fichier de sauvegarde \n");
    exit(-1);
}

type_arbre* lire_arbre(FILE* f1)
{
    char chaine[100];
    type_arbre* a;
    int type, noeud;
    float noeud_f;
    if (fscanf(f1, "%s", chaine) == 1) {
        if (!strcmp(chaine, "vide")) {
            a = malloc(sizeof(type_arbre));
            fscanf(f1, " %d %d %f ", &type, &noeud, &noeud_f);
            a->type = type;
            a->noeud = noeud;
            a->noeudf = noeud_f;
            fscanf(f1, " %s ", chaine);
            a->frere = lire_arbre(f1);
            fscanf(f1, " %s ", chaine);
            a->fils = lire_arbre(f1);
        }
    }
    return a;
}
