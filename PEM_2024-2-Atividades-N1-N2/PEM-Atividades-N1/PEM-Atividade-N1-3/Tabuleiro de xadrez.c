/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Um tabuleiro de xadrez com vetor unidimensional
* Data - 30/08/2024                                         * 
* Autor: Mariana Fernandes Vieira
*--------------------------------------------------------*/

#include <stdio.h>

int main() {
    char* tabuleiro[64] = {
        "PT1", "PC1", "PB1", "PD1", "PR1", "PB2", "PC2", "PT2",
        "PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        "BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8",
        "BT1", "BC1", "BB1", "BD1", "BR1", "BB2", "BC2", "BT2"
    };

    int linha = 8;
    for(int i = 0; i < 64; i += 8)
    {
        printf("%d | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", linha, 
            tabuleiro[0 + i], tabuleiro[1 + i], tabuleiro[2 + i], tabuleiro[3 + i], 
            tabuleiro[4 + i], tabuleiro[5 + i], tabuleiro[6 + i], tabuleiro[7 + i]);
    
        linha -= 1;
    }

    printf("   --------------------------------\n");
    printf("     a   b   c   d   e   f   g   h\n");

    return 0;
}