#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#include "jogo_multiplayer.h"
#include "ranking.h"
#include "utils.h"

void jogoMultiplayer() { 
    int opcaoJogador1, opcaoJogador2;
    char escolhaJogador1[20], escolhaJogador2[20], resultado[20];
    int quantPartidas = 0, condicao = 1;
    char jogarNovamente;
    int quantEmpates = 0;
    int quantVitoriasJogador1 = 0;
    int quantVitoriasJogador2 = 0;
    int opcao;

    carregarRanking();
    delay();

    inicio:

    printf("\nEscolha o tipo de partida:\n");

    printf("\n1 - Melhor de 3\n");
    printf("2 - Melhor de 5\n");
    printf("\nOpção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        quantPartidas = 3;
    } else if (opcao == 2) {
        quantPartidas = 5;
    } else {
        printf("\nOpção inválida. Tente novamente.\n");
        Sleep(1000);
        system("cls");
        goto inicio;
    }
    system("cls");

    char nomeJogador1[20], nomeJogador2[20];

    getchar();
    printf("\nNome do jogador 1: ");
    fgets(nomeJogador1, sizeof(nomeJogador1), stdin);
    nomeJogador1[strcspn(nomeJogador1, "\n")] = 0;

    printf("\nNome do jogador 2: ");
    fgets(nomeJogador2, sizeof(nomeJogador2), stdin);
    nomeJogador2[strcspn(nomeJogador2, "\n")] = 0;

    int idxJogador1 = procurarJogador(nomeJogador1);
    if(idxJogador1==-1) idxJogador1 = adicionarJogador(nomeJogador1);

    int idxJogador2 = procurarJogador(nomeJogador2);
    if(idxJogador2==-1) idxJogador2 = adicionarJogador(nomeJogador2);

    do{
        system("cls");
        printf("\nIniciando a partida...\n");
        Sleep(1000);
        system("cls");

        for(int i = 0; i < quantPartidas; i++){

            iniciarRodada(i+1);

            do{
                printf("\nJogador 1 (%s)\n", nomeJogador1);
                printf("\nEscolha sua jogada: \n");
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");

                char c = _getch();

                if (c >= '1' && c <= '4') {
                    opcaoJogador1 = c - '0';
                    printf("*\n"); // Exibe um placeholder (asterisco) para indicar que a escolha foi registrada.
                }

                escolhaFeitaJogador(opcaoJogador1, escolhaJogador1);

            } while(opcaoJogador1 != 1 && opcaoJogador1 != 2 && opcaoJogador1 != 3 && opcaoJogador1 != 4);

            system("cls");
            Sleep(2000);

            do{
                printf("\nJogador 2 (%s)\n", nomeJogador2);
                printf("\nEscolha sua jogada: \n");
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");

                char c = _getch();

                if (c >= '1' && c <= '4') {
                    opcaoJogador2 = c - '0';
                    printf("*\n"); // Exibe um placeholder (asterisco) para indicar que a escolha foi registrada.
                }

                escolhaFeitaJogador(opcaoJogador2, escolhaJogador2);

            } while(opcaoJogador2 != 1 && opcaoJogador2 != 2 && opcaoJogador2 != 3 && opcaoJogador2 != 4);

            system("cls");
            printf("\nCarregando o resultado da rodada...\n");
            Sleep(1000);
            system("cls");

            printf("\nJogador 1 (%s): %s", jogadores[idxJogador1].nomeJogador, escolhaJogador1, jogadores[idxJogador1].nomeJogador, escolhaJogador1);
            printf("\nJogador 2 (%s): %s\n", jogadores[idxJogador2].nomeJogador, escolhaJogador2, jogadores[idxJogador2].nomeJogador, escolhaJogador2);

            if(strcmp(escolhaJogador1, escolhaJogador2)==0){
                strcpy(resultado, "EMPATE!");
                jogadores[idxJogador1].quantEmpatesJogador++;
                jogadores[idxJogador2].quantEmpatesJogador++;
                quantEmpates++;

            } else if((strcmp(escolhaJogador1,"PEDRA")==0 && strcmp(escolhaJogador2,"TESOURA")==0) ||
                      (strcmp(escolhaJogador1,"PAPEL")==0 && strcmp(escolhaJogador2,"PEDRA")==0) ||
                      (strcmp(escolhaJogador1,"TESOURA")==0 && strcmp(escolhaJogador2,"PAPEL")==0)){
                strcpy(resultado, "JOGADOR 1 VENCEU!");
                jogadores[idxJogador1].quantVitoriasJogador++;
                jogadores[idxJogador2].quantDerrotasJogador++;
                quantVitoriasJogador1++;

            } else {
                strcpy(resultado, "JOGADOR 2 VENCEU!");
                jogadores[idxJogador2].quantVitoriasJogador++;
                jogadores[idxJogador1].quantDerrotasJogador++;
                quantVitoriasJogador2++;
            }

            jogadores[idxJogador1].pontuacao = jogadores[idxJogador1].quantVitoriasJogador*10 + jogadores[idxJogador1].quantEmpatesJogador*5;
            jogadores[idxJogador2].pontuacao = jogadores[idxJogador2].quantVitoriasJogador*10 + jogadores[idxJogador2].quantEmpatesJogador*5;

            printf("\nResultado: %s\n", resultado);

            if(i==(quantPartidas-1)){
                setbuf(stdin, NULL);
                printf("\nPressione ENTER para CONTINUAR...");
                getchar();
                system("cls");
                printf("\nEmpates: %d", quantEmpates);
                printf("\nVitórias Jogador 1 (%s): %d", nomeJogador1, quantVitoriasJogador1);
                printf("\nVitórias Jogador 2 (%s): %d\n", nomeJogador2, quantVitoriasJogador2);
            }
            setbuf(stdin, NULL);
            printf("\nPressione ENTER para CONTINUAR...");
            getchar();
            system("cls");

            salvarRanking();

            if(i < (quantPartidas-1)){
                printf("\nIniciando a próxima rodada...");
                Sleep(1000);
                system("cls");
            }
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

    system("cls");
    printf("\nVoltando para a página do jogo...\n");
    Sleep(1000);
    system("cls");
}