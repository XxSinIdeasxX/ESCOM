#include<stdio.h>
#include<stdlib.h>

struct racional {
    int num, den;
}; 
typedef struct racional Racional;

Racional *crearRacional(int num, int den){
    if (den!=0){
        Racional *nvo;
        nvo = (Racional *)malloc(sizeof(Racional));
        nvo->num = num;
        nvo->den = den;
        return nvo;
    }
}

void impRacional(Racional *r){
    printf("%d/%d\n",r->num, r->den);
}

Racional *suma(Racional *r1, Racional *r2){
    return crearRacional((r1->num*r2->den)+(r1->den*r2->num), r1->den * r2->den);
}

Racional *resta(Racional *r1, Racional *r2){
    return crearRacional((r1->num*r2->den)-(r1->den*r2->num), r1->den * r2->den);
}

void main(){
    Racional *r1, *r2;
    r1=crearRacional(3,2);
    r2=crearRacional(1,4);
    impRacional(suma(r1,r2));
    impRacional(resta(r1,r2));
}