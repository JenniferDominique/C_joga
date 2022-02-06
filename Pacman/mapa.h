// Constantes
#define PACMAN 'C'
#define FANTASMA '#'
#define CAMINHO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

// Conjunto de variaveis
struct mapa{
    char** matriz; // ** -> ponteiro de ponteiro
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao{
    int x;
    int y;
};
typedef struct posicao POSICAO;

// Assinatura de funcoes
void liberarMapa(MAPA* m);
void lerMapa(MAPA* m);
void alocaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void encontraNoMapa(MAPA* m, POSICAO* p, char personagem);
int ehValida(MAPA* m, int x, int y);
int ehCaminho(MAPA* m, int x, int y);
void andaNoMapa(MAPA* m, int origemX, int origemY, int destinoX, int destinoY);
void copiaMapa(MAPA* destino, MAPA* origem);