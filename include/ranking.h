#ifndef RANKING_H
#define RANKING_H
typedef struct {
    char nomeJogador[20];
    int quantVitoriasJogador;
    int quantDerrotasJogador;
    int quantEmpatesJogador;
    int pontuacao;
} tJogador;

extern tJogador* jogadores;
extern int totalJogadores;

void carregarRanking();
void salvarRanking();
int procurarJogador(char nome[]);
int adicionarJogador(char nome[]);
void mostrarRanking();

#endif
