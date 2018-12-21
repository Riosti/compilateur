all: obj bin objbis
	make all_compilateur
	make MV
	make clean_gch

all_compilateur: lex.l yacc.y html.o arbre.o hash.o sauv.o pile.o erreur.o table_region.o table_declaration.o table_rep_type.o analyse_sementique.o file.o bin obj clean_gch
	yacc -d -v yacc.y
	lex lex.l
	gcc -c lex.yy.c
	gcc -o bin/exec y.tab.c lex.yy.o obj/html.o obj/erreur.o obj/arbre.o obj/sauv.o obj/hash.o obj/pile.o obj/table_region.o obj/table_declaration.o obj/analyse_sementique.o obj/table_rep_type.o obj/file.o -ly -ll
	mv y.* obj/
	mv *.o obj/
	mv lex.yy.c obj/


all.o: arbre.o html.o sauv.o file.o hash.o table_rep_type.o erreur.o table_region.o table_declaration.o

analyse_sementique.o: src/analyse_sementique.c inc/analyse_sementique.h
	gcc -Wall -c src/analyse_sementique.c inc/analyse_sementique.h
	mv analyse_sementique.o obj/
arbre.o: src/arbre.c inc/arbre.h obj
	gcc -Wall src/arbre.c inc/arbre.h -c
	mv arbre.o obj/ 
sauv.o: inc/sauv.h src/sauv.c obj
	gcc -Wall src/sauv.c inc/sauv.h -c
	mv sauv.o obj/
file.o: inc/file.h src/file.c obj
	gcc -Wall inc/file.h src/file.c -c
	mv file.o obj/
hash.o: src/hash.c inc/hash.h obj
	gcc -Wall src/hash.c inc/hash.h -c
	mv hash.o obj/
table_rep_type.o: src/table_rep_type.c inc/table_rep_type.h obj 
	gcc -Wall src/table_rep_type.c inc/table_rep_type.h -c
	mv table_rep_type.o obj/
erreur.o : src/erreur.c inc/erreur.h obj
	gcc -Wall src/erreur.c inc/erreur.h -c
	mv erreur.o obj/
table_region.o: inc/table_region.h src/table_region.c obj
	gcc -Wall src/table_region.c inc/table_region.h -c
	mv table_region.o obj/
table_declaration.o : src/table_declaration.c inc/table_declaration.h obj
	gcc -Wall inc/table_declaration.h src/table_declaration.c -c
	mv table_declaration.o obj/
pile.o : src/pile.c inc/pile.h
	gcc -Wall src/pile.c inc/pile.h -c
	mv pile.o obj/
html.o: inc/html.h src/html.c obj
	gcc -Wall src/html.c inc/html.h -c
	mv html.o obj/
#######################MACHINE VIRTUELLE##################################
##########################################################################
MV: objbis pile_exec 
	mv pile_exec bin/

pile_exec: pile_exec.o fileBC.o charger.o calcule_deplacement.o
	gcc -Wall -o pile_exec objbis/pile_exec.o objbis/fileBC.o objbis/charger.o obj/table_rep_type.o obj/table_declaration.o obj/table_region.o obj/file.o obj/arbre.o obj/hash.o obj/pile.o objbis/calcule_deplacement.o obj/erreur.o


pile_exec.o: src/pile_exec.c inc/pile_exec.h
	gcc -Wall src/pile_exec.c inc/pile_exec.h -c
	mv pile_exec.o objbis/


fileBC.o: src/fileBC.c inc/fileBC.h
	gcc -Wall src/fileBC.c inc/fileBC.h -c
	mv fileBC.o objbis/

charger.o: src/charger.c inc/charger.h
	gcc -Wall src/charger.c inc/charger.h -c
	mv charger.o objbis/


module_chargement.o: module_chargement.c inc/charger.h
	gcc -Wall  module_chargement.c inc/charger.h -c

module: module_chargement.o charger.o
	gcc -Wall -o module module_chargement.o charger.o

calcule_deplacement.o : src/calcule_deplacement.c inc/calcule_deplacement.h
	gcc -Wall src/calcule_deplacement.c inc/calcule_deplacement.h -c
	mv calcule_deplacement.o objbis/

###########################################################################

obj:
	mkdir obj

bin:
	mkdir bin
objbis:
	mkdir objbis

clean_gch:
	rm -rf inc/*.gch

clean_obj:
	rm -rf obj

clean_bin:
	rm -rf bin
clean_objbis:
	rm -rf objbis
clean_ocea:
	rm *.ocea


clean: clean_bin clean_gch clean_obj clean_objbis 
