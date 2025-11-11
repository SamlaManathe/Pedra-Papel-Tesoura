#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void menuPrincipal();
void iniciarJogo();
void jogoMultiplayer();
void jogoOffline();
void mostrarRanking();
void iniciarRodada(int rodada);  // Nova função do cronômetro

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
        default:
            printf("\nOpção Inválida.\n");
            break;
    }
}

// Nova função: Cronômetro para iniciar a rodada
void iniciarRodada(int rodada) {
    printf("RODADA %d COMEÇANDO EM ", rodada);
    for (int i = 1; i <= 3; i++) {
        printf("%d", i);
        if (i < 3) {
            printf("...");
        } else {
            printf("! INICIANDO!\n");
        }
        fflush(stdout);
        Sleep(1000);
    }
    printf("\n");
    Sleep(500);
    system("cls");
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
        iniciarRodada(i+1);  // <-- AQUI: Integra o cronômetro

        do{
            printf("\nJogador 1\n");
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n");
            printf("\nOpcao (1,2,3): ");
            scanf("%d", &opcaoJogador1);
            escolhaFeitaJogador(opcaoJogador1, escolhaJogador1);
        } while(opcaoJogador1 != 1 && opcaoJogador1 != 2 && opcaoJogador1 != 3);
        system("cls");
        do{
            printf("\nJogador 2\n");
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n");
            printf("\nOpcao (1,2,3): ");
            scanf("%d", &opcaoJogador2);
            escolhaFeitaJogador(opcaoJogador2, escolhaJogador2);
        } while(opcaoJogador2 != 1 && opcaoJogador2 != 2 && opcaoJogador2 != 3);
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
            printf("\nVitorias Jogador: %d", quantVitoriasJogador1);
            printf("\nVitorias Computador: %d\n", quantVitoriasJogador2);
        }
        getchar();
        printf("\nPressione ENTER para CONTINUAR...");
        getchar();
        system("cls");
        if(i < (quantPartidas-1)){
            printf("\nIniciando a proxima rodada...");
            Sleep(1000);
            system("cls");
        }
    }
    printf("\nVoltando para a pagina do jogo...\n");
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
    printf("\nPARTIDA (MELHOR DE TRES)\n");
    for(int i = 0; i < quantPartidas; i++){
       iniciarRodada(i+1);  // <-- AQUI: Integra o cronômetro

        do{
            printf("\nEscolha sua jogada: \n");
            printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n");
            printf("\nOpção (1,2,3): ");
            scanf("%d", &opcao);
            system("cls");
            escolhaFeitaJogador(opcao, escolhaJogador);
        } while(opcao != 1 && opcao != 2 && opcao != 3);
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
            printf("\nVitorias Jogador: %d", quantVitoriasJogador);
            printf("\nVitorias Computador: %d\n", quantVitoriasCPU);
        }
        getchar();
        printf("\nPressione ENTER para CONTINUAR...");
        getchar();
        system("cls");
        if(i < (quantPartidas-1)){
            printf("\nIniciando a proxima rodada...");
            Sleep(1000);
            system("cls");
        }
    }
    printf("\nVoltando para a pagina do jogo...\n");
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
        printf("\nOpcao: ");
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
                printf("\nOpcao inválida.\n");
                break;
        }
    } while(opcao != 3);
}

void menuPrincipal() {
    int opcao;
    do {
        printf("\n====== MENU ======\n\n");
        printf("1 - Iniciar Jogo\n2 - Ver Ranking\n3 - Creditos\n0 - Sair\n");
        printf("\nOpcao: ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1:
                system("cls");
                printf("\nIniciando o jogo...\n");
                Sleep(1000);
                system("cls");
                iniciarJogo();
                break;
            case 2:
                system("cls");
                printf("\nCarregando o ranking...\n");
                Sleep(1000);
                system("cls");
                mostrarRanking();
                break;
            case 3:
                system("cls");
                printf("\nCarregando os créditos...\n");
                Sleep(1000);
                system("cls");
                printf("\nDaniel Tavares\nGuilherme Simão\nRafael Lucas\nSamla Manathe\nVicente Queiroz\n");
                getchar();
                printf("\nPressione ENTER para voltar ao MENU...");
                getchar();
                system("cls");
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

int main() {
    SetConsoleOutputCP(CP_UTF8); //tira palavras estranhas.
    menuPrincipal();
    return 0;
}
