#include <stdio.h>
#include <string.h>

void cabecalho(){
    printf("***************************\n");
    printf("*    Jogo de Forca        *\n");
    printf("***************************\n");
}

void novoChute(char chutes[26], int* tentativ){
    // int* tentativ -> aceita um ponteiro como parametro/ endereco de memoria

    char chute;
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    //Dica: coloca um espaco antes do %c para ignorar o caractere de enter

    // Guardando as letras ja chutadas
    chutes[(*tentativ)] = chute; 
    // *tentativ -> pega o conteudo de onde esse ponteiro aponta
    // Se fosse sem o * entao estaria se referindo ao endereco de memoria
    (*tentativ)++;
    // Acrescentando +1 no conteudo da variavel apontada
}

int jaChutou(char letra, char chutes[26], int tentativas){
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

void imprimePalavraSecreta(char palavraSecreta[20], char chutes[26], int tentativas){
    int tamanhoPalavra = strlen(palavraSecreta); // strlen - utiliza #include <string.h>

    // Formando a palavra na tela
    for (int i = 0; i < tamanhoPalavra; i++){

        int achou = jaChutou(palavraSecreta[i], chutes, tentativas);

        if (achou){
            printf("%c ", palavraSecreta[i]);
        }
        else{
            printf("_ ");
        }
    }

    printf("\n");
}

void escolhePalavra(char palavraSecreta[20]){
    sprintf(palavraSecreta, "MELANCIA"); //atribuindo a string ao array
}

void main(){
    char palavraSecreta[20];

    escolhePalavra(palavraSecreta); 

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    cabecalho();

    do{
        imprimePalavraSecreta(palavraSecreta, chutes, tentativas);

        novoChute(chutes, &tentativas);
        // &tentativas -> indica o endereco da variavel e passa como parametro

    } while (!acertou && !enforcou);
}