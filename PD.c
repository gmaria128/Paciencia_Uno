#include <stdio.h>
#include <stdlib.h>
#include "PD.h"
#include "info.h"
//Insere um elemento no topo da pilha (insert an element at the top of the stack);
void push (Pilha *p, info_t a){
    nodo_pilha *novo  = (nodo_pilha*)malloc(sizeof(nodo_pilha));
    novo -> carta = a;
    novo -> prox = p -> topo;
    p-> topo  = novo;
}
//Remove o elemento do topo (Remove the top element.);
info_t pop (Pilha *p){
    info_t a = p -> topo -> carta;
    nodo_pilha *aux = p-> topo;
    p-> topo = p-> topo -> prox;
    free (aux);
    return a;
}
//Verifica se a pilha está vazia(Checks whether the stack is empty);
int vazia(Pilha *p){
    if (p-> topo == NULL) return 1;
    else 
    return 0;
}
//Cria uma pilha vazia(Creates an empty stack);
Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc (sizeof(Pilha));
    p->topo = NULL;
    return p;
}
// Retorna o elemento do topo sem removê-lo(Returns the top element without removing it);
info_t topo(Pilha *p){
return p -> topo -> carta;
}
