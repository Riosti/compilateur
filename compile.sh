#!/usr/bin/env bash
if (( $# != 1 ))
then
    echo "<nom de fichier a compilier>"

else
    ./bin/exec $1 < $1
    string=$1
    string=${string/cea/ocea}
    sed -i '1iexit' table_prog
    sed -i '1irm table_prog' table_prog
    sed -i '1i./bin/pile_exec' table_prog
    sed -i '1ichmod 666 table_prog' table_prog
    sed -i '1ised -i "1,8d" table_prog' table_prog
    sed -i '1icp $string table_prog' table_prog
    sed -i '1istring='$string table_prog
    sed -i '1i#!/usr/bin/env bash' table_prog
    mv table_prog $string
    chmod 766 $string
fi;
