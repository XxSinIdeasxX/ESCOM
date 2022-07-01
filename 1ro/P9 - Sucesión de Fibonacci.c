#include<stdio.h>
// Sucesión de Fibonacci
int fib(int n){
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else return fib(n-1)+fib(n-2);
}

int main(){
	int n;
	printf("Dame un valor para n\n");
	scanf("%d",&n);
	printf("\nfib(%d) = %d", n,fib(n));
}
