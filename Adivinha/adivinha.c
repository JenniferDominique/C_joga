#include <stdio.h>

void main()
{
    int numSecreto=42, chute, ganhou, tentativas, pontos;

    printf("\n********************************* \n");
    printf("*______Jogo de Adivinhacao______* \n");

    ganhou = 0;
    tentativas = 0;
    pontos = 1000;

    while(1){ // while true - loop infinito
        printf("********************************* \n");
        printf("Tentativa %d \n", ++tentativas);
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n\n", chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos!\n");
            tentativas--; // Nao contabilizar no numero de tentativas
            continue; // Para a execucao do bloco e vai para a proxima iteracao
        }

        int acertou = (chute == numSecreto); // Retorna 0 ou 1

        if (acertou){
            printf("Voce acertou o numero secreto!!! :) \n");
            printf("Jogue de novo, voce eh um bom jogador. \n\n");
            break; // Força a quebra do loop
        }
        else{
            printf("Voce errou!!! :( \n");

            if (chute > numSecreto){
                printf("Seu chute foi MAIOR que o num secreto! \n");
            }
            else{
                printf("Seu chute foi MENOR que o numero secreto! \n");
            }

            printf("Mas nao desanime, tente de novo. \n\n");
        }

        int pontosPerdidos = (chute - numSecreto) / 2;
        pontos = pontos - pontosPerdidos;
    }

    printf("********************************* \n");
    printf("Fim de jogo!!!\n");
    printf("Voce acertou em %d tentativas.\n", tentativas);
    printf("Voce ganhou %d pontos.\n\n", pontos);
}
