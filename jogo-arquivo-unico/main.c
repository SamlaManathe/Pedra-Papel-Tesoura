#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

//Sleep(tempo_segundos); Dá uma pausa antes da próxima execução
//system("cls"); Apaga o conteúdo do terminal

void menuPrincipal(); //Chama as funções iniciarJogo e mostrarRanking
void iniciarJogo(); //Chama as funções jogoMultiplayer e jogoSingleplayer
void jogoMultiplayer();
void jogoSingleplayer();
void mostrarRanking();
void escolhaFeitaJogador(int opcao, char escolhaJogador[]);
void carregarRanking();
void salvarRanking();
int procurarJogador(char nome[]);
int adicionarJogador(char nome[]);
void iniciarRodada(int rodada);
void telaCarregamento();
void menuInicial();
void mostrarTutorial();
void delay();

typedef struct{
    char nomeJogador[20];
    int quantVitoriasJogador;
    int quantDerrotasJogador;
    int quantEmpatesJogador;
    int pontuacao;
}tJogador;

tJogador* jogadores = NULL;
int totalJogadores = 0;

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

void menuInicial() { //
    printf("\n=== PEDRA PAPEL E TESOURA ===\n");
    Sleep(0700);
    printf("\n\n- Pressione ENTER para iniciar.\n");
    getchar();

    telaCarregamento();
}

void delay(){
	system("cls");
	printf("Carregando .");
	Sleep(0400);
	system("cls");
}

void telaCarregamento(){ //
	system("cls");
	    printf("\nCarregando");
			for (int i = 0; i <= 2; i++) {
				printf(" .");
		        Sleep(0400);
			}
		system("cls");
	    fflush(stdin);

}

void iniciarRodada(int rodada) { //
    printf("\nRODADA %d COMEÇANDO EM ", rodada);
    for (int i = 1; i <= 3; i++) {
        printf("%d", i);
        if (i < 3) {
            printf("...");
        } else {
            printf("! \n\nINICIANDO!\n");
        }
        fflush(stdout);
        Sleep(1000);
    }
    printf("\n");
    Sleep(500);
    system("cls");
}

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
            printf("\nVoltando para o menu principal ...\n");
            delay();
            system("cls");
            menuPrincipal();
            exit(0);
        default:
            system("cls");
            printf("\nOpção Inválida.\n");
            Sleep(1000);
            system("cls");
            break;
    }
}

void jogoMultiplayer() { //
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
                scanf("%d", &opcaoJogador1);

                escolhaFeitaJogador(opcaoJogador1, escolhaJogador1);

            } while(opcaoJogador1 != 1 && opcaoJogador1 != 2 && opcaoJogador1 != 3 && opcaoJogador1 != 4);

            system("cls");
            Sleep(2000);

            do{
                printf("\nJogador 2 (%s)\n", nomeJogador2);
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
                getchar();
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

void jogoSingleplayer() { //
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
                getchar();
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

void iniciarJogo() { //
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

void menuPrincipal() { //
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
                printf("\nDaniel Tavares\nGuilherme Simão\nRafael Lucas\nSamla Manathe\nVicente Queiroz\n");
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

int main() { //
    SetConsoleOutputCP(CP_UTF8); //Retira anomalias dos caracteres
    menuInicial();
    menuPrincipal();
    return 0;
}
