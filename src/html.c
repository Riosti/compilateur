#include "../inc/html.h"
#include "../inc/arbre.h"
#include "../inc/table_declaration.h"
#include "../inc/table_region.h"
#include "../inc/table_rep_type.h"

char* tab[] = { "DEBUT_PROG", "DEBUT", "FIN", "POINT_VIRGULE", "TYPE", "DEUX_POINTS", "STRUCT", "FSTRUCT", "TABLEAU", "CO", "CF", "VIRGULE", "POINT", "VARIABLE", "PROCEDURE", "FONCTION", "PO", "PF", "VIDE", "TANT_QUE", "FAIRE", "OPAFF", "PLUS", "MOINS", "DIV", "MULT", "VRAI", "FAUX", "INF", "SUP", "INFEGAL", "SUPEGAL", "EGAL", "DIFF", "RETOURNE", "SI", "ALORS", "SINON", "ET", "OU", "DE", "INCREMENTE", "DECREMENTE", "DIEZ", "NON", "CSTE_ENTIERE", "IDF", "CSTE_CARACTERE", "CSTE_CHAINE", "ENTIER", "REEL", "CHAINE", "BOOLEEN", "CARACTERE", "CSTE_REEL" };
FILE* html;
FILE* tabled;
FILE* tabler;
FILE* tablet;

int aac = 1;

void init_html()
{
    html = fopen("aff_arbre.html", "w");
    tabled = fopen("tablesd.html", "w");
    tabler = fopen("tablesr.html", "w");
    tablet = fopen("tablest.html", "w");
    fprintf(html, "<html>\n "
                  "\n"
                  "<head>\n"
                  "\t<meta charset=\"UTF8\">\n"
                  "\t<title>Affichage arbre</title>\n"
                  "\t<LINK href=\" inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                  "\t<script src=\"inc/affichage.js\"></script>\n"
                  "</head>\n"
                  "</head>\n"
                  "\n"
                  "<body>\n"
                  "\t<header>\n"
                  "\t\t<h1>Arbre</h1>\n"
                  "\t\t<nav>\n"
                  "\t\t\t<a href=\"aff_arbre.html\">arbre</a>\n"
                  "\t\t\t<a href=\"tablesd.html\">Déclaration</a>\n"
                  "\t\t\t<a href=\"tablesr.html\">Regions</a>\n"
                  "\t\t\t<a href=\"tablest.html\">Types</a>\n"
                  "\t\t</nav>\n"
                  "\t</header>\n"
                  "\t<input id=\"tp\" type=\"button\" value=\"Tout Plier\" onclick=\" toutPlier() \">\n"
                  "\t<input id=\"tp\" type=\"button\" value=\"Tout Deplier\" onclick=\" toutDePlier() \">\n"
                  "\t<section class=\" arbre \"> <ul id=\"0\" hid=\"0\"><li><a href=\"javascript:\" onclick=\"toggle(1)\">Prog</a><ul id=\"1\" hid=\"0\">");

    fprintf(tabled, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\" inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table des déclarations</h1>\n"
                    "\t\t<nav>\n"
                    "\t\t\t<a href=\"aff_arbre.html\">arbre</a>\n"
                    "\t\t\t<a href=\"tablesd.html\">Déclaration</a>\n"
                    "\t\t\t<a href=\"tablesr.html\">Regions</a>\n"
                    "\t\t\t<a href=\"tablest.html\">Types</a>\n"
                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>Nature</th>\n"
                    "\t<th>Suivant</th>\n"
                    "\t<th>Region</th>\n"
                    "\t<th>Description</th>\n"
                    "\t<th>Execution</th>\n"
                    "</thead>");

    fprintf(tabler, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\" inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table des regions</h1>\n"
                    "\t\t<nav>\n"
                    "\t\t\t<a href=\"aff_arbre.html\">arbre</a>\n"
                    "\t\t\t<a href=\"tablesd.html\">Déclaration</a>\n"
                    "\t\t\t<a href=\"tablesr.html\">Regions</a>\n"
                    "\t\t\t<a href=\"tablest.html\">Types</a>\n"
                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>Taille</th>\n"
                    "\t<th>NIS</th>\n"
                    "\t<th>Arbre</th>\n"
                    "</thead>");
    fprintf(tablet, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\" inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table de déclaration des types</h1>\n"
                    "\t\t<nav>\n"
                    "\t\t\t<a href=\"aff_arbre.html\">arbre</a>\n"
                    "\t\t\t<a href=\"tablesd.html\">Déclaration</a>\n"
                    "\t\t\t<a href=\"tablesr.html\">Regions</a>\n"
                    "\t\t\t<a href=\"tablest.html\">Types</a>\n"
                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>int</th>\n"

                    "</thead>");
}

void end_html()
{
    fprintf(html, "\n</section>\n<input hidden=\"true\" id=\"acc\" value=\"%d\">\n</body>\n</html>", aac);

    fprintf(tabled, "\n</table>\n</section>\n</body>\n</html>");

    fprintf(tabler, "\n</table>\n</section>\n</body>\n</html>");

    fprintf(tablet, "\n</table>\n</section>\n</body>\n</html>");
}

void genere_html(type_arbre* a)
{
    if (!arbre_vide(a)) {
        //corres tab noeud noeudf type
        fprintf(html, "<li>\n<a href=\"javascript:\" onclick=\"toggle(%d)\"> %s</a>\n", aac + 1, "coress tab");
        aac++;
        if (!arbre_vide(a->fils)) {

            fprintf(html, "<ul id=\"%d\" hid=\"0\">\n", aac);
            genere_html(a->fils);
            fprintf(html, "</ul>\n");
        }
        genere_html(a->frere);
        fprintf(html, "</li>\n");
    }
}

void genere_table_d()
{
    for (int i = 0; i < TAILLE_TABLE_DECLARATION; i++) {
        // fprintf(tabled, " <tr><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td></tr>", td->nature, td->suivant, td->region, td->description, td->execution);
    }
}

void genere_table_r()
{

    for (int i = 0; i < TAILLE_TABLE_REGION; i++) {
        // fprintf(tabler, " <tr><td>%d</td><td>%d</td><td>%d</td><td>%d</td></tr>", -1, tr->nis, tr->taille);
    }
}

void genere_table_t(int* tt)
{
    for (int i = 0; i < TAILLE_TAB_REP_TYPE; i++) {
        // fprintf(tablet, " <tr><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td></tr>", tt[i]);
    }
}