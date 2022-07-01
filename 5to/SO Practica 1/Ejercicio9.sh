#!/bin/sh
# Ejercicio 8
echo "~ Ejercicio 8 ~"

for i in $(tr ' ' '_' </etc/passwd)
do
set $(echo $i | tr ':' ' ')
echo user: $1, UID: $3, Home Directory: $6
done
