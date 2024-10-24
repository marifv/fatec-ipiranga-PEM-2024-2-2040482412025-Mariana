/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Manipular Struct                     *
*                                                              *
* Data: 24/10/2024                                             * 
* Autor: Mariana Fernandes Vieira e Ryan Almeida Silva         *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Estrutura para representar um produto
typedef struct {
    int id;
    char nome[50];
    char descricao[100];
    float preco;
    int quantidade;
} Produto;

// Prototipos das funções
void adicionarProduto(Produto produtos[], int *contador);
void listarProdutos(Produto produtos[], int contador);
void bubbleSort(Produto produtos[], int contador);
void comprarProduto(Produto produtos[], int contador);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int contador = 0;
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Comprar Produto\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarProduto(produtos, &contador);
                break;
            case 2:
                listarProdutos(produtos, contador);
                break;
            case 3:
                comprarProduto(produtos, contador);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Função para adicionar um produto à lista
void adicionarProduto(Produto produtos[], int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Erro: Não é possível adicionar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    printf("Informe o ID do produto: ");
    scanf("%d", &novoProduto.id);
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Informe a descrição do produto: ");
    scanf(" %[^\n]", novoProduto.descricao);
    printf("Informe o preço unitário: ");
    scanf("%f", &novoProduto.preco);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);

    produtos[*contador] = novoProduto;
    (*contador)++;
    bubbleSort(produtos, *contador);
    printf("Produto adicionado com sucesso!\n");
}

// Função para listar produtos em ordem alfabética
void listarProdutos(Produto produtos[], int contador) {
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d, Nome: %s, Descrição: %s, Preço: %.2f, Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].descricao, produtos[i].preco, produtos[i].quantidade);
    }
}

// Função para implementar o bubble sort
void bubbleSort(Produto produtos[], int contador) {
    for (int i = 0; i < contador - 1; i++) {
        for (int j = 0; j < contador - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

// Função para simular a compra de um produto
void comprarProduto(Produto produtos[], int contador) {
    if (contador == 0) {
        printf("Nenhum produto disponível para compra.\n");
        return;
    }

    int idProduto, quantidade;
    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < contador; i++) {
        if (produtos[i].id == idProduto) {
            printf("Informe a quantidade que deseja comprar: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].quantidade) {
                printf("Quantidade indisponível em estoque.\n");
            } else {
                produtos[i].quantidade -= quantidade;
                printf("Compra realizada com sucesso! Você comprou %d unidade(s) de %s.\n", quantidade, produtos[i].nome);
            }
            return;
        }
    }
    printf("Produto Inexistente.\n");
}
