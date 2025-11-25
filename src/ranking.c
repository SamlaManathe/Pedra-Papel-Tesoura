#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

tJogador* jogadores = NULL;
int totalJogadores = 0;

void carregarRanking(){ 
    FILE* file = fopen("ranking.txt", "r" /*ler*/);
    if(file == NULL) return;

    char nome[20];
    int vitorias, derrotas, empates, pontos;
    totalJogadores = 0;

    while(fscanf(file, "%s %d %d %d %d", nome, &vitorias, &derrotas, &empates, &pontos) != EOF){
        totalJogadores++;
    }
    rewind(file); //volta ao inicio do arquivo

    jogadores = (tJogador*) malloc(totalJogadores * sizeof(tJogador));

    int i = 0;

    while(fscanf(file, "%s %d %d %d %d", jogadores[i].nomeJogador, &jogadores[i].quantVitoriasJogador, &jogadores[i].quantDerrotasJogador, &jogadores[i].quantEmpatesJogador, &jogadores[i].pontuacao) != EOF){
        i++;
    }
    fclose(file);
}

int procurarJogador(char nome[]){ 
    for(int i = 0; i < totalJogadores; i++){
        if(strcmp(jogadores[i].nomeJogador, nome)==0) return i;
    }
    return -1;
}

int adicionarJogador(char nome[]){ 
    totalJogadores++;
    jogadores = (tJogador*)realloc(jogadores, totalJogadores * sizeof(tJogador));
    strcpy(jogadores[totalJogadores-1].nomeJogador, nome);
    jogadores[totalJogadores-1].quantVitoriasJogador = 0;
    jogadores[totalJogadores-1].quantDerrotasJogador = 0;
    jogadores[totalJogadores-1].quantEmpatesJogador = 0;
    jogadores[totalJogadores-1].pontuacao = 0;
    return totalJogadores-1;
}

void salvarRanking(){ 
    FILE* file = fopen("ranking.txt", "w" /*escrever*/);
    if(file == NULL){
        printf("\nErro ao criar o arquivo!\n");
        return;
    }
    for(int i = 0; i < totalJogadores; i++){
        fprintf(file, "%s %d %d %d %d\n",
        jogadores[i].nomeJogador,
        jogadores[i].quantVitoriasJogador,
        jogadores[i].quantDerrotasJogador,
        jogadores[i].quantEmpatesJogador,
        jogadores[i].pontuacao);
    }
    fclose(file);
}

void mostrarRanking(){ 
    carregarRanking();
    system("cls");

    printf("\n================RANKING================\n");
    printf("\nNOME\tVIT\tDER\tEMP\tPONTOS\n");
    for(int i = 0; i < totalJogadores; i++){
        printf("\n%s\t%d\t%d\t%d\t%d\n", jogadores[i].nomeJogador, jogadores[i].quantVitoriasJogador, jogadores[i].quantDerrotasJogador, jogadores[i].quantEmpatesJogador, jogadores[i].pontuacao);
    }
    printf("\n\nPressione ENTER para voltar ao menu...");

    getchar();
    getchar();
    system("cls");
}
