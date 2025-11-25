#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "tutorial.h"

void mostrarTutorial() { 
	char voltarAoMenu;
    char opcao;

    getchar();

    // Primeiro Bloco
    system("cls");
    printf("\n================== TUTORIAL ==================\n\n");
    printf("Bem-vindo ao clássico jogo de PEDRA, PAPEL e TESOURA!\n\n\n");
    printf("- Pressione ENTER para continuar ou 'M' para voltar ao menu.\n");

    opcao = getchar();

    if (opcao == 'm' || opcao == 'M') {
    	system("cls");
        return;
    }

    system("cls");

    // Segundo Bloco
    // Início do Bloco Anterior
    printf("\n================== TUTORIAL ==================\n\n");
    printf("Bem-vindo ao clássico jogo de PEDRA, PAPEL e TESOURA!\n\n");
    // Fim do Bloco Anterior

    printf("O objetivo é simples: vença o seu oponente escolhendo a jogada certa\n"
           "para derrotar a escolha dele. ");
    printf("Cada rodada tem três opções:\n\n");
    printf("1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n\n");
    printf("- Pressione ENTER para continuar ou 'M' para voltar ao menu.\n");

	opcao = getchar();

    if (opcao == 'm' || opcao == 'M') {
    	system("cls");
        return;
    }

    system("cls");

	//Terceiro Bloco
	// Início do Bloco Anterior
    printf("\n================== TUTORIAL ==================\n\n");
    printf("Bem-vindo ao clássico jogo de PEDRA, PAPEL e TESOURA!\n\n");
    printf("O objetivo é simples: vença o seu oponente escolhendo a jogada certa\n"
           "para derrotar a escolha dele. ");
    printf("Cada rodada tem três opções:\n\n");
    printf("1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n\n");
    printf("----------------------------------------------\n\n");
    // Fim do Bloco Anterior
	printf("Regras básicas:\n\n"
           "- PEDRA quebra TESOURA.\n"
           "- TESOURA corta PAPEL.\n"
           "- PAPEL embrulha PEDRA.\n\n");
    printf("- Pressione ENTER para continuar ou 'M' para voltar ao menu.\n");

    opcao = getchar();

    if (opcao == 'm' || opcao == 'M') {
    	system("cls");
        return;
    }

    system("cls");

    // Quarto Bloco
    // Início do Bloco Anterior
    printf("\n================== TUTORIAL ==================\n\n");
    printf("Bem-vindo ao clássico jogo de PEDRA, PAPEL e TESOURA!\n\n");
    printf("O objetivo é simples: vença o seu oponente escolhendo a jogada certa\n"
           "para derrotar a escolha dele. ");
    printf("Cada rodada tem três opções:\n\n");
    printf("1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n\n");
    printf("----------------------------------------------\n\n");
    printf("Regras básicas:\n\n"
           "- PEDRA quebra TESOURA.\n"
           "- TESOURA corta PAPEL.\n"
           "- PAPEL embrulha PEDRA.\n\n");
    printf("----------------------------------------------\n\n");
    // Fim do Bloco Anterior

    printf("MODOS DE JOGO:\n\n");
    printf("- SINGLEPLAYER: jogue contra o computador.\n\n");
    printf("- MULTIPLAYER: jogue contra outro jogador.\n\n");
    printf("\n- Pressione ENTER para continuar ou 'M' para voltar ao menu.\n");

    opcao = getchar();

    if (opcao == 'm' || opcao == 'M') {
    	system("cls");
        return;
    }

    system("cls");

	quintoBloco:
    // Quinto e Último Bloco
    fflush(stdin);
    // Início do Bloco Anterior
    printf("\n==================== TUTORIAL ====================\n\n");
    printf("Bem-vindo ao clássico jogo de PEDRA, PAPEL e TESOURA!\n\n");
    printf("O objetivo é simples: vença o seu oponente escolhendo a jogada certa\n"
           "para derrotar a escolha dele. ");
    printf("Cada rodada tem três opções:\n\n");
    printf("1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n\n");
    printf("----------------------------------------------\n\n");
    printf("Regras básicas:\n\n"
           "- PEDRA quebra TESOURA.\n"
           "- TESOURA corta PAPEL.\n"
           "- PAPEL embrulha PEDRA.\n\n");
    printf("----------------------------------------------\n\n\n");
    printf("MODOS DE JOGO:\n\n");
    printf("- OFFLINE: jogue contra o computador.\n");
    printf("- MULTIPLAYER: jogue contra outro jogador.\n\n");
    printf("----------------------------------------------\n\n");
    // Fim do Bloco Anterior

    printf("PARTIDAS:\n\n");
    printf("As partidas são no modo MELHOR DE CINCO ou MELHOR DE TRÊS.\n");
    printf("Quem vencer duas rodadas é o campeão!\n\n");
    printf("\n- Pressione 'ENTER' para voltar ao MENU.\n");

    getchar();

    do {
                printf("\n- Deseja realmente voltar ao MENU? (S/N): ");
                fflush(stdin);
                scanf(" %c", &voltarAoMenu);

                if(voltarAoMenu == 'S' || voltarAoMenu == 's'){
                	system("cls");
                    break;
                } else if(voltarAoMenu == 'N' || voltarAoMenu == 'n') {
                	system("cls");
                    goto quintoBloco;
                } else {
                	system("cls");
                    printf("\nOpção inválida, digite novamente.\n");
                    Sleep(1500);
                    system("cls");
                    goto quintoBloco;
                }
            } while(voltarAoMenu != 'S' && voltarAoMenu != 'N');
}