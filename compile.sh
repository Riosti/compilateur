#!/usr/bin/env bash
if (( $# != 1 ))
then
    echo "<nom de fichier a compilier>"

else
    ./bin/exec $1 < $1
    string=$1
fi;
