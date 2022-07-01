#include<stdio.h>
#include"LogDig.h"

int main(){
	Bit b1=0,b2=1;
	NOT(b1)?printf("1\n"):printf("0\n");		//1
	NOT(b2)?printf("1\n"):printf("0\n");		//0
	AND(b1,b2)?printf("1\n"):printf("0\n");		//0
	NAND(b1,b2)?printf("1\n"):printf("0\n");	//1
	OR(b1,b2)?printf("1\n"):printf("0\n");		//1
	NOR(b1,b2)?printf("1\n"):printf("0\n");		//0
	XOR(b1,b2)?printf("1\n"):printf("0\n");		//1
	XNOR(b1,b2)?printf("1\n"):printf("0\n");	//0
	return 0;
}
