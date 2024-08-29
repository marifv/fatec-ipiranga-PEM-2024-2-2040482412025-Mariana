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
        "PT1", "PC2", "PB3", "PD4", "PR5", "PB6", "PC7", "PT8",
        "PP1", "PP2", "PP3", "PP4", "PP5", "PP6", "PP7", "PP8",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        " X ", " X ", " X ", " X ", " X ", " X ", " X ", " X ",
        "BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8",
        "BT1", "BC2", "BB3", "BD4", "BR5", "BB6", "BC7", "BT8"
    };


    printf("8 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[0], tabuleiro[1], tabuleiro[2], tabuleiro[3], tabuleiro[4], tabuleiro[5], tabuleiro[6], tabuleiro[7]);
    printf("7 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[8], tabuleiro[9], tabuleiro[10], tabuleiro[11], tabuleiro[12], tabuleiro[13], tabuleiro[14], tabuleiro[15]);
    printf("6 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[16], tabuleiro[17], tabuleiro[18], tabuleiro[19], tabuleiro[20], tabuleiro[21], tabuleiro[22], tabuleiro[23]);
    printf("5 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[24], tabuleiro[25], tabuleiro[26], tabuleiro[27], tabuleiro[28], tabuleiro[29], tabuleiro[30], tabuleiro[31]);
    printf("4 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[32], tabuleiro[33], tabuleiro[34], tabuleiro[35], tabuleiro[36], tabuleiro[37], tabuleiro[38], tabuleiro[39]);
    printf("3 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[40], tabuleiro[41], tabuleiro[42], tabuleiro[43], tabuleiro[44], tabuleiro[45], tabuleiro[46], tabuleiro[47]);
    printf("2 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[48], tabuleiro[49], tabuleiro[50], tabuleiro[51], tabuleiro[52], tabuleiro[53], tabuleiro[54], tabuleiro[55]);
    printf("1 | %-4s%-4s%-4s%-4s%-4s%-4s%-4s%-4s\n", 
        tabuleiro[56], tabuleiro[57], tabuleiro[58], tabuleiro[59], tabuleiro[60], tabuleiro[61], tabuleiro[62], tabuleiro[63]);

    printf("   --------------------------------\n");
    printf("     a   b   c   d   e   f   g   h\n");
    
    return 0;
}