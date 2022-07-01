#include<stdio.h>
// Máximo común divisor
int mcd(int a, int b){
	if (b>a)
		return mcd(b,a);
	else if (a==b)
		return a;
	else 
		return mcd(a-b,b);
}

// Sumatoria de los naturales hasta n
int sum(int n){
	if (n==1)
		return 1;
	else
		return n+sum(n-1);
}

int main(){
	int n;
//	int a,b;
//	printf("Que numeros quieres?\n");
//	scanf("%d%d",&a,&b);
//	printf("MCD(%d,%d) = %d",a,b,mcd(a,b));
	printf("Desde que numero natural deseas sumar?\n");
	scanf("%d",&n);
	printf("\nLa suma de los naturales desde %d es: %d", n, sum(n));
	return 0;
}
