#include<stdio.h>
void recu1(){
	char c;
	if((c=getchar())!='\n'){
		recu1();
		putchar(c);
	}	
}

void recu2(){
	char c;
	if ((c=getchar())!='\n'){
		putchar(c);
		recu2();
	}
}

void recu3(char *p){
	if ((*p=getchar())!='\n')
		recu3(p+1);
}

int main(){
	char a[80];
	//recu1();
	//recu2();
	recu3(a);
	printf("La cadena leida es:\n%s\n",a);
	return 0;
}
