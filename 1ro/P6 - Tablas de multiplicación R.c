#include<stdio.h>
// Tablas de multiplicar de n, desde 1 hasta i
void TablaRec(int n,int i){
	if (i>0){
		TablaRec(n,i-1);
		printf("%d x %d = %d \n", n,i,n*i);
	}
}

int main(){
	int n,l;
	printf("Cual tabla quieres?  ");
	scanf("%d%d",&n,&l);
	printf("\nTabal del %d:\n\n", n);
	TablaRec(n,l);
	return 0;
}
