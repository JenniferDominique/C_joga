#include <stdio.h>

#define NUM_TENTATIVAS 3

void main()
{
    int numSecreto=42, chute;

    //Cabecalho do jogo
    printf("\n********************************* \n");
    printf("*______Jogo de Adivinhacao______* \n");

    for (int i = 1; i <= NUM_TENTATIVAS; i++){
        printf("********************************* \n");
        printf("Tentativa %d de %d \n", i, NUM_TENTATIVAS);
        printf("Qual eh o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n\n", chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos!\n");
            i--; // Nao contabilizar no numero de tentativas
            continue; // Para a execucao do bloco for e vai para a proxima iteracao do for
        }

        int acertou = chute == numSecreto; // Retorna 0 ou 1

        if (acertou){
            printf("Voce acertou o numero secreto!!! :) \n");
            printf("Jogue de novo, voce eh um bom jogador. \n\n");
            break; // Quebra o loop do for
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
    }

    printf("Fim de jogo!!!\n\n");
}
