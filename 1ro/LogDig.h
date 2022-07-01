typedef int Bit;
typedef Bit* Nibble;

Bit NOT(Bit b){return !b;}
Bit OR(Bit b1, Bit b2){return b1|b2;}
Bit AND(Bit b1, Bit b2){return b1&b2;}
Bit XOR(Bit b1, Bit b2){return OR(AND(NOT(b1),b2),AND(b1,NOT(b2)));}
Bit NAND(Bit b1, Bit b2){return NOT(AND(b1,b2));}
Bit NOR(Bit b1, Bit b2){return NOT(OR(b1,b2));}
Bit XNOR(Bit b1, Bit b2){return NOT(XOR(b1,b2));}

Bit FA(Bit b1, Bit b2, Bit c){return XOR(c,XOR(b1,b2));}
Bit C(Bit b1, Bit b2){return AND(b1,b2);}

Nibble FA4(Nibble n1, Nibble n2){
	Nibble s=(Nibble)malloc(sizeof(Bit)*5)
	s[4]=0;
	int i;
	for(i=0;i<4;i++){
		s[i]=FA(n1[i],n2[i],s[4]);
		s[4]==0?s[4]=C(n1[i],n2[i]):s[4]==C(s[4],s[i]);
	}
}
