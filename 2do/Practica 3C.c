#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"pilas.h"

void LeeCad(char []);
void Post(char []);
void EvPost(char []);
int menu();
void impArbol(Nodo *);

int main(){
    int op;
    while(1){
        char cad[256];
        op = menu();
        switch (op){
        case 1:
            printf("\nIntroduzca la expresion en notacion infija: "); 
            LeeCad(cad);
            Post(cad);
            putchar('\n');
            break;
        case 2:
            printf("\nIntroduzca la expresion postfija: ");
            LeeCad(cad);
            EvPost(cad);
            putchar('\n');
            break;
        case 3:
            printf("\nHasta luego :D");
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}

void EvPost(char cad[]){
    /*Se van a crear estructuras de arbles 
    binarios en algunos nodos de la pila*/
    int i;
    Pila p;
    initialize(&p);
    for(i=0; cad[i]!='\0';i++){
        Nodo *e;
        e=(Nodo *)malloc(sizeof(Nodo));
        e->valor=cad[i];
        if(isalnum(cad[i])){
            e->izquierda=NULL;
            e->derecha=NULL;
            pushNod(&p, e);
        }else{
            if(p.size==1){
                printf("\n\t-La expresion es incorrecta-\n\n");
                char cad2[256];
                printf("Introduzca nuevamente la expresion postfija: "); 
                LeeCad(cad2);
                EvPost(cad2);
                return;
            }    
            e->derecha=popNod(&p);   
            e->izquierda=popNod(&p);
            pushNod(&p, e);
        }
    }
    if(p.size>1){
        printf("\n\t-La expresion es incorrecta-\n\n");
        char cad2[256];
        printf("Introduzca nuevamente la expresion postfija: "); 
        LeeCad(cad2);
        EvPost(cad2);
        return;
    }
    printf("Expresion en notacion infija: ");
    impArbol(popNod(&p));
    putchar('\n');
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
        }else if(isEmpty(&p) || cad[i]=='('){
            push(&p,cad[i]);
        }else if(cad[i]==')'){
            while(!(isEmpty(&p) || top(&p)=='(')){
                res[j]=pop(&p);
                j++;
            }if(isEmpty(&p)){
                printf("\n\t-La expresion es incorrecta-\n\n");
                char cad2[256];
                printf("Introduzca nuevamente la expresion en notacion infija: "); 
                LeeCad(cad2);
                Post(cad2);
                return;
            }pop(&p);
        }else{
            if(cad[i]=='^'){
                if(top(&p)=='^'){
                    res[j]=cad[i];
                    j++;
                }else{
                    push(&p,cad[i]);
                }
            }else if((cad[i]=='+') || (cad[i]=='-')){
                while(!(isEmpty(&p) || top(&p)=='(')){
                    res[j]=pop(&p);
                    j++;
                }push(&p,cad[i]);
            }else{
                while(!(isEmpty(&p) || top(&p)=='(' || (top(&p)=='+') || (top(&p)=='-'))){
                    res[j]=pop(&p);
                    j++;
                }push(&p,cad[i]);
            }
        }
    }
    //Vacia la pila
    while(!(isEmpty(&p))){
        res[j]=pop(&p);
        if(res[j]=='('){    //Revisa si hay más '(' que ')'
            printf("\n\t-La expresion es incorrecta-\n\n");
            char cad2[256];
            printf("Introduzca nuevamente la expresion en notacion infija: "); 
            LeeCad(cad2);
            Post(cad2);
            return;
        }
        j++;
    }
    res[j]='\0';
    printf("Operaciones en notacion postfija: %s\n",res);
}

void LeeCad(char cad[]){//Lee una cadena y coloca los elementos en un arreglo
    fflush(stdin);
    int i;
	for(i=0;(cad[i]=getchar())!='\n';i++);
	cad[i]='\0';
}

int menu(){
	int respuesta = 0;
	printf("\n\t\t    Menu\n============================================\n");
	printf("1. Convertir una expresion infija a postfija\n");
	printf("2. Evaluar una expresion postfija\n");
	printf("3. Salir\n\nSeleccione una opcion: ");
	scanf("%d",&respuesta);
	while(respuesta>3 || respuesta<1){
        fflush(stdin);
		printf("\n\t> Error <\n\nSeleccione una opcion valida: ");
		scanf("%d",&respuesta);
	}return respuesta;
}

void impArbol(Nodo *e){//Imprime el arbol del nodo en inorden
    if(e->izquierda)
        impArbol(e->izquierda);
    putchar(e->valor);
    if(e->derecha)
        impArbol(e->derecha);
}