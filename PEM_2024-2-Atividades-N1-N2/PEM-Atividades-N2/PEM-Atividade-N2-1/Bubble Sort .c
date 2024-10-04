/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Bubble Sort Autoria própria              *
*                                                              *
* Data: 04/09/2024                                             * 
* Autor: Mariana Fernandes Vieira               *
*--------------------------------------------------------------*/


#include <stdio.h>

// Função para ler os números e armazená-los em um array
void lerNumeros(int arr[], int n) {
    printf("Digite %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
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
    int n;

    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    int arr[n];

    // Ler números do usuário
    lerNumeros(arr, n);

    // Exibir o array original
    exibirArray(arr, n);

    // Ordenar o array
    bubbleSort(arr, n);

    // Exibir o array ordenado
    printf("Array ordenado:\n");
    exibirArray(arr, n);

    return 0;
}
