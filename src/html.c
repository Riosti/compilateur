#include "../inc/html.h"

char* tab[] = { "A_LIST", "A_CSTE_E", "A_CSTE_R", "A_IDF", "A_CSTE_CARAC", "A_CSTE_CHAINE", "A_BOOL", "A_TQ", "A_APPEL_F", "A_APPEL_P", "A_VARIABLE", "A_TABLEAU", "A_STRUCT", "A_ET", "A_OU", "A_PLUS", "A_MULT", "A_MOINS", "A_DIV", "A_NON", "A_INF", "A_SUP", "A_EGAL", "A_SUPEGAL", "A_INFEGAL", "A_DIFF", "A_OPAFF", "A_SI", "A_ALORS", "A_SINON", "A_PROC", "A_FONCTION", "A_INCR", "A_DEC", "A_CHAINE", "A_VIRGULE", "A_ARG", "A_PARAM", "A_APPEL", "A_VIDE", "A_RETURN", "A_INT", "A_FLOAT", "A_CHAR" };

FILE* html;
FILE* tabled;
FILE* tabler;
FILE* tablet;
FILE* tableh;

int aac = 1;
int narbre = -1;
void init_html()
{
    html = fopen("bin/aff_arbre.html", "w");
    tabled = fopen("bin/tablesd.html", "w");
    tabler = fopen("bin/tablesr.html", "w");
    tablet = fopen("bin/tablest.html", "w");
    tableh = fopen("bin/tablesh.html", "w");

    char* liens = "\t\t\t<a href=\"aff_arbre.html\">arbre</a>\n"
                  "\t\t\t<a href=\"tablesd.html\">Déclaration</a>\n"
                  "\t\t\t<a href=\"tablesr.html\">Regions</a>\n"
                  "\t\t\t<a href=\"tablest.html\">Types</a>\n"
                  "\t\t\t<a href=\"tablesh.html\">Hash</a>\n";

    fprintf(html, "<html>\n "
                  "\n"
                  "<head>\n"
                  "\t<meta charset=\"UTF8\">\n"
                  "\t<title>Affichage arbre</title>\n"
                  "\t<LINK href=\"../inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                  "\t<script src=\"../inc/affichage.js\"></script>\n"
                  "</head>\n"
                  "\n"
                  "<body>\n"
                  "\t<header>\n"
                  "\t\t<h1>Arbre</h1>\n"
                  "\t\t<nav>\n%s"
                  "\t\t</nav>\n"
                  "\t</header>\n",
        liens);

    fprintf(tabled, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\"../inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table des déclarations</h1>\n"
                    "\t\t<nav>\n%s"

                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>Index</th>\n"
                    "\t<th>Nature</th>\n"
                    "\t<th>Suivant</th>\n"
                    "\t<th>Region</th>\n"
                    "\t<th>Description</th>\n"
                    "\t<th>Execution</th>\n"
                    "</thead>",
        liens);

    fprintf(tabler, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\"../inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table des regions</h1>\n"
                    "\t\t<nav>\n%s"

                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>Index</th>\n"
                    "\t<th>Taille</th>\n"
                    "\t<th>NIS</th>\n"
                    "\t<th>Arbre</th>\n"
                    "</thead>",
        liens);
    fprintf(tablet, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table</title>\n"
                    "\t<LINK href=\"../inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table de déclaration des types</h1>\n"
                    "\t\t<nav>\n%s"
                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>int</th>\n"
                    "</thead>",
        liens);

    fprintf(tableh, "<html>\n"
                    "\n"
                    "<head>\n"
                    "\t<meta charset=\"UTF8\">\n"
                    "\t<title>Affichage table Hash</title>\n"
                    "\t<LINK href=\"../inc/style.css \" rel=\" stylesheet \" type=\" text / css \">\n"
                    "</head>\n"
                    "\n"
                    "<body>\n"
                    "\t<header>\n"
                    "\t\t<h1>Table des hash</h1>\n"
                    "\t\t<nav>\n%s"

                    "\t\t</nav>\n"
                    "\t</header>\n"
                    "\t<section class=\" table \">\n"
                    "\t<table>"
                    "<thead>\n"
                    "\t<th>Index</th>\n"
                    "\t<th>Chaine</th>\n"
                    "\t<th>Taille</th>\n"
                    "\t<th>Suivant</th>\n"
                    "</thead>",
        liens);
}

void new_arbre_html(int t)
{
    char titre[30];
    sprintf(titre, "Arbre Region de nis %d", t);
    narbre++;
    if (narbre != 0) {
        fprintf(html, "</section>\n<input hidden=\"true\" id=\"acc%d\" value=\"%d\">\n", narbre - 1, aac);
        aac = 1;
    }
    fprintf(html,
        "\t<input id=\"sec%d\" class=\"tp\" type=\"button\" value=\"Tout Plier\" onclick=\" toutPlier(%d) \">\n"
        "\t<input class=\"tdp\" type=\"button\" value=\"Tout Deplier\" onclick=\" toutDePlier(%d) \">\n"
        "\t<span class=\" titreSection \">%s</span>\n"
        "\t<section  class=\" arbre \"> <ul id=\"a%da1\" hid=\"0\">",
        narbre, narbre, narbre, titre, narbre);
}

void end_html()
{
    fprintf(html, "\n</section>\n<input hidden=\"true\" id=\"acc%d\" value=\"%d\">\n<footer><a href=\"https://codepen.io/simplyhue/pen/pjEYGo\" >Modèle</a> d'arbre vertical par <a href=\"https://codepen.io/simplyhue/\">SimplyHue</a> <!-- Design uniquement, génération et fonctionnalités supplémentaires personnelles mais bon personne ne viendra voir ce commentaire --></footer></body>\n</html>", narbre, aac);

    fprintf(tabled, "\n</table>\n</section>\n</body>\n</html>");

    fprintf(tabler, "\n</table>\n</section>\n</body>\n</html>");

    fprintf(tablet, "\n</tr></table>\n</section>\n</body>\n</html>");
    fprintf(tableh, "\n</tr></table>\n</section>\n</body>\n</html>");
}

void genere_html(type_arbre* a)
{
    if (!arbre_vide(a)) {
        //corres tab noeud noeudf type
        aac++;
        char c[20];
        if (a->noeud == 0 && a->noeudf != 0) {
            sprintf(c, "%f", a->noeudf);
        } else if (a->noeudf == 0 && a->noeud != 0) {
            if (a->noeud == -1) {
                sprintf(c, " ");
            } else if (a->type == A_IDF) {
                sprintf(c, "%s", get_lexeme(a->noeud));
            } else {
                sprintf(c, "%d", a->noeud);
            }
        } else {
            sprintf(c, " ");
        }
        fprintf(html, "<li>\n<a id=\"i%di%d\" href=\"javascript:\" onclick=\"toggle('a%da%d')\">%s %s</a> <!-- t%d dec%d tf%d tv%d -->\n", narbre, aac, narbre, aac, tab[a->type], c, a->type, a->num_dec, a->type_final, a->type_var);

        if (!arbre_vide(a->fils)) {
            fprintf(html, "<ul id=\"a%da%d\" hid=\"0\">\n", narbre, aac);
            genere_html(a->fils);
            fprintf(html, "</ul>\n");
        } else {
            fprintf(html, "<script>document.getElementById(\"i%di%d\").style.backgroundColor = \"#ecdfc2\"</script>", narbre, aac);
        }
        genere_html(a->frere);
        fprintf(html, "</li>\n");
    }
}

void genere_table_d(int x, int n, int s, int r, int d, int e)
{
    fprintf(tabled, "<tr><th>%d</th><td>%d</td><td>%d</td><td>%d</td><td>%d</td><td>%d</td></tr>", x, n, s, r, d, e);
}
void genere_table_r(int x, int taille, int nis, type_arbre* a)
{
    new_arbre_html(nis);
    genere_html(a);
    fprintf(tabler, "<tr><th>%d</th><td>%d</td><td>%d</td><td><a class=\"lienArbre\" href=\"aff_arbre.html#sec%d\">Arbre correspondant</a></td></tr>", x, taille, nis, nis);
}

int nbRType = 0;
void genere_table_t(int a, int tt)
{
    nbRType++;

    if (nbRType == 16) {
        fprintf(tablet, "</tr><tr>");
    }
    fprintf(tablet, "<td>%d %d</td>", a, tt);
}

void genere_table_h(int x, char* c, int a, int b)
{
    fprintf(tableh, "<tr><th>%d</th><td>%s</td><td>%d</td><td>%d</td></tr>", x, c, a, b);
}