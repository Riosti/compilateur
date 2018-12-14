#include "../inc/pile_exec.h"

int BC = 0, indice_libre = 0, NIScourant = 0;
file *chainage = NULL;

void depiler(){
    indice_libre-=1;
}


void init_pile(){
    BC = 0;
    indice_libre = 1;
    pexec[0].type = INT;
    pexec[0].val = -1;
}

cellule evalue_fonction(type_arbre *a){
    cellule res;
     int i;
    //Mise à jour de la base courante
    pexec[indice_libre].val = BC; //la region appelante
    enfile(BC);
    //enfile(chainage, BC);
    BC = indice_libre; //MaJ de la BC
    //empiler le chainage dynamique
    file *p = chainage;
    while(p != NULL){
	empile(p->num);
	p = p->suivant;
	indice_libre++;
    }
    //empiler les paramètres
    for( i = 1; i <= Table_rep_type[Tab_dec[a->num_dec].description]; i++ ){
	empiler(evalue_expression(a->fils));
	a = a->frere;
    }
    region_courante = Tab_dec[a->num_dec].region;
    evalue_arbre(table_region[region_courante].a);
    //!!ATTENTION LA FONCTION RENVOIE QQ CHOSE
}
void evalue_procedure(type_arbre *a){
    int i;
    //Mise à jour de la base courante
    pexec[indice_libre].val = BC; //la region appelante
    enfile(BC);
    //enfile(chainage, BC);
    BC = indice_libre; //MaJ de la BC
    //empiler le chainage dynamique
    file *p = chainage;
    while(p != NULL){
	empile(p->num);
	p = p->suivant;
	indice_libre++;
    }
    //empiler les paramètres
    for( i = 1; i <= Table_rep_type[Tab_dec[a->num_dec].description]; i++ ){
	empiler(evalue_expression(a->fils));
	a = a->frere;
    }
    region_courante = Tab_dec[a->num_dec].region;
    evalue_arbre(table_region[region_courante].a);
}

int evalue_condition(type_arbre *a){ //A MODIFIER SI REEL
    int sol;
    switch(a->type){
    case A_ET:
	sol = evalue_condition(a->fils) &&
	    evalue_condition(a->fils->frere);
	break;
    case A_OU:
	sol = (evalue_condition(a->fils)) ||
	    (evalue_condition(a->fils->frere));
	break;
    case A_NON:
	sol = !evalue_condition(a->fils);
	break;
    case A_INF: 
	if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		< evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val < evalue_expression(a->fils->frere).val;
	break;
	
    case A_SUP:
	if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		> evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val > evalue_expression(a->fils->frere).val;
	break;
	
    case A_EGAL:
	 if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		== evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val == evalue_expression(a->fils->frere).val;
	 break;
	 
    case A_SUPEGAL:
	 if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		>= evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val >= evalue_expression(a->fils->frere).val;
	break;
	
    case A_INFEGAL:
	if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		<= evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val <= evalue_expression(a->fils->frere).val;
	break;
	
    case A_DIFF:
	if (evalue_expression(a->fils).type == REEL)
	    sol = evalue_expression(a->fils).reel
		!= evalue_expression(a->fils->frere).reel;
	else
	    sol = evalue_expression(a->fils).val != evalue_expression(a->fils->frere).val;
	break;
    case A_BOOL:
	return a->noeud;
    }
    return sol;
}


void evalue_arbre(type_arbre *a){//on connait la région
    int NISdeclaration, NIScourant = table_region[region_courante].nis;
    switch(a->type){
    case A_LIST:
	evalue_arbre(a->fils);
	break;
    case A_APPEL_P: //afficher la pile
	evalue_procedure(a);
	evalue_arbre(a->frere);
	break;

    case A_RETURN:
	//recule la BC
	indice_libre = BC;//corrigé
	BC = defile(chainage);//FAUX à corriger
	break;
	
    case A_TQ:
	while( evalue_condition(a->fils) )
	    evalue_arbre( a->fils->frere);
	evalue_arbre(a->frere);
	break;
	
    case A_SI:
	if( evalue_condition(a->fils) )
	    evalue_arbre(a->fils->frere);
	else
	    evalue_arbre(a->fils->frere->frere);
	evalue_arbre(a->frere);
	break;
	
	//LE most important
    case A_OPAFF:
	NISdeclaration = table_region[Tab_dec[a->fils->num_dec].region].nis;
	pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution]=
	    evalue_expression(a->fils->frere);
	break;

	
    case A_INCR: 
	NISdeclaration = table_region[Tab_dec[a->num_dec].region].nis;
	switch(pexec[pexec[BC+NIScourant-NISdeclaration].val +
		Tab_dec[a->fils->frere->num_dec].execution].type){
	case INT:
	    pexec[pexec[BC+NIScourant-NISdeclaration].val +
		 Tab_dec[a->fils->frere->num_dec].execution].val--;
	    break;
	case REEL:
	    pexec[pexec[BC+NIScourant-NISdeclaration].val +
		 Tab_dec[a->fils->frere->num_dec].execution].reel--;
	    break;
	default:
	    fprintf(stderr, "Le type attendue INT/REEL\nReçu %d\n", pexec[pexec[BC+NIScourant-NISdeclaration].val +Tab_dec[a->fils->frere->num_dec].execution].type);
	}
	evalue_arbre(a->frere);
	break;
    case A_DEC://dansevalueexpression
	 NIScourant = table_region[region_courante].nis;
	 NISdeclaration = table_region[Tab_dec[a->num_dec].region].nis;
	switch(pexec[pexec[BC+NIScourant-NISdeclaration].val +
		Tab_dec[a->fils->frere->num_dec].execution].type){
	case INT:
	    pexec[pexec[BC+NIScourant-NISdeclaration].val +
		 Tab_dec[a->fils->frere->num_dec].execution].val++;
	    break;
	case REEL:
	    pexec[pexec[BC+NIScourant-NISdeclaration].val +
		 Tab_dec[a->fils->frere->num_dec].execution].reel++;
	    break;
	default:
	    fprintf(stderr, "Le type attendue INT/REEL\nReçu %d\n", pexec[pexec[BC+NIScourant-NISdeclaration].val +Tab_dec[a->fils->frere->num_dec].execution].type);
	}
	evalue_arbre(a->frere);
	break;
    }
}

cellule evalue_expression(type_arbre *a){ //
    cellule rep;
    switch(a->type){
    case A_CSTE_E:
	rep.type = INT;
	rep.val = a->noeud;
	break;
    case A_CSTE_R:
	rep.type = REEL;
	rep.reel = a->noeudf;
	break;
    case A_BOOL:
	rep.type = BOOL;
	rep.val = a->noeud;
	break;
    case A_PLUS:
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val +=evalue_expression(a->fils->frere).val;
	else
	    rep.reel += evalue_expression(a->fils->frere).reel;
	break;	
    case A_MOINS:
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val -=evalue_expression(a->fils->frere).val;
	else
	    rep.reel -= evalue_expression(a->fils->frere).reel;
	break;	
    case A_DIV:
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val /=evalue_expression(a->fils->frere).val;
	else
	    rep.reel /= evalue_expression(a->fils->frere).reel;
	break;	
    case A_MULT:
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val *=evalue_expression(a->fils->frere).val;
	else
	    rep.reel *= evalue_expression(a->fils->frere).reel;
	break;
    }
    return rep;
}




