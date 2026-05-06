#include <stdio.h>
#include <stdlib.h>
#include "FD.h"

//alterado para que receba um tipo info ao invés de um inteiro
void push (Fila *f, info x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo -> carta = x;
    novo -> prox = NULL;
    if(f -> fim != NULL)
        f-> fim -> prox = novo;
    else 
        f-> inicio = novo;
    f -> fim = novo;
}

//alterado para que retorne um tipo info ao invés de um inteiro
info pop (Fila *f){
    info aux = f -> inicio->carta;
    nodo *a= f -> inicio;
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

void libera_lista (nodo *inicio){
    if (inicio == NULL) return;
    libera_lista (inicio -> prox);
    free (inicio);
}

void libera_fila(Fila *f){
    libera_lista(f -> inicio);
    free(f);
}
