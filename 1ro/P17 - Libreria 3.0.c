
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Elem.h"
#include"Arreglos.h"
#include"Orden.h"

int main(){
	Elem pals[5];
/*	
	Elem p1,p2;
	printf("Dame dos palabras\n");
	p1=LeeElem();
	p2=LeeElem();
	ImpElem(p1); putchar('\n');
	ImpElem(p2); putchar('\n');
	EsMenor(p1,p2)?printf("SI\n"):printf("NO\n");
	puts("-------------");
*/
	LeeArreglo(pals,5);
	Burbuja(pals,5); putchar('\n');
	ImpArreglo(pals,5);
	return 0;
}
