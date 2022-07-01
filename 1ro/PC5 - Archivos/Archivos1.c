#include<stdio.h>

int main(int argc, char *argv[]){
     FILE *entrada;

     if(entrada=fopen(*(argv+1),"r")) // ((entrada=fopen(*(argv+1),"r"))!=NULL)
           printf("Archivo abierto exitosamente.\n");
     else
           printf("Error al abrir el archivo.\n");

     return 0;
}
