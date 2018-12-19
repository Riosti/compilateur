%{
#include "y.tab.h"
#include "inc/hash.h"
int Num_lignes=1;
int Num_inst=0;
int Num_mots_lu=0;
%}

%%
"Prog" {return(DEBUT_PROG);}
"{" {return(DEBUT);}
"}" {return(FIN);}
";" {return(POINT_VIRGULE);}
"Type" {return(TYPE);}
":" {return(DEUX_POINTS);}
"Struct" {return(STRUCT);}
"Fstruct" {return(FSTRUCT);}
"Tab" {return(TABLEAU);}
"[" {return(CO);}
"]" {return(CF);}
"," {return(VIRGULE);}
"." {  return(POINT);}
"Int" {yylval.type_int=ajoute_lexem(yytext);return(ENTIER);}
"Float" {yylval.type_int=ajoute_lexem(yytext);return(REEL);}
"Bool" {yylval.type_int=ajoute_lexem(yytext);return(BOOLEEN);}
"Char" {yylval.type_int=ajoute_lexem(yytext);return(CARACTERE);}
"String" {yylval.type_int=ajoute_lexem(yytext);return(CHAINE);}
"Var" { return(VARIABLE);}
"Procedure" {return(PROCEDURE);}
"Fonction" {return(FONCTION);}
"Return" {return(RETOURNE);}
"If" {return(SI);}
"Then" {return(ALORS);}
"Else" {return(SINON);}
"(" {return(PO);}
")" {return(PF);}
"Null" {return(VIDE);}
"While" {return(TANT_QUE);}
"Do" {return(FAIRE);}
"=" {return(OPAFF);}
"+" {return(PLUS);}
"-" {return(MOINS);}
"/" {return(DIV);}
"*" {return(MULT);}
"True" {return(VRAI);}
"False" {return(FAUX);}
"<" {return(INF);}
">" {return(SUP);}
"<=" {return(INFEGAL);}
">=" {return(SUPEGAL);}
"==" {return(EGAL);}
"&&" {return(ET);}
"||" {return(OU);}
"Of" {return(DE);}
"++" {return(INCREMENTE);}
"--" {return(DECREMENTE);}
"!=" {return(DIFF);}
"#" {return(DIEZ);}
"!" {return(NON);}
"Read" {return (READ);}
"Write" {return (WRITE);}



(0|([1-9][0-9]*))"."([0-9]+) {yylval.type_float=atof(yytext); return(CSTE_REEL);}
0|([1-9][0-9]*) { yylval.type_int=atoi(yytext);return(CSTE_ENTIERE);}
[a-z][a-zA-Z0-9_]* {yylval.type_int=ajoute_lexem(yytext);return(IDF);}
\'[a-zA-Z]\' {return(CSTE_CARACTERE);}
\"[a-zA-Z0-9_]+\" {return(CSTE_CHAINE);}
\n {Num_lignes++;Num_inst=0;Num_mots_lu++;}
" " {Num_inst++;Num_mots_lu++;}
.
%%

