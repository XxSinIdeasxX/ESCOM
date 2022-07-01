#!/bin/sh
# Ejercicio 5

echo "~ Ejercicio 5 ~"

if [ -r "$1" ]; then
echo "$1 tiene permisos de lectura";
else echo "$1 no tiene permisos de lectura";
fi

if [ -e "$2" ]; then
	if [ -x "$2" ]; then
	echo "$2 existe y tiene permisos de ejecucion";
	else echo "$2 no tiene permisos de ejecucion";
	fi;
else echo "$2 no existe";
fi

aux= -o "$3"
echo "Propietario de $3: $aux"

if [ "$1" -ot "$2" ]; then
	if [ "$1" -ot "$3" ]; then
	echo "$1 es el archivo mas antiguo";
	else echo "$3 es el archivo mas antiguo";
	fi;
else if [ "$2" -ot "$3" ]; then
	echo "$2 es el archivo mas antiguo";
	else echo "$3 es el archivo mas antiguo";
	fi;
fi
