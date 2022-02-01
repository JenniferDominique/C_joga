#include <stdio.h>
#include <string.h>

void main(){
    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA"); //atribuindo a string ao array

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    do{
        int tamanhoPalavra = strlen(palavraSecreta); // strlen - utiliza #include <string.h>

        // Formando a palavra na tela
        for(int i = 0; i < tamanhoPalavra; i++){

            int achou = 0;

            // Varrendo o array com todas as letras chutadas
            for(int j = 0; j < tentativas; j++){
                if(chutes[j] == palavraSecreta[i]){
                    achou = 1;
                    break;
                }
            }

            if(achou){
                printf("%c ", palavraSecreta[i]);
            } else{
                printf("_ ");
            }
        }

        printf("\n\n");
        
        char chute;
        printf("Chute uma letra: ");
        scanf(" %c", &chute); 
        //Dica: coloca um espaco antes do %c para ignorar o caractere de enter

        // Guardando as letras ja chutadas
        chutes[tentativas] = chute;
        tentativas++;

    } while(!acertou && !enforcou);
}