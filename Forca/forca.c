#include <stdio.h>
#include <string.h>

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
    sprintf(palavraSecreta, "MELANCIA"); //atribuindo a string ao array
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
    for(int i; i < chutesDados; i++){
        int existe = 0;
        
        // Varrendo a palavra secreta
        for(int j = 0; j < strlen(palavraSecreta); j++){
            printf("Chute: %s Letra: %c\n", chutes[i],palavraSecreta[j]);
            if(chutes[i] == palavraSecreta[j]){
                existe = 1;
                break;
            }
        }

        if(!existe) {
            erros++;
        }
        printf("Existe: %d\n", existe);
    }
        printf("Erros: %d\n", erros);
    
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