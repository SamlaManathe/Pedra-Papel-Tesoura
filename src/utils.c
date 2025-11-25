#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utils.h"

void delay(){ 
	system("cls");
	printf("Carregando .");
	Sleep(0400);
	system("cls");
}

void telaCarregamento(){ 
	system("cls");
	    printf("\nCarregando");
			for (int i = 0; i <= 2; i++) {
				printf(" .");
		        Sleep(0400);
			}
		system("cls");
	    fflush(stdin);

}

void iniciarRodada(int rodada) { 
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
