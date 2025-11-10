//OPÇÃO DE JOGAR, VER RANKING, CRÉDITOS E SAIR

//Fazer função menuPrincipal

#include <stdio.h>
#include "../include/jogo.h"
#include "../include/ranking.h"

#include <stdio.h>

void menuPrincipal(){
    int opcao;

    do{
        printf("\n======MENU======\n\n1 - Iniciar Jogo\n2 - Ver Ranking\n3 - Créditos\n0 - Sair\n");

        printf("\nOpção: ");
        scanf(" %d", &opcao);

        switch(opcao){
            case 1:
                iniciarJogo();
                break;
            case 2:
                mostrarRanking();
                break;
            case 3:
                printf("\nDaniel\nGuilherme\nRafael\nSamla\nVicente\n");
                break;
            case 0:
                printf("Saindo...");
                break;
            default:
                printf("\nOpção inválida, escolha novamente.\n");
                menuPrincipal();
                break;
        }

    } while(opcao != 0);
}
