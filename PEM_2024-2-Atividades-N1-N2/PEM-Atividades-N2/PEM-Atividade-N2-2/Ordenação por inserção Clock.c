/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: ORDENAÇÃO POR INSERÇÃO                 *
*                                                              *
* Data: 04/10/2024                                             * 
* Autor: Letícia Sudan Gauy e Fernando Palmieri                *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[] = {5, 3, 8, 4, 2,
              115, 113, 118, 114, 112,
              125, 123, 128, 124, 122,
              35, 33, 38, 34, 32,
              45, 43, 48, 44, 42,
              55, 53, 58, 54, 52,
              65, 63, 68, 64, 62,
              75, 73, 78, 74, 72,
              85, 83, 88, 84, 82,
              95, 93, 98, 94, 92,
              15, 13, 18, 14, 12,
              25, 23, 28, 24, 22
             };

// Ordena um array usando o algoritmo de ordenação por inserção
void ordenacaoInsercao(int numeros[], int quantidade) {
    int i, elemento, posicao;
    for (i = 1; i < quantidade; i++) {
        elemento = numeros[i]; // Elemento a ser inserido
        posicao = i - 1;

        // Move elementos maiores para a direita
        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
        }
        numeros[posicao + 1] = elemento; // Insere o elemento na posição correta
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {
    int quantidadeNumeros = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, quantidadeNumeros);

    clock_t start, end;
    start = clock(); // Início da medição de tempo

    ordenacaoInsercao(arr, quantidadeNumeros); // Ordena o array

    end = clock(); // Fim da medição de tempo

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado: ");
    imprimirArray(arr, quantidadeNumeros);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
