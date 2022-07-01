#include<stdio.h>

int main(int argc, char *argv[]){
    FILE *entrada, *salida;
    int c, n=0;
    entrada=fopen(*(argv+1),"r");
    salida=fopen(*(argv+2),"w");
	
    while((c=fgetc(entrada))!=EOF){
        fputc(c,salida);
        n++;
    }
    printf("Se han copiado %d caracteres al archivo \"%s\".\n",n,*(argv+2));
    fclose(entrada);
    fclose(salida);
	return 0;
}
