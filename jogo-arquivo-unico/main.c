#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <Windows.h>

void escolhaFeitaJogador(int opcao, char escolhaJogador[]);
void jogoMultiplayer();
void jogoOffline();
void mostrarRanking();
void iniciarJogo();
void mostrarTutorial();
void menuPrincipal();
void menuInicial();
void telaCarregamento();

void telaCarregamento(){
	system("cls");
	for (int i = 0; i <= 1; i++) {
	    printf("\nCarregando ");
			for (int i = 0; i <= 3; i++) {
		        printf(". ");
		        Sleep(0400);
		    }
		    system("cls");
	}
	    system("cls");
	    printf("\nConcluído!\n");
	    Sleep(0500);
	    system("cls");
	    
	    fflush(stdin);
}

void escolhaFeitaJogador(int opcao, char escolhaJogador[]){

    switch(opcao){
        case 1:
            strcpy(escolhaJogador, "PEDRA");
            break;
        case 2:
            strcpy(escolhaJogador, "PAPEL");
            break;
        case 3:
            strcpy(escolhaJogador, "TESOURA");
            break;
        case 4:
            system("cls");
            printf("\nVoltando para o menu principal...\n");
            Sleep(1000);
            system("cls");
            menuPrincipal();
        default:
            printf("\nOpção Inválida.\n");
            break;
    }
}

void jogoMultiplayer() {
    char nomeJogador1[50], nomeJogador2[50];
    int opcaoJogador1;
    int opcaoJogador2;
    char escolhaJogador1[20];
    char escolhaJogador2[20];
    char resultado[20];
    int quantPartidas = 3;
    char jogador[10];
    int quantVitoriasJogador1 = 0;
    int quantVitoriasJogador2 = 0;
    int quantEmpates = 0;

    printf("\nCarregando...\n");
    Sleep(1000);
    system("cls");

    printf("\nNome do jogador 1: ");
    getchar();
    fgets(nomeJogador1, sizeof(nomeJogador1), stdin);

    printf("\nNome do jogador 2: ");
    getchar();
    fgets(nomeJogador2, sizeof(nomeJogador2), stdin);

    system("cls");
    printf("\nIniciando a partida...\n");
    Sleep(1000);
    system("cls");

    printf("\nPARTIDA (MELHOR DE TRÊS)\n");

    for(int i = 0; i < quantPartidas; i++){
        printf("\nRODADA %d\n", i+1);

        do{
            printf("\nJogador 1\n");
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

            printf("\nOpção (1,2,3,4): ");
            scanf("%d", &opcaoJogador1);

            escolhaFeitaJogador(opcaoJogador1, escolhaJogador1);

        } while(opcaoJogador1 != 1 && opcaoJogador1 != 2 && opcaoJogador1 != 3 && opcaoJogador1 != 4);

        system("cls");

        do{
            printf("\nJogador 2\n");
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

            printf("\nOpção (1,2,3,4): ");
            scanf("%d", &opcaoJogador2);

            escolhaFeitaJogador(opcaoJogador2, escolhaJogador2);

        } while(opcaoJogador2 != 1 && opcaoJogador2 != 2 && opcaoJogador2 != 3 && opcaoJogador2!= 4);

        system("cls");
        printf("\nCarregando o resultado da rodada...\n");
        Sleep(1000);
        system("cls");

        printf("\nJogador 1: %s", escolhaJogador1);
        printf("\nJogador 2: %s\n", escolhaJogador2);

        if (strcmp(escolhaJogador1, "PEDRA") == 0 && strcmp(escolhaJogador2, "PEDRA") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador1, "PEDRA") == 0 && strcmp(escolhaJogador2, "PAPEL") == 0) {
            strcpy(resultado, "JOGADOR 2 VENCEU!");
            quantVitoriasJogador2++;

        } else if (strcmp(escolhaJogador1, "PEDRA") == 0 && strcmp(escolhaJogador2, "TESOURA") == 0) {
            strcpy(resultado, "JOGADOR 1 VENCEU!");
            quantVitoriasJogador1++;

        } else if (strcmp(escolhaJogador1, "PAPEL") == 0 && strcmp(escolhaJogador2, "PAPEL") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador1, "PAPEL") == 0 && strcmp(escolhaJogador2, "TESOURA") == 0) {
            strcpy(resultado, "JOGADOR 2 VENCEU!");
            quantVitoriasJogador2++;

        } else if (strcmp(escolhaJogador1, "PAPEL") == 0 && strcmp(escolhaJogador2, "PEDRA") == 0) {
            strcpy(resultado, "JOGADOR 1 VENCEU!");
            quantVitoriasJogador1++;

        } else if (strcmp(escolhaJogador1, "TESOURA") == 0 && strcmp(escolhaJogador2, "TESOURA") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador1, "TESOURA") == 0 && strcmp(escolhaJogador2, "PEDRA") == 0) {
            strcpy(resultado, "JOGADOR 2 VENCEU!");
            quantVitoriasJogador2++;

        } else {
            strcpy(resultado, "JOGADOR 1 VENCEU");
            quantVitoriasJogador1++;
        }

        printf("\nResultado: %s\n", resultado);

        if(i==(quantPartidas-1)){
            printf("\nEmpates: %d", quantEmpates);
            printf("\nVitórias Jogador: %d", quantVitoriasJogador1);
            printf("\nVitórias Computador: %d\n", quantVitoriasJogador2);
        }

        getchar();
        printf("\nPressione ENTER para CONTINUAR...");
        getchar();
        system("cls");
        if(i < (quantPartidas-1)){
            printf("\nIniciando a próxima rodada...");
            Sleep(1000);
            system("cls");
        }
    }
    printf("\nVoltando para a página do jogo...\n");
    Sleep(1000);
    system("cls");
}

void jogoOffline() {
    char nomeJogador[50];
    int opcao;
    char escolhaJogador[20];
    char escolhaCPU[20];
    char resultado[20];
    int quantPartidas = 3;
    int quantVitoriasJogador = 0;
    int quantVitoriasCPU = 0;
    int quantEmpates = 0;

    printf("\nCarregando...\n");
    Sleep(1000);
    system("cls");

    printf("\nNome do jogador: ");
    getchar();
    fgets(nomeJogador, sizeof(nomeJogador), stdin);

    system("cls");
    printf("\nIniciando a partida...\n");
    Sleep(1000);
    system("cls");

    printf("\nPARTIDA (MELHOR DE TRÊS)\n");


    for(int i = 0; i < quantPartidas; i++){
        printf("\nRODADA %d\n", i+1);

        do{
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

            printf("\nOpção (1,2,3,4): ");
            scanf("%d", &opcao);

            system("cls");

            escolhaFeitaJogador(opcao, escolhaJogador);

        } while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

        srand(time(NULL));

        int escolhaIntCPU = (rand() % 3) + 1;

        escolhaFeitaJogador(escolhaIntCPU, escolhaCPU);

        system("cls");
        printf("\nCarregando o resultado da rodada...\n");
        Sleep(1000);
        system("cls");

        printf("\nJogador: %s", escolhaJogador);
        printf("\nComputador: %s\n", escolhaCPU);

        if (strcmp(escolhaJogador, "PEDRA") == 0 && strcmp(escolhaCPU, "PEDRA") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador, "PEDRA") == 0 && strcmp(escolhaCPU, "PAPEL") == 0) {
            strcpy(resultado, "COMPUTADOR VENCEU!");
            quantVitoriasCPU++;

        } else if (strcmp(escolhaJogador, "PEDRA") == 0 && strcmp(escolhaCPU, "TESOURA") == 0) {
            strcpy(resultado, "JOGADOR VENCEU!");
            quantVitoriasJogador++;

        } else if (strcmp(escolhaJogador, "PAPEL") == 0 && strcmp(escolhaCPU, "PAPEL") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador, "PAPEL") == 0 && strcmp(escolhaCPU, "TESOURA") == 0) {
            strcpy(resultado, "COMPUTADOR VENCEU!");
            quantVitoriasCPU++;

        } else if (strcmp(escolhaJogador, "PAPEL") == 0 && strcmp(escolhaCPU, "PEDRA") == 0) {
            strcpy(resultado, "JOGADOR VENCEU!");
            quantVitoriasJogador++;

        } else if (strcmp(escolhaJogador, "TESOURA") == 0 && strcmp(escolhaCPU, "TESOURA") == 0) {
            strcpy(resultado, "EMPATE!");
            quantEmpates++;

        } else if (strcmp(escolhaJogador, "TESOURA") == 0 && strcmp(escolhaCPU, "PEDRA") == 0) {
            strcpy(resultado, "COMPUTADOR VENCEU!");
            quantVitoriasCPU++;

        } else {
            strcpy(resultado, "JOGADOR VENCEU!");
            quantVitoriasJogador++;
        }
        printf("\nResultado: %s\n", resultado);

        if(i==(quantPartidas-1)){
            printf("\nEmpates: %d", quantEmpates);
            printf("\nVitórias Jogador: %d", quantVitoriasJogador);
            printf("\nVitórias Computador: %d\n", quantVitoriasCPU);
        }

        getchar();
        printf("\nPressione ENTER para CONTINUAR...");
        getchar();
        system("cls");
        if(i < (quantPartidas-1)){
            printf("\nIniciando a próxima rodada...");
            Sleep(1000);
            system("cls");
        }
}
    printf("\nVoltando para a página do jogo...\n");
    Sleep(1000);
    system("cls");
}

void mostrarRanking() {
    printf("\nMostrando ranking");
}

void iniciarJogo() {
    int opcao;

    do {
        printf("\n1 - MULTIPLAYER\n2 - OFFLINE\n3 - VOLTAR\n");
        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                system("cls");
                jogoMultiplayer();
                break;
            case 2:
                system("cls");
                jogoOffline();
                break;
            case 3:
                system("cls");
                printf("\nVoltando ao menu principal...\n");
                Sleep(1000);
                system("cls");
                break;
            default:
                system("cls");
                printf("\nOpção inválida.\n");
                break;
        }

    } while(opcao != 3);
}

void mostrarTutorial() {
	char voltarAoMenu;
    char opcao;

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
    printf("----------------------------------------------\n\n\n");
    // Fim do Bloco Anterior

    printf("MODOS DE JOGO:\n\n");
    printf("• OFFLINE: jogue contra o computador.\n\n");
    printf("• MULTIPLAYER: jogue contra outro jogador.\n\n");
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


void menuPrincipal() {
    int opcao;

    do {
        printf("\n====== MENU ======\n\n");
        printf("1 - Iniciar Jogo\n2 - Ver Ranking\n3 - Créditos\n4 - Tutorial\n0 - Sair\n");

        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                telaCarregamento();
                iniciarJogo();
                break;
            case 2:
                telaCarregamento();
                mostrarRanking();
                break;
            case 3:
                telaCarregamento();
                printf("\nDaniel Tavares\nGuilherme Simão\nRafael Lucas\nSamla Manathe\nVicente Queiroz\n");
                getchar();
                printf("\nPressione ENTER para voltar ao MENU...");
                getchar();
                system("cls");
                break;
            case 4:
                telaCarregamento();
			    mostrarTutorial();
                break;
            case 0:
                system("cls");
                printf("\nSaindo...\n");
                Sleep(1000);
                system("cls");
                break;
            default:
                system("cls");
                printf("\nOpção inválida, escolha novamente.\n");
                break;
        }

    } while(opcao != 0);
}

void menuInicial() {
    printf("\n=== PEDRA PAPEL E TESOURA ===\n");
    Sleep(1100);
    printf("\n\n- Pressione ENTER para iniciar.\n");
    getchar();
    
    telaCarregamento();
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    menuInicial();
    menuPrincipal();
    return 0;
}
