#include <stdio.h>
#include <stdlib.h>
#include "PD.h"
#include "info.h"

void push (Pilha *p, info_t a){
    nodo_pilha *novo  = (nodo_pilha*)malloc(sizeof(nodo_pilha));
    novo -> carta = a;
    novo -> prox = p -> topo;
    p-> topo  = novo;
}

info_t pop (Pilha *p){
    info_t a = p -> topo -> carta;
    nodo_pilha *aux = p-> topo;
    p-> topo = p-> topo -> prox;
    free (aux);
    return a;
}

int vazia(Pilha *p){
    if (p-> topo == NULL) return 1;
    else 
    return 0;
}

Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc (sizeof(Pilha));
    p->topo = NULL;
    return p;
}

info_t topo(Pilha *p){
return p -> topo -> carta;
}
