#include<stdio.h>
char LeerCar(){
	return getchar();
}

void EscribirCar(char a){
	putchar(a);
}

int main(){
	EscribirCar(LeerCar);
}
