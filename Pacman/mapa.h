#ifndef _MAPA_H_
#define _MAPA_H_

// Constantes
#define PACMAN 'C'
#define FANTASMA '#'
#define CAMINHO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA '*'

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
int encontraNoMapa(MAPA* m, POSICAO* p, char personagem);
int ehValida(MAPA* m, int x, int y);
int ehCaminho(MAPA* m, int x, int y);
int podeAndar(MAPA* m, char personagem, int x, int y);
void andaNoMapa(MAPA* m, int origemX, int origemY, int destinoX, int destinoY);
void copiaMapa(MAPA* destino, MAPA* origem);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);

#endif