#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FD.h"
#include "PD.h"
#include "info.h"

void imprimi_mesa(Fila *f, Pilha *a, int *v, int b, info_t mao){
    for (int i =0; i<b; i ++){
        info_t temp = pop (&a[i]);
        printf("%d: [%d %s] +%d \n", i++, temp.num, temp.cor, v[i]);
        push(&a[i], temp);
    }
    printf("Na mao: [%d %s] \n Jogada:", mao.num, mao.cor);
    return;
}

void atacar (Fila *f, Pilha *a, int *v, info_t mao, int numPilha){
    int jogada;
    scanf("%d", &jogada);

    if (jogada <= numPilha){
        if (v [jogada -1] != 0){
            info_t x = pop(&a[jogada-1]);
            if(x.cor == mao.cor || x.num == mao.num){
            push(f,mao);
            mao = pop(f);
            push(f,mao);
            v[jogada-1]=v[jogada-1]-1;
            }else {
                printf("Jogada invalida. \n Jogada:");
                scanf("%d", &jogada);
            }
        }else {
            printf("Jogada invalida. \n Jogada:");
            scanf("%d", &jogada);
        }
    }else {
        printf("Jogada invalida. \n Jogada:");
        scanf("%d", &jogada);
        }
}

int main (){

    //criação do baralho
    info_t baralho[20];
    char cores[4][10]= {"amarelo", "verde", "azul", "vermelho"};

    int idx=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<=4; j++){
            baralho[idx].num = j;
            strcpy(baralho[idx].cor, cores[i]);
            idx++;
        }
    }

    //embaralhando as cartas
    srand(time(NULL));
    for (int i=19; i>0; i--){
        int j = rand() % (i+1);
        info_t temp = baralho[i];
        baralho[i] = baralho [j];
        baralho[j]= temp;
    }
    info_t mao = baralho[0];
    //lendo o numero de pilhas
    int numPilha;
    scanf("%d", &numPilha);

    //lendo e criando a fila
    int tamFila;
    int idx =1;
    scanf("%d", &tamFila);
    int t = tamFila;
    Fila *f;
    if (tamFila > 0){
    f = cria_fila();
    while(tamFila!=0){
        push(f, baralho[idx]);
        idx++;
        tamFila--;
    }
}
    else {
    printf("a sua fila nao pode estar vazia");
}


tamFila = t;
//criando as pilhas e colocando elas em um vetor
Pilha *a[numPilha];
for (int i =0; i<numPilha; i++){
    a[i]= criaPilha();
}
int b = (20-1-tamFila)/numPilha;
int v [numPilha];
for (int i =0; i< numPilha; i++){
    v[i] = b;
}
for (int i =0; i<numPilha; i++){
    for (int j =0; j<b; j++){
        push(a[i], baralho[idx]);
    }
}



}
