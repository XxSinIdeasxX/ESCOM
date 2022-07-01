#include<stdio.h>
#include"Elem.h"
#include"Arreglos.h"
#include"Orden.h"

int main(){
	Elem l[20];
	int n;
	printf("Introduzca el número de elementos a ordenar: ");
	scanf("%d",&n);
	printf("Introduzca los elementos a ordenar: ");
	LeeArreglo(l,n);
	OrdMezcla(l,n);
	printf("\nArreglo ordenado: ");
	ImpArreglo(l,n);
	return 0;
	}

