#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "mapa.h"

char desenhoFantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoParede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoPacman[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhoPilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhoCaminho[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};

void imprimeParte(char desenho[4][7], int parte){
    printf("%s", desenho[parte]);
}

void imprimeMapa(MAPA* m){
    for(int i = 0; i < m->linhas; i++){
        // Cada linha/caminho do mapa.txt vai virar 4 linhas de ui.h
        for(int parte = 0; parte < 4; parte++){

           for(int j = 0; j < m->colunas; j++){
               
                switch(m->matriz[i][j]){
                    case FANTASMA:
                        imprimeParte(desenhoFantasma, parte);
                        break;

                    case PACMAN:
                        imprimeParte(desenhoPacman, parte);
                        break;

                    case PILULA:
                        imprimeParte(desenhoPilula, parte);
                        break;

                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        imprimeParte(desenhoParede, parte);
                        break;

                    case CAMINHO:
                        imprimeParte(desenhoCaminho, parte);
                        break;
                }
           }

           printf("\n"); 
        }
    }
}