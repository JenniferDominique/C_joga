#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS
char** mapa; // ** -> ponteiro de ponteiro
int linhas;
int colunas;

void main(){
    
    // Abrindo o arquivo de mapa
    FILE* f;
    f = fopen("mapa.txt", "r");
    // Se der erro no acesso ao arquivo
    if(f == 0){
        printf("Erro na leitura do mapa!\n");
        exit(1); // Fecha o programa
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("Linhas: %d, Colunas: %d\n", linhas, colunas);

    // Caso eu nao saiba o tamanho do mapa
    // Alocacao de memoria
    mapa = malloc(sizeof(char*) * linhas); // Linhas -> sao ponteiros de char
    for(int i = 0; i < linhas; i++ ){
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); // alocando espaco para as colunas
        // +1 por causa do \0 no final da string
    }

    // Imprimindo mapa
    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]); // Pegando por linha
    }
    
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);

    //Liberando a memoria que foi alocada
    for(int i = 0; i < linhas; i++){
        free(mapa[i]);
    }

    free(mapa);

}