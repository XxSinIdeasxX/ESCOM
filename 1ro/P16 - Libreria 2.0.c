#include<stdio.h>
#include"Elem.h"
#include"Arreglos.h"
#include"Orden.h"

int main(){
	Elem letras[100];
	int n;
	printf("Cuantas letras vas a introducir?\n");
	scanf("%d",&n);
	fflush(stdin); //Limpia el buffer del teclado
	LeeArreglo(letras,n);
	ImpArreglo(letras,n);
	Burbuja(letras,n);
	ImpArreglo(letras,n);
	return 0;
}
