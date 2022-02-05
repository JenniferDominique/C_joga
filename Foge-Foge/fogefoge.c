#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"

//VARIAVEIS GLOBAIS
char** mapa; // ** -> ponteiro de ponteiro
int linhas;
int colunas;

void liberarMapa(){
    //Liberando a memoria que foi alocada
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }

    free(mapa);
}

void alocaMapa(){
    // Caso eu nao saiba o tamanho do mapa
    // Alocacao de memoria
    mapa = malloc(sizeof(char*) * linhas); // Linhas -> sao ponteiros de char
    for(int i = 0; i < linhas; i++ ){
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); // alocando espaco para as colunas
        // +1 por causa do \0 no final da string
    }
}

void lerMapa(){
    // Abrindo o arquivo de mapa
    FILE* f;
    f = fopen("mapa.txt", "r");
    // Se der erro no acesso ao arquivo
    if(f == 0){
        printf("Erro na leitura do mapa!\n");
        exit(1); // Fecha o programa
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    alocaMapa();

    // Lendo e Imprimindo mapa
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]); // Pegando por linha
    }

    fclose(f);
}

void main(){
    
    lerMapa();
    
    //Imprimindo mapa
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    liberarMapa();
}