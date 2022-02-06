#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void liberarMapa(MAPA* m){
    //Liberando a memoria que foi alocada
    for(int i = 0; i < m->linhas; i++){
        free((*m).matriz[i]);
    }
    // (*m) eh a mesma coisa q m->
    free(m->matriz);
}

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

void imprimeMapa(MAPA* m){
    //Imprimindo mapa
    for(int i = 0; i < 5; i++){
        printf("%s\n", m->matriz[i]);
    }
}