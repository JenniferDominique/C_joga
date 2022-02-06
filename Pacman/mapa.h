// Conjunto de variaveis
struct mapa{
    char** matriz; // ** -> ponteiro de ponteiro
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

// Assinatura de funcoes
void liberarMapa(MAPA* m);
void lerMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);