#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *nombre;
    char *simb;
    int na;
} Elemento;

void ImpElem(Elemento e){
    printf("%s\t\t%s\t%d\n",e.nombre,e.simb,e.na);
}

void ImpElemF(Elemento e, FILE *a){
    fprintf(a,"%s\t\t%s\t%d\n",e.nombre,e.simb,e.na);
}

void ImpArreglo(Elemento arrelem[],int n){
    int i=0;

    for(i=0;i<n;i++)
        ImpElem(arrelem[i]);

};

void ImpArregloF(Elemento arrelem[],int n, FILE *a){
    int i=0;

    for(i=0;i<n;i++)
        ImpElemF(arrelem[i],a);

};

void OrdArrNA(Elemento arrelem[],int n){
    int i,j;
    Elemento t;

    for(i=0;i<n-1;i++)
       for(j=n-1;j>i;j--)
          if(arrelem[j].na<arrelem[j-1].na){
               t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
          }
};

void OrdArrNombre(Elemento arrelem[],int n){
    int i,j;
    Elemento t;

    for(i=0;i<n-1;i++)
       for(j=n-1;j>i;j--)
          if(strcmp(arrelem[j].nombre,arrelem[j-1].nombre)<0){
               t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
          }
};

void OrdArrSimb(Elemento arrelem[],int n){
    int i,j;
    Elemento t;

    for(i=0;i<n-1;i++)
       for(j=n-1;j>i;j--)
          if(strcmp(arrelem[j].simb,arrelem[j-1].simb)<0){
               t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
          }
};

int main(int argc, char *argv[]){
     FILE *entrada=fopen(*(argv+1),"r"), *nombre=fopen(*(argv+2),"w");
     FILE *simbolo=fopen(*(argv+3),"w"), *na=fopen(*(argv+4),"w");
     Elemento arrelem[200];
     int i=0, n=0;

     fflush(stdin);

     while(fscanf(entrada,"%s%s%d",arrelem[i].nombre=(char*)malloc(sizeof(char)*15),arrelem[i].simb=(char*)malloc(sizeof(char)*4),&arrelem[i].na)!=EOF)
            i++;

     ImpArreglo(arrelem,i);
     OrdArrNA(arrelem,i);
     puts("Tabla ordenada por numero atomico:");
     ImpArreglo(arrelem,i);
     ImpArregloF(arrelem,i,na);
     OrdArrNombre(arrelem,i);
     puts("Tabla ordenada por nombre:");
     ImpArreglo(arrelem,i);
     ImpArregloF(arrelem,i,nombre);
     OrdArrSimb(arrelem,i);
     puts("Tabla ordenada por simbolo:");
     ImpArreglo(arrelem,i);
     ImpArregloF(arrelem,i,simbolo);

     fclose(entrada);
     fclose(nombre);
     fclose(simbolo);
     fclose(na);

     return 0;
}
