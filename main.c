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
            printf("%d: [] \n", i+1);
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

    //1 passo: cria o baralho de 20 cartas, e combina os 5 numeros (0-4) com as 4 cores;
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

    //2 passo: embaralha aleatóriamente as cartas, usando números aleatórios com base no relógio do sistema;
    srand(time(NULL));
    for (int i=19; i>0; i--){
        int j = rand() % (i+1);
        info_t temp = baralho[i];
        baralho[i] = baralho [j];
        baralho[j]= temp;
    }
    //3 passo: manda a primeira carta do baralho pra "mao";
    info_t mao = baralho[0];
    //4 passo: recebe do usuario o numero desejado de pilhas e o tamaho da fila e armazena em variaveis inteiras;
    printf("Numero de pilhas:");    
    int numPilha;
    scanf("%d", &numPilha);

    printf("Tamanho da fila:");
    int tamFila;
    idx = 1;
    scanf("%d", &tamFila);
    int t = tamFila;
    //5 passo: cria a fila vazia e preenche com as cartas seguintes do baralho (apartir da posicao 1) e insere cartas até atingir o tamanho escplhido pelo usuario;
    Fila *f = cria_fila();
    while(tamFila!=0){
        pushf(f,baralho[idx]);
        idx++;
        tamFila--;
    }



    tamFila = t;
    //6 passo: Agora distribui as cartas restantes nas pilhas, mantendo a quantidade de cada pilha o mais uniforme possive;
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
    //7 passo: Aqui inicia o looping do jogo;
    while (1) {
        //passo 7.1: Verifica a vitória e verifica se todas as pilhas estao vazias ao percorrer o vetor v[], linha 43;
        if (terminar(v, numPilha)) {
            printf("Voce venceu, parabens! :)\n");
            printf("Voce fez %d jogadas.\n", contador_jogadas);
            break;
        }
    //passo 7.2: imprime a mesa,exibindo o toppo de cada pilha e a carta na mao;
    imprimi_mesa(a, v, numPilha, mao);
    //passo 7.3: lê qual é a jogada do usuario;
    scanf("%d", &jogada);
    //passo 7.4: Agora o programa executa a jogada do usuario;
        //Imprime a derrota e encerra se -1;
    if (jogada == -1) {
        printf("Voce perdeu :(\n");
        break;
    }
        //Chama troca_mao se 0;
    else if (jogada == 0) {
        mao = troca_mao(f, mao);
        contador_jogadas++;
    }
       //verifica se a jogada digitada é um número válido de pilha;
    else if (jogada >= 1 && jogada <= numPilha) {
        
        //se a pilha não estiver vazia
        if (v[jogada-1] > 0) {
            //pega a carta escolhida pra comparar;
            info_t topoCarta = topo(a[jogada-1]);
            // verifica se a acao é permitida pelas regras;
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



