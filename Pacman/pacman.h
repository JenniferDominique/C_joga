// Assinatura de funcoes
void liberarMapa();
void lerMapa();
void alocaMapa();
void imprimeMapa();
int acabou();
void move(char direcao);

// Conjunto de variaveis
struct mapa{
    char** matriz; // ** -> ponteiro de ponteiro
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;
