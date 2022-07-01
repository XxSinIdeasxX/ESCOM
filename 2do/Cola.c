#include<stdio.h>
#include<stdlib.h>
#include"colas.h"

int menu();
void clean_stdin();
void LeeCad(char []);

int main(){
	int op, i, n;
	Cola c;
	Nodo e;
	initialize(&c);
	printf("\nEste programa simula una cola\n");
	while(1){
		op=menu();
		switch(op){
			case 1://Queue
				printf("\nIntroduzca un valor: ");
				scanf("%d",e.valor);
				Queue(&c, &e);
				printf("\n\"%d\" ha sido añadido exitosamente a la cola",e.valor);
				break;
			case 2://Dequeue
				if(Empty(&c)){
					printf("\n\t<Error, la cola esta vacia>\n");
					break;
				}
				printf("\n\"%d\" ha sido desencolado\n", Dequeue(&c)->valor);
				break;
			case 3://Element
				if(Empty(&c)){
					printf("\n\t<Error, la cola esta vacia>\n");
					break;
				}
				printf("\nIntroduzca el numero del elemento que desea: ");
				scanf("%d",&n);
				while(n<1 || n>c.size){
					printf("\n<Error, no existe el elemento %d en la cola>\n\nIntroduzca un numero valido: ", n);
					scanf("%d",&n);
				}
				copyNod(c.frente, &e);
				//e=c->frente;
				i=n;
				while(i!=1){
					copyNod(e.sig, &e);
					//e=e->sig;
					i--;
				}		
				printf("\n\"%d\" es el elemento numero %d\n", e.valor, n);
				break;
			case 4://printQueue
				if(Empty(&c)){
					printf("\n\t<Error, la cola esta vacia>\n");
					break;
				}
				copyNod(c.frente, &e);
				//e=c->frente;
				printf("\n\tCola\n====================\n");
				for(i=0; i<c.size; i++){
					printf("%d.- %d\n",i+1,e.valor);
					copyNod(e.sig, &e);
					//e=e->sig;
				}
				break;
			case 5://Salir
				printf("\nHasta luego :D");
        	    exit(0);
        	    break;
        	default:
        	    break;
		}
	}
	return 0;
}

int menu(){
	int respuesta = 0;
	printf("\n\t\t    Menu\n============================================\n");
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

void LeeCad(char cad[]){
    clean_stdin();
    int i;
	for(i=0;(cad[i]=getchar())!='\n';i++);
	cad[i]='\0';
}

/*Esta funcion es la equivalente a fflush(stdin)*/
void clean_stdin()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}