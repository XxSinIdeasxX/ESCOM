#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Crea un tipo de dato con tres argumentos
//dos apuntadores de tipo char y un entero
//[nombre, simb, na]
//[ *char,*char,int]
typedef struct {
    char *nombre;
    char *simb;
    int na;
} Elemento;

//Muestra en la panalla el elemento "nombre simb na"
void ImpElem(Elemento e){
    printf("%s\t\t%s\t%d\n",e.nombre,e.simb,e.na);
}

//Copia a un archivo 'a' una el elemento "nombre simb na"
void ImpElemF(Elemento e, FILE *a){
    fprintf(a,"%s\t\t%s\t%d\n",e.nombre,e.simb,e.na);
}

//Muestra en pantalla los primeros n elementos de arrelem
void ImpArreglo(Elemento arrelem[],int n){
    int i=0;
    for(i=0;i<n;i++)
        ImpElem(arrelem[i]);
}

//Copia a un archivo 'a' los primeros n elementos de arrelem
void ImpArregloF(Elemento arrelem[],int n, FILE *a){
    int i=0;
    for(i=0;i<n;i++)
        ImpElemF(arrelem[i],a);
}

void OrdArrNA(Elemento arrelem[],int n){
    int i,j;
    Elemento t;
	
    for(i=0;i<n-1;i++)
        for(j=n-1;j>i;j--)
			//Ordena arrelem de mayor a menor
            if(arrelem[j].na>arrelem[j-1].na){
            	t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
            }
}

void OrdArrNombre(Elemento arrelem[],int n){
    //Ordena arrelem alfabeticamente
    //comparando los valores 'nombre' de los Elementos
	int i,j;
    Elemento t;
	
    for(i=0;i<n-1;i++)
   		for(j=n-1;j>i;j--)
   			//Comparacion de cadenas
			//Si strcmp(cad1, cad2)<0 entonces cad1<cad2
        	if(strcmp(arrelem[j].nombre,arrelem[j-1].nombre)<0){
            	t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
        	}
}

void OrdArrSimb(Elemento arrelem[],int n){
	//Ordena arrelem alfabeticamente 
	//comparando los valores 'simb' de los Elementos
    int i,j;
    Elemento t;
	
    for(i=0;i<n-1;i++)
        for(j=n-1;j>i;j--)
    		if(strcmp(arrelem[j].simb,arrelem[j-1].simb)<0){
               t=arrelem[j]; arrelem[j]=arrelem[j-1]; arrelem[j-1]=t;
        	}
}

int main(int argc, char *argv[]){
	//Abre los archivos txt, el primer archivo en modo lectura
	//los otros tres en escritura, si no existen los crea
	FILE *entrada=fopen(*(argv+1),"r"), *nombre=fopen(*(argv+2),"w");
    FILE *simbolo=fopen(*(argv+3),"w"), *numero=fopen(*(argv+4),"w");
    Elemento arrelem[30];//Arreglo de 30 Elementos [nombre,simb,na]
    
	int i=0;
    fflush(stdin);
	
	//Llena los Elementos [nombre, simb, na] de arrelem con los valores
	// de cada linea del archivo entrada hasta encontrar el EOF
    while(fscanf(entrada,"%s%s%d",arrelem[i].nombre=(char*)malloc(sizeof(char)*15),arrelem[i].simb=(char*)malloc(sizeof(char)*10),&arrelem[i].na)!=EOF)
        i++;

    OrdArrNA(arrelem,i);//Ordena arrelem con BuubleSort usando los valores 'na' de los Elementos
    puts("\nTabla ordenada por millones de habitantes:\n---------------------------");
    ImpArreglo(arrelem,i);//Muestra el arrreglo ordenado en pantalla
    ImpArregloF(arrelem,i,numero);//Copia los Elementos arrelem al archivo txt
    //Repite el proceso con los valores 'nombre'
    OrdArrNombre(arrelem,i);
    puts("\nTabla ordenada por nombre:\n---------------------------");
    ImpArreglo(arrelem,i);
    ImpArregloF(arrelem,i,nombre);
    //Repite el proceso con los valores 'simb'
    OrdArrSimb(arrelem,i);
    puts("\nTabla ordenada por continente:\n---------------------------");
	ImpArreglo(arrelem,i);
    ImpArregloF(arrelem,i,simbolo);
    
    //Cierra los archivos
    fclose(entrada);
    fclose(nombre);
    fclose(simbolo);
    fclose(numero);
    return 0;
}
