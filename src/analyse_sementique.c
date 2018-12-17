#ifndef _ANALYSE_SEMENTIQUE_C
#define _ANALYSE_SEMENTIQUE_C
#include "../inc/analyse_sementique.h"

int num_dec(int num_hash)
{
    int num_declaration;
    int indice_a_regarder = num_hash;
    if (Tab_dec[indice_a_regarder].nature == -1) {
        fprintf(stderr, "%s n'est pas declarer ! \n", get_lexeme(num_hash));
        exit(-1);
    }
    num_declaration = -1;
    indice_a_regarder = num_hash;

    while (indice_a_regarder != -1) {
        if (est_dans_pile(Tab_dec[indice_a_regarder].region)) {
            num_declaration = indice_a_regarder;
        }
        indice_a_regarder = Tab_dec[indice_a_regarder].suivant;
    }

    if (num_declaration == -1) {
        fprintf(stderr, "%s n'est pas declarer ! \n", get_lexeme(num_hash));
        exit(-1);
    }
    return num_declaration;
}

int type_var(int hash_num)
{
    int num_declaration;
    int indice_a_regarder = hash_num;
    if (Tab_dec[indice_a_regarder].nature == -1) {
        fprintf(stderr, "%s n'est pas declarer ! \n", get_lexeme(hash_num));
        exit(-1);
    }
    num_declaration = hash_num;
    indice_a_regarder = Tab_dec[indice_a_regarder].suivant;

    while (indice_a_regarder != -1) {
        if (est_dans_pile(Tab_dec[indice_a_regarder].region)) {
            num_declaration = indice_a_regarder;
        }
        indice_a_regarder = Tab_dec[indice_a_regarder].suivant;
    }
    return Tab_dec[num_declaration].description;
}

int type_dun_struct(int la_struct, int hash_champ)
{
    int num_dans_tab_rep_type = Tab_dec[la_struct].description;
    int nbr_champ = Table_rep_type[num_dans_tab_rep_type];
    int i = 0;
    while (i < nbr_champ) {
        if (Table_rep_type[num_dans_tab_rep_type + 1 + i * 3] == hash_champ) {
            return Table_rep_type[num_dans_tab_rep_type + 2 + i * 3];
        }
        i++;
    }

    fprintf(stderr, "le champ %s n'existe pas dans la structure %s\n", get_lexeme(hash_champ), get_lexeme(la_struct));

    exit(-1);
}

int type_dun_tab(int le_tab)
{
    if (Tab_dec[le_tab].nature == TYPE_T) {
        return Table_rep_type[Tab_dec[le_tab].description];
    } else {
        fprintf(stderr, "le champ %s n'est pas un tableau\n", get_lexeme(le_tab));

        exit(-1);
    }
}

int test_des_types_arbre(type_arbre* a, type_arbre* a2)
{
    if (donne_type_final(a) != donne_type_final(a2)) {
        fprintf(stderr, "type differents\n");
        return 0;
    }
    return 1;
}

int test_type(type_arbre* a, int type_t)
{
    if (donne_type_final(a) != type_t) {
        fprintf(stderr, "type diff\n");
        return 0;
    }
    return 1;
}

int donne_type_fonction(int num)
{
    if (Tab_dec[num].nature == FUNC) {
        return Table_rep_type[Tab_dec[num].description + 1];
    } else {
        fprintf(stderr, "le champ %s n'est pas une fonction", get_lexeme(num));

        exit(-1);
    }
}

int nombre_param_proc_fonc(int num)
{
    return Table_rep_type[Tab_dec[num].description];
}

int type_arg_n_fonction(int num, int n)
{
    return Table_rep_type[Tab_dec[num].description + 3 + n * 2];
}

int type_arg_n_procedure(int num, int n)
{
    return Table_rep_type[Tab_dec[num].description + 2 + n * 2];
}

int verif_arg_fonction(int num_f, type_arbre* param)
{
    int nbr_param, i;
    type_arbre* a = param;
    num_f = num_dec(num_f);
    i = 0;
    nbr_param = nombre_param_proc_fonc(num_f);
    while (i < nbr_param) {
        if (a == NULL) {
            fprintf(stderr, "il n'y a pas assez de parametre a la fonction %s ici %d sont donner elle attend %d param", get_lexeme(num_f), i, nbr_param);
            exit(-1);
        }

        fprintf(stderr, "type de l'arg %d est %d\n", i, type_arg_n_fonction(num_f, i));

        if (!test_type(a, type_arg_n_fonction(num_f, i))) {
            fprintf(stderr, "l'argument n° %d de la fonction %s n'est pas du bon type\n", i, get_lexeme(num_f));
            exit(-1);
        }
        a = a->frere;
        i++;
    }
    if (a != NULL) {
        fprintf(stderr, "il ya trop d'arg pour la fonction %s elle attend %d arg\n", get_lexeme(num_f), nbr_param);
        exit(-1);
    }
    return 1;
}

int verif_arg_procedure(int num_f, type_arbre* param)
{
    int nbr_param, i;
    type_arbre* a = param;
    num_f = num_dec(num_f);
    i = 0;
    nbr_param = nombre_param_proc_fonc(num_f);
    while (i < nbr_param) {
        if (a == NULL) {
            fprintf(stderr, "il n'y a pas assez de parametre a la procedure %s ici %d sont donner elle attend %d param", get_lexeme(num_f), i, nbr_param);
            exit(-1);
        }
        if (!test_type(a, type_arg_n_procedure(num_f, i))) {
            fprintf(stderr, "l'argument n° %d de la procedure %s n'est pas du bon type\n", i, get_lexeme(num_f));
            exit(-1);
        }
        a = a->frere;
        i++;
    }
    if (a != NULL) {
        fprintf(stderr, "il ya trop d'arg pour la procedure %s elle attend %d arg\n", get_lexeme(num_f), nbr_param);
        exit(-1);
    }
    return 1;
}

int est_une_fonction(int num)
{
    return Tab_dec[num].nature == FUNC;
}

int est_une_procedure(int num)
{
    return Tab_dec[num].nature == PROC;
}

int est_une_var(int num)
{
    return Tab_dec[num].nature == VAR;
}

int test_return_dans_liste_instruction(type_arbre* a, int type_return)
{
    if (a == NULL) {
        return 0;
    }
    if (a->type == A_RETURN) {
        if (donne_type_final(a) == type_return) {
            return 1;
        } else {
            fprintf(stderr, "erreur sur le type de renvoie %d il dois etre de type %d\n", donne_type_final(a), type_return);
            exit(-1);
        }
    }
    if (a->type == A_SI) {
        return test_return_dans_si(a, type_return);
    }
    return test_return_dans_liste_instruction(a->fils, type_return) || test_return_dans_liste_instruction(a->frere, type_return);
}

int test_return_dans_si(type_arbre* a, int type_return)
{
    return test_return_dans_liste_instruction(a->fils->fils, type_return) && test_return_dans_liste_instruction(a->fils->frere->fils, type_return);
}

int test_corp_fonction(int num_hash, type_arbre* a)
{
    int type_return = donne_type_fonction(num_dec(num_hash));
    if (!test_return_dans_liste_instruction(a, type_return)) {
        fprintf(stderr, " il n'y a pas de return ou il en manque dans la fonction %s", get_lexeme(num_hash));
        exit(-1);
    }
    return 0;
}

int test_corp_procedure(type_arbre* a)
{
    test_return_dans_liste_instruction(a, -1);
    return 0;
}

#endif
