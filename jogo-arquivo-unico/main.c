#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//Sleep(tempo_segundos); Dá uma pausa antes da próxima execução
//system("cls"); Apaga o conteúdo do terminal

void menuPrincipal(); //Chama as funções iniciarJogo e mostrarRanking
void iniciarJogo(); //Chama as funções jogoMultiplayer e jogoOffline
void jogoMultiplayer();
void jogoOffline();
void mostrarRanking();
void escolhaFeitaJogador(int opcao, char escolhaJogador[]);

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
            system("cls");
            printf("\nOpção Inválida.\n");
            Sleep(1000);
            system("cls");
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
    int condicao = 1;
    char jogarNovamente;

    printf("\nCarregando...\n");
    Sleep(1000);
    system("cls");

    printf("\nPEDRA PAPEL TESOURA\n");
    Sleep(2000);
    system("cls");

    printf("\nNome do jogador 1: ");
    getchar();
    fgets(nomeJogador1, sizeof(nomeJogador1), stdin);

    printf("\nNome do jogador 2: ");
    getchar();
    fgets(nomeJogador2, sizeof(nomeJogador2), stdin);

    do{
        system("cls");
        printf("\nIniciando a partida...\n");
        Sleep(1000);
        system("cls");

        for(int i = 0; i < quantPartidas; i++){
            system("cls");
            printf("\nRODADA %d (MELHOR DE TRÊS)\n", i+1);
            Sleep(2000);
            system("cls");

            do{
                printf("\nJogador 1\n");
                printf("\nEscolha sua jogada: \n");
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");
                scanf("%d", &opcaoJogador1);

                escolhaFeitaJogador(opcaoJogador1, escolhaJogador1);

            } while(opcaoJogador1 != 1 && opcaoJogador1 != 2 && opcaoJogador1 != 3 && opcaoJogador1 != 4);

            system("cls");
            Sleep(2000);

            do{
                printf("\nJogador 2\n");
                printf("\nEscolha sua jogada: \n");
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");
                scanf("%d", &opcaoJogador2);

                escolhaFeitaJogador(opcaoJogador2, escolhaJogador2);

            } while(opcaoJogador2 != 1 && opcaoJogador2 != 2 && opcaoJogador2 != 3 && opcaoJogador2 != 4);

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
                Sleep(3000);
                system("cls");
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
        do{
                printf("\nDeseja jogar novamente? (S/N): ");
                fflush(stdin);
                scanf(" %c", &jogarNovamente);

                if(jogarNovamente=='S'){
                    condicao = 1;
                }else if(jogarNovamente=='N'){
                    condicao = 0;
                    break;
                } else{
                    printf("\nOpção inválida, digite novamente.\n");
                    Sleep(1000);
                    system("cls");
                }
            }while(jogarNovamente != 'S' && jogarNovamente != 'N');

    }while(condicao == 1);

    system("cls");
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
    char jogarNovamente;
    int condicao = 1;

    printf("\nCarregando...\n");
    Sleep(1000);
    system("cls");

    printf("\nPEDRA PAPEL TESOURA\n");
    Sleep(2000);
    system("cls");

    printf("\nNome do jogador: ");
    getchar();
    fgets(nomeJogador, sizeof(nomeJogador), stdin);

    do{
        system("cls");
        printf("\nIniciando a partida...\n");
        Sleep(1000);
        system("cls");

        for(int i = 0; i < quantPartidas; i++){
            system("cls");
            printf("\nRODADA %d (MELHOR DE TRÊS)\n", i+1);
            Sleep(2000);
            system("cls");

            do{
                printf("\nEscolha sua jogada: \n");
                printf("\n1 - PEDRA\n2 - PAPEL\n3 - TESOURA\n4 - DESISTIR\n");

                printf("\nOpção (1,2,3,4): ");
                scanf("%d", &opcao);

                system("cls");

                escolhaFeitaJogador(opcao, escolhaJogador);

            }while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4);

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
                Sleep(3000);
                system("cls");
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
            system("cls");
        }
        do{
            printf("\nDeseja jogar novamente? (S/N): ");
            fflush(stdin);
            scanf(" %c", &jogarNovamente);

            if(jogarNovamente=='S'){
                condicao = 1;
            }else if(jogarNovamente=='N'){
                condicao = 0;
                break;
            } else{
                printf("\nOpção inválida, digite novamente.\n");
                Sleep(1000);
                system("cls");
            }
        }while(jogarNovamente != 'S' && jogarNovamente != 'N');

    }while(condicao == 1);

    system("cls");
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

            //Chama a função jogoMultiplayer
            case 1:
                system("cls");
                jogoMultiplayer();
                break;

            //Chama a função jogoOffline
            case 2:
                system("cls");
                jogoOffline();
                break;

            //Volta para o MENU
            case 3:
                system("cls");
                printf("\nVoltando ao menu principal...\n");
                Sleep(1000);
                system("cls");
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
        printf("1 - Iniciar Jogo\n2 - Ver Ranking\n3 - Créditos\n0 - Sair\n");

        printf("\nOpção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            //Chama a função iniciarJogo
            case 1:
                system("cls");
                printf("\nIniciando o jogo...\n");
                Sleep(1000);
                system("cls");
                iniciarJogo();
                break;

            //Chama a função mostrarRanking
            case 2:
                system("cls"); //
                printf("\nCarregando o ranking...\n");
                Sleep(1000);
                system("cls");
                mostrarRanking();
                break;

            //Exibe créditos dos desenvolvedores
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

int main() {
    SetConsoleOutputCP(CP_UTF8); //Retira anomalias dos caracteres
    menuPrincipal();
    return 0;
}
