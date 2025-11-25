#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "jogo_singleplayer.h"
#include "ranking.h"
#include "utils.h"

void jogoSingleplayer() { 
    int opcao;
    char escolhaJogador[20], escolhaCPU[20], resultado[20];
    int quantPartidas = 0, condicao = 1;
    char jogarNovamente;
    int opcaoPartida;
    int quantVitoriasComputador = 0;
    int quantVitoriasJogador = 0;
    int quantEmpates = 0;

    carregarRanking();
    delay();

    inicio:

    printf("\nEscolha o tipo de partida:\n");
    printf("\n1 - Melhor de 3\n");
    printf("2 - Melhor de 5\n");
    printf("\nOpção: ");
    scanf("%d", &opcaoPartida);

    if (opcaoPartida == 1) {
        quantPartidas = 3;
    } else if (opcaoPartida == 2) {
        quantPartidas = 5;
    } else {
        printf("\nOpção inválida. Tente novamente.\n");
        Sleep(1000);
        system("cls");
        goto inicio;
    }
    system("cls");

    char nomeJogador[20];
    printf("\nNome do jogador: ");
    getchar();

    fgets(nomeJogador, sizeof(nomeJogador), stdin);
    nomeJogador[strcspn(nomeJogador, "\n")] = 0;

    int idxJogador = procurarJogador(nomeJogador);
    if(idxJogador==-1) idxJogador = adicionarJogador(nomeJogador);

    do{
        system("cls");
        printf("\nIniciando a partida...\n");
        Sleep(1000);
        system("cls");

        for(int i = 0; i < quantPartidas; i++){

            iniciarRodada(i+1);

            do{
                printf("\n%s, escolha sua jogada: \n", nomeJogador);
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");
                scanf("%d", &opcao);

                system("cls");

                escolhaFeitaJogador(opcao, escolhaJogador);

            }while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

            srand(time(NULL));

            int escolhaIntCPU = (rand() % 3) + 1;

            escolhaFeitaJogador(escolhaIntCPU, escolhaCPU);

            telaCarregamento();

            printf("\nJogador: %s", escolhaJogador);
            printf("\nComputador: %s\n", escolhaCPU);

            if(strcmp(escolhaJogador, escolhaCPU)==0){
                strcpy(resultado,"EMPATE!");
                jogadores[idxJogador].quantEmpatesJogador++;
                quantEmpates++;

            } else if((strcmp(escolhaJogador,"PEDRA")==0 && strcmp(escolhaCPU,"TESOURA")==0) ||
                      (strcmp(escolhaJogador,"PAPEL")==0 && strcmp(escolhaCPU,"PEDRA")==0) ||
                      (strcmp(escolhaJogador,"TESOURA")==0 && strcmp(escolhaCPU,"PAPEL")==0)){
                strcpy(resultado,"JOGADOR VENCEU!");
                jogadores[idxJogador].quantVitoriasJogador++;
                quantVitoriasJogador++;

            } else {
                strcpy(resultado,"COMPUTADOR VENCEU!");
                jogadores[idxJogador].quantDerrotasJogador++;
                quantVitoriasComputador++;
            }

            jogadores[idxJogador].pontuacao = jogadores[idxJogador].quantVitoriasJogador*10 + jogadores[idxJogador].quantEmpatesJogador*5;

            printf("\nResultado: %s\n", resultado);

            if(i==(quantPartidas-1)){
                setbuf(stdin, NULL);
                printf("\nPressione ENTER para CONTINUAR...");
                getchar();
                system("cls");
                printf("\nEmpates: %d", quantEmpates);
                printf("\nVitórias Jogador (%s): %d", nomeJogador,quantVitoriasJogador);
                printf("\nVitórias Computador: %d\n", quantVitoriasComputador);
            }
            setbuf(stdin, NULL);
            printf("\nPressione ENTER para CONTINUAR...");
            getchar();
            system("cls");
            if(i < (quantPartidas-1)){
                printf("\nIniciando a próxima rodada...");
                Sleep(1000);
                system("cls");
            }
            system("cls");
        }

        salvarRanking();

        do{
            printf("\nDeseja jogar novamente? (S/N): ");
            fflush(stdin);
            scanf(" %c", &jogarNovamente);

            if(jogarNovamente == 'S' || jogarNovamente == 's'){
                condicao = 1;
            }else if(jogarNovamente == 'N' || jogarNovamente == 'n'){
                condicao = 0;
                break;
            } else{
                printf("\nOpção inválida, digite novamente.\n");
                Sleep(1000);
                system("cls");
            }
        }while(jogarNovamente != 'S' && jogarNovamente != 's' && jogarNovamente != 'N' && jogarNovamente != 'n');

    }while(condicao == 1);

    telaCarregamento();
}