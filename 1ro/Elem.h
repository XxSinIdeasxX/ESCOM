typedef char *Elem;
void ImpElem(Elem e){printf("%s", e);}
Elem LeeElem(){
	Elem pal=(Elem)malloc(sizeof(char)*80);
	scanf("%s", pal);
	return pal;
}
int EsMenor(Elem e1, Elem e2){return strcmp(e1,e2)<0;}
void Intercambia(Elem*e1, Elem*e2){
	Elem t;
	t=*e1;*e1=*e2;*e2=t;
}
