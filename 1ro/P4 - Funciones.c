#include<stdio.h>
void Eco(int n){
	printf("%d\n",n);
}

int Suma(int n1, int n2){
	return n1+n2;
}

int Resta(int r1, int r2){
	return r1-r2;
}

int Mult(int m1, int m2){
	return m1*m2;
}

int Div(int d1, int d2){
	return d1/d2;
}

int main(){
	//Eco(3);
	//Eco(4);
	//Eco(Suma(3,4));
	//Eco(Mult(3,4));
	
	Eco(Mult(Suma(4,8),Suma(6,2)));
	return 0;
}
