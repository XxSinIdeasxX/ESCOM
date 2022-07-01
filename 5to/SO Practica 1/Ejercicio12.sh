#!/bin/sh
# Ejercicio 12
echo "~ Ejercicio 12 ~"

read -p "Dime tu nombre: " NOMBRE
while IFS=: read usuario clave uid gid nombre ignorar
do
  printf "%8s (%s)\n" $usuario $nombre
done </etc/passwd

