#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRINGS 100
#define MAX_NOME 50

void pauseExecution(void) {
  printf("\nPressione ENTER Para Continuar..");

  getchar();
  getchar();
}


void clearScreen(void) {
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}


// FALTA ESTILIZAR O MENU
void menu(void) {
  printf("[ 1 ] - ATUALIZAR NOTAS PROVA FINAL\n"); // FALTA DESIGN
  printf("[ 0 ] - SAIR E MOSTRAR O BOLETIM GERAL\n"); // EM PROCESSO
}


void gerarIdAleatorio() {
  exit(1);
}


void mostrarBoletimGeral(char nomes[][MAX_NOME], float *arrayNotas, float *medias, char situacoes[][20], int qtdAlunos, int qtdNotas, int *qtdAlunosProvaFinal, float *notasProvaFinal, float *mediasProvaFinal, int *verificarProvaFinal) {
  printf("\033[1;37mALUNOS        ");

  for (int j = 0; j < qtdNotas; j++) {
    printf("NOTA %d       ", j + 1);
  }
  printf("MÉDIA     NOTA PF     MÉDIA FINAL     SITUAÇÃO\n");

  for (int i = 0; i < qtdAlunos; i++) {
    printf("\033[1;34m%-15s\033[0m", nomes[i]);

    for (int j = 0; j < qtdNotas; j++) {
      printf("%.1f          ", arrayNotas[i * qtdNotas + j]);
    }
    printf("%.1f        ", medias[i]);

    if (strcmp(situacoes[i], "PROVA FINAL") == 0 && verificarProvaFinal[i] == 0) {
      printf("ATT         ");
    } else if (strcmp(situacoes[i], "PROVA FINAL") == 0 && verificarProvaFinal[i] == 1) {
      printf("%.1f          ", notasProvaFinal[i]);
    } else {
      printf("---         ");
    }

    if (verificarProvaFinal[i] == 0) {
      printf("%.1f", medias[i]);
    } else {
      printf("%.1f", mediasProvaFinal[i]);
    }

    if (verificarProvaFinal[i] == 0 && medias[i] >= 7) {
      printf("\033[1;92m          APROVADO\033[0m\n");
    } else if (verificarProvaFinal[i] == 0 && medias[i] < 4) {
      printf("\033[1;31m          REPROVADO\033[0m\n");
    } else if (verificarProvaFinal[i] == 1 && mediasProvaFinal[i] >= 6) {
      printf("\033[1;92m          APROVADO\033[0m\n");
    } else if (verificarProvaFinal[i] == 1 && mediasProvaFinal[i] < 6) {
      printf("\033[1;31m          REPROVADO\033[0m\n");
    } else {
      printf("\033[1;93m          PROVA FINAL\033[0m\n");
    }
  }
  pauseExecution();
}


void calcularSituacoes(float *medias, char situacoes[][20], int qtdAlunos, int *qtdAlunosProvaFinal, int *verificarProvaFinal) {
  *qtdAlunosProvaFinal = 0;

  for (int i = 0; i < qtdAlunos; i++) {
    if (medias[i] >= 7) {
      sprintf(situacoes[i], "PROVADOA");
    } else if (medias[i] >= 4) {
      sprintf(situacoes[i], "PROVA FINAL");
      (*qtdAlunosProvaFinal)++;
    } else {
      sprintf(situacoes[i], "REPROVADO");
    }
  }
}


void calcularMediaProvaFinal(int i, float *medias, float *mediasProvaFinal, float notaProvaFinal) {
  mediasProvaFinal[i] = (medias[i] + notaProvaFinal) / 2;
}


float calcularMedia(float somaNotas, int qtdNotas) {
  return somaNotas / (float)qtdNotas;
}


void alocarMemoriaArrays(int **verificarProvaFinal, float **medias, float **notasProvaFinal, float **mediasProvaFinal, int qtdAlunos) {
  *verificarProvaFinal = calloc(qtdAlunos, sizeof(int));

  if (*verificarProvaFinal == NULL) {
    fprintf(stderr, "ERRO NA ALOCAÇÃO DE MEMÓRIA");
    exit(1);
  }

  *medias = malloc(qtdAlunos * sizeof(float));

  if (*medias == NULL) {
    fprintf(stderr, "ERRO NA ALOCAÇÃO DE MEMÓRIA");
    exit(1);
  }

  *notasProvaFinal = malloc(qtdAlunos * sizeof(float));

  if (*notasProvaFinal == NULL) {
    fprintf(stderr, "ERRO NA ALOCAÇÃO DE MEMÓRIA");
    exit(1);
  }

  *mediasProvaFinal = malloc(qtdAlunos * sizeof(float));

  if (*mediasProvaFinal == NULL) {
    fprintf(stderr, "ERRO NA ALOCAÇÃO DE MEMÓRIA");
    exit(1);
  }
}


int main() {
  int qtdAlunos, qtdNotas, qtdAlunosProvaFinal = 0, choice;
  float notas, somaNotas;
  char nomes[MAX_STRINGS][MAX_NOME];
  float *medias = NULL, *notasProvaFinal = NULL, *mediasProvaFinal = NULL; 
  char situacoes[MAX_STRINGS][20];
  int *verificarProvaFinal = NULL;

  clearScreen();

  printf("\033[32m=== INFORMAÇÕES ===\033[0m\n");
  printf("\nDigite Quantos Alunos Deseja Adicionar: ");
  scanf("%d", &qtdAlunos);

  alocarMemoriaArrays(&verificarProvaFinal, &medias, &notasProvaFinal, &mediasProvaFinal, qtdAlunos);

  printf("\nDigite a Quantidade de Notas Por Aluno: ");
  scanf("%d", &qtdNotas);

  float arrayNotas[MAX_STRINGS * qtdNotas];

  clearScreen();

  for (int i = 0; i < qtdAlunos; i++) {
    somaNotas = 0;

    printf("\nNome %d° Aluno: ", i + 1);
    scanf("%s", nomes[i]);

    puts("\n");
    for (int j = 0; j < qtdNotas; j++) {
      printf("%d° Nota: ", j + 1);
      scanf("%f", &notas);

      arrayNotas[i * qtdNotas + j] = notas;
      somaNotas += notas;
    }
    clearScreen();

    float media = calcularMedia(somaNotas, qtdNotas);
    medias[i] = media;
  }

  while (true) {
    clearScreen();
    menu();

    printf("\nDigite a Funcionalidade: ");
    scanf("%d", &choice);
    clearScreen();

    switch (choice) {
        case 1: {
            float notaProvaFinal;
  
            printf("Digite as Notas da Prova Final Dos Alunos\n\n");
  
            for (int i = 0; i < qtdAlunos; i++) {
                if (medias[i] < 7 && medias[i] >= 4 && verificarProvaFinal[i] != 1) {
                    printf("Nota do(a) %s: ", nomes[i]);
                    scanf("%f", &notaProvaFinal);
                    notasProvaFinal[i] = notaProvaFinal;
                    calcularMediaProvaFinal(i, medias, mediasProvaFinal, notaProvaFinal);
                    verificarProvaFinal[i] = 1;
                }
            }
            pauseExecution();
            break;
        }

        case 0:
            calcularSituacoes(medias, situacoes, qtdAlunos, &qtdAlunosProvaFinal, verificarProvaFinal);
            mostrarBoletimGeral(nomes, arrayNotas, medias, situacoes, qtdAlunos, qtdNotas, &qtdAlunosProvaFinal, notasProvaFinal, mediasProvaFinal, verificarProvaFinal);
            break;
        }
    }
    free(verificarProvaFinal);
    free(medias);
    free(notasProvaFinal);
    free(mediasProvaFinal);

    return 0;
}
