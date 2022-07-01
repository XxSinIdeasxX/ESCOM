#include<stdio.h>
int rfact(int);
int ifact(int);
int combina(int,int);

int main(){
	int n, r, c;
	printf("Dame los valores para n y r\n");
	scanf("%d%d", &n,&r);
	//printf("C(%d, %d)=%d\n",n,r,combina(n,r));
	printf("%d\n",ifact(n));
	return 0;
}

int rfact(int n){
	if((n>=0)&&(n<=1))
		return 1;
	else
		return n*rfact(n-1);
}

int ifact(int n){
	int f=1;
	int i=2;
	for(;i<=n;i++)
		f=f*i;
	return f;
}

int combina(int n, int r){
	return ifact(n)/(ifact(n-r)*ifact(r));
}
	
