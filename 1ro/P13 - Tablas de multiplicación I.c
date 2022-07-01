#include<stdio.h>
void itabla(int n, int t){
	int i;
	for(i=1;i<=t;i++)
		printf("%dx%d=%d\n",n,i,n*i);
}

int main(){
	int n,t;
	puts("Dame n y hasta donde quieres su tabla");
	scanf("%d%d",&n,&t);
	itabla(n,t);
	return 0;
}
