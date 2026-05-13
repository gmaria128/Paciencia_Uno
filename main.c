#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FD.h"
#include "PD.h"
#include "info.h"

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

    //lendo o numero de pilhas
    int numPilha;
    scanf("%d", &numPilha);

    //lendo e criando a fila
    int tamFila;
    int idx =0;
    scanf("%d", &tamFila);
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

//criando as pilhas e colocando elas em um vetor
Pilha *a[numPilha];
for (int i =0; i<numPilha; i++){
    a[i]= criaPilha();
}
int b = (20-1-idx)/numPilha;
for (int i =0; i<numPilha; i++){
    for (int j =0; j<b; j++){
        push(a[i], baralho[idx]);
    }
}


}
