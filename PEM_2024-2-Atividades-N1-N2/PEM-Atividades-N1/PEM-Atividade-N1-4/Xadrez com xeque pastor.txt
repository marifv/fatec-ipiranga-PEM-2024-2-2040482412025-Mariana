/*--------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular          *
*          Prof. Carlos Veríssimo                        *
*--------------------------------------------------------*
* Objetivo do Programa: Um tabuleiro de xadrez simulando um xeque pastor
* Data - 30/08/2024                                      * 
* Autor: Mariana Fernandes Vieira
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

char pecasBrancas[8][4] = {"BT1", "BC1", "BB1", "BD1", "BR1", "BB2", "BC2", "BT2"};
char peoesBrancos[8][4] = {"BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8"};
char linhaVazia1[8][4] = {"", "", "", "", "", "", "", ""};
char linhaVazia2[8][4] = {"", "", "", "", "", "", "", ""};
char linhaVazia3[8][4] = {"", "", "", "", "", "", "", ""};
char linhaVazia4[8][4] = {"", "", "", "", "", "", "", ""};
char peoesPretos[8][4] = {"PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8"};
char pecasPretas[8][4] = {"PT1", "PC1", "PB1", "PD1", "PR1", "PB2", "PC2", "PT2"};

void mostrarTabuleiro() {
    printf("     a   b   c   d   e   f   g   h\n");
    printf("   --------------------------------\n");
    
    printf("8| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", pecasPretas[i]);
    }
    printf("\n");
    
    printf("7| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", peoesPretos[i]);
    }
    printf("\n");
    
    printf("6| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", linhaVazia4[i]);
    }
    printf("\n");
    
    printf("5| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", linhaVazia3[i]);
    }
    printf("\n");
    
    printf("4| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", linhaVazia2[i]);
    }
    printf("\n");
    
    printf("3| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", linhaVazia1[i]);
    }
    printf("\n");
    
    printf("2| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", peoesBrancos[i]);
    }
    printf("\n");
    
    printf("1| ");
    for (int i = 0; i < 8; i++) {
        printf("%-4s", pecasBrancas[i]);
    }
    printf("\n");
}

int main() {
    printf("    --------------------------------\n");
    printf("          INICIO DA PARTIDA\n");
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 1 - BRANCO JOGA\n");
    strcpy(linhaVazia2[4], "BP5");
    strcpy(peoesBrancos[4], "...");    
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 2 - PRETO JOGA\n");
    strcpy(linhaVazia3[4], "PP5");
    strcpy(peoesPretos[4], "...");    
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 3 - BRANCO JOGA\n");
    strcpy(pecasBrancas[5], "...");    
    strcpy(linhaVazia2[2], "BB2");
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 4 - PRETO JOGA\n");
    strcpy(pecasPretas[1], "...");    
    strcpy(linhaVazia4[2], "PC1");
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 5 - BRANCO JOGA\n");
    strcpy(pecasBrancas[3], "...");    
    strcpy(linhaVazia3[7], "BD1");
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 6 - PRETO JOGA\n");
    strcpy(pecasPretas[6], "...");    
    strcpy(linhaVazia4[5], "PC2");
    mostrarTabuleiro();
    printf("----------------------------------");

    printf("\n          JOGADA 7 - BRANCO JOGA\n");
    strcpy(linhaVazia3[7], "...");    
    strcpy(peoesBrancos[4], "...");    
    strcpy(peoesPretos[5], "BD1");
    mostrarTabuleiro();
    printf("----------------------------------");
    printf("\n");
    printf("\n XEQUE MATE, FIM DE JOGO");
    
    return 0;
}
