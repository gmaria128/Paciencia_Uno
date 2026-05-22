#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

// Função que insere um elemento no topo da pilha;
void push (Pilha *p, info_t a){
    p -> topo ++;
    p-> v[p-> topo] = a;
}
// Função que remove e retorna o elemento do topo;
info_t pop (Pilha *p){
    info_t a  = p -> v[p->topo];
    p-> topo --;
    return a;
}
// Função que verifica se a pilha está vazia;
int vazia (Pilha *p){
    if (p->topo == -1) return 1;
    else
    return 0;
}
// Função que cria uma pilha dinamicamente;
Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc (sizeof(Pilha));
    p->topo = -1;
    return p;
}
// Função que retorna o elemento do topo sem removê-lo;
info_t topo (Pilha *p){
    return p-> v [p-> topo];
}
