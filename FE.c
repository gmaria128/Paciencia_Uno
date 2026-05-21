#include <stdio.h>
#include <stdlib.h>
#include "FE.h"

void pushf (Fila *f, info_t a){
    f -> v [f -> fim] = a;
    f -> fim = (f -> fim +1) % MAX;
    f -> tam ++;
}

info_t popf (Fila *f){
    info_t a = f -> v[f -> inicio];
    f -> inicio = (f-> inicio +1)%MAX;
    f -> tam --;
    return a;
}

int vaziaf (Fila *f){
    if (f -> tam == 0)
    return 1;
    else
    return 0;
}

Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f-> inicio =0;
    f -> fim = 0;
    f -> tam = 0;
    return f;
}
