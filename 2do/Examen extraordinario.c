#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	char *nombre;
    char *colonia;
    char *municipio;
    int cp;
    char *celular;
    int edad;
    struct nodo *anterior;
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

void ordAlpha(Cola *);
int cadEsMenor(char *, char *);
int cadEsIgual(char*, char*);

void copyNodo(Nodo *, Nodo *);
int menu();
void copyString(char *, char *);
int sizeString(char *);
void clean_stdin();

int main(){
	int opcion, n, i;
    char *nombre;
	Cola cola;
	Nodo nodo, *aux;
	nodo.nombre = malloc(255);/*Tamaño de la cadena de entrada inicial*/
	nodo.colonia = malloc(255);
    nodo.municipio = malloc(255);
    nodo.celular = malloc(255);
    initialize(&cola);
	printf("\nEste programa simula una cola\n");
	do{
		opcion = menu();
		switch(opcion){
			case 1: //Agregar contacto
				printf("\nIntroducir un nombre: ");
				clean_stdin();
				scanf("%[^\n]",nodo.nombre);
                printf("Introducir una colonia: ");
				clean_stdin();
				scanf("%[^\n]",nodo.colonia);
                printf("Introducir un municipio: ");
				clean_stdin();
				scanf("%[^\n]",nodo.municipio);
                printf("Introducir un codigo postal: ");
				clean_stdin();
				scanf("%d",&nodo.cp);
                printf("Introducir un celular: ");
				clean_stdin();
				scanf("%[^\n]",nodo.celular);
                printf("Introducir una edad: ");
				clean_stdin();
				scanf("%d",&nodo.edad);
                nodo.anterior = NULL;
				nodo.sig = NULL;
				Queue(&cola,&nodo);
				break;
			case 2: //Ordenados por nombre
				ordAlpha(&cola);
                printQueue(&cola);
				break;
			case 4: //Buscar contacto por nombre
				if(isEmpty(&cola)){
					printf("\n   <Error, la cola esta vacia>\n");
					break;
				}
				printf("\nIntroduzca el nombre del contacto que desea: ");
                clean_stdin();
				scanf("%[^\n]",nombre);
				copyNodo(cola.frente, &nodo);
				while(!cadEsIgual(nombre, nodo.nombre)){
                    if(!nodo.sig)break;
					copyNodo(nodo.sig, &nodo);
				}if(!&nodo){
                    printf("\nNo se encontro al contacto %s en la agenda\n", nombre);
                    break;
                }
                printf("---------------\n");
                printf("-Nombre: %s\n",nodo.nombre);
                printf("-Colonia: %s\n",nodo.colonia);
                printf("-Municipio: %s\n",nodo.municipio);
                printf("-Codigo postal: %d\n",nodo.cp);
                printf("-Celular: %s\n",nodo.celular);
                printf("-Edad: %d\n",nodo.edad);
			    printf("---------------\n");
				break;
            case 5: //buscar por telefono
                if(isEmpty(&cola)){
					printf("\n   <Error, la cola esta vacia>\n");
					break;
				}
				printf("\nIntroduzca el numero del contacto que desea: ");
                clean_stdin();
				scanf("%[^\n]",nombre);//usa el apuntador nombre pero en verdad tiene un numero
				copyNodo(cola.frente, &nodo);
				while(!cadEsIgual(nombre, nodo.celular)){// unica diferencia con el caso 4
                    if(!nodo.sig)break;
					copyNodo(nodo.sig, &nodo);
				}if(!&nodo){
                    printf("\nNo se encontro al contacto %s en la agenda\n", nombre);
                    break;
                }
                printf("---------------\n");
                printf("-Nombre: %s\n",nodo.nombre);
                printf("-Colonia: %s\n",nodo.colonia);
                printf("-Municipio: %s\n",nodo.municipio);
                printf("-Codigo postal: %d\n",nodo.cp);
                printf("-Celular: %s\n",nodo.celular);
                printf("-Edad: %d\n",nodo.edad);
			    printf("---------------\n");
				break;

			case 7: //Eliminar la agenda
				printf("\nLa agenda ha sido borrada\n");
                initialize(&cola);
				break;
			case 8:
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

void ordAlpha(Cola *cola){
	if(isEmpty(cola)){
		printf("\n   <Error, la cola esta vacia>\n");
		return;
	}else{
        Nodo *asc, *des, *aux;
        asc = cola->frente;
		while(asc->sig){
            des = cola->final;
            while(&asc!=&des){
                if(cadEsMenor(des->anterior->nombre, des->nombre)){
                    aux = des->sig;
                    des->sig=des->anterior;
                    des->anterior=des->anterior->anterior;
                    des->sig->sig=aux;
                    aux->anterior=des->sig;
                    des->sig->anterior=des;
                    des->anterior->sig=des;
                }
                des=des->anterior;
            }
            asc=asc->sig;
        }
	}
}

int cadEsIgual(char *s1, char *s2){
    int i=0;
	int sizeS1 = sizeString(s1);
    while(s1[i]==s2[i] && i<=sizeS1)i++;
    if(i==sizeS1)return 1;
    return 0;
}
 
int cadEsMenor(char *s1, char *s2){// s1<s2 ?
    int i=0;
	int sizeS1 = sizeString(s1);
    while(s1[i]==s2[i] && i<=sizeS1)i++;
    if(s1[i]<s2[i])return 1;
    return 0;
}

void Queue(Cola *cola,Nodo *nodo){
	printf("\n\"%s\" ha sido agregado a la agenda\n",nodo->nombre);
	Nodo *aux;
	aux = (Nodo *)malloc(sizeof(Nodo));
	aux->nombre = malloc(sizeString(nodo->nombre)+1);
    aux->colonia = malloc(sizeString(nodo->colonia)+1);
    aux->municipio = malloc(sizeString(nodo->municipio)+1);
    aux->celular = malloc(sizeString(nodo->celular)+1);
	copyNodo(nodo,aux);
	if(isEmpty(cola)){
		cola->frente = aux;
		cola->final = aux;
		cola->size++;
	}else{
        aux->anterior = cola->final;
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
            printf("-Colonia: %s\n",aux->colonia);
            printf("-Municipio: %s\n",aux->municipio);
            printf("-Codigo postal: %d\n",aux->cp);
            printf("-Celular: %s\n",aux->celular);
            printf("-Edad: %d\n",aux->edad);
			printf("---------------\n");
			aux = aux->sig;
		}
	}
}

int menu(){
	int respuesta = 0;
	printf("\n\t\tMenu\n========================================\n");
	printf("1. Agregar contacto\n");
	printf("2. Mostrar contactos ordenados alfabeticamente por nombre\n");
	printf("3. Mostrar contactos ascendentemente por edad\n");
	printf("4. Buscar contactos por nombre\n");
    printf("5. Buscar contactos por telefono\n");
    printf("6. Eliminar contactos por nombre\n");
    printf("7. Eliminar agenda\n");
	printf("8. Salir\n\nSeleccione una opcion: ");
	scanf("%d",&respuesta);
	while(respuesta>8 || respuesta<1){
        clean_stdin();
		printf("\n\t> Error <\n\nSeleccione una opcion valida: ");
		scanf("%d",&respuesta);
	}return respuesta;
}

/*Esta funcion copia el Nodo n1 en el Nodo n2*/
void copyNodo(Nodo *n1, Nodo *n2){
	copyString(n1->nombre,n2->nombre);
    copyString(n1->colonia,n2->colonia);
    copyString(n1->municipio, n2->municipio);
    copyString(n1->celular, n2->celular);
    n2->cp=n1->cp;
    n2->edad=n1->edad;
	n2->sig = n1->sig;
//	printf("\n%s\n%s\n",n1->nombre,n2->nombre);
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
