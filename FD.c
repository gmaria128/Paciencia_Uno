#include <stdio.h>
#include <stdlib.h>
#include "FD.h"


void push (Fila *f, int x){
    nodo *novo = (nodo*)malloc(sizeof(nodo));
    novo -> info = x;
    novo -> prox = NULL;
    if(f -> fim != NULL)
        f-> fim -> prox = novo;
    else 
        f-> inicio = novo;
    f -> fim = novo;
}

int pop (Fila *f){
    int aux = f -> inicio -> info;
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
