#include<stdio.h>
#include"Elem.h"
//Para las librerias que creamos 
//hay que especificar su ubicaci�n
int main(){
	Elem a,b;
	a=LeeElem();
	b=LeeElem();
	EsMenor(a,b)?ImpElem(a):ImpElem(b);// if taquigr�fico
	Intercambia(&a,&b);
	ImpElem(a);
	return 0;
}
