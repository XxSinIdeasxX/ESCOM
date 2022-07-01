#include<stdio.h>

int main(int argc, char *argv[]){
    FILE *entrada;
    char c;
    int n=0;
    if(entrada=fopen(*(argv+1),"r")) // ((entrada=fopen(*(argv+1),"r"))!=NULL)
        printf("El archivo \"%s\" ha sido abierto exitosamente.\n",*(argv+1));
    else
        printf("Error al abir el archivo \"%s\".\n",*(argv+1));

	printf("\n-%s:\n\n",*(argv+1));
    while((c=fgetc(entrada))!=EOF){
        putchar(c);
        n++;
    }
    printf("\n\nEl archivo \"%s\" tiene %d caracteres.\n",*(argv+1),n);
    return 0;
}
