/* La libreria requiere de stdio.h y stdlib.h
Esta es una versión de la libreria Funciones_pilas.h
modificada para la Práctica 3 */

//Tipo de dato de los valores de los nodos
typedef char Dato;

typedef struct nodo{
    Dato valor;
    struct nodo *izquierda;
    struct nodo *derecha;
    struct nodo *sig;
}Nodo;

typedef struct pila{
    int size;
    Nodo *tope; 
}Pila;

void initialize(Pila *p){
    p->size=0;
    p->tope=NULL;
}

Dato top(Pila *p){
    return p->tope->valor;
}

int isEmpty(Pila *p){
    if(p->size==0) return 1;
//  if(p->tope==NULL) return 1;
    else return 0;
}

int size(Pila *p){
    return p->size;
}

void push(Pila *p, Dato x){
    Nodo *e;
    e=(Nodo *)malloc(sizeof(Nodo));
    e->valor=x;
    e->sig=p->tope;
    p->size++;
    p->tope=e;
}

void pushNod(Pila *p, Nodo *e){
    e->sig=p->tope;
    p->size++;
    p->tope=e;
}

// Regresa el valor del nodo tope, no la estructura completa
Dato pop(Pila *p){
    if(isEmpty(p)) return '\0';//Caso especial para Datos char
//  if(isEmpty(p)) return NULL;    
    Dato t; //Mismo tipo de dato que en el nodo
    t=top(p);
    p->size--;
    p->tope=p->tope->sig;
    return t;
}

// Regresa la estructura completa del nodo tope
Nodo *popNod(Pila *p){
    Nodo *aux;
    aux=(Nodo *)malloc(sizeof(Nodo));
	if(isEmpty(p)){
		aux = NULL;
	}else{
		aux = p->tope;
		p->tope = p->tope->sig;
		p->size--;
	}
	return aux;
}