#include "../inc/pile_exec.h"

int BC = 0, indice_libre = 0, NIScourant = 0;
FileBC chainage = NULL;

void depiler(){
    indice_libre-=1;
}


void init_pile(){
    BC = 0;
    indice_libre = 1;
    pexec[0].type = INT;
    pexec[0].val = -1;
}

void evalue_appel(type_arbre *a){
     int i;
    //Mise à jour de la base courante
    pexec[indice_libre].val = BC; //la region appelante
    enfile(BC, chainage);
    BC = indice_libre; //MaJ de la BC
    indice_libre++;
    
    //empiler le chainage dynamique
    FileBC p = chainage;
    while(!est_vide(p)){
	pexec[indice_libre].val = p->bc;
	indice_libre++
	p = p->suivant;
    }
    //empiler les paramètres
    type_arbre *b = a;
    for( i = 1; i <= Table_rep_type[Tab_dec[b->num_dec].description]; i++ ){
	empiler(evalue_expression(b->fils));
	b = b->frere;
    }
}


int evalue_condition(type_arbre *a){ 
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
	sol = a->noeud;
    }
    return sol;
}


void evalue_arbre(type_arbre *a){//on connait la région
    int NISdeclaration, NIScourant = table_region[region_courante].nis;
    switch(a->type){	
    case A_LIST:
	evalue_arbre(a->fils);
	break;
    case A_APPEL: //afficher la pile
	evalue_appel(a);
	evalue_arbre(a->frere);
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
	
    case A_DEC:
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
cellule evalue_fonction(type_arbre *a){
    while( a->type != A_RETURN ){
	evalue_arbre(a);
	a = a->frere;
    }
    //recule la BC
    indice_libre = BC;//corrigé
    BC = defile(chainage);//corrigé
    return evalue_expression(a->fils);
}

void evalue_procedure(type_arbre *a){
    while( a->type != A_RETURN ){
	evalue_arbre(a);
	a = a->frere;
    }
    indice_libre = BC;//corrigé
    BC = defile(chainage);//corrigé
}

cellule evalue_expression(type_arbre *a){ //
    cellule rep;
    switch(a->type){
    case A_APPEL: //il sagit d'une fonction
	evalue_appel(a);
	region_courante = Tab_dec[a->num_dec].execution;
	rep = evalue_fonction(TabReg[region_courante].a);
	region_courante = Tab_dec[a->num_dec].region;
	break;
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

int main(int argc, char *argv[]){
    //initialiser les tables

    return 1;
}

