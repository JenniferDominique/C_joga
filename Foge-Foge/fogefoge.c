#include <stdio.h>
#include <stdlib.h>

//VARIAVEIS GLOBAIS
char mapa[5][10+1]; // Matriz = linha x coluna -> +1 por causa do \0 do final da string
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

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]); // Pegando por linha
    }
    
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);

}