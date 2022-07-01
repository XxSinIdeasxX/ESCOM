#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"pilas.h"

//Lee una cadena coloca los elementos en un arreglo
void LeeCad(char cad[]){
    fflush(stdin);
    int i;
	for(i=0;(cad[i]=getchar())!='\n';i++);
	cad[i]='\0';
}

void Post(char cad[]){
    char res[strlen(cad)+1];
    int i, j=0; 
    Pila p;
    initialize(&p);
    for(i=0; cad[i]!='\0'; i++){
        if(isalnum(cad[i])){
            res[j]=cad[i];
            j++;
        }else if(isEmpty(&p)){
            push(&p,cad[i]);
        }else{
            if(cad[i]=='^'){
                if(top(&p)=='^'){
                    res[j]=cad[i];
                    j++;
                }else{
                    push(&p,cad[i]);
                }
            }else if((cad[i]=='+') || (cad[i]=='-')){
                while(!(isEmpty(&p))){
                    res[j]=pop(&p);
                    j++;
                }push(&p,cad[i]);
            }else{
                while(!(isEmpty(&p) || (top(&p)=='+') || (top(&p)=='-'))){
                    res[j]=pop(&p);
                    j++;
                }push(&p,cad[i]);
            }
        }
    }
    //Vacia la pila
    while(!(isEmpty(&p))){
        res[j]=pop(&p);
        j++;
    }
    res[j]='\0';
    /*Copia la cadena res a cad
    for(i=0; res[i]!='\0'; i++){
        cad[i]=res[i];
    } */
    printf("Operaciones en notacion postfija: %s",res);
}

int main(){
    char cad[256];
    printf("Introduzca las operaciones en notacion infija: "); 
    LeeCad(cad);
    Post(cad);
    return 0;
}

