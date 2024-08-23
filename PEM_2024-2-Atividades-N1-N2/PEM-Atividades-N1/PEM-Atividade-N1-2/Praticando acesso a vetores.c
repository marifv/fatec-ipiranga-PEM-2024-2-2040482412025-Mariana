// autor: Mariana Fernandes Vieira

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 100
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
            printf("Número inválido de notas. Tente novamente.\n");
            continue;
        }

        if (provaIndex >= MAX_PROVAS) {
            printf("Número máximo de provas excedido.\n");
            break;
        }

        printf("\nDigite o nome da prova %d: ", provaIndex + 1);
        scanf(" %[^\n]", nomesProvas[provaIndex]);

        printf("Digite as %d notas do candidato:\n", N);
        for (int i = 0; i < N; i++) {
            while (1) {
                printf("Digite a %dª nota: ", i + 1);
                scanf("%f", &notas[i]);
                
                if (notas[i] < 0.0 || notas[i] > 10.0) {
                    printf("Nota inválida. A nota deve estar entre 0 e 10. Tente novamente.\n");
                } else {
                    break;
                }
            }
        }

        notaFinal[provaIndex] = calcularNotaFinal(notas, N);
        notaFinalTotal += notaFinal[provaIndex];

        // Imprime o resultado da prova atual
        printf("Nota %s = %.0f\n", nomesProvas[provaIndex], notaFinal[provaIndex]);

        provaIndex++;
    }

    // Imprime as notas finais de todas as provas e a nota final total
    printf("\nNotas finais das provas:\n");
    for (int i = 0; i < provaIndex; i++) {
        printf("Nota %s = %.0f\n", nomesProvas[i], notaFinal[i]);
    }

    printf("\nNota final do candidato = %.0f\n", notaFinalTotal);

    return 0;
}
