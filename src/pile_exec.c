#include "../inc/pile_exec.h"

int BCbis;


void empiler(cellule elem){
    pexec[indice_libre] = elem;
    indice_libre ++;
}



void init_pexec(){
    BC = 0;
    BCbis = 0;
    indice_libre = 1;
    pexec[0].type = INT;
    pexec[0].val = 0;
}

void evalue_appel(type_arbre *a){
    int i, tmp;
     cellule rep;
     //Mise à jour de la base courante
     indice_libre = BC + table_region[Tab_dec[a->num_dec].region].taille;
     pexec[indice_libre].val = BC; //la region appelante
     pexec[indice_libre].type = INT;
     //MaJ du chainage dynamique
     chainage = NULL;
     
     tmp = BC;
     while(tmp != 0){
	 enfile_bc(tmp, chainage);
	 tmp = pexec[tmp].val;
     }
     enfile_bc(0, chainage);
     BC = indice_libre;
     printf("NOUVELLE BC %d\n", BC);

     //On monte le NIS
     NIScourant++;
     //empiler le chainage dynamique
     FileBC p = chainage;
     int dc = 1;
     printf("CHAINAGE :\n");
     while(!est_vide(p)){
	 printf("p->bc %d  BC + dc = %d ", p->bc, BC+dc);
	pexec[BC + dc].type = INT;
	pexec[BC + dc].val = p->bc;
	p = p->suivant;
	dc++;
    }
    printf("\n");
    //empiler les paramètres
    type_arbre *b = a;
    for( i = 1; i <= Table_rep_type[Tab_dec[b->num_dec].description]; i++ ){
	//empiler
	rep = evalue_expression(b->fils);
	pexec[ BC + Tab_dec[b->fils->num_dec].execution ]= rep;
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
/*
int decalage(int numdec){
    int dec = 1;
    int reg = Tab_dec[numdec].region;
    for( int i = 0; i < numdec; i++)
	if( Tab_dec[i].region == reg )
	    dec += Tab_dec[i].execution;
    return dec;
}
*/
void evalue_arbre(type_arbre *a){//on connait la région
    if(a == NULL){
	affiche_pile();
	printf("\nfin de l'execution\n");
	exit(0);
    }
    printf("je suis dans evalue_arbre\n");
    int NISdeclaration, NIScourant = table_region[region_courante].nis;
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
	printf("Il s'agit d'une liste\n");
	evalue_arbre(a->fils);
	break;
    case A_APPEL_P: 
	printf("Il s'agit d'une procedure\n");
	
       	evalue_appel(a);
	region_courante = Tab_dec[a->num_dec].execution; //on change de region
	printf("num_dec %d\n", a->num_dec);
	printf("Region courante %d\n", region_courante);
	evalue_procedure(table_region[region_courante].a->fils->frere->frere);
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
	printf("Il s'agit d'une affectation\n");
	NISdeclaration = table_region[Tab_dec[a->fils->num_dec].region].nis;
	printf("     NIS de declaration %d\n", NISdeclaration);
	printf("     NIS courant %d\n", NIScourant);
	printf("     BC %d\n", BC);
	int dec = Tab_dec[a->fils->num_dec].execution;
	printf("decalage %d\n", dec);
	if( BC != 0)
	    pexec[pexec[BC+NIScourant-NISdeclaration].val +dec] = evalue_expression(a->fils->frere);
	else
	    pexec[dec] = evalue_expression(a->fils->frere);
	printf("Affectation done\n");
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
    BC = defile_bc(chainage);//corrigé
    //Recule NIScourant
    NIScourant--;
    affiche_pile();
    return evalue_expression(a->fils);
}

void evalue_procedure(type_arbre *a){
    printf("Je suis dans evalue procedure\n");
    evalue_arbre(a);
    FileBC p = chainage -> suivant;
    free(chainage);
    chainage = p;
    //BC = defile_bc(chainage);//corrigé
    for(int i = BC; i<= 10; i++){
pexec[i].type = -1;
	pexec[i].val = -1;
	pexec[i].reel = -1;
    }
    BC = p ->bc;
    NIScourant--;
}

cellule evalue_expression(type_arbre *a){ //
    cellule rep;
    printf("Dans evalue_expression %d\n", a->type);
    switch(a->type){
    case A_IDF: //
	//ATTENTION NIScourant
	printf("Il s'agit d'un IDF\nNIScourant = %d\nBC %d\n", NIScourant, BC);
	NISdeclaration = table_region[Tab_dec[a->num_dec].region].nis;
	
	int dec = Tab_dec[a->num_dec].execution;
	printf("DECALAGE %d\nIndice %d\n", dec, BC+NIScourant-NISdeclaration+dec);
	if(BC != 0)
	rep = pexec[pexec[BC+NIScourant - NISdeclaration].val];
	else
	    rep = pexec[dec];
	printf("I've got %d\n", rep.val);
	//rep = pexec[rep.val + dec];
	
	break;
    case A_APPEL: //il sagit d'une fonction
	evalue_appel(a);
	region_courante = Tab_dec[a->num_dec].execution;
	rep = evalue_fonction(table_region[region_courante].a);
	region_courante = Tab_dec[a->num_dec].region;
	break;
    case A_CSTE_E: //testé et ok
	printf("Il s'agit d'une cste entiere\n");
	rep.type = INT;
	rep.val = a->noeud;
	break;
    case A_CSTE_R: //a tester
	rep.type = REEL;
	rep.reel = a->noeudf;
	break;
    case A_BOOL: //a tester
	rep.type = BOOL;
	rep.val = a->noeud;
	break;
    case A_PLUS: //testé et ok
	printf("Il s'agit d'une addition\n");
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val +=evalue_expression(a->fils->frere).val;
	else
	    rep.reel += evalue_expression(a->fils->frere).reel;
	break;
	
    case A_MOINS: // TOTEST
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val -=evalue_expression(a->fils->frere).val;
	else
	    rep.reel -= evalue_expression(a->fils->frere).reel;
	break;
	
    case A_DIV: //TOTEST
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val /=evalue_expression(a->fils->frere).val;
	else
	    rep.reel /= evalue_expression(a->fils->frere).reel;
	break;
	
    case A_MULT: //TOTEST
	printf("Il s'agit d'une multiplication\n");
	rep = evalue_expression(a->fils);
	if(rep.type == INT)
	    rep.val *=evalue_expression(a->fils->frere).val;
	else
	    rep.reel *= evalue_expression(a->fils->frere).reel;
	break;
    }
    printf("Resulat(eval) %d\n", rep.val);
    return rep;
}

void affiche_pile(){
    printf("INDICE      VALEUR\n");
    for( int i = 0; i<50; i++){
	switch(pexec[i].type)
	    {
	    case INT:
		printf("%d            %d\n", i, pexec[i].val);
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
    printf("lancement de la pile\n");
    FILE *f = fopen("table_prog", "r");
    if ( f == NULL){
	printf("erreur ouverture du fichier");
	exit(-1);
    }
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
    init_pexec();
    printf("Region %d\n", table_region[0].a->type);
    evalue_arbre(table_region[0].a);
    return 1;
}

