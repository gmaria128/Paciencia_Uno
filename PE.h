#ifndef PE_H
#define PE_H
#include "info.h"
#define MAX 100

typedef struct{
    info_t v[MAX];
    int topo;
}Pilha;

Pilha *criaPilha();
int vazia(Pilha *p);
info_t pop (Pilha *p);
void push(Pilha *p, info_t x);
info_t topo (Pilha *p);

#endif