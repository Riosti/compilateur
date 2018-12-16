%{
  #include "inc/sauv.h"
  #include "inc/html.h"
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

%token DEBUT_PROG DEBUT FIN POINT_VIRGULE TYPE DEUX_POINTS STRUCT FSTRUCT TABLEAU CO CF VIRGULE POINT VARIABLE PROCEDURE FONCTION PO PF VIDE TANT_QUE FAIRE OPAFF PLUS MOINS DIV MULT VRAI FAUX INF SUP INFEGAL SUPEGAL EGAL DIFF RETOURNE SI ALORS SINON ET OU DE  INCREMENTE DECREMENTE DIEZ NON READ WRITE

%token<type_int> CSTE_ENTIERE IDF CSTE_CARACTERE CSTE_CHAINE ENTIER REEL CHAINE BOOLEEN CARACTERE
%token<type_float> CSTE_REEL


%type<arbre> plus_moins variable variable_idf tableau liste_param_tab param_du_tab expression_chaine expression expression_et expression_ou expression_neg expression_bcn cste_bool expression_cmp opcomp expression_num e1 e2 e3 e4 e5 appel liste_arguments un_arg liste_args corps liste_instructions suite_liste_inst instruction resultat_retourne condition tant_que affectation liste_parametres un_param liste_param nom_type type_simple ecrire lire
 
%%
all : programme{sauvegarde_tables("table_prog");} ;

programme : DEBUT_PROG corps {printf("prog \n");fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),$2));}
         ;

corps : liste_declarations  liste_instructions {$$=$2;}
      | liste_instructions {$$=$1;}
      ;

liste_declarations : dec1
                   ;

liste_instructions : DEBUT suite_liste_inst FIN {$$=$2;}
                   ;

suite_liste_inst : instruction POINT_VIRGULE{$$=$1;}
                 | suite_liste_inst instruction POINT_VIRGULE {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;a=a->fils;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_LIST,-1),$2));;$$=$1;} 
                 ;


dec1: declaration_type POINT_VIRGULE
    | declaration_type POINT_VIRGULE dec1
    | dec2
    ;

dec2: declaration_variable  POINT_VIRGULE
    | declaration_variable  POINT_VIRGULE dec2
    | dec3
    ;

dec3: declaration_procedure POINT_VIRGULE
    | declaration_fonction  POINT_VIRGULE
    | declaration_procedure POINT_VIRGULE dec3
    | declaration_fonction  POINT_VIRGULE dec3
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

un_champ : IDF DEUX_POINTS nom_type POINT_VIRGULE {enfile($1);enfile($3->noeud);enfile(taille_type($3->noeud));}
         ;

nom_type : type_simple {$$=$1;}
| IDF {type_arbre *a ;a=cree_noeud(A_IDF,$1);ajoute_type_final(a,type_var(num_dec($1)));$$=a;}
         ;

type_simple : ENTIER {type_arbre *a;a=cree_noeud(A_INT,$1); ajoute_type_final(a,0);$$=a;}
            | REEL {type_arbre *a;a=cree_noeud(A_FLOAT,$1);ajoute_type_final(a,1);$$=a;}  
            | BOOLEEN {type_arbre *a;a=cree_noeud(A_BOOL,$1);ajoute_type_final(a,3);$$=a;}
            | CARACTERE{type_arbre *a;a=cree_noeud(A_CHAR,$1);ajoute_type_final(a,2);$$=a;}
            | CHAINE CO CSTE_ENTIERE CF {type_arbre *a;a=concat_pere_fils(cree_noeud(A_CHAINE,$1),cree_noeud(A_CSTE_E,$3));ajoute_type_final(a,4);$$=a;}
            ;

declaration_variable : VARIABLE IDF DEUX_POINTS nom_type {ajoute_variable($2,$4->noeud);{taille_de_la_region();}}
                     ;

declaration_procedure : PROCEDURE  IDF liste_parametres {ajoute_proc($2);} corps {test_corp_procedure($5);fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_PROC,$2),concat_pere_frere($3,concat_pere_fils(cree_noeud(A_LIST,-1),$5)))));}
                      ;

declaration_fonction : FONCTION IDF liste_parametres RETOURNE nom_type {enfile($5->noeud);ajoute_fonction($2);} corps {test_corp_fonction(num_dec($2),$7);fin_proc_fonc_region(concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(cree_noeud(A_FONCTION,$2),concat_pere_frere($3,concat_pere_frere(concat_pere_fils(cree_noeud(A_RETURN,-1),$5),concat_pere_fils(cree_noeud(A_LIST,-1),$7))))));}/*nom type nan?*/
                     ;


liste_parametres : {$$=cree_noeud(A_VIDE,-1);}
                 | PO liste_param PF {$$=$2;}
		 ;

liste_param : un_param {type_arbre *a ;
   a=concat_pere_fils(cree_noeud(A_PARAM,-1),$1);
   ajoute_type_final(a,donne_type_final($1));
   $$=a;
 }
| liste_param POINT_VIRGULE un_param {type_arbre * a,*b;a=$1;b=concat_pere_fils(cree_noeud(A_PARAM,-1),$3);while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,b);$$=a;ajoute_type_final(b,donne_type_final($3));}
            ;

un_param : IDF DEUX_POINTS nom_type {type_arbre *a;a=cree_noeud(A_IDF,$1);enfile($1);enfile($3->noeud);ajoute_type_final(a,donne_type_final($3));$$=a;}/*nom type nan ?*/
         ;

instruction : affectation {$$=$1;}
            | condition {$$=$1;}
            | tant_que {$$=$1;}
            | appel  {$$=$1;}
            | VIDE {$$=cree_noeud(A_VIDE,-1);}
| RETOURNE resultat_retourne {type_arbre *a;a=concat_pere_fils(cree_noeud(A_RETURN,-1),$2);ajoute_type_final(a,donne_type_final($2));$$=a;fprintf(stderr,"return \n");}
            | lire {$$=$1;}
            | ecrire {$$=$1;}
            ;

lire : READ PO type_simple PF {$$ =concat_pere_fils(cree_noeud(A_LIRE,-1),$3);}/*type*/


ecrire : WRITE PO IDF PF {$$ = concat_pere_fils(cree_noeud(A_LIRE,-1),cree_noeud(A_IDF,$3));} /*expression*/


resultat_retourne : {$$=cree_noeud(A_VIDE,-1);}
                  | expression {$$=$1;}
                  | expression_chaine {$$=$1;}
		  ;

appel : IDF liste_arguments {type_arbre *a;
   if(est_une_fonction(num_dec($1))){
     a=concat_pere_fils(cree_noeud(A_APPEL_F,-1),concat_pere_frere(cree_noeud(A_IDF,$1),$2));ajoute_type_final(a,donne_type_fonction(num_dec($1)));verif_arg_fonction(num_dec($1),$2);$$=a;
   }
   else{
     if(est_une_procedure(num_dec($1))){
       a=concat_pere_fils(cree_noeud(A_APPEL_P,-1),concat_pere_frere(cree_noeud(A_IDF,$1),$2));verif_arg_procedure(num_dec($1),$2);$$=a;
     }
     else{
       fprintf(stderr,"%s n'est pas une fonction ou une procedure donc appelle impossible\n",get_lexeme($1));
       exit(-1);
     }
   }
 } 
      ;

liste_arguments :PO PF {$$=NULL;}
                |PO liste_args PF {$$=$2;}
		;

liste_args : un_arg {type_arbre *a;a=concat_pere_fils(cree_noeud(A_ARG,-1),$1);ajoute_type_final(a,donne_type_final($1));$$=a;}
| liste_args VIRGULE un_arg {type_arbre * a, *b;
   a=$1;
   b=concat_pere_fils(cree_noeud(A_ARG,-1),$3);
   ajoute_type_final(b,donne_type_final($3));
   while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,b);
   $$=$1;}
           ;

un_arg : expression {$$=$1;}
       ;

condition : SI expression
           ALORS liste_instructions 
SINON liste_instructions {
  if(test_type($2,3)){
    $$=concat_pere_fils(cree_noeud(A_LIST,-1),concat_pere_frere(concat_pere_fils(cree_noeud(A_SI,-1),$2),concat_pere_frere(concat_pere_fils(cree_noeud(A_ALORS,-1),$4),concat_pere_fils(cree_noeud(A_SINON,-1),$6))));
  }
  else{
    fprintf(stderr,"apres un il il faut une expression boolean \n");
    exit(-1);
  }}
          ;

tant_que : TANT_QUE expression FAIRE liste_instructions {
  if(test_type($2,3)){
    $$=concat_pere_fils(cree_noeud(A_TQ,-1),concat_pere_frere($2,$4));
  }
  else{
    fprintf(stderr,"apres un tant que le type de l'expression dois etre un boolean \n");
    exit(-1);
  }
}
         ;

affectation : variable OPAFF expression {
  if(test_des_types_arbre($1,$3)){
     $$=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere($1,$3));
   }
   else{
     fprintf(stderr,"affectaion de impossible types diffents \n");
     exit(-1);
   }
 }
            | variable OPAFF expression_chaine {
	      if(test_des_types_arbre($1,$3)){
		$$=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_frere($1,$3));
	      }
	      else{
		fprintf(stderr,"affectaion de impossible types diffents \n");
		exit(-1);
	      }
 }
            | variable plus_moins {
	      type_arbre *a ;
	      a=concat_pere_fils(cree_noeud(A_OPAFF,-1),concat_pere_fils($2,concat_pere_frere($1,cree_noeud(A_CSTE_E,1))));
	      if(test_type($1,0) || test_type($1,1) || test_type($1,2)){
		ajoute_type_final(a,donne_type_final($1));
	      }
	      else{
		fprintf(stderr,"erreur type pour le ++ ou -- n'est pas respecter \n");
		exit(-1);
	      }
	      $$=a;}
            ;

variable : variable_idf {$$=$1;
   ajoute_type_var($1,type_var(num_dec(donne_num_hash_arbre($1))));
   ajoute_type_final($1,type_var(num_dec(donne_num_hash_arbre($1))));
   ajoute_num_dec($1,num_dec(donne_num_hash_arbre($1)));
 }



| tableau {$$=$1;
   ajoute_type_final($1,type_dun_tab(type_var(num_dec(donne_num_hash_arbre($1->fils)))));
   ajoute_num_dec($1,num_dec(donne_num_hash_arbre($1->fils)));
  }




| variable POINT tableau {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_STRUCT,-1),$3));
   ajoute_type_var($3,type_dun_tab(type_dun_struct(donne_type_arbre(a),donne_num_hash_arbre($3->fils))));
   ajoute_type_final($1,donne_type_arbre($3->fils));
   $$=$1;}



| variable POINT variable_idf {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_STRUCT,-1),$3));

   ajoute_type_var($3,type_dun_struct(donne_type_final($1),donne_num_hash_arbre($3)));

   ajoute_type_final($1,donne_type_arbre($3));
   $$=$1; }
         ;

variable_idf : IDF {$$=cree_noeud(A_IDF,$1);}
             ;

tableau : IDF liste_param_tab {type_arbre *a ; a=concat_pere_fils(cree_noeud(A_TABLEAU,-1),concat_pere_frere(cree_noeud(A_IDF,$1),$2));$$=a;}
        ;

liste_param_tab : CO param_du_tab CF {$$=$2;}
                | liste_param_tab CO param_du_tab CF {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_PARAM,-1),$3));;$$=$1;}/*ici je sais pas si ca serais pas inutile*/

param_du_tab : expression {type_arbre *a;
   if(test_type($1,0)){
     $$=$1;
   }
   else{
     fprintf(stderr,"un tableau ne peux prendre que des entier en parametre\n");
     exit(-1);
   }
 }
             | param_du_tab VIRGULE expression {type_arbre * a;a=$1;while(a->frere!=NULL){a=a->frere;}concat_pere_frere(a,concat_pere_fils(cree_noeud(A_VIRGULE,-1),$3));;$$=$1;}
             ;

expression_chaine : expression_chaine PLUS CSTE_CHAINE {concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere($1,cree_noeud(A_CHAINE,$3)));}
                  | CSTE_CHAINE {$$=cree_noeud(A_CHAINE,$1);}
                  ;

expression : expression_et {$$=$1;}
           ;

expression_et : expression_et ET expression_ou {
type_arbre *a;
   if(test_type($3,3) && test_type($1,3)){
     a=concat_pere_fils(cree_noeud(A_ET,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,3);
       $$=a;
     }
   else{
     fprintf(stderr,"seul les expressions booleen ou les booleans peuvent avoir un et entre elles\n");
     exit(-1);
   }
 }
              | expression_ou {$$=$1;}
              ;

expression_ou : expression_ou OU expression_neg {
 type_arbre *a;
   if(test_type($3,3) && test_type($1,3)){
     a=concat_pere_fils(cree_noeud(A_OU,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,3);
       $$=a;
     }
   else{
     fprintf(stderr,"seul les expressions booleen ou les booleans peuvent avoir un ou entre elles\n");
     exit(-1);
   }
 }
              | expression_neg {$$=$1;}
              ;

expression_neg : NON expression_bcn {
 type_arbre *a;
   if(test_type($2,3)){
     a=concat_pere_fils(cree_noeud(A_NON,-1),$2);
       ajoute_type_final(a,3);
       $$=a;
     }
   else{
     fprintf(stderr,"seul les expression booleen ou les boolean peuvente avoir un non davant eux\n");
     exit(-1);
   }}
               | expression_bcn {$$=$1;}
               ;

expression_bcn : cste_bool {$$=$1;}
               | expression_cmp {$$=$1;}
               | expression_num {$$=$1;}
               ;

cste_bool : VRAI {type_arbre *a;a=cree_noeud_type(A_BOOL,1,3); ajoute_type_final(a,3);$$=a;}
| FAUX {type_arbre *a;a=cree_noeud_type(A_BOOL,-1,3); ajoute_type_final(a,3);$$=a;}
          ;

expression_cmp : expression_num opcomp expression_num {type_arbre *a;
   if((test_type($1,0) || test_type($1,1)) && (test_type($3,0) || test_type($3,1))){
     if(test_des_types_arbre($1,$3)){
       a=concat_pere_fils($2,concat_pere_frere($1,$3));
       ajoute_type_final(a,3);
       $$=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc imposible de les comparer\n");
       exit(-1);
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels imposible de comparer d'autres types\n");
     exit(-1);
   }}
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
| e1 PLUS e2 {type_arbre *a;
  if((test_type($1,0) || test_type($1,1)) && (test_type($3,0) || test_type($3,1))){
     if(test_des_types_arbre($1,$3)){
       a=concat_pere_fils(cree_noeud(A_PLUS,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,donne_type_final($1));
       $$=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc + imposible\n");
       exit(-1);
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels + imposible\n");
     exit(-1);
   }
 }
| e1 MOINS e2 {type_arbre *a;
     if((test_type($1,0) || test_type($1,1)) && (test_type($3,0) || test_type($3,1))){
     if(test_des_types_arbre($1,$3)){
       a=concat_pere_fils(cree_noeud(A_MOINS,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,donne_type_final($1));
       $$=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc - imposible\n");
       exit(-1);
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels - imposible\n");
     exit(-1);
   }
 }
   ;

e2 : e3 {$$=$1;}
| e2 MULT e3 {type_arbre *a;
   if((test_type($1,0) || test_type($1,1)) && (test_type($3,0) || test_type($3,1))){
     if(test_des_types_arbre($1,$3)){
       a=concat_pere_fils(cree_noeud(A_MULT,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,donne_type_final($1));
       $$=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc multiplication imposible\n");
       exit(-1);
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels multiplication imposible\n");
     exit(-1);
   }
 }
| e2 DIV e3 {type_arbre *a;
   if((test_type($1,0) || test_type($1,1)) && (test_type($3,0) || test_type($3,1))){
     if(test_des_types_arbre($1,$3)){
       a=concat_pere_fils(cree_noeud(A_DIV,-1),concat_pere_frere($1,$3));
       ajoute_type_final(a,donne_type_final($1));
       $$=a;
     }
     else{
       fprintf(stderr,"les type ne sont pas identique donc division imposible\n");
       exit(-1);
     }
   }
   else{
     fprintf(stderr,"les type ne sont pas des int ou des reels division imposible\n");
     exit(-1);
   }}
   ;

e3 : MOINS e4 {
  if(test_type($2,0) || test_type($2,1)){
  $2->noeud*=-1;
   $2->noeudf*=-1;
   $$=$2;
      }
      else{
	fprintf(stderr,"erreur - var mais la variable n'est pas un entier ou un reel \n");
	exit(-1);
      }
      }
   | e4 {$$=$1;}
   ;

e4 : PO expression PF {$$=$2;}
   | CSTE_ENTIERE {type_arbre *a; a=cree_noeud_type(A_CSTE_E,$1,0); ajoute_type_final(a,0);$$=a;}
   | CSTE_REEL { type_arbre *a; a=cree_noeud_f_type(A_CSTE_R,$1,1); ajoute_type_final(a,1); $$=a;}
   | CSTE_CARACTERE {type_arbre *a;a=cree_noeud_type(A_CSTE_E,$1,2); ajoute_type_final(a,2);$$=a;}
| appel {$$=$1;}/* ici a faire plus hautr*/
   | e5{$$=$1;}
   ;

e5 : variable {$$=$1;}
| variable plus_moins {
   type_arbre *a ;
   a=concat_pere_fils($2,concat_pere_frere($1,cree_noeud(A_CSTE_E,1)));
   if(test_type($1,0) || test_type($1,1) || test_type($1,2)){
       ajoute_type_final(a,donne_type_final($1));
     }
     else{
       fprintf(stderr,"erreur type pour le ++ ou -- n'est pas respecter \n");
       exit(-1);
     }
     $$=a;}
   ;

plus_moins : INCREMENTE {$$=cree_noeud(A_INCR,-1);}
           | DECREMENTE {$$=cree_noeud(A_DEC,-1);}
           ;









%%

int yyerror(){ printf("Erreur ligne %d instruction %d\n",Num_lignes,Num_inst);}


int main(){
  init_html();
  init_table_hash();
  init_table_decla();
  init_table_rep_type();
  init_table_region();
  init_file();
  nouvelle_region();
  ajoute_type_base(ajoute_lexem("Int"));
  ajoute_type_base(ajoute_lexem("Float"));
  ajoute_type_base(ajoute_lexem("Char"));
  ajoute_type_base(ajoute_lexem("Bool"));
  ajoute_type_base(ajoute_lexem("String"));
  yyparse();
  end_html();
}


