/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Desafio de resolver os bugs da HP12C
* Data - 21/09/2024                                        * 
* Autores: Mariana Fernandes Vieira e Ryan Almeida Silva
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAMANHO_PILHA 4

// Função para exibir a pilha
void exibirPilha(int pilha[]) {
    printf("Pilha: [T: %d] [Z: %d] [Y: %d] [X: %d]\n", pilha[3], pilha[2], pilha[1], pilha[0]);
}

// Função para empurrar valores na pilha
int empurrar(int pilha[], int valor) {
    if (pilha[TAMANHO_PILHA - 1] != 0) {
        return 0; // Pilha cheia
    }
    for (int i = TAMANHO_PILHA - 1; i > 0; i--) {
        pilha[i] = pilha[i - 1];
    }
    pilha[0] = valor; // Adiciona o novo valor no topo
    return 1; // Sucesso
}

// Função para realizar uma operação
int executarOperacao(int pilha[], char operador) {
    // Verifica se há operandos suficientes
    if (pilha[0] == 0 || pilha[1] == 0) {
        printf("Erro: Não há operandos suficientes para a operação '%c'.\n", operador);
        return 0; // Indica erro
    }

    // Verifica divisão por zero
    if (operador == '/' && pilha[0] == 0) {
        printf("Erro: Divisão por zero não permitida.\n");
        return 0; // Indica erro
    }

    int resultado;
    switch (operador) {
        case '+':
            resultado = pilha[1] + pilha[0];
            break;
        case '-':
            resultado = pilha[1] - pilha[0];
            break;
        case '*':
            resultado = pilha[1] * pilha[0];
            break;
        case '/':
            resultado = pilha[1] / pilha[0];
            break;
        default:
            printf("Operador inválido!\n");
            return 0; // Indica erro
    }

    // Atualiza a pilha
    for (int i = 0; i < TAMANHO_PILHA - 1; i++) {
        pilha[i] = pilha[i + 1]; // Move elementos para baixo
    }
    pilha[0] = resultado; // Coloca o resultado no topo da pilha
    return 1; // Sucesso
}

// Função para verificar se um token é um número válido
int verificarNumero(const char *token) {
    // Verifica se o token é um número ou um número negativo
    if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        return 1; // É um número
    }
    return 0; // Não é um número
}

int main() {
    int pilha[TAMANHO_PILHA] = {0}; // Inicializando a pilha com zeros
    char entrada[100]; // Para armazenar a entrada do usuário
    char continuar;

    printf("Bem-vindo à Calculadora Fatec-HP12c!\n");

    do {
        printf("\nDigite a expressão em formato RPN (ex: 5 1 2 + 4 * + 3) ou 'sair' para encerrar: ");
        fgets(entrada, sizeof(entrada), stdin); // Lê a entrada do usuário

        // Remove o caractere de nova linha se presente
        entrada[strcspn(entrada, "\n")] = 0;

        // Verifica se o usuário deseja sair
        if (strncmp(entrada, "sair", 4) == 0) {
            break;
        }

        // Divide a entrada em tokens (números e operadores)
        char *token = strtok(entrada, " ");
        while (token != NULL) {
            if (verificarNumero(token)) {
                int valor = atoi(token); // Converte para inteiro
                if (empurrar(pilha, valor)) {
                    exibirPilha(pilha); // Exibe estado da pilha
                } else {
                    printf("Erro: Pilha cheia. Não foi possível empurrar o valor.\n");
                }
            } else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
                if (executarOperacao(pilha, token[0])) {
                    exibirPilha(pilha); // Exibe estado da pilha
                } else {
                    printf("Erro ao executar a operação '%c'.\n", token[0]);
                }
            } else {
                printf("Erro: Token inválido '%s'. Somente números e operadores são permitidos.\n", token);
            }
            token = strtok(NULL, " "); // Avança para o próximo token
        }

        if (pilha[0] != 0) {
            printf("\nResultado final: %d\n", pilha[0]);
        } else {
            printf("\nNenhum resultado válido.\n");
        }

        // Pergunta se deseja realizar outra operação
        printf("\nDeseja realizar outra operação? (s/n): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa o buffer
    } while (continuar == 's' || continuar == 'S');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c!\n");
    return 0;
}
