#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declaração das variáveis globais
int a = 0;
int b = 0;
int c = 0;

// Declaração das funções
char* get_string(const char* prompt);

// Função principal
int main() {
    char *input_a, *input_b;

    // Obtenção dos valores das variáveis
    input_a = get_string("Digite um valor para a variável a: ");
    input_b = get_string("Digite um valor para a variável b: ");

    // Conversão das entradas para inteiros
    a = atoi(input_a);
    b = atoi(input_b);

    // Troca dos valores de a e b usando a variável c como temporária
    c = a;
    a = b;
    b = c;

    // Impressão dos valores
    printf("A variável a é: %d\n", a);
    printf("A variável b é: %d\n", b);

    // Liberação da memória alocada
    free(input_a);
    free(input_b);

    return 0;
}

// Função para obter uma string de entrada do usuário
char* get_string(const char* prompt) {
    char *input = (char*) malloc(256 * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(1);
    }

    printf("%s", prompt);
    if (fgets(input, 256, stdin) == NULL) {
        fprintf(stderr, "Erro ao ler entrada\n");
        free(input);
        exit(1);
    }

    // Remover o caractere de nova linha se presente
    input[strcspn(input, "\n")] = '\0';

    return input;
}
