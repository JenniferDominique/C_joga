#include <stdio.h>
#include <string.h>

void main(){
    char palavraSecreta[20];

    sprintf(palavraSecreta, "MELANCIA"); //atribuindo a string ao array

    int acertou = 0;
    int enforcou = 1;

    do{
        char chute;
        printf("Chute uma letra: ");
        scanf("%c", &chute);

        // Varrendo a string para ver se tem a letra do chute
        int tamanhoPalavra = strlen(palavraSecreta); // strlen - utiliza #include <string.h>
        
        for(int i = 0; i < tamanhoPalavra; i++){
            if(chute == palavraSecreta[i]){
                printf("A posicao %d tem essa letra!\n", i);
            }
        }

    } while(!acertou && !enforcou);
}