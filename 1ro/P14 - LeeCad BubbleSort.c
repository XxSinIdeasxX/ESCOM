#include<stdio.h>
int LeeCad(char []);
void ImpCad(char []);
void Bubble(char [],int);
void Intercambia(int, int);

int main(){
	char cad[80];
	int i;
	printf("Dame una cadena");
//	cad representa la ubicación en memoria del arreglo	
	i=LeeCad(cad);
	printf("Antes de ordenar: ");
	ImpCad(cad);
	Bubble(cad,i);
	printf("\nDespues de ordenar: ");
	ImpCad(cad);
	return 0;
}

//Lee cadenas
int LeeCad(char pal[]){
	int i;
	for(i=0;(pal[i]=getchar())!='\n';i++);
	pal[i]='\0';
	return i;
}

void ImpCad(char pal[]){
	int i;
	for(i=0;pal[i]!='\0';i++)
	     putchar(pal[i]);
}

//Bubble sort - Ordena cadenas de menor a mayor
//				orden alfabetico
void Bubble(char a[],int n){
	int i,j;
	char t;
	for(j=0;j<n-1;j++)
		for(i=n-1;i>j;i--)
			if(a[i]<a[i-1]){
				t=a[i];a[i]=a[i-1];a[i-1]=t;
			}
}

void Intecambia(int x, int y){
	int t;
	t=x;x=y;y=t;
}

