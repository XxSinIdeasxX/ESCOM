#include<stdio.h>
void iAsce(char);
void iDesc(char);

int main(){
	char c;
	puts("Dame una letra mayuscula");
	iAsce(c=getchar());
	iDesc(c);
	return 0;
}

void iAsce(char a){
	char c;
	puts("\nAscendente");
	for(c='A';c<=a;c++)
		putchar(c); 
}

void iDesc(char a){
	puts("\n\nDescendente");
	for(;a>='A';a--)
		putchar(a); 
}
