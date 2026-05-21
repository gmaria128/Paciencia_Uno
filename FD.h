#ifndef FD_H
#define FD_H
#include "info.h"

typedef struct Nodofila {
    info_t carta;
    struct Nodofila *prox;
}nodo_fila;

typedef struct{
    nodo_fila *inicio;
    nodo_fila *fim;
}Fila;

Fila *cria_fila();
void pushf(Fila *f, info_t x);
info_t popf(Fila *f);
void libera_fila(Fila *f);
int vaziaf(Fila *f);

#endif
