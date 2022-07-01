#include<stdio.h>
#include<stdlib.h>

#include"Ordenamiento.h"
#include"Arreglos.h"
int BusqBin(int a[],int n, int T){
	int m,L,R;
	L=0;R=n-1;
	while(L<=R){
		m=(L+R)/2;
		if(a[m]<T)
			L=m+1;
		else if(a[m]>T)
			R=m-1;
		else if(a[m]==T)
			return m;
	}
	return -1;
}

int main(){
	int a[1000],n,m,T;
	printf("¿Que longitud tendra el arreglo?\n");
	scanf("%d",&n);
	RandArreglo(a,n);
	QuickSort(a,n);
//	ImpArreglo(a,n);
	printf("¿Que elemento desea buscar?\n");
	scanf("%d",&T);
	m=BusqBin(a,n,T);
	if(m==-1)
		printf("El elemento %d no esta en el arreglo",T);
	else
		printf("El elemento %d esta en la posicion %d del arreglo",T,m);
	return 0;
}
