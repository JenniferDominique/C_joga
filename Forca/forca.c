#include <stdio.h>
#include <string.h>

// Variaveis globais
char palavraSecreta[20];
char chutes[26];
int tentativas = 0;

void cabecalho(){
    printf("***************************\n");
    printf("*    Jogo de Forca        *\n");
    printf("***************************\n");
}

void novoChute(){
    char chute;
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    //Dica: coloca um espaco antes do %c para ignorar o caractere de enter

    // Guardando as letras ja chutadas
    chutes[tentativas] = chute; 
    tentativas++;
}

int jaChutou(char letra){
    int achou = 0;

    // Varrendo o array com todas as letras chutadas
    for (int j = 0; j < tentativas; j++){
        if (chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void imprimePalavraSecreta(){
    int tamanhoPalavra = strlen(palavraSecreta); // strlen - utiliza #include <string.h>

    // Formando a palavra na tela
    for (int i = 0; i < tamanhoPalavra; i++){

        int achou = jaChutou(palavraSecreta[i]);

        if (achou){
            printf("%c ", palavraSecreta[i]);
        }
        else{
            printf("_ ");
        }
    }

    printf("\n");
}

void escolhePalavra(){
    sprintf(palavraSecreta, "MELANCIA"); //atribuindo a string ao array
}

void main(){
    escolhePalavra(); 

    int acertou = 0;
    int enforcou = 0;

    cabecalho();

    do{
        imprimePalavraSecreta();

        novoChute();
        // &tentativas -> indica o endereco da variavel e passa como parametro

    } while (!acertou && !enforcou);
}