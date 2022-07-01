#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	/*Atributos*/
	int valor;
	char *nombre;
	struct nodo *sig;
}Nodo;

typedef struct pila{
	int size;
	Nodo *Tope;
}Pila;

void push(Pila *,Nodo *);
Nodo* pop(Pila *);
int isEmpty(Pila *);
void initialize(Pila *);
void printStack(Pila *);
void copyNodo(Nodo *, Nodo *);
int menu();
void copyString(char *, char *);
int sizeString(char *);
void clean_stdin();

int main(){
	int opcion;
	Pila pila;
	Nodo nodo, *aux;
	nodo.nombre = malloc(255);/*Tamaño de la cadena de entrada inicial*/
	initialize(&pila);
	printf("Este programa simula una pila\n\n");
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				printf("Introducir un Nombre:\n");
				clean_stdin();
				//fflush(stdin);
				scanf("%[^\n]",nodo.nombre);
				printf("Introduce un Valor:\n");
				clean_stdin();
				//fflush(stdin);
				scanf("%d",&nodo.valor);
				nodo.sig = NULL;
				push(&pila,&nodo);
				break;
			case 2:
				printf("extraer un elemento:\n");
				aux = pop(&pila);
				break;
			case 3:
				printf("Es vacia?\n");
				if(isEmpty(&pila))
					printf("La Pila esta vacia\n");
				else
					printf("La Pila NO esta vacia\n");
				break;
			case 4:
				printf("Imprimir Pila:\n");
				printStack(&pila);
				break;
			case 5:
				printf("Salir\n");
				exit(0);
				break;
			default:
				printf("Error\n");
				/*En teoria nunca se podria acceder a esta opcion*/
				break;
		}
	}while(1);
	return 0;
}

/*Apila un elemento en la pila*/
void push(Pila *pila,Nodo *nodo){
	printf("Entre push\n %s\n",nodo->nombre);
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	aux->nombre = malloc(sizeString(nodo->nombre)+1);
	copyNodo(nodo,aux);
	if(isEmpty(pila)){
		pila->Tope = aux;
		pila->size++;
	}else{
		aux->sig = pila->Tope;
		pila->Tope = aux;
		pila->size++;
	}
	printStack(pila);
}

/*Desapila un elemento de la pila*/
Nodo* pop(Pila *pila){
	Nodo *aux;
	if(isEmpty(pila)){
		printf("Error, no se pueden sacar elementos de la Pila\n");
		aux = NULL;
	}else{
		aux = pila->Tope;
		pila->Tope = pila->Tope->sig;
		pila->size--;
	}
	return aux;
}

/*Comprueba si la pila esta vacia*/
int isEmpty(Pila *pila){
	int respuesta = 0;
	if(!pila->Tope)
		respuesta = 1;
	return respuesta;
}

/*Inicializa la pila*/
void initialize(Pila *pila){
	pila->size = 0;
	pila->Tope = NULL;
}

/*Imprimir la pila*/
void printStack(Pila *pila){
	Nodo *aux;
	aux = pila->Tope;
	if(isEmpty(pila)){
		printf("---------------\n");
		printf("Pila Vacia\n");
		printf("---------------\n");
	}else{
		printf("--------------g-\n");
		while(aux){
			printf("--Nombre: %s\n",aux->nombre);
			printf("--Valor: %d\n",aux->valor);
			printf("---------------\n");
			aux = aux->sig;
		}
	}
}

/*Menu de opciones para usar las funciones de la pila*/
int menu(){
	int respuesta = 0;
	do{
		printf("Menu\nSelecciona una opcion:\n\n");
		printf("1. Insertar a la Pila (Push)\n");
		printf("2. Extraer un elemento de la Pila (pop)\n");
		printf("3. Esta vacia la Pila? (isEmpty)\n");
		printf("4. Imprimir la Pila? (printStack)\n");
		printf("5. salir\n");
		scanf("%d",&respuesta);
		while(respuesta>5 || respuesta<1){
			printf("Error, Introduce un nuevo valor:");
			scanf("%d",&respuesta);
		}
	}while(respuesta>5 || respuesta<1);
	return respuesta;
}

/*Esta funcion copia el Nodo n1 en el Nodo n2*/
void copyNodo(Nodo *n1, Nodo *n2){
	n2->valor = n1->valor;
	copyString(n1->nombre,n2->nombre);
	n2->sig = n1->sig;
}

/*Copia la cadena s1 en la cadena s2*/
void copyString(char *s1, char *s2){
	int i=0;
	int sizeS1 = sizeString(s1);
	for(i=0;i<sizeS1;i++){
		s2[i]=*(s1+i);
	}
	*(s2+i+1)='\0';
	printf("%s\n",s1);
	printf("%s\n",s2);
}

/*Esta funcion obtiene el numero de caracteres de una cadena hasta el caracter nulo*/
int sizeString(char *s){
	int i=0;
	while(s[i])
		i++;
	printf("El tamaño de la cadena es: %d\n",i);
}

/*Esta funcion es la equivalente a fflush(stdin)*/
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
