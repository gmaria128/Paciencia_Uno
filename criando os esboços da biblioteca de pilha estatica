#include <stdio.h>
#include <stdlib.h>
#include "PE.h"

void push (Pilha *p, int x){
    p -> topo ++;
    p-> v[p-> topo] =x;
}

int pop (Pilha *p){
    int a  = p -> v[p->topo];
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
