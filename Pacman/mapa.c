#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem){
    // Quantidade de linhas e colunas
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    alocaMapa(destino);

    // Copiando de um mapa para o outro
    for(int i=0; i < origem->linhas; i++){
        strcpy(destino->matriz[i], origem->matriz[i]);
        // strcpy - copia uma string de um para o outro
        //ele para de copiar quando ele encontra o \n do final da string
    }
}

void andaNoMapa(MAPA* m, int origemX, int origemY, int destinoX, int destinoY){
    //Qual eh o caractere que identifica o pacman
    char personagem = m->matriz[origemX][origemY];
    // Colocando o pacman na proxima direcao
    m->matriz[destinoX][destinoY] = personagem;
    // Substituindo onde o pacman estava por um '.'
    m->matriz[origemX][origemY] = CAMINHO;
}

int ehCaminho(MAPA* m, int x, int y){
    // O pacman so pode ir para a proxima casa
    // se ela for uma casa que seja representada por '.'
    //logo se for diferente ele nao move
    return m->matriz[x][y] == CAMINHO;
}

// Se o pacman ja estiver na ultima casada linha/colunas possivel 
int ehValida(MAPA* m, int x, int y){
    // Ele nao se mexe
    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;

    return 1;
}

int ehParede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_VERTICAL ||
        m->matriz[x][y] == PAREDE_HORIZONTAL;
}

int ehPersonagem(MAPA* m, char personagem, int x, int y){
    return m->matriz[x][y] == personagem;
}

int podeAndar(MAPA* m, char personagem, int x, int y){
    return ehValida(m, x, y) && 
    !ehParede(m, x, y) &&
    !ehPersonagem(m, personagem, x, y);
}

int encontraNoMapa(MAPA* m, POSICAO* p, char personagem){
     // Acha a posicao onde está o pacman no mapa
    for(int i=0; i < m->linhas; i++){
        for(int j=0; j < m->colunas; j++){
            if(m->matriz[i][j] == personagem){ // Acamos a posicao do pac-man
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }

    return 0;
}

void liberarMapa(MAPA* m){
    //Liberando a memoria que foi alocada
    for(int i = 0; i < m->linhas; i++){
        free((*m).matriz[i]);
    }
    // (*m) eh a mesma coisa q m->
    free(m->matriz);
}

// Define o tamanho de memoria que eu preciso para o mapa
void alocaMapa(MAPA* m){
    // Caso eu nao saiba o tamanho do mapa
    // Alocacao de memoria
    m->matriz = malloc(sizeof(char*) * m->linhas); // Linhas -> sao ponteiros de char
    for(int i = 0; i < m->linhas; i++ ){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1)); // alocando espaco para as colunas
        // +1 por causa do \0 no final da string
    }
}

void lerMapa(MAPA* m){
    // Abrindo o arquivo de mapa
    FILE* f;
    f = fopen("mapa.txt", "r");
    // Se der erro no acesso ao arquivo
    if(f == 0){
        printf("Erro na leitura do mapa!\n");
        exit(1); // Fecha o programa
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocaMapa(m);

    // Lendo e Imprimindo mapa
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]); // Pegando por linha
    }

    fclose(f);
}

