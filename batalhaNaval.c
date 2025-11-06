#include <stdio.h>

#define LINHAS 10 // Matriz 10x10 para o tabuleiro
#define COLUNAS 10 // Matriz 10x10 para o tabuleiro
#define AGUA 0 // Representa água no tabuleiro
#define TAMANHO_NAVIO 3 // Tamanho do navio 
#define NAVIO 3 // Representa navio no tabuleiro

int main () {
    
    int tabuleiro[LINHAS][COLUNAS];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // ----- Coordenadas iniciais -----
    // Navio horizontal
    int linhaH = 2;
    int colunaH = 4;
   
    // Navio vertical
    int linhaV = 5;
    int colunaV = 7;

    // Navio Diagonal descendo
    int linhaD1 = 0;
    int colunaD1 = 0;

    // Navio Diagoanl subindo
    int linhaD2 = 9;
    int colunaD2 = 0;

    // Validação dos Limites
    if (colunaH + TAMANHO_NAVIO > COLUNAS) {
        printf("Erro: navio horizontal fora dos limites.\n");
        return 1;
    }

    if (linhaV + TAMANHO_NAVIO > LINHAS) {
        printf("Erro: navio vertical fora dos limites.\n");
        return 1;
    }

    if (linhaD1 + TAMANHO_NAVIO > LINHAS || colunaD1 + TAMANHO_NAVIO > COLUNAS) {
        printf("Erro: navio diagonal (descendo) fora dos limites.\n");
        return 1;
    }

    if (linhaD2 - (TAMANHO_NAVIO - 1) < 0 || colunaD2 + TAMANHO_NAVIO > COLUNAS) {
        printf("Erro: navio diagonal (subindo) fora dos limites.\n");
        return 1;
    }
    
    //----- Posicionar Navios -----
    // Navio Horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaH][colunaH + i] = NAVIO;
    }

    // Navio Vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaV + i][colunaV] = NAVIO;
    }

    // Navio Diagonal descendo
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
    }

    // Navio Diagonal subindo
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaD2 - i][colunaD2 + i] = NAVIO;
    }

    // Exibir o tabuleiro
    printf("\n=== Tabuleiro de Batalha Naval ===\n\n");
    
    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}