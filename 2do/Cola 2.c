#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	/*Atributos*/
	char *nombre;
	struct nodo *sig;
}Nodo;

typedef struct cola{
	int size;
	Nodo *frente;
	Nodo *final;
}Cola;

void initialize(Cola *);
int isEmpty(Cola *);
void Queue(Cola *,Nodo *);
Nodo* Dequeue(Cola *);
void printQueue(Cola *);

void copyNodo(Nodo *, Nodo *);
int menu();
void copyString(char *, char *);
int sizeString(char *);
void clean_stdin();

int main(){
	int opcion, n, i;
	Cola cola;
	Nodo nodo, *aux;
	nodo.nombre = malloc(255);/*Tamaño de la cadena de entrada inicial*/
	initialize(&cola);
	printf("\nEste programa simula una cola\n");
	do{
		opcion = menu();
		switch(opcion){
			case 1:
				printf("Introducir un Nombre:\n");
				clean_stdin();
				//fflush(stdin);
				scanf("%[^\n]",nodo.nombre);
				nodo.sig = NULL;
				Queue(&cola,&nodo);
				break;
			case 2: //Dequeue
				aux = Dequeue(&cola);
				break;
			case 3: //Element
				if(isEmpty(&cola)){
					printf("\n   <Error, la cola esta vacia>\n");
					break;
				}
				printf("\nIntroduzca el numero del elemento que desea: ");
				scanf("%d",&n);
				while(n<1 || n>cola.size){
					printf("\n<Error, no existe el elemento %d en la cola>\n\nIntroduzca un numero valido (1-%d): ", n,cola.size);
					scanf("%d",&n);
				}
				copyNodo(cola.frente, &nodo);
				i=n;
				while(i!=1){
					copyNodo(nodo.sig, &nodo);
					//e=e->sig;
					i--;
				}		
				printf("\n\"%s\" es el elemento numero %d\n", nodo.nombre, n);
				break;
			case 4: //printQueue
				printQueue(&cola);
				break;
			case 5:
				printf("\nHasta luego :D\n");
				exit(0);
				break;
			default:
				printf("<Error>\n");
				/*En teoria nunca se podria acceder a esta opcion*/
				break;
		}
	}while(1);
	return 0;
}

void Queue(Cola *cola,Nodo *nodo){
	printf("\n\"%s\" ha sido encolado\n",nodo->nombre);
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	aux->nombre = malloc(sizeString(nodo->nombre)+1);
	copyNodo(nodo,aux);
	if(isEmpty(cola)){
		cola->frente = aux;
		cola->final = aux;
		cola->size++;
	}else{
		cola->final->sig = aux;
		cola->final = aux;
		cola->size++;
	}
}

Nodo* Dequeue(Cola *cola){
	Nodo *aux;
	if(isEmpty(cola)){
		printf("\n   <Error, la cola esta vacia>\n");
		aux = NULL;
	}else{
		aux = cola->frente;
		cola->frente = cola->frente->sig;
		cola->size--;
		printf("\n\"%s\" ha sido desencolado\n",aux->nombre);
	}
	return aux;
}

/*Comprueba si la cola esta vacia*/
int isEmpty(Cola *pila){
	int respuesta = 0;
	if(!pila->frente)
		respuesta = 1;
	return respuesta;
}

/*Inicializa la cola*/
void initialize(Cola *cola){
	cola->size = 0;
	cola->frente = NULL;
}

/*Imprimir la cola*/
void printQueue(Cola *cola){
	Nodo *aux;
	aux = cola->frente;
	if(isEmpty(cola)){
		printf("\n   <Error, la cola esta vacia>\n");
	}else{
		printf("---------------\n");
		while(aux){
			printf("-Nombre: %s\n",aux->nombre);
			printf("---------------\n");
			aux = aux->sig;
		}
	}
}

int menu(){
	int respuesta = 0;
	printf("\n\t\tMenu\n========================================\n");
	printf("1. Encolar (Queue)\n");
	printf("2. Desencolar (Dequeue)\n");
	printf("3. Mostrar elemento (Element)\n");
	printf("4. Imprimir la cola (printQueue)\n");
	printf("5. Salir\n\nSeleccione una opcion: ");
	scanf("%d",&respuesta);
	while(respuesta>5 || respuesta<1){
        clean_stdin();
		printf("\n\t> Error <\n\nSeleccione una opcion valida: ");
		scanf("%d",&respuesta);
	}return respuesta;
}

/*Esta funcion copia el Nodo n1 en el Nodo n2*/
void copyNodo(Nodo *n1, Nodo *n2){
	copyString(n1->nombre,n2->nombre);
	n2->sig = n1->sig;
	printf("\n%s\n%s\n",n1->nombre,n2->nombre);
}

/*Copia la cadena s1 en la cadena s2*/
void copyString(char *s1, char *s2){
	int i=0;
	int sizeS1 = sizeString(s1);
	for(i=0;i<sizeS1;i++){
		s2[i]=*(s1+i);
	}
	*(s2+i)='\0';
}

/*Esta funcion obtiene el numero de caracteres de una cadena hasta el caracter nulo*/
int sizeString(char *s){
	int i=0;
	while(s[i])
		i++;
	return i;
}

/*Esta funcion es la equivalente a fflush(stdin)*/
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
