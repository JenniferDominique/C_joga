#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;

void move(char direcao){
    int x;
    int y;

    // Acha a posicao onde está o pacman no mapa
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

int acabou(){
    return 0;
}

void main(){
    
    lerMapa(&m);
    
    do{

        imprimeMapa(&m);

        char comando;
        printf("Digite um comando: ");
        scanf(" %c", &comando);

        move(comando);

        system("cls");

    }while(!acabou());
    

    liberarMapa(&m);
}