#include <stdio.h>
#include <stdlib.h>
#include "PD.h"

void push (Pilha *p, int x){
    nodo *novo  = (nodo*)malloc(sizeof(nodo));
    novo -> info = x;
    novo -> prox = p -> topo;
    p-> topo  = novo;
}

int pop (Pilha *p){
    int a = p -> topo -> info;
    nodo *aux = p-> topo;
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
    p->topo == NULL;
}
