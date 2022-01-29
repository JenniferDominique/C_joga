#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int numSecreto, chute, ganhou=0, nivel, tentativa, maxTenta;
    float pontos=1000;

    // Sorteando um numero
    srand(time(0)); // Utiliza o #include <time.h>
    numSecreto= rand() % 100; // Numero entre 0 e 99

    printf("\n********************************* \n");
    printf("*      Jogo de Adivinhacao      * \n");
    printf("********************************* \n");

    // Nivel de jogo
    printf("Qual nivel de dificuldade?\n");
    printf("(1) Facil \n(2) Medio \n(3) Dificil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            maxTenta = 20;
            break;
        case 2:
            maxTenta = 15;
            break;
        default:
            maxTenta = 6;
            break;
    }
    
    // Que o jogo comece
    for(tentativa = 1; tentativa <= maxTenta; tentativa++){ 
        printf("\n*********************************");
        printf("\nTentativa %d \n", tentativa);
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n\n", chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos!\n");
            tentativa--; // Nao contabilizar no numero de tentativas
            continue; // Para a execucao do bloco e vai para a proxima iteracao
        }

        int acertou = (chute == numSecreto); // Retorna 0 ou 1

        if (acertou){
            printf("Voce acertou o numero secreto!!! :) \n");
            printf("Jogue de novo, voce eh um bom jogador. \n");
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

            printf("Mas nao desanime, tente de novo. \n");
        }

        float pontosPerdidos = abs(chute - numSecreto) / (float)2; //casting - convertendo tipo
        // abs() - absoluto - eh o modulo do numero, converte ele para positivo
        // utiliza o #include <stdlib.h>
        pontos = pontos - pontosPerdidos;
    }

    printf("********************************* \n");
    printf("Fim de jogo!!!\n");
    printf("Voce acertou em %d tentativas.\n", tentativa);
    printf("Voce ganhou %.1f pontos.\n\n", pontos);
}
