#include "../inc/pile_exec.h"

void empiler(cellule elem){
    pexec[indice_libre] = elem;
    indice_libre ++;
}

void depiler(){
    indice_libre-=1;
}


void init_pexec(){
    BC = 0;
    indice_libre = 1;
    pexec[0].type = INT;
    pexec[0].val = -1;
}

void evalue_appel(type_arbre *a){
     int i;
    //Mise à jour de la base courante
    pexec[indice_libre].val = BC; //la region appelante
    enfile_bc(BC, chainage);
    BC = indice_libre; //MaJ de la BC
    indice_libre++;
    
    //empiler le chainage dynamique
    FileBC p = chainage;
    while(!est_vide(p)){
	pexec[indice_libre].val = p->bc;
	indice_libre++;
	p = p->suivant;
    }
    //empiler les paramètres
    type_arbre *b = a;
    for( i = 1; i <= Table_rep_type[Tab_dec[b->num_dec].description]; i++ ){
	empiler(evalue_expression(b->fils));
	b = b->frere;
    }
    affiche_pile();
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
    printf("je suis dans evalue_arbre\n");
    int NISdeclaration, NIScourant = table_region[region_courante].nis;
    printf("%d\n", a->type);
    switch(a->type){
    case A_LIRE: //comme une affectation, c'est une procédure donc que des types simples
	//pour Antho
	NISdeclaration = table_region[Tab_dec[a->fils->num_dec].region].nis;
	if( a->fils->type == REEL )
	    fscanf(stdin, "%f", &pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution].reel);
	else
	    fscanf(stdin, "%d", &pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution].val);
	break;
	
    case A_ECRIRE://procedure => des types simples en paramètres
	NISdeclaration = table_region[Tab_dec[a->fils->num_dec].region].nis;
	switch(a->fils->type){
	case CHAR:
	    printf("%c\n", pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution].val);
	break;
	case REEL:
	    printf("%lf\n", pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution].reel);
	    break;
	default:
	    printf("%d\n", pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution].val);
	}
	break;
    case A_LIST:
	evalue_arbre(a->fils);
	break;
    case A_APPEL: //il s'agit d'une procédure
	evalue_appel(a);
	region_courante = Tab_dec[a->num_dec].execution; //on change de region
	evalue_procedure(table_region[region_courante].a);
	region_courante = Tab_dec[a->num_dec].region;//on revient dans la region englobante
	break;
	
    case A_TQ:
	while( evalue_condition(a->fils) )
	    evalue_arbre( a->fils->frere);
	break;
	
    case A_SI:
	if( evalue_condition(a->fils) )
	    evalue_arbre(a->fils->frere);
	else
	    evalue_arbre(a->fils->frere->frere);
	break;
	
	//LE most important
    case A_OPAFF:
	printf("Affectation\n");
	NISdeclaration = table_region[Tab_dec[a->fils->num_dec].region].nis;
	printf("NIS de declaration %d\n", NISdeclaration);
	printf("NIS courant %d\n", NIScourant);
	printf("BC %d\n", BC);
	printf("%d\n",pexec[BC+NIScourant-NISdeclaration].val);
	printf("%d\n",Tab_dec[a->fils->num_dec].execution);
	pexec[pexec[BC+NIScourant-NISdeclaration].val+Tab_dec[a->fils->num_dec].execution] = evalue_expression(a->fils->frere);
	printf("Affectation done");
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
	}
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
	break;
    }
    evalue_arbre(a->frere);
}
cellule evalue_fonction(type_arbre *a){
    while( a->type != A_RETURN ){
	evalue_arbre(a);
	a = a->frere;
    }
    //recule la BC
    indice_libre = BC;//corrigé
    BC = defile_bc(chainage);//corrigé
    affiche_pile();
    return evalue_expression(a->fils);
}

void evalue_procedure(type_arbre *a){
    while( a->type != A_RETURN ){
	evalue_arbre(a);
	a = a->frere;
    }
    indice_libre = BC;//corrigé
    BC = defile_bc(chainage);//corrigé
}

cellule evalue_expression(type_arbre *a){ //
    cellule rep;
    printf("evalexp\n");
    printf("Dans evalue_expression %d\n", a->type);
    switch(a->type){
    case A_APPEL: //il sagit d'une fonction
	evalue_appel(a);
	region_courante = Tab_dec[a->num_dec].execution;
	rep = evalue_fonction(table_region[region_courante].a);
	region_courante = Tab_dec[a->num_dec].region;
	break;
    case A_CSTE_E:
	printf("Il s'agit d'une cste entiere\n");
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

void affiche_pile(){
    printf("INDICE      VALEUR\n");
    for( int i = 0; i<indice_libre; i++){
	switch(pexec[i].type)
	    {
	    case INT:
		printf("%d     %d\n", i, pexec[i].val);
		break;
	    case BOOL:
		if(pexec[i].val)
		    printf("%d     Vrai\n", i);
		else
		    printf("%d     Faux\n", i);
		break;
	    case REEL:
		printf("%d     %f\n", i,pexec[i].reel);
		break;
	    case CHAR:
		printf("%d     %c\n", (char)pexec[i].val);
		break;
	    }
    }
}
	
int main(int argc, char *argv[]){
    //charger les tables
    FILE *f = fopen("table_prog", "r");
    init_table_region();
    init_table_decla();
    init_table_rep_type();
    charger_TabLex(f);
    charger_TabDec(f);
    charger_TabRep(f);
    charger_TabReg(f);

    fclose(f);
    
    chainage = init_bc();
    indice_libre =0;
    BC = 0;
    init_pexec();
    printf("%d\n", table_region[0].a->type);
    evalue_arbre(table_region[0].a);
    return 1;
}

