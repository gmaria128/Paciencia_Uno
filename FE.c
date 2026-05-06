#include <stdio.h>
#include <stdlib.h>
#include "FE.h"

void push (fila *f, info a){
    f -> v [f -> fim] = a;
    f -> fim = (f -> fim +1) % MAX;
    f -> tam ++;
}

info pop (fila *f){
    info a = f -> v[f -> inicio];
    f -> inicio = (f-> inicio +1)%MAX;
    f -> tam --;
    return a;
}

int vazia (fila *f){
    if (f -> tam == 0)
    return 1;
    else
    return 0;
}

fila *CriaFila(){
    fila *f = (fila*)malloc(sizeof(fila));
    f-> inicio =0;
    f -> fim = 0;
    f -> tam = 0;
}
