/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Utilizar ponteiros                     *
*                                                              *
* Data: 06/11/2024                                             * 
* Autor: Mariana Fernandes Vieira                              *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_PRODUCTS 100

// Definição da estrutura Produto
typedef struct {
    int id;
    char nome[MAX_NAME_LEN];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Contador global para gerar IDs automaticamente
int contadorID = 1;

// Função para incluir um produto
void incluirProduto(Produto* pProduto, Produto produtos[], int qtdProdutos) {
    // Gerar ID automaticamente
    pProduto->id = contadorID++;
    
    printf("ID gerado automaticamente: %d\n", pProduto->id);
    
    printf("Digite o nome do produto: ");
    getchar();  // Limpar o buffer do teclado
    fgets(pProduto->nome, MAX_NAME_LEN, stdin);
    pProduto->nome[strcspn(pProduto->nome, "\n")] = '\0';  // Remover a nova linha no final da string
    
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &pProduto->quantidadeEmEstoque);
    
    printf("Digite o valor do produto: ");
    scanf("%lf", &pProduto->valorDoProduto);
    
    printf("Produto cadastrado com sucesso!\n");
}

// Função para consultar um produto por ID
Produto* consultarProduto(Produto produtos[], int qtdProdutos, int id) {
    for (int i = 0; i < qtdProdutos; i++) {
        if (produtos[i].id == id) {
            return &produtos[i];
        }
    }
    return NULL;
}

// Função para alterar um produto por ID
void alterarProduto(Produto* pProduto) {
    printf("Digite o novo nome do produto: ");
    getchar();  // Limpar o buffer do teclado
    fgets(pProduto->nome, MAX_NAME_LEN, stdin);
    pProduto->nome[strcspn(pProduto->nome, "\n")] = '\0';  // Remover a nova linha no final da string
    
    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &pProduto->quantidadeEmEstoque);
    
    printf("Digite o novo valor do produto: ");
    scanf("%lf", &pProduto->valorDoProduto);
    
    printf("Produto alterado com sucesso!\n");
}

// Função para excluir um produto
void excluirProduto(Produto* pProduto) {
    pProduto->id = -1;
    pProduto->quantidadeEmEstoque = 0;
    pProduto->valorDoProduto = 0.0;
    pProduto->nome[0] = '\0';  // Limpar o nome
    
    printf("Produto excluído com sucesso!\n");
}

// Função para imprimir os dados de um produto
void imprimirProduto(Produto* pProduto) {
    printf("\nID: %d\n", pProduto->id);
    printf("Nome: %s\n", pProduto->nome);
    printf("Quantidade em estoque: %d\n", pProduto->quantidadeEmEstoque);
    printf("Valor do produto: %.2f\n", pProduto->valorDoProduto);
}

// Função para vender um produto
void venderProduto(Produto* pProduto) {
    int quantidadeVendida;
    
    printf("Digite a quantidade a ser vendida: ");
    scanf("%d", &quantidadeVendida);
    
    if (quantidadeVendida > pProduto->quantidadeEmEstoque) {
        printf("Estoque insuficiente!\n");
    } else {
        pProduto->quantidadeEmEstoque -= quantidadeVendida;
        printf("Venda realizada com sucesso!\n");
        printf("Total: %.2f\n", pProduto->valorDoProduto * quantidadeVendida);
    }
}

int main() {
    Produto produtos[MAX_PRODUCTS];
    int qtdProdutos = 0, opcao, id;
    
    while (1) {
        printf("\n1. Incluir produto\n");
        printf("2. Consultar produto\n");
        printf("3. Alterar produto\n");
        printf("4. Excluir produto\n");
        printf("5. Vender produto\n");
        printf("6. Imprimir dados do produto\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:  // Incluir produto
                if (qtdProdutos < MAX_PRODUCTS) {
                    incluirProduto(&produtos[qtdProdutos], produtos, qtdProdutos);
                    qtdProdutos++;
                } else {
                    printf("Limite de produtos atingido!\n");
                }
                break;
            
            case 2:  // Consultar produto
                printf("Digite o ID do produto para consulta: ");
                scanf("%d", &id);
                Produto* pProdutoConsulta = consultarProduto(produtos, qtdProdutos, id);
                if (pProdutoConsulta != NULL) {
                    imprimirProduto(pProdutoConsulta);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            
            case 3:  // Alterar produto
                printf("Digite o ID do produto para alterar: ");
                scanf("%d", &id);
                Produto* pProdutoAlterar = consultarProduto(produtos, qtdProdutos, id);
                if (pProdutoAlterar != NULL) {
                    alterarProduto(pProdutoAlterar);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            
            case 4:  // Excluir produto
                printf("Digite o ID do produto para excluir: ");
                scanf("%d", &id);
                Produto* pProdutoExcluir = consultarProduto(produtos, qtdProdutos, id);
                if (pProdutoExcluir != NULL) {
                    excluirProduto(pProdutoExcluir);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            
            case 5:  // Vender produto
                printf("Digite o ID do produto para vender: ");
                scanf("%d", &id);
                Produto* pProdutoVender = consultarProduto(produtos, qtdProdutos, id);
                if (pProdutoVender != NULL) {
                    venderProduto(pProdutoVender);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            
            case 6:  // Imprimir dados do produto
                printf("Digite o ID do produto para imprimir os dados: ");
                scanf("%d", &id);
                Produto* pProdutoImprimir = consultarProduto(produtos, qtdProdutos, id);
                if (pProdutoImprimir != NULL) {
                    imprimirProduto(pProdutoImprimir);
                } else {
                    printf("Produto não encontrado!\n");
                }
                break;
            
            case 7:  // Sair
                printf("Saindo...\n");
                return 0;
            
            default:
                printf("Opção inválida!\n");
        }
    }
    
    return 0;
}
