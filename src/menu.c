#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"
#include "tutorial.h"
#include "ranking.h"
#include "jogo_singleplayer.h"
#include "jogo_multiplayer.h"
#include "utils.h"

void menuInicial() { 
    printf("\n=== PEDRA PAPEL E TESOURA ===\n");
    Sleep(0700);
    printf("\n\n- Pressione ENTER para iniciar.\n");
    getchar();

    telaCarregamento();
}

void iniciarJogo() { 
    int opcao;
    do {
        printf("\n1 - SINGLEPLAYER\n2 - MULTIPLAYER\n3 - VOLTAR\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            //Chama a função jogoMultiplayer
            case 1:
                system("cls");
                jogoSingleplayer();
                break;

            //Chama a função jogoSingleplayer
            case 2:
                system("cls");
                jogoMultiplayer();
                break;

            //Volta para o MENU
            case 3:
                delay();
                break;

            //Repete as opções de iniciarJogo, até receber uma entrada válida
            default:
                system("cls");
                printf("\nOpção inválida.\n");
                break;
        }

    } while(opcao != 3);
}

void menuPrincipal() { 
    int opcao;
    do {
        printf("\n====== MENU ======\n\n");
        printf("1 - Iniciar Jogo\n2 - Ver Ranking\n3 - Créditos\n4 - Tutorial\n0 - Sair\n");

        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            //Chama a função iniciarJogo
            case 1:
            	delay();
                iniciarJogo();
                break;

            //Chama a função mostrarRanking
            case 2:
                delay();
                mostrarRanking();
                break;

            //Exibe créditos dos desenvolvedores
            case 3:
                delay();
                printf("\nDaniel Tavares\nGuilherme Simão\nRafael Lucas\nSamla Manathe\nVicente Queiroz\nYahonan Alcântara\n");
                getchar();
                printf("\nPressione ENTER para voltar ao MENU...");
                getchar();
                system("cls");
                break;

            case 4:
                delay();
                mostrarTutorial();
                break;

            //Finaliza a execução do programa
            case 0:
                system("cls");
                printf("\nSaindo...\n");
                Sleep(1000);
                system("cls");
                break;

            //Exibe o MENU novamente, caso a opção seja inválida
            default:
                system("cls");
                printf("\nOpção inválida, escolha novamente.\n");
                Sleep(1000);
                system("cls");
                break;
        }
    } while(opcao != 0);
}