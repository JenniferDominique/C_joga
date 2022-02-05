#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

//VARIAVEIS GLOBAIS
struct mapa m;

void liberarMapa(){
    //Liberando a memoria que foi alocada
    for(int i = 0; i < m.linhas; i++){
        free(m.matriz[i]);
    }

    free(m.matriz);
}

void alocaMapa(){
    // Caso eu nao saiba o tamanho do mapa
    // Alocacao de memoria
    m.matriz = malloc(sizeof(char*) * m.linhas); // Linhas -> sao ponteiros de char
    for(int i = 0; i < m.linhas; i++ ){
        m.matriz[i] = malloc(sizeof(char) * (m.colunas + 1)); // alocando espaco para as colunas
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

    fscanf(f, "%d %d", &(m.linhas), &(m.colunas));

    alocaMapa();

    // Lendo e Imprimindo mapa
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", m.matriz[i]); // Pegando por linha
    }

    fclose(f);
}

void imprimeMapa(){
    //Imprimindo mapa
    for(int i = 0; i < 5; i++){
        printf("%s\n", m.matriz[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    for(int i=0; i < m.linhas; i++){
        for(int j=0; j < m.colunas; j++){
            if(m.matriz[i][j] == '@'){ // Acamos a posicao do pac-man
                x = i;
                y = j;
                break;
            }
        }
    }

    switch(direcao){
        case 'a': // esquerda
            m.matriz[x][y-1] = '@';
            break;
        case 'w': // cima
            m.matriz[x-1][y] = '@';
            break;
        case 's': // baixo
            m.matriz[x+1][y] = '@';
            break;
        case 'd': // direita
            m.matriz[x][y+1] = '@';
            break;
    }

    // Tirar o pacman da posicao atual e mover ele
    m.matriz[x][y] = '.';
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