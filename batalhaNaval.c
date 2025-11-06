#include <stdio.h>

int main () {
    
    int tabuleiro[10][10]; // Matriz 10x10 para o tabuleiro
    int i, j;
    int Agua = 0; // Representa água no tabuleiro
    int Navio = 3;
    int TamanhoNavio = 3; 

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = Agua;
        }
    }

    // ----- Coordenadas iniciais -----
    // Navio horizontal
    int LinhaH = 2;
    int colunaH = 4;
   
    // Navio vertical
    int linhaV = 5;
    int ColunaV = 7;

    // Validação dos Limites
    if (colunaH + TamanhoNavio > 10) {
        printf("Erro: navio horizontal sai dos limites do tabuleiro.\n");
        return 1;
    }

    if (linhaV + TamanhoNavio > 10) {
        printf("Erro: navio vertical sai dos limites do tabuleiro.\n");
        return 1;
    }

    // ----- Verificar sobreposição -----
    int sobrepoe = 0;
    for (i = 0; i < TamanhoNavio; i++) {
        if (tabuleiro[LinhaH][colunaH + i] == Navio ||
            tabuleiro[linhaV + i][ColunaV] == Navio) {
            sobrepoe = 1;
            break;
        }    
    }

    if (sobrepoe) {
        printf("Erro: navios se sobrepoem.\n");
        return 1;
    }
    
    //----- Posicionar o Navio Horizontal -----
    for (i = 0; i < TamanhoNavio; i++) {
        tabuleiro[LinhaH][colunaH + i] = Navio;
    }

    // ----- Posicionar o Navio Vertical -----
    for (i = 0; i < TamanhoNavio; i++) {
        tabuleiro[linhaV + i][ColunaV] = Navio;
    }
    // Exibir o tabuleiro
    printf("\n=== Tabuleiro de Batalha Naval ===\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}