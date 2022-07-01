#include<stdio.h>
#include<time.h>
#include<windows.h>
#include<stdlib.h>

#include"Ordenamiento.h"
#include"Arreglos.h"

int main(){
	time_t ti1,tf1,ti2,tf2;
	int a[50000],b[50000],n;
	printf("¿Que longitud tendra el arreglo?\n");
	scanf("%d",&n);
	RandArreglo(a,n);
	CopyArreglo(a,b,n);
//	printf("Arreglo original: ");
//	ImpArreglo(a,n);
	ti1=time(NULL);
	QuickSort(a,n);
	tf1=time(NULL);
	printf("Ordenamiento QuickSort realizado despued de: %d s\n",tf1-ti1);
	ti2=time(NULL);
	Bubble(a,n);
	tf2=time(NULL);
	printf("Ordenamiento BubbleSort realizado despued de: %d s\n",tf2-ti2);
//	printf("\nArreglo ordenado: ");
//	ImpArreglo(a,n);
	return 0;
}
