#include<stdio.h>

int main(int argc, char *argv[]){
    FILE *entrada;
    char c;
    if(entrada=fopen(*(argv+1),"r")) // ((entrada=fopen(*(argv+1),"r"))!=NULL)
        printf("El archivo \"%s\" ha sido abierto exitosamente.\n",*(argv+1));
    else
        printf("Error al abrir el archivo \"%s\".\n",*(argv+1));
	
	printf("\n-%s:\n\n",*(argv+1));
    while((c=fgetc(entrada))!=EOF)
        putchar(c);
    return 0;
}
