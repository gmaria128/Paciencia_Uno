#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

//alterado para receber um info 
void push (Pilha *p, info a){
    p -> topo ++;
    p-> v[p-> topo] = a;
}

//alterado para retornar um info
info pop (Pilha *p){
    info a  = p -> v[p->topo];
    p-> topo --;
    return a;
}

int vazia (Pilha *p){
    if (p->topo == -1) return 1;
    else
    return 0;
}

Pilha *criaPilha(){
    Pilha *p = (Pilha*)malloc (sizeof(Pilha));
    p->topo = -1;
    return p;
}
