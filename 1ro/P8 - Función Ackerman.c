#include<stdio.h>
// Función de Ackerman
int Ack(int m, int n){
	if (m==0)
		return n+1;
	else if ((m>0)&&(n==0))
		return Ack(m-1,1);
	else if ((m>0)&&(n>0))
		return Ack(m-1,Ack(m,n-1));
}

int main(){
	int m,n;
	printf("Que valores quieres para n y m?\n");
	scanf("%d%d",&n,&m);
	printf("Ack(%d, %d) = %d",n,m,Ack(n,m));
}
