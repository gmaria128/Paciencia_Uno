#include <stdio.h>
#include <stdlib.h>
#include "FE.h"

// Insere um elemento no final da fila (Inserts an element at the end of the queue);
void pushf (Fila *f, info_t a){
    f -> v [f -> fim] = a;
    f -> fim = (f -> fim +1) % MAX;
    f -> tam ++;
}
// Remove e retorna o elemento do início da fila (Removes and returns the first element of the queue);
info_t popf (Fila *f){
    info_t a = f -> v[f -> inicio];
    f -> inicio = (f-> inicio +1)%MAX;
    f -> tam --;
    return a;
}
// Verifica se a fila está vazia (Checks whether the queue is empty);
int vaziaf (Fila *f){
    if (f -> tam == 0)
    return 1;
    else
    return 0;
}
// Cria uma fila vazia (Creates an empty queue);
Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f-> inicio =0;
    f -> fim = 0;
    f -> tam = 0;
    return f;
}
