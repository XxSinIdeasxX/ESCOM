#!/bin/sh
# Ejercicio 8
echo "~ Ejercicio 8 ~"

echo "Codigo 1: "
echo answer yes or noread word
case $word in
yes | YES )echo you answered yes;;
no | NO )echo you answered no;;
esac

echo "Codigo 2: "
echo answer yes or noread word
case $word in
[Yy]* )echo you answered yes;;
[Nn]* )echo you answered no;;
* )echo you did not say yes or no;;
esac

