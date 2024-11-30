/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: Programa N2-5 REFATORADO               *
*                                                              *
* Data: 29/11/2024                                             * 
* Autor: Mariana Fernandes Vieira                              *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    int quantidadeEmEstoque;
    double valorDoProduto;
} Produto;

// Prototipação das funções
void exibirMenu();
int lerOpcao();
double lerDoublePositivo(const char *mensagem);
int lerInteiroPositivo(const char *mensagem);
void incluirProduto(Produto *produtos, int *quantidade);
Produto* consultarProduto(Produto *produtos, int quantidade, int id);
void alterarProduto(Produto *produtos, int quantidade);
void excluirProduto(Produto *produtos, int *quantidade);
void imprimirProduto(const Produto *produto);
void venderProduto(Produto *produtos, int quantidade);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade = 0;

    while (1) {
        exibirMenu();
        int opcao = lerOpcao();

        switch (opcao) {
            case 1:
                incluirProduto(produtos, &quantidade);
                break;
            case 2: {
                int id = lerInteiroPositivo("Digite o ID do produto a ser consultado: ");
                Produto *produto = consultarProduto(produtos, quantidade, id);
                if (produto) {
                    imprimirProduto(produto);
                } else {
                    printf("Produto não encontrado.\n");
                }
                break;
            }
            case 3:
                alterarProduto(produtos, quantidade);
                break;
            case 4:
                excluirProduto(produtos, &quantidade);
                break;
            case 5:
                venderProduto(produtos, quantidade);
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

void exibirMenu() {
    // Exibe o menu de opções para o usuário
    printf("\nMenu:\n");
    printf("1 - Incluir produto\n");
    printf("2 - Consultar produto\n");
    printf("3 - Alterar produto\n");
    printf("4 - Excluir produto\n");
    printf("5 - Vender produto\n");
    printf("0 - Sair\n");
}

int lerOpcao() {
    // Lê a opção escolhida pelo usuário no menu, garantindo que seja um número inteiro válido
    int opcao;
    while (1) {
        printf("Escolha uma opção: ");
        if (scanf("%d", &opcao) == 1) {
            return opcao; // Retorna a opção caso seja válida
        }
        printf("Entrada inválida. Digite um número.\n");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
}

double lerDoublePositivo(const char *mensagem) {
    // Lê um número decimal positivo, utilizando uma mensagem personalizada
    double valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%lf", &valor) == 1 && valor >= 0) {
            return valor; // Retorna o valor se for válido e positivo
        }
        printf("Entrada inválida. Digite um valor positivo.\n");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
}

int lerInteiroPositivo(const char *mensagem) {
    // Lê um número inteiro positivo, utilizando uma mensagem personalizada
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor >= 0) {
            return valor; // Retorna o valor se for válido e positivo
        }
        printf("Entrada inválida. Digite um número inteiro positivo.\n");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
}

void incluirProduto(Produto *produtos, int *quantidade) {
    // Inclui um novo produto na lista de produtos
    if (*quantidade >= MAX_PRODUTOS) {
        printf("Erro: Capacidade máxima de produtos atingida.\n");
        return; // Verifica se o limite de produtos foi atingido
    }

    Produto *produto = &produtos[*quantidade]; // Aponta para o próximo produto disponível
    produto->id = lerInteiroPositivo("Digite o ID do produto: "); // Lê o ID do produto

    // Verifica se o ID já está cadastrado
    if (consultarProduto(produtos, *quantidade, produto->id)) {
        printf("Erro: ID já cadastrado.\n");
        return;
    }

    // Lê os dados do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", produto->nome); // Lê o nome com espaços

    produto->quantidadeEmEstoque = lerInteiroPositivo("Digite a quantidade em estoque: ");
    produto->valorDoProduto = lerDoublePositivo("Digite o valor do produto: ");

    (*quantidade)++; // Aumenta a quantidade de produtos
    printf("Produto incluído com sucesso!\n");
}

Produto* consultarProduto(Produto *produtos, int quantidade, int id) {
    // Busca um produto pelo ID na lista de produtos
    for (int i = 0; i < quantidade; i++) {
        if (produtos[i].id == id) {
            return &produtos[i]; // Retorna o produto encontrado
        }
    }
    return NULL; // Retorna NULL se o produto não for encontrado
}

void alterarProduto(Produto *produtos, int quantidade) {
    // Altera as informações de um produto já existente
    int id = lerInteiroPositivo("Digite o ID do produto a ser alterado: ");
    Produto *produto = consultarProduto(produtos, quantidade, id);

    if (produto) {
        // Se o produto foi encontrado, permite alterar os dados
        printf("Digite o novo nome do produto: ");
        scanf(" %[^\n]", produto->nome);
        produto->quantidadeEmEstoque = lerInteiroPositivo("Digite a nova quantidade em estoque: ");
        produto->valorDoProduto = lerDoublePositivo("Digite o novo valor do produto: ");
        printf("Produto alterado com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void excluirProduto(Produto *produtos, int *quantidade) {
    // Exclui um produto da lista
    int id = lerInteiroPositivo("Digite o ID do produto a ser excluído: ");
    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id == id) {
            // Se encontrado, move todos os produtos seguintes uma posição à esquerda
            for (int j = i; j < *quantidade - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*quantidade)--; // Decrementa a quantidade de produtos
            printf("Produto excluído com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void imprimirProduto(const Produto *produto) {
    // Exibe as informações de um produto
    printf("\nID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade em Estoque: %d\n", produto->quantidadeEmEstoque);
    printf("Valor do Produto: %.2f\n", produto->valorDoProduto);
}

void venderProduto(Produto *produtos, int quantidade) {
    // Realiza a venda de um produto, diminuindo sua quantidade em estoque
    int id = lerInteiroPositivo("Digite o ID do produto a ser vendido: ");
    Produto *produto = consultarProduto(produtos, quantidade, id);

    if (produto) {
        int quantidadeVendida = lerInteiroPositivo("Digite a quantidade a ser vendida: ");
        if (quantidadeVendida <= produto->quantidadeEmEstoque) {
            produto->quantidadeEmEstoque -= quantidadeVendida; // Diminui a quantidade em estoque
            printf("Venda realizada com sucesso!\n");
            imprimirProduto(produto); // Exibe os dados do produto após a venda
        } else {
            printf("Quantidade em estoque insuficiente.\n");
        }
    } else {
        printf("Produto não encontrado.\n");
    }
}
