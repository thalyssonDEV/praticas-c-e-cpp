#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura do tipo Registro
typedef struct {
    int idade;      
    char *nome;
    float altura;
} Registro;

// Função que aloca memória para o array de caracteres que armazenará -> nome
void alocarMemoriasArrays(char **nome) {
    *nome = (char*)malloc(sizeof(char) * 20);
    
    // Verifica se a alocação de memória foi bem-sucedida
    if (*nome == NULL) {
        printf("ERRO AO ALOCAR MEMÓRIA\n");
        exit(1); // Encerra o programa se não conseguir alocar memória para evitar comportamento indefinido
    }
}

int main() {
    Registro reg; // Declara uma variável do tipo Registro
    Registro *regCopia = &reg; // Cria um ponteiro para a estrutura reg

    alocarMemoriasArrays(&reg.nome);

    printf("Digite o Nome: ");
    scanf("%19s", reg.nome); // Lê uma string de até 19 caracteres (1 reservado para o terminador nulo)

    printf("Digite a Altura: ");
    scanf("%f", &reg.altura);

    printf("Digite a Idade: ");
    scanf("%d", &reg.idade);

    // Acessa as informações usando o ponteiro RegCopia
    printf("Nome: %s\n", regCopia->nome);
    printf("Altura: %.2f\n", regCopia->altura);
    printf("Idade: %d\n", regCopia->idade);

    // Libera a memória alocada para -> nome
    free(reg.nome);

    return 0;
}
