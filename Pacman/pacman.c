#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO pacman;
int temPilula = 0;

void explodePilula(){
    if(!temPilula) return; //Se eu nao tenho pilula eu nao faco nada

    // A pilula explode 3 casas
    explodePilula2(pacman.x, pacman.y, 0, 1, 3);  // Explode para a direita
    explodePilula2(pacman.x, pacman.y, 0, -1, 3); // esquerda
    explodePilula2(pacman.x, pacman.y, 1, 0, 3);  // para baixo
    explodePilula2(pacman.x, pacman.y, -1, 0, 3);  // para cima

    temPilula = 0; // Depois que eu usei a pilula
}

void explodePilula2(int x, int y, int somaX, int somaY, int qnt){
    // Condicoes para parar de invocar a funcao recursiva
    if(qnt == 0) return; //Se ela ja executou o max de vezes possivel
    
    int novoX = x + somaX;
    int novoY = y + somaY;

    if(!ehValida(&m, novoX, novoY)) return;//Se a prox. direita nao for valida
    if(ehParede(&m, novoX, novoY)) return;// Se a prox. posicao for parede
    // A parede bloqueia a exploxao das proximas casas

    m.matriz[novoX][novoY] = CAMINHO;// Limpa o caminho, mata os fantasmas

    explodePilula2(novoX, novoY, somaX, somaY, qnt-1); //Funcao recursiva -> ela chama ela mesma
}

int paraOndeFastasmaVai(int xAtual, int yAtual, int* xDestino, int* yDestino){
    
    int opcoesPossicoes[4][2]={
        {xAtual, yAtual+1},
        {xAtual+1, yAtual},
        {xAtual, yAtual-1},
        {xAtual-1, yAtual}
    };

    //Sorteando uma posicao para o fantasma andar
    srand(time(0));
    // Posso sortear ate 10 vezes uma posicao para 1 fantasma
    for(int i=0; i<10; i++){
        int linhaOpcao = rand() % 4;

        if(podeAndar(&m, FANTASMA, opcoesPossicoes[linhaOpcao][0], opcoesPossicoes[linhaOpcao][1])){

            *xDestino = opcoesPossicoes[linhaOpcao][0];
            *yDestino = opcoesPossicoes[linhaOpcao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas(){
    MAPA copia;
    // Copiando um mapa para saber se eu ja mexi no fantasma
    copiaMapa(&copia, &m);

    //Varrendo a matriz para achar os fantasmas
    for(int i=0; i < m.linhas; i++){
        for(int j=0; j < m.colunas; j++){

            if(copia.matriz[i][j] == FANTASMA){

                int xDestino;
                int yDestino;

                int novaPosicao = paraOndeFastasmaVai(i, j, &xDestino, &yDestino);

                if(novaPosicao){
                    andaNoMapa(&m, i, j, xDestino, yDestino);
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
    // E se nao for caminho, ele nao mexe
    if(!podeAndar(&m, PACMAN, proximoX, proximoY))
        return;

    // Se a proxima posicao for uma pilula
    // Entao o pac come ela e adiciona na lista de poderes
    if(ehPersonagem(&m, PILULA, proximoX, proximoY)){
        temPilula = 1;
    }

    // Se a prixima posicao nao for barrada pela
    // verificacoes descritas acima entao ele pode andar
    andaNoMapa(&m, pacman.x, pacman.y, proximoX, proximoY);
    
    // Atualizando a posicao atual do pacman no mapa
    pacman.x = proximoX;
    pacman.y = proximoY;
}

int acabou(){
    POSICAO pos;
    int pacmanNoMapa = encontraNoMapa(&m, &pos, PACMAN);
    return !pacmanNoMapa;
}

void main(){
    lerMapa(&m);

    encontraNoMapa(&m, &pacman, PACMAN);
    
    do{
        system("clear||cls"); // Limpando o prompt de comando

        imprimeMapa(&m);

        printf("(a)direita (d)esquerda (s)baixo (w)cima    (b)Bomba 4 direcoes\n");
        printf("Tem pilula(s): %s\n", (temPilula ? "SIM" : "NAO"));

        char comando;
        printf("Digite um comando: ");
        scanf(" %c", &comando);

        move(comando);

        if(comando == BOMBA){
            explodePilula();
        }

        fantasmas();

    }while(!acabou());
    
    // liberando a memoria que foi alocada
    liberarMapa(&m);
}