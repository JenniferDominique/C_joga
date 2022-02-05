#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h" // Assinaturas das funcoes

// Variaveis globais
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26]; // 26 - porque eh a qnt de letras do alfabeto
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

void desenhaForca(){
    int erros = chutesErrados();

    printf("  _______      \n");
    printf(" |/      |     \n"); // if ternario
    printf(" |      %s     \n", (erros >= 1 ? "(_)" : " "));
    printf(" |      %c%c%c     \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 5 ? '/' : ' '), (erros >= 6 ? '\\' : ' ') );
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

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

void adicionarPalavra(){
    char quer;
    printf("Deseja adicionar uma nova palavra? (S/N) ");
    scanf(" %c", &quer);

    if(quer == 'S' || quer == 's'){
        FILE* f;
        f = fopen("palavras.txt", "r+");

        if(f == 0){
            printf("Arquivo de dados indisponivel!! :(\n\n");
            exit(1);
        }

        printf("Qual palavra voce deseja adicionar? ");
        scanf("%s", palavraSecreta);

        // Descobrindo a qnt de palavras q ja tenho e adicionando +1
        //ja que irei adicionar uma nova palavra
        int qnt;
        fscanf(f, "%d", &qnt);
        qnt++;

        fseek(f, 0, SEEK_SET); 
        // Reposicionando o ponteiro de leitura do aquito p/ primeira linha do arquivo
        fprintf(f, "%d", qnt); // Reescrevendo a qnt de palavras do arquivo

        fseek(f, 0, SEEK_END); //Reposicionando o ponteiro de leitura do arquivo para a ultima linha
        //para adicionar uma nova palavra
        fprintf(f, "\n%s",palavraSecreta); // \n para pular uma linha e escrever na seguinte
    
    } else{
        printf("Tudo bem, nos vemos na proxima rodada!! :)\n\n");
        exit(1);
    }
}

int acertou(){
    for(int i = 0; i < strlen(palavraSecreta); i++){
        if(!jaChutou(palavraSecreta[i])){
            return 0;
        }
    }

    return 1;
}

int chutesErrados(){
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
    return erros;
}

int enforcou(){
    return chutesErrados() >= 7;
}

void main(){
    escolhePalavra(); 
    cabecalho();

    do{
        desenhaForca();
        novoChute();
        // &tentativas -> indica o endereco da variavel e passa como parametro

    } while (!acertou() && !enforcou());

    if(acertou()){
        printf("\nParabens, você ganhou!!\n\n");

        printf("     ___________    \n");
        printf("    '._==_==_=_.'   \n");
        printf("    .-\\:      /-.   \n");
        printf("   | (|:.     |) |  \n");
        printf("    '-|:.     |-'   \n");
        printf("      \\::.    /     \n");
        printf("       '::. .'      \n");
        printf("         ) (        \n");
        printf("       _.' '._      \n");
        printf("      `\"\"\"\"\"\"\"`     \n");
    }else{
        printf("Voce foi enforcado!!\n");
        printf("A palavra secreta era: %s\n\n", palavraSecreta);

        printf("         ______         \n");
        printf("      .-'      '-.      \n");
        printf("     /            \\    \n");
        printf("    |              |    \n");
        printf("    |,  .-.  .-.  ,|    \n");
        printf("    | )(__/  \\__)( |   \n");
        printf("    |/     /\\     \\|  \n");
        printf("    (_     ^^     _)    \n");
        printf("     \\__|IIIIII|__/    \n");
        printf("      | \\IIIIII/ |     \n");
        printf("      \\          /     \n");
        printf("       `--------`       \n");
    }

    adicionarPalavra();
}