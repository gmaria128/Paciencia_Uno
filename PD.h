#ifndef PD_H
#define PD_H
#include "info.h"

typedef struct Nodopilha {
    info_t carta;
    struct Nodopilha *prox;
} nodo_pilha;

typedef struct {
    nodo_pilha *topo;
}Pilha;

Pilha *criaPilha();
void push(Pilha *p, info_t x);
info_t pop(Pilha *p);
int vazia(Pilha *p);
info_t topo (Pilha *p);

#endif