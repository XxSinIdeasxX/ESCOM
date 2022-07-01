#include<stdio.h>
//Imprime los caracteres desde la letra ingresada hasta la A
void Asce(char);

int main (){
	Asce(getchar());
	return 0;
}

void Asce(char c){
	if (c>='A'){
		putchar(c);
		Asce(c-1);
	}
}
