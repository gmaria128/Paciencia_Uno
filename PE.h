#ifndef PE_H
#define PE_H
#include "info.h"
#define MAX 100
// Cria a estrutura que define a pilha (Create a structure to define the stack);
typedef struct{
    info_t v[MAX];
    int topo;
}Pilha;
//Declara os prototipos das funcoes;
Pilha *criaPilha();
int vazia(Pilha *p);
info_t pop (Pilha *p);
void push(Pilha *p, info_t x);
info_t topo (Pilha *p);

#endif
