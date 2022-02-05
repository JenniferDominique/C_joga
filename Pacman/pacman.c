#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

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

void imprimeMapa(){
    //Imprimindo mapa
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    for(int i=0; i < linhas; i++){
        for(int j=0; j < colunas; j++){
            if(mapa[i][j] == '@'){ // Acamos a posicao do pac-man
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a': // esquerda
            mapa[x][y-1] = '@';
            break;
        case 'w': // cima
            mapa[x-1][y] = '@';
            break;
        case 's': // baixo
            mapa[x+1][y] = '@';
            break;
        case 'd': // direita
            mapa[x][y+1] = '@';
            break;
    }

    // Tirar o pacman da posicao atual e mover ele
    mapa[x][y] = '.';
}

void main(){
    
    lerMapa();
    
    do{

        imprimeMapa();

        char comando;
        printf("Digite um comando: ");
        scanf(" %c", &comando);

        move(comando);

        system("cls");

    }while(!acabou());
    

    liberarMapa();
}