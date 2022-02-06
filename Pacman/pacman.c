#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO pacman;

void fantasmas(){
    MAPA copia;
    // Copiando um mapa para saber se eu ja mexi no fantasma
    copiaMapa(&copia, &m);

    //Varrendo a matriz para achar os fantasmas
    for(int i=0; i < m.linhas; i++){
        for(int j=0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){
                // Se a proxima posicao for valida
                if(ehValida(&m, i, j+1) && ehCaminho(&m, i, j+1)){
                    andaNoMapa(&m, i, j, i, j+1);
                }
            }
        }
    }
    // Liberando a memoria que foi alocada
    liberarMapa(&copia);
}

int ehDirecao(char direcao){
    return direcao == ESQUERDA || direcao == BAIXO ||
        direcao == DIREITA || direcao == CIMA;
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
        case ESQUERDA: // esquerda
            proximoY--;
            break;
        case CIMA: // cima
            proximoX--;
            break;
        case BAIXO: // baixo
            proximoX++;
            break;
        case DIREITA: // direita
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
    
    andaNoMapa(&m, pacman.x, pacman.y, proximoX, proximoY);
    
    // Atualizando a posicao atual do pacman no mapa
    pacman.x = proximoX;
    pacman.y = proximoY;
}

int acabou(){
    return 0;
}

void main(){
    
    lerMapa(&m);

    encontraNoMapa(&m, &pacman, PACMAN);
    
    do{

        imprimeMapa(&m);

        char comando;
        printf("Digite um comando: ");
        scanf(" %c", &comando);

        move(comando);

        fantasmas();

        system("cls"); // Limpando o prompt de comando

    }while(!acabou());
    
    // liberando a memoria que foi alocada
    liberarMapa(&m);
}