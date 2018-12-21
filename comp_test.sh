#!/usr/bin/env bash

	rm -rf bin/struct bin/if bin/fonction bin/inc bin/procedure bin/tout bin/while
	rm -rf tests/*.ocea

if (( $# != 1 ))
then

	# bin/exec < tests/erreur.cea
	# mkdir bin/erreur
	# mv bin/*.html bin/erreur/

	# bin/exec < tests/erreurtab.cea
	# mkdir bin/erreurtab
	# mv bin/*.html bin/erreurtab/

	# bin/exec < tests/tab.cea
	# mkdir bin/tab
	# mv bin/*.html bin/tab/

	bin/exec < tests/struct.cea
	mkdir bin/struct
	mv -f bin/*.html bin/struct/

	bin/exec < tests/if.cea
	mkdir bin/if
	mv -f bin/*.html bin/if/

	bin/exec < tests/while.cea
	mkdir bin/while
	mv -f bin/*.html bin/while/

	bin/exec < tests/procedure.cea
	mkdir bin/procedure
	mv -f bin/*.html bin/procedure/

	bin/exec < tests/fonction.cea
	mkdir bin/fonction
	mv -f bin/*.html bin/fonction/

	bin/exec < tests/tout.cea
	mkdir bin/tout
	mv -f bin/*.html bin/tout/

	mkdir bin/inc/
	cp inc/style.css bin/inc/
	cp inc/affichage.js bin/inc/
fi;

