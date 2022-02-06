#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO pacman;

void move(char direcao){
    // Usuario digitou valor invalido
    if(direcao != 'a' && direcao != 's' &&
        direcao != 'd' && direcao != 'w'){
            return; // Finaliza essa funcao move()
    }

    // Tirar o pacman da posicao atual e mover ele
    m.matriz[pacman.x][pacman.y] = '.';

    switch(direcao){
        case 'a': // esquerda
            m.matriz[pacman.x][pacman.y-1] = '@';
            pacman.y--;
            break;
        case 'w': // cima
            m.matriz[pacman.x-1][pacman.y] = '@';
            pacman.x--;
            break;
        case 's': // baixo
            m.matriz[pacman.x+1][pacman.y] = '@';
            pacman.x++;
            break;
        case 'd': // direita
            m.matriz[pacman.x][pacman.y+1] = '@';
            pacman.y++;
            break;
    }
}

int acabou(){
    return 0;
}

void main(){
    
    lerMapa(&m);

    encontraNoMapa(&m, &pacman, '@');
    
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