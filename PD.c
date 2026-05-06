#include <stdio.h>
#include <stdlib.h>
#include "PD.h"
#include "info.h"

// alterado para inseriri um info ao invés de um inteiro
void push (Pilha *p, info a){
    nodo *novo  = (nodo*)malloc(sizeof(nodo));
    novo -> carta = a;
    novo -> prox = p -> topo;
    p-> topo  = novo;
}

//alterado para retornar um info ao invés de um inteiro
info pop (Pilha *p){
    info a = p -> topo -> carta;
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
