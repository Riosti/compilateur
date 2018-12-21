//MODULE DE CHARGEMENT DES TABLES UTILE POUR LA PILE D'EXECUTION
#ifndef _CHARGER_H_
#define _CHARGER_H_

#include "analyse_sementique.h"

//fonction d'erreur de chargement
int erreur_fichier();

//Precondition: les fichiers sont déjà ouverts

//charger la table des lexèmes
void charger_TabLex(FILE *f);

//charger la table des déclaration
void charger_TabDec(FILE *f);

//fonction de chargement d'un arbre
type_arbre *lire_arbe(FILE f);
//charger la table des régions
void charger_TabReg(FILE *f);    

//charger la table des déclarations
void charger_TabRep(FILE *f);


#endif
