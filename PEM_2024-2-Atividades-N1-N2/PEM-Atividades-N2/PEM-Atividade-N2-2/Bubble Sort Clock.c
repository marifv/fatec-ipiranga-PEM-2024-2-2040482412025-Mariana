/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Bubble Sort com clock       *
*                                                              *
* Data: 11/09/2024                                             * 
* Autor: Mariana Fernandes Vieira                               *
*--------------------------------------------------------------*/

#include <stdio.h>
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

// Função para ler os números e armazená-los em um array
void lerNumeros(int arr[], int n) {
    // A função não será usada, pois usaremos um array fixo
}

// Função para exibir o array
void exibirArray(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // Troca para ordem crescente
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibir o array original
    printf("Array original: ");
    exibirArray(arr, n);

    clock_t start, end;
    start = clock(); // Início da medição de tempo

    // Ordenar o array
    bubbleSort(arr, n);
    
    end = clock(); // Fim da medição de tempo

    // Exibir o array ordenado
    printf("Array ordenado:\n");
    exibirArray(arr, n);
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", cpu_time_used);

    return 0;
}
