#ifndef PD_H
#define PD_H
#include "info.h"
//declara a estrutura da pilha dinâmica(declares the dynamic stack structure);
typedef struct Nodopilha {
    info_t carta;
    struct Nodopilha *prox;
} nodo_pilha;

typedef struct {
    nodo_pilha *topo;
}Pilha;
//declara as funcoes(declares the functions);
Pilha *criaPilha();
void push(Pilha *p, info_t x);
info_t pop(Pilha *p);
int vazia(Pilha *p);
info_t topo (Pilha *p);

#endif
