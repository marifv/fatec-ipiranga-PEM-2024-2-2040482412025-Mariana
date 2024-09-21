/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Fazer uma Calculadora HP 12C que simule o padrão RPN
* Data - 20/09/2024                                        * 
* Autores: Mariana Fernandes Vieira e Ryan Almeida Silva
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 4
#define MAX_INPUT_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->stack[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    }
    return 0;
}

int performOperation(char operator, int operand1, int operand2) {
    switch (operator) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                printf("Erro: Divisão por 0 não é permitida!\n");
                return -1;
            }
            return operand1 / operand2;
        default: return 0;
    }
}

void displayStack(Stack *s) {
    printf("Estado da pilha (X, Y, Z, T): ");
    for (int i = 0; i < MAX_STACK_SIZE; i++) {
        if (i <= s->top) {
            printf("%d ", s->stack[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void processRPN(Stack *s, char *input) {
    char *token = strtok(input, " ");
    int numberCount = 0;
    int errorOccurred = 0;

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            if (numberCount < MAX_STACK_SIZE) {
                push(s, atoi(token));
                numberCount++;
                displayStack(s);
            } else {
                printf("Erro: Apenas 4 números são permitidos!\n");
                errorOccurred = 1;
                break;
            }
        } else {
            if (s->top < 1) {
                printf("Erro: Número insuficiente de operandos na pilha!\n");
                errorOccurred = 1;
                break;
            }
            int operand2 = pop(s);
            int operand1 = pop(s);
            int result = performOperation(token[0], operand1, operand2);
            if (result != -1) {
                push(s, result);
                printf("Aplicando %d %c %d\n", operand1, token[0], operand2);
                displayStack(s);
            }
        }
        token = strtok(NULL, " ");
    }

    if (!errorOccurred && !isEmpty(s) && s->top >= 0) {
        printf("Resultado: %d\n", s->stack[s->top]);
    }
}

int main() {
    Stack stack;
    char input[MAX_INPUT_SIZE];
    char again;

    initStack(&stack);

    do {
        printf("Digite a expressão em RPN, colocando os numeros e operadores separados por um espaço em branco > \n");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        processRPN(&stack, input);

        initStack(&stack);

        printf("Deseja fazer uma nova entrada? (s/n): ");
        scanf(" %c", &again);
        getchar();

    } while (again == 's' || again == 'S');

    printf("Obrigado por usar nossa Calculadora Fatec-HP12c\n");
    return 0;
}
