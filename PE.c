#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

//insere um elemento no topo da pilha;
void push (Pilha *p, info_t a){
    p -> topo ++;
    p-> v[p-> topo] = a;
}
//remove e retorna o elemento do topo;
info_t pop (Pilha *p){
    info_t a  = p -> v[p->topo];
    p-> topo --;
    return a;
}
//verifica se a pilha está vazia;
int vazia (Pilha *p){
    if (p->topo == -1) return 1;
    else
    return 0;
}
//cria uma pilha dinamicamente;
Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc (sizeof(Pilha));
    p->topo = -1;
    return p;
}
//retorna o elemento do topo sem removê-lo;
info_t topo (Pilha *p){
    return p-> v [p-> topo];
}
