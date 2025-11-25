#include <windows.h>
#include "menu.h"

int main() { 
    SetConsoleOutputCP(CP_UTF8); //Retira anomalias dos caracteres
    menuInicial();
    menuPrincipal();
    return 0;
}