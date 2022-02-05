#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h" // Assinaturas das funcoes

// Variaveis globais
char palavraSecreta[20];
char chutes[26];
int chutesDados = 0;

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
    chutes[chutesDados] = chute; 
    chutesDados++;
}

int jaChutou(char letra){
    int achou = 0;

    // Varrendo o array com todas as letras chutadas
    for (int j = 0; j < chutesDados; j++){
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
    FILE* f; // Tipo de arquivo eh um ponteiro

    f = fopen("palavras.txt", "r"); // abrir um arquivo
    // Parametros: nome do arquivo e o tipo de acao -> r - read

    // Tratamento de erro - caso ocorra um problema com o arquivo a ser lido
    if(f == 0){
        printf("Arquivo de dados indisponível!! :(\n\n");
        exit(1); // Fecha o programa
    }

    int qntPalavras;
    fscanf(f, "%d", &qntPalavras);
    // A primeira linha do nosso arquivo tem um inteiro c/ a qnt de palavras

    // Escolhendo uma palavra aleatorio
    srand(time(0));
    int randomico = rand() % qntPalavras; 
    // Um número aleatório entre zero e a qnt de palavras q tenho no arquivo

    // Lendo o arquivo ate pegar a palavra sorteada
    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f); //fechando o aquivo
}

int acertou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }

    return 1;
}

int enforcou(){
    int erros = 0;

    // Varrendo o array de chutes que o usuario deu
    for(int i = 0; i < chutesDados; i++){
        int existe = 0;
        
        // Varrendo a palavra secreta
        for(int j = 0; j < strlen(palavraSecreta); j++){
            
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }

        if(!existe) {
            erros++;
        }
    }

    return erros >= 6;
}

void main(){
    escolhePalavra(); 
    cabecalho();

    do{
        imprimePalavraSecreta();
        novoChute();
        // &tentativas -> indica o endereco da variavel e passa como parametro

    } while (!acertou() && !enforcou());
}