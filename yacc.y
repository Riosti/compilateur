%{
  #include "inc/sauv.h"
  extern int Num_lignes;
  extern int Num_inst;
  int yylex();
  int yyerror();
  
%}

%union{
  struct arbre * arbre;
  int type_int;
  float type_float;
  }

%token DEBUT_PROG DEBUT FIN POINT_VIRGULE TYPE DEUX_POINTS STRUCT FSTRUCT TABLEAU CO CF VIRGULE POINT VARIABLE PROCEDURE FONCTION PO PF VIDE TANT_QUE FAIRE OPAFF PLUS MOINS DIV MULT VRAI FAUX INF SUP INFEGAL SUPEGAL EGAL DIFF RETOURNE SI ALORS SINON ET OU DE  INCREMENTE DECREMENTE DIEZ NON

%token<type_int> CSTE_ENTIERE IDF CSTE_CARACTERE CSTE_CHAINE ENTIER REEL CHAINE BOOLEEN CARACTERE
%token<type_float> CSTE_REEL


%type<arbre> plus_moins variable variable_idf tableau liste_param_tab param_du_tab expression_chaine expression expression_et expression_ou expression_neg expression_bcn cste_bool expression_cmp opcomp expression_num e1 e2 e3 e4 e5 appel liste_arguments un_arg liste_args corps liste_instructions suite_liste_inst instruction resultat_retourne condition tant_que affectation programme declaration_procedure liste_parametres un_param liste_param nom_type type_simple declaration_fonction
 
%%
all : programme {sauvegarder_arbre($1,"test_sauv");sauvegarde_tables("test_tables");supprime_arbre($1);}

programme : DEBUT_PROG corps {printf("prog \n");$$=concat_pere_fils(cree_noeud(A_LIST,-1),$2);afficher_arbre($2);}
         ;

corps : liste_declarations liste_instructions {$$=$2;}
      | liste_instructions {$$=$1;}
      ;

liste_declarations : dec1
                   ;

liste_instructions : DEBUT suite_liste_inst FIN {$$=$2;ajoue_arbre_table_region($2);}
                   ;

suite_liste_inst : instruction POINT_VIRGULE{$$=$1;}
                 | suite_liste_inst instruction POINT_VIRGULE {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;a=a->fils;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_LIST,-1),$2));;$$=$1;} 
                 ;

/*g30.sncf.com*/

dec1: declaration_type POINT_VIRGULE
    | declaration_type POINT_VIRGULE dec1
    | dec2
    ;

dec2: declaration_variable POINT_VIRGULE
    | declaration_variable POINT_VIRGULE dec2
    | dec3
    ;

dec3: declaration_procedure POINT_VIRGULE{sauvegarder_arbre($1,"test_sauv");supprime_arbre($1);}
    | declaration_fonction  POINT_VIRGULE{sauvegarder_arbre($1,"test_sauv");supprime_arbre($1);}
    | declaration_procedure POINT_VIRGULE{sauvegarder_arbre($1,"test_sauv");supprime_arbre($1);} dec3
    | declaration_fonction  POINT_VIRGULE{sauvegarder_arbre($1,"test_sauv");supprime_arbre($1);} dec3
    ;

declaration_type : TYPE IDF DEUX_POINTS suite_declaration_type_t {ajoute_tableau($2);}
                 | TYPE IDF DEUX_POINTS suite_declaration_type_s {ajoute_struct($2);}
                 ;

suite_declaration_type_s : STRUCT liste_champs FSTRUCT 
                       ;

suite_declaration_type_t: TABLEAU dimension DE nom_type {enfile($4->noeud);}
                        ;

dimension : CO liste_dimensions CF 
          ;

liste_dimensions : une_dimension 
                 | liste_dimensions VIRGULE une_dimension
                 ;

une_dimension : const_entier DIEZ const_entier 
              ;

const_entier : CSTE_ENTIERE {enfile($1);}
             | MOINS CSTE_ENTIERE {enfile(-1*$2);}
             ;

liste_champs : un_champ 
             | liste_champs un_champ
             ;

un_champ : IDF DEUX_POINTS nom_type POINT_VIRGULE {enfile($1);enfile($3->noeud);}
         ;

nom_type : type_simple {$$=$1;}
         | IDF {$$=cree_noeud(A_IDF,$1);}
         ;

type_simple : ENTIER {$$=cree_noeud(A_INT,$1);}
            | REEL {$$=cree_noeud(A_FLOAT,$1);}  
            | BOOLEEN {$$=cree_noeud(A_BOOL,$1);}
            | CARACTERE{$$=cree_noeud(A_CHAR,$1);}
            | CHAINE CO CSTE_ENTIERE CF {$$=concat_pere_fils(cree_noeud(A_CHAINE,$1),cree_noeud(A_CSTE_E,$3));}
            ;

declaration_variable : VARIABLE IDF DEUX_POINTS nom_type {ajoute_variable($2,$4->noeud);}
                     ;

declaration_procedure : PROCEDURE  IDF liste_parametres {ajoute_proc($2);} corps {$$=concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_PROC,$2),concat_pere_frere($3,concat_pere_fils(cree_noeud(A_LIST,-1),$5))));}
                      ;

declaration_fonction : FONCTION IDF liste_parametres RETOURNE nom_type {enfile($5->noeud);ajoute_fonction($2);} corps {$$=concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_FONCTION,$2),concat_pere_frere($3,concat_pere_frere(concat_pere_fils(cree_noeud(A_RETURN,-1),$5),concat_pere_fils(cree_noeud(A_LIST,-1),$7)))));}/*nom type nan?*/
                     ;


liste_parametres : {$$=cree_noeud(A_VIDE,-1);}
                 | PO liste_param PF {$$=$2;}
		 ;

liste_param : un_param {$$=$1;}
            | liste_param POINT_VIRGULE un_param {$$=concat_pere_fils(cree_noeud(A_PARAM,-1),$3);};
            ;

un_param : IDF DEUX_POINTS nom_type {$$=cree_noeud(A_IDF,$1);enfile($1);enfile($3->noeud);}/*nom type nan ?*/
         ;

instruction : affectation {$$=$1;}
            | condition {$$=$1;}
            | tant_que {$$=$1;}
            | appel  {$$=$1;}
            | VIDE {$$=cree_noeud(A_VIDE,-1);}
            | RETOURNE resultat_retourne {$$=concat_pere_fils(cree_noeud(A_RETURN,-1),$2);} 
            ;

resultat_retourne : {$$=cree_noeud(A_VIDE,-1);}
                  | expression {$$=$1;}
                  | expression_chaine {$$=$1;}
		  ;

appel : IDF liste_arguments {$$=concat_pere_fils(cree_noeud(A_APPEL,-1),concat_pere_frere(cree_noeud(A_IDF,$1),$2));} 
      ;

liste_arguments :PO PF {$$=NULL;}
                |PO liste_args PF {$$=$2;}
		;

liste_args : un_arg {$$=$1;}
           | liste_args VIRGULE un_arg {$$=concat_pere_fils(cree_noeud(A_ARG,-1),$3);}
           ;

un_arg : expression {$$=$1;}
       ;

condition : SI expression
           ALORS liste_instructions 
SINON liste_instructions {$$=concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(concat_pere_fils(cree_noeud(A_SI,-1),$2),concat_pere_frere(concat_pere_fils(cree_noeud(A_ALORS,-1),$4),concat_pere_fils(cree_noeud(A_SINON,-1),$6))));}
          ;

tant_que : TANT_QUE expression FAIRE liste_instructions {printf("voila\n");$$=concat_pere_fils(cree_noeud(A_TQ,-1),concat_pere_frere($2,$4));}
         ;

affectation : variable OPAFF expression {$$=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere($1,$3));}
            | variable OPAFF expression_chaine {$$=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere($1,$3));}
            | variable plus_moins {$$=concat_pere_fils($2,$1);}
            ;

variable : variable_idf {$$=$1;}
         | tableau {$$==$1;}
         | variable POINT tableau {$$=concat_pere_fils(cree_noeud(A_STRUCT,-1),concat_pere_frere($1,$3));} 
| variable POINT variable_idf {$$=concat_pere_fils(cree_noeud(A_STRUCT,-1),concat_pere_frere($1,$3));printf("voila\n");} 
         ;

variable_idf : IDF {$$=cree_noeud(A_IDF,$1);}
             ;

tableau : IDF liste_param_tab {$$=concat_pere_fils(cree_noeud(A_TABLEAU,-1),concat_pere_frere(cree_noeud(A_IDF,$1),$2));}
        ;

liste_param_tab : CO param_du_tab CF {$$=$2;}
                | liste_param_tab CO param_du_tab CF {$$=concat_pere_fils(cree_noeud(A_PARAM,-1),concat_pere_frere($1,$3));}/*ici je sais pas si ca serais pas inutile*/

param_du_tab : expression {$$=$1;}
             | param_du_tab VIRGULE expression {concat_pere_fils(cree_noeud(A_VIRGULE,-1),concat_pere_frere($1,$3));}
             ;

expression_chaine : expression_chaine PLUS CSTE_CHAINE {concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere($1,cree_noeud(A_CHAINE,$3)));}
                  | CSTE_CHAINE {$$=cree_noeud(A_CHAINE,$1);}
                  ;

expression : expression_et {$$=$1;}
           ;

expression_et : expression_et ET expression_ou {$$=concat_pere_fils(cree_noeud(A_ET,-1),concat_pere_frere($1,$3));}
              | expression_ou {$$=$1;}
              ;

expression_ou : expression_ou OU expression_neg {$$=concat_pere_fils(cree_noeud(A_OU,-1),concat_pere_frere($1,$3));}
              | expression_neg {$$=$1;}
              ;

expression_neg : NON expression_bcn {concat_pere_fils(cree_noeud(A_NON,-1),$2);}
               | expression_bcn {$$=$1;}
               ;

expression_bcn : cste_bool {$$=$1;}
               | expression_cmp {$$=$1;}
               | expression_num {$$=$1;}
               ;

cste_bool : VRAI {$$=cree_noeud(A_BOOL,1);}
          | FAUX {$$=cree_noeud(A_BOOL,-1);}
          ;

expression_cmp : expression_num opcomp expression_num {printf("voila\n");$$=concat_pere_fils($2,concat_pere_frere($1,$3));printf("truc\n");}
               ;

opcomp : INF {$$=cree_noeud(A_INF,-1);}
       | INFEGAL {$$=cree_noeud(A_INFEGAL,-1);}
       | SUP {$$=cree_noeud(A_SUP,-1);}
       | SUPEGAL {$$=cree_noeud(A_SUPEGAL,-1);}
       | EGAL {$$=cree_noeud(A_EGAL,-1);}
       | DIFF {$$=cree_noeud(A_DIFF,-1);}
       ;

expression_num : e1 {$$==$1;} 
               ;

e1 : e2 {$$=$1;}
   | e1 PLUS e2 {$$=concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere($1,$3));}
   | e1 MOINS e2 {$$=concat_pere_fils(cree_noeud(A_MOINS,-1),concat_pere_frere($1,$3));}
   ;

e2 : e3 {$$=$1;}
   | e2 MULT e3 {$$=concat_pere_fils(cree_noeud(A_MULT,-1),concat_pere_frere($1,$3));}
   | e2 DIV e3 {$$=concat_pere_fils(cree_noeud(A_DIV,-1),concat_pere_frere($1,$3));}
   ;

e3 : MOINS e4 {$2->noeud*=-1; $2->noeudf*=-1;$$=$2;}
   | e4 {$$=$1;}
   ;

e4 : PO expression PF {$$=$2;}
   | CSTE_ENTIERE {$$=cree_noeud(A_CSTE_E,$1);}
   | CSTE_REEL {$$=cree_noeud_f(A_CSTE_R,$1);}
   | CSTE_CARACTERE {$$=cree_noeud(A_CSTE_E,$1);}
   | appel {$$=$1;}
   | e5{$$=$1;}
   ;

e5 : variable {$$=$1;}
| variable plus_moins {$$=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere($1,concat_pere_frere(cree_noeud(A_PLUS,-1),concat_pere_frere($1,cree_noeud(A_CSTE_E,1)))));}
   ;

plus_moins : INCREMENTE {$$=cree_noeud(A_INCR,-1);}
           | DECREMENTE {$$=cree_noeud(A_DEC,-1);}
           ;









%%

int yyerror(){ printf("Erreur ligne %d instruction %d\n",Num_lignes,Num_inst);}


int main(){
  init_table_hash();
  init_table_decla();
  init_table_rep_type();
  init_file();
  nouvelle_region();
  ajoute_type_base(ajoute_lexem("Int"));
  ajoute_type_base(ajoute_lexem("Float"));
  ajoute_type_base(ajoute_lexem("Char"));
  ajoute_type_base(ajoute_lexem("Bool"));
  ajoute_type_base(ajoute_lexem("String"));
  yyparse();
}


