#!/bin/sh
# Ejercicio 10
echo "~ Ejercicio 10 ~"

for number in 1 2 3 4 5 6
do
	for letter in a b c d e f g
	do
		case $number in
			3) break
		esac
		echo $number $letter
	done
done
