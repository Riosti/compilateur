#ifndef _PILE_exec_H
#define _PILE_exec_H
#include <stdio.h>
#include <stdlib.h>
#include "table_region.h"
#include "table_rep_type.h"
#include "table_declaration.h"
#include "arbre.h"
#include "define_const.h"
#include "fileBC.h"
/*IMPORTANT le chaine de caractere doivent etre des tableaux de caractère*/
#define INT 1
#define BOOL 2
#define REEL 3
#define CHAR 4

typedef struct cellule{
    int type;
    int val ; //boolen ou entier
    float reel ;
    char caractere ;
}cellule;

cellule pexec[5000] ;

int region_courante; //utile pour retrouver le NIScourant

//globale table ou fonction charger table
//TODO


//fonction de gestion de la pile
void empiler( cellule elem );
void depiler();


fileBC chainage;
 //fonctions principales
//gère un appel (fonction ou proecdure cad mise à jour de la BC,...)
void evalue_appel(type_arbre *a);
//une procédure ne peut renvoyer une valeur
void evalue_procedure(type_arbre *a);
//en revanche une fonction peut le faire
cellule evalue_fonction(type_arbre *a);

int evalue_condition(type_arbre *a);
void evalue_arbre(type_arbre *a);
cellule evalue_expression(type_arbre *a);


/*POUR LE MAIN
    init_pile();
    
    //recupérer arbre de la region 0 tab_region[0]
    //faire pile pour le chainage statique (initialisation)
    //ma fonction main_evaluer
    */
#endif
