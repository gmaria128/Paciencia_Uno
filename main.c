#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

void push (Pilha *p, info_t a){
    p -> topo ++;
    p-> v[p-> topo] = a;
}

info_t pop (Pilha *p){
    info_t a  = p -> v[p->topo];
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

info_t topo (Pilha *p){
    return p-> v [p-> topo];
}
