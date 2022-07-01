#!/bin/sh

# Ejercicio 1
echo "\n~ Ejercicio 1 ~"
ls -al /usr /tmp /noexiste >ls.sal 2>ls.err find /tmp -print >find.sal 2>/dev/null

# Ejercicio 2
echo "\n~ Ejercicio 2 ~"
ls | tee salida | sort -r

# Ejercicio 3
echo "\n~ Ejercicio 3 ~"

echo "SHELL: $SHELL"
echo "HOME: $HOME"
echo "LOGNAME: $LOGNAME"
echo "PATH: $PATH"
echo "PAGER: $PAGER"
echo "EDITOR: $EDITOR"
echo "TERM: $TERM"
echo "PS1: $PS1"
echo "PS2: $PS"
echo "TZ: $TZ"

# Ejercicio 4
echo "\n~ Ejercicio 4 ~"

a=10
b=$(expr 2 \* 10)
c=$(expr $a + \( $b / 2 \))
c=$(expr \( 2 + 3 \) \* 10)
div=$(expr $c / 2)
res=$(expr $b % $c)
echo "a=$a b=$b c=$c div=$div res=$res"

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

# Ejercicio 7
echo "~ Ejercicio 7 ~"

if [ $# -eq 0 ]; then
echo "Sin argumentos";
else echo "Argumentos: $*";
fi

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

# Ejercicio 9
echo "~ Ejercicio 9 ~"

for i in $(tr ' ' '_' </etc/passwd)
do
set $(echo $i | tr ':' ' ')
echo user: $1, UID: $3, Home Directory: $6
done

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

# Ejercicio 12
echo "~ Ejercicio 12 ~"

read -p "Dime tu nombre: " NOMBRE
while IFS=: read usuario clave uid gid nombre ignorar
do
  printf "%8s (%s)\n" $usuario $nombre
done </etc/passwd