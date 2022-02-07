// Constantes
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

// Assinatura de funcoes
int acabou();
void move(char direcao);
int ehDirecao(char direcao);
void fantasmas();
int paraOndeFastasmaVai(int xAtual, int yAtual, 
    int* xDestino, int* yDestino);

void explodePilula();
