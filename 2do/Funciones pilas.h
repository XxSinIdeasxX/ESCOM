//La libreria requiere de stdio.h y stdlib.h / malloc.h
typedef char Dato;

typedef struct nodo{
    Dato valor;
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

Nodo *top(Pila *p){
    return p->tope;
}

int isEmpty(Pila *p){
    if(p->size==0) return 1;
//  if(p->tope==NULL) return 1;
    else return 0;
}

int size(Pila *p){
    return p->size;
}

void push(Pila *p, Nodo *e){
    e->sig=p->tope;
    p->size++;
    p->tope=e;
}

// Regresa la estructura completa del nodo tope
Nodo *pop(Pila *p){
    if(isEmpty(p)) return NULL;
    Nodo *a, *t;
    t=top(p);
    a=p->tope->sig;
    p->size--;
    p->tope=a;
    free(a);
    return t;
}
