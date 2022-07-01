#include<stdio.h>
#include<string.h>

int Menu(){
    int op;
    printf("\n\t\tMenú9\n====================================\n");
    printf("1) Introducir una nueva cadena\n2) Imprimir la cadena\n3) Invertir la cadena\n");
    printf("4) Concatenar la cadena n veces consigo misma\n5) Salir\n\n¿Qué desea hacer?\n> ");
    fflush(stdin);
    scanf("%i",&op);
    putchar('\n');
    return op;
}

void LeeCad(char cad[]){
    fflush(stdin);
    int i;
	for(i=0;(cad[i]=getchar())!='\n';i++);
	cad[i]='\0';
}

void Invertir(char cad[]){
    char t;
    int l, i, j;
    l=strlen(cad);
    for(i=0, j=l-1;i<(l/2);i++,j--){
        t=cad[i];
        cad[i]=cad[j];
        cad[j]=t;
    }
}

void Concatenar(char cad[], int n){
    if(n==0){
        cad[0]='\0';
    }else{
        int i,len;
        len=strlen(cad);
        if(n<0){
            Invertir(cad);
            n=n*-1;
        }
        for(i=len;i<(n*len);i++){
            cad[i]=cad[i-len];
        }     
        cad[i]='\0';
    }
}

int main(){
    char cad[256];
    int op, n;
    printf("Introduzca una cadena: ");
    LeeCad(cad);
    while (1){
        op=Menu();
        if(op==1){
            printf("Introduzca la nueva cadena: ");
            LeeCad(cad);
        }else if(op==2){
            printf("Cadena: %s\n",cad);
        }else if(op==3){
            Invertir(cad);
            printf("Cadena invertida: %s\n",cad);
        }else if(op==4){
            printf("¿Cuánto vale n?\n");
            scanf("%i",&n);
            Concatenar(cad,n);
            printf("\nCadena concatenada: %s\n",cad);
        }else if(op==5){
            printf("Hasta luego :D\n");
            break;
        }else{
            printf("<Opción no válida, por favor seleccione de nuevo>\n");
        }
    }
    return 0;
}