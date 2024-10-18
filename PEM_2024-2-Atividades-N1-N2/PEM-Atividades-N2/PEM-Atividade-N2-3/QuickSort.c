/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: QuickSort                              *
*                                                              *
* Data: 18/10/2024                                             * 
* Autor: Ryan Almeida Silva e Mariana Fernandes Vieira         *
*--------------------------------------------------------------*/

#include <stdio.h>

// Função de troca de elementos
void troca(int* posicao1, int* posicao2) {
    int temp = *posicao1;
    *posicao1 = *posicao2;
    *posicao2 = temp;
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para a execução da partição
int particao(int arr[], int limInf, int limSup) {
    int pivo = arr[limSup]; 
    int ind = (limInf - 1);

    for (int j = limInf; j <= limSup - 1; j++) {
        if (arr[j] <= pivo) {
            ind++; 
            troca(&arr[ind], &arr[j]);
        }
    }
    troca(&arr[ind + 1], &arr[limSup]);
    return (ind + 1);
}

// Função do QuickSort
void QuickSort(int arr[], int limInferior, int limSup) {
    if (limInferior < limSup) {
        int indParticao = particao(arr, limInferior, limSup);
        QuickSort(arr, limInferior, indParticao - 1);
        QuickSort(arr, indParticao + 1, limSup);
    }
}

int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
