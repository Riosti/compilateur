all: lex.l yacc.y arbre.o hash.o sauv.o pile.o table_region.o
	yacc -d -v yacc.y 
	lex lex.l
	gcc -c lex.yy.c
	gcc -o exec y.tab.c lex.yy.o arbre.o sauv.o hash.o pile.o table_region.o  -ly -ll

all.o: arbre.o sauv.o file.o hash.o table_rep_type.o erreur.o table_region.o table_declaration.o

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

obj:
	mkdir obj

bin:
	mkdir bin

clean_obj:
	rm -rf obj

clean_bin:
	rm -rf bin

clean:
	rm -rf bin
	rm -rf obj
	rm y.output
	rm y.tab.h
	rm y.tab.c
	rm lex.yy.c
	rm *.o
	rm *.gch