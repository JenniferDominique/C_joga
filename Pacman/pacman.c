#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO pacman;

int ehDirecao(char direcao){
    return direcao == 'a' || direcao == 's' ||
        direcao == 'd' || direcao == 'w';
}

void move(char direcao){
    // Usuario digitou valor invalido
    if(!ehDirecao(direcao)){
        return; // Finaliza essa funcao move()
    }

    // Proxima casa para onde o pac ira
    int proximoX = pacman.x;
    int proximoY = pacman.y;

    switch(direcao){
        case 'a': // esquerda
            proximoY--;
            break;
        case 'w': // cima
            proximoX--;
            break;
        case 's': // baixo
            proximoX++;
            break;
        case 'd': // direita
            proximoY++;
            break;
    }

    // Se a proxima posicao nao for valida
    // Ou seja, se for parede/obstaculo
    if(!ehValida(&m, proximoX, proximoY))
        return;

    // Se nao for caminho, ele nao mexe
    if(!ehCaminho(&m, proximoX, proximoY))
        return;


    // Se a prixima posicao nao for barrada pela
    // verificacoes descritas acima entao ele pode andar
    
    // Colocando o pacman na proxima casa
    m.matriz[proximoX][proximoY] = '@'; 
    // Substituindo o lugar onde o pacman estava antes
    m.matriz[pacman.x][pacman.y] = '.';

    // Atualizando a posicao atual do pacman no mapa
    pacman.x = proximoX;
    pacman.y = proximoY;
    
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