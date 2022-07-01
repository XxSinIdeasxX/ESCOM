// La libreria requiere de stdio.h y stdlib.h / malloc.h
typedef int Dato;

typedef struct nodo{
    Dato valor;
    struct nodo *sig; 
}Nodo;

typedef struct cola{
    int size;
    Nodo *frente; 
    Nodo *final;
}Cola;

void copyNod(Nodo *n1, Nodo *n2){//Copia el Nodo n1 en el Nodo n2
	n2->valor=n1->valor;
	n2->sig = n1->sig;
}

void initialize(Cola *c){
    c->size=0;
    c->frente=NULL;
    c->final=NULL;
}

Nodo *front(Cola *c){
    return c->frente;
}

Nodo *final(Cola *c){
    return c->final;
}

int Empty(Cola *c){
//  if(c->size==0) return 1;
    if(c->frente==NULL) return 1;
    else return 0;
}

int size(Cola *c){
    return c->size;
}

//    Frente        <Cola>        Final
//      A  ->  B  ->  C  ->  D  ->  E  ->  NULL

void Queue(Cola *c, Nodo *e){
    e->sig=NULL;
    c->size++;
    if(Empty(c)){
        printf("Hola");
        c->frente=e;
        
    }else{
        c->final->sig=e;
    }
    c->final=e;
}

// Regresa la estructura completa del nodo frente
Nodo *Dequeue(Cola *c){
    Nodo *aux;
	if(Empty(c)){
		aux = NULL;
	}else{
		aux = c->frente;
		c->frente = c->frente->sig;
		c->size--;
	}
	return aux;
}