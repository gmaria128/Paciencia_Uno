#include <stdio.h>
#include <stdlib.h>
#include "FD.h"


void pushf (Fila *f, info_t x){
    nodo_fila *novo = (nodo_fila*)malloc(sizeof(nodo_fila));
    novo -> carta = x;
    novo -> prox = NULL;
    if(f -> fim != NULL)
        f-> fim -> prox = novo;
    else 
        f-> inicio = novo;
    f -> fim = novo;
}

info_t popf (Fila *f){
    info_t aux = f -> inicio->carta;
    nodo_fila *a= f -> inicio;
    f -> inicio = f -> inicio -> prox;
    free(a);
    if (f -> inicio == NULL)
        f -> fim = NULL;
    return aux;
}

Fila *cria_fila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f -> inicio = NULL;
    f-> fim = NULL;
    return f;
}

void libera_lista (nodo_fila *inicio){
    if (inicio == NULL) return;
    libera_lista (inicio -> prox);
    free (inicio);
}

void libera_fila(Fila *f){
    libera_lista(f -> inicio);
    free(f);
}

int vaziaf (Fila *f){
    if (f -> inicio == NULL) return 1;
    else
    return 0;
}
