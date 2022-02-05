#include <stdio.h>
#include <stdlib.h>

void main(){
    char mapa[5][10+1]; // Matriz = linha x coluna
    // +1 por causa do \0 do final da string

    // Abrindo o arquivo de mapa
    FILE* f;
    f = fopen("mapa.txt", "r");

    // Se der erro no acesso ao arquivo
    if(f == 0){
        printf("Erro na leitura do mapa!\n");
        exit(1); // Fecha o programa
    }

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]); // Pegando por linha
    }
    
    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    fclose(f);

}