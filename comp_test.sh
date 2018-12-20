#!/usr/bin/env bash

./compil.sh tests/erreur.cea
mkdir bin/erreur
mv bin/*.html bin/erreur/

./compil.sh tests/erreurtab.cea
mkdir bin/erreurtab
mv bin/*.html bin/erreurtab/

./compil.sh tests/tab.cea
mkdir bin/tab
mv bin/*.html bin/tab/

./compil.sh tests/srtuct.cea
mkdir bin/srtuct
mv bin/*.html bin/srtuct/

./compil.sh tests/if.cea
mkdir bin/if
mv bin/*.html bin/if/

./compil.sh tests/while.cea
mkdir bin/while
mv bin/*.html bin/while/

./compil.sh tests/procedure.cea
mkdir bin/procedure
mv bin/*.html bin/procedure/

./compil.sh tests/fonction.cea
mkdir bin/fonction
mv bin/*.html bin/fonction/

./compil.sh tests/tout.cea
mkdir bin/tout
mv bin/*.html bin/tout/