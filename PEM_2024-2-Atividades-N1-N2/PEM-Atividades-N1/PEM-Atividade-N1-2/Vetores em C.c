/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Implementação de vetor para receber todas as notas
Implementação de vetor para receber todas provas    *
* Data - 23/08/2024                                           * 
* Autor: Mariana Fernandes Vieira
*--------------------------------------------------------*/

                                    /* Calculadora das notas dos candidatos */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 10
#define MAX_PROVAS 10
#define TAM_NOME_PROVA 50

int compare(const void *a, const void *b) {
    return (*(float*)a - *(float*)b);
}

float calcularNotaFinal(float notas[], int N) {
    float soma = 0.0;
    qsort(notas, N, sizeof(float), compare);

    for (int i = 1; i < N - 1; i++) {
        soma += notas[i];
    }

    return soma;
}

int main() {
    int N;
    float notas[MAX_NOTAS];
    float notaFinal[MAX_PROVAS];
    char nomesProvas[MAX_PROVAS][TAM_NOME_PROVA];
    float notaFinalTotal = 0.0;
    
    int provaIndex = 0;

    while (1) {
        printf("Digite a quantidade de notas (N) ou 0 para encerrar: ");
        scanf("%d", &N);

        if (N == 0) {
            break;
        }

        if (N <= 2 || N > MAX_NOTAS) {
            printf("Número inválido de notas. Deve ser entre 3 e %d. Tente novamente.\n", MAX_NOTAS);
            continue;
        }

        if (provaIndex >= MAX_PROVAS) {
            printf("Número máximo de provas excedido.\n");
            break;
        }

        printf("\nDigite o nome da prova %d: ", provaIndex + 1);
        scanf(" %[^\n]", nomesProvas[provaIndex]);

        printf("Digite as %d notas do candidato na mesma linha, separadas por espaço:\n", N);
        int i = 0;
        while (i < N) {
            if (scanf("%f", &notas[i]) != 1) {
                while (getchar() != '\n');
                printf("Nota inválida. Tente novamente.\n");
            } else if (notas[i] < 0.0 || notas[i] > 10.0) {
                printf("Nota inválida. A nota deve estar entre 0 e 10. Tente novamente.\n");
            } else {
                i++;
            }
        }
        while (getchar() != '\n');

        notaFinal[provaIndex] = calcularNotaFinal(notas, N);
        notaFinalTotal += notaFinal[provaIndex];

        printf("Nota %s = %.1f\n", nomesProvas[provaIndex], notaFinal[provaIndex]);

        provaIndex++;
    }

    printf("\nNotas finais das provas:\n");
    for (int i = 0; i < provaIndex; i++) {
        printf("Nota %s = %.1f\n", nomesProvas[i], notaFinal[i]);
    }

    printf("\nNota final do candidato = %.1f\n", notaFinalTotal);

    return 0;
}
