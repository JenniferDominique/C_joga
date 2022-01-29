#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int numSecreto, chute, ganhou=0, tentativas=0;
    float pontos=1000;

    printf("\n********************************* \n");
    printf("*______Jogo de Adivinhacao______* \n");

    // Sorteando um numero
    srand(time(0)); // Utiliza o #include <time.h>
    numSecreto= rand() % 100; // Numero entre 0 e 99

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

        float pontosPerdidos = abs(chute - numSecreto) / (float)2; //casting - convertendo tipo
        // abs() - absoluto - eh o modulo do numero, converte ele para positivo
        // utiliza o #include <stdlib.h>
        pontos = pontos - pontosPerdidos;
    }

    printf("********************************* \n");
    printf("Fim de jogo!!!\n");
    printf("Voce acertou em %d tentativas.\n", tentativas);
    printf("Voce ganhou %.1f pontos.\n\n", pontos);
}
