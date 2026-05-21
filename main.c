#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FD.h"
#include "PD.h"
#include "info.h"

void imprimi_mesa(Pilha *a[], int *v, int numPilha, info_t mao){
    info_t temp;
    for (int i =0; i<numPilha; i ++){
        if (!vazia(a[i])){
        temp = topo (a[i]);
        printf("%d: [%d %s] +%d \n", i+1, temp.num, temp.cor, v[i]);
        } else {
            printf("%d: []", i+1);
        }
    }
    printf("Na mao: [%d %s] \n Jogada:", mao.num, mao.cor);
    return;
}

void atacar (Fila *f, Pilha *a[], int *v, info_t *mao, int jogada){
    info_t x = pop(a[jogada-1]);
    pushf(f, x);
    if (!vaziaf(f))
    *mao = popf(f);

    v[jogada-1]=v[jogada-1]-1;
    return;
}


//faz a troca de mão;
info_t troca_mao(Fila *f, info_t mao){
    pushf (f, mao);
    mao = popf (f);
    return mao;
}


//verifica se o jogo acabou
int terminar(int v[], int numPilhas) {
    for (int i = 0; i < numPilhas; i++) {
        if (v[i] != 0) {
            return 0;  
        }
    }
    return 1;
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
    printf("Numero de pilhas:");    
    int numPilha;
    scanf("%d", &numPilha);

    //lendo e criando a fila
    printf("Tamanho da fila:");
    int tamFila;
    idx = 1;
    scanf("%d", &tamFila);
    int t = tamFila;
    Fila *f = cria_fila();
    while(tamFila!=0){
        pushf(f,baralho[idx]);
        idx++;
        tamFila--;
    }



    tamFila = t;
    //criando as pilhas e colocando elas em um vetor
    Pilha *a[numPilha];
    for (int i =0; i<numPilha; i++){
        a[i]= criaPilha();
    }

    int b = (20-1-tamFila)/numPilha;  //numero de cartas por fila
    int resto = (20-1-tamFila) % numPilha;  

    int v[numPilha];
    int idx_carta = 1 + tamFila;  

    for (int i = 0; i < numPilha; i++) {
    int tamanho = b;
    if (i < resto) tamanho++;  
    v[i] = tamanho;
    
    for (int j = 0; j < tamanho; j++) {
        push(a[i], baralho[idx_carta]);
        idx_carta++;
        }
    }

    int contador_jogadas = 0;
    int jogada;

    while (1) {
        if (terminar(v, numPilha)) {
            printf("Voce venceu, parabens! :)\n");
            printf("Voce fez %d jogadas.\n", contador_jogadas);
            break;
        }
    
    imprimi_mesa(a, v, numPilha, mao);
    scanf("%d", &jogada);
    
    if (jogada == -1) {
        printf("Voce perdeu :(\n");
        break;
    }
    else if (jogada == 0) {
        mao = troca_mao(f, mao);
        contador_jogadas++;
    }
    else if (jogada >= 1 && jogada <= numPilha) {
        
        //se a pilha não estiver vazia
        if (v[jogada-1] > 0) {
            info_t topoCarta = topo(a[jogada-1]);
            //verifica se a jogada é valida
            if (strcmp(topoCarta.cor, mao.cor) == 0 || topoCarta.num == mao.num) {
                atacar(f, a, v, &mao, jogada);
                contador_jogadas++;
            } else {
                printf("Jogada invalida.\n");
            }
        } else {
            printf("Jogada invalida.\n");
        }
    }
    else {
        printf("Jogada invalida.\n");
    }
}

}



