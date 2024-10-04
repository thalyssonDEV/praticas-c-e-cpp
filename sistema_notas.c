#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
  printf("[ 1 ] - VISUALIZAR MÉDIAS E RESULTADOS\n"); // FEITO PARCIALMENTE, FALTA MOSTRAR APROV\REPROV PÓS PROVA FINAL
  printf("[ 2 ] - LISTAR ALUNOS E NOTAS\n"); // FEITO, FALTA ESTIlIZAR
  printf("[ 3 ] - ATUALIZAR NOTAS PROVA FINAL\n"); // FALTA FAZER TUDO, URGENTEMENTE
  printf("[ 0 ] - SAIR E MOSTRAR O BOLETIM GERAL\n"); // EM PROCESSO
}

void listarAlunosNotas(char nomes[][MAX_NOME], int qtdAlunos, int qtdNotas, float *arrayNotas) {
  int indexGeral = 0;

  for (int i = 0; i < qtdAlunos; i++) {
    printf("%s --> ", nomes[i]);

    for (int j = 0; j < qtdNotas; j++) {
      printf("%.1f ", arrayNotas[indexGeral]);
      indexGeral++;
    }
    puts("\n");
  }
}


void mostrarBoletimGeral(char nomes[][MAX_NOME], float *arrayNotas, float *medias, char situacoes[][20], int qtdAlunos, int qtdNotas) {
  printf("\033[1;37mALUNOS        ");

  for (int j = 0; j < qtdNotas; j++) {
    printf("NOTA %d       ", j + 1);
  }
  printf("MÉDIA        SITUAÇÃO\n");

  for (int i = 0; i < qtdAlunos; i++) {
    printf("\033[1;34m%-15s\033[0m", nomes[i]);

    for (int j = 0; j < qtdNotas; j++) {
      printf("\033[1;37m%.1f          \033[0m", arrayNotas[i * qtdNotas + j]);
    }
    printf("%.1f        ", medias[i]);

    printf("%s\n", situacoes[i]);
  }

  pauseExecution();
}


void calcularSituacoes(float *medias, char situacoes[][20], int qtdAlunos) {
  for (int i = 0; i < qtdAlunos; i++) {
    if (medias[i] >= 7) {
      sprintf(situacoes[i], "APROVADO");
    } else if (medias[i] >= 4) {
      sprintf(situacoes[i], "PROVA FINAL");
    } else {
      sprintf(situacoes[i], "REPROVADO");
    }
  }
}


void mostrarResultados(char nomes[][MAX_NOME], float *medias, int qtdAlunos, char situacoes[][20]) {
  printf("\033[1;37m============= RESULTADO GERAL ===============\033[0m\n");
  for (int i = 0; i < qtdAlunos; i++) {

    if (medias[i] >= 7) {
      printf("\033[1;34m%s\033[0m --> \033[1;92m%.1lf\033[0m, "
             "\033[1;92m%s\033[0m\n",
             nomes[i], medias[i], situacoes[i]);

    } else if (medias[i] >= 4) {
      printf("\033[1;34m%s\033[0m --> \033[1;93m%.1lf\033[0m, "
             "\033[1;93m%s\033[0m\n",
             nomes[i], medias[i], situacoes[i]);

    } else {
      printf("\033[1;34m%s\033[0m --> \033[1;31m%.1lf\033[0m, "
             "\033[1;31m%s\033[0m\n",
             nomes[i], medias[i], situacoes[i]);
    }
  }
  bool found;

  found = false;
  printf("\n\033[1;37m========== ALUNOS APROVADOS ===========\n");
  for (int i = 0; i < qtdAlunos; i++) {
    if (medias[i] >= 7) {
      found = true;
      printf("\033[1;34m%s\033[0m\n", nomes[i]);
    }
  }
  if (!found) {
    printf("\033[1;31mNULL\033[0m\n");
  }

  found = false;
  printf("\n\033[1;37m========== ALUNOS REPROVADOS ==========\n");
  for (int i = 0; i < qtdAlunos; i++) {
    if (medias[i] < 4) {
      found = true;
      printf("\033[1;34m%s\033[0m\n", nomes[i]);
    }
  }
  if (!found) {
    printf("\033[1;31mNULL\033[0m\n");
  }

  found = false;
  printf("\n\033[1;37m========== ALUNOS DE PROVA FINAL ==========\n");
  for (int i = 0; i < qtdAlunos; i++) {
    if (medias[i] >= 4 && medias[i] < 7) {
      found = true;
      printf("\033[1;34m%s\033[0m\n", nomes[i]);
    }
  }
  if (!found) {
    printf("\033[1;31mNULL\033[0m\n");
  }
}


void calcularMediaProvaFinal(int i, char nomes[][MAX_NOME], float *medias, float notaProvaFinal) {
  float mediaFinal = (medias[i] + notaProvaFinal) / 2;
  medias[i] = mediaFinal;
}

float calcularMedia(float somaNotas, int qtdNotas) {
  return somaNotas / (float)qtdNotas;
}

int main() {
  int qtdAlunos, qtdNotas, choice;
  float notas, somaNotas;
  float media;
  char nomes[MAX_STRINGS][MAX_NOME];
  float medias[MAX_STRINGS];
  char situacoes[MAX_STRINGS][20];

  clearScreen();

  printf("\033[32m=== INFORMAÇÕES ===\033[0m\n");

  printf("\nDigite Quantos Alunos Deseja Adicionar: ");
  scanf("%d", &qtdAlunos);

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

    media = calcularMedia(somaNotas, qtdNotas);
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
      calcularSituacoes(medias, situacoes, qtdAlunos);
      mostrarResultados(nomes, medias, qtdAlunos, situacoes);
      pauseExecution();

      break;
    }

    case 2: {
      listarAlunosNotas(nomes, qtdAlunos, qtdNotas, arrayNotas);
      pauseExecution();

      break;
    }

    case 3: {
      float notaProvaFinal;

      printf("Digite as Notas da Prova Final Dos Alunos\n\n");

      for (int i = 0; i < qtdAlunos; i++) {
        if (medias[i] < 7 && medias[i] > 4) {
          printf("Nota do(a) %s: ", nomes[i]);
          scanf("%f", &notaProvaFinal);
          calcularMediaProvaFinal(i, nomes, medias, notaProvaFinal);
        }
      }
      pauseExecution();

      break;
    }

      case 0: {
        mostrarBoletimGeral(nomes, arrayNotas, medias, situacoes, qtdAlunos, qtdNotas);

      break;
    }
    }
  }
}
