#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void clearScreen(void) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}


void menu() {
    printf("\n[ 1 ] NOVA MATRIZ");
    printf("\n[ 0 ] SAIR\n");
}


void criarMatriz(int lin, int col, int **matriz) {
    int elemento;
    
    *matriz = malloc(lin * col * sizeof(int));

    if (matriz == NULL) {
        fprintf(stderr, "\033[1;31mErro: Falha ao Alocar a Memória.\033[0m\n");
        exit(1);
    }

    printf("\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            printf("Elemento [%d][%d] -> ", i, j);

            while (true) {
                scanf("%d", &elemento);

                if (elemento < 10 && elemento >= 0) {
                    break;
                } else {
                    printf("DIGITE UM NÚMERO VÁLIDO: ");
                }
            }
            (*matriz)[i * col + j] = elemento;
        }
    }
}


void mostrarMatriz(int *matriz, int col, int lin) {
    printf("\n=== MATRIZ ===\n");
    printf("   ");
    for (int z = 0; z < col; z++) {
        printf(" \033[1;92m%d\033[0m ", z);
    }
    printf("\n");

    for (int i = 0; i < lin; i++) {
        printf(" \033[1;92m%d\033[0m ", i);
        for (int j = 0; j < col; j++) {
            printf(" %d ", matriz[i * col + j]);
        }
        printf("\n");
    }
}


int main() {
    int lin, col, opcao;
    int *matriz = NULL;

    while (true) {
        printf("\nMATRIZ COM VALORES DE 0 A 9\n\n");
        printf("DIGITE A QUANTIDADE DE LINHAS E COLUNAS DA MATRIZ RESPECTIVAMENTE E SEPARADAS POR ESPAÇO: ");
        
        scanf("%d %d", &lin, &col);

        criarMatriz(lin, col, &matriz);
        clearScreen();
        mostrarMatriz(matriz, col, lin);
        
        while (true) {
            menu();
            printf("\nDigite sua Opção: ");
            scanf("%d", &opcao);

            if (opcao == 0) {
                free(matriz);
                return 0;
                
            } else if (opcao == 1) {
                clearScreen();
                free(matriz); 
                break; 
            } 
        }
    }
    return 0;
}
