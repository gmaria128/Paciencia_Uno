#ifndef FE_H
#define FE_H
#define MAX 100
#include "info.h"

typedef struct{
    info_t v[MAX];
    int tam;
    int inicio, fim;
}Fila;

void pushf(Fila *f, info_t a);
info_t popf (Fila *f);
int vaziaf (Fila *f);
Fila *criaFila();

#endif