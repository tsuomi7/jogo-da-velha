#include <stdio.h>
#include <stdbool.h>

#define TAMANHO 3

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
bool fazerJogada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char jogador);
bool verificarVitoria(char tabuleiro[TAMANHO][TAMANHO], char jogador);
bool tabuleiroCheio(char tabuleiro[TAMANHO][TAMANHO]);

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    char jogadorAtual = 'X';
    int linha, coluna;

    inicializarTabuleiro(tabuleiro);

    do {
        exibirTabuleiro(tabuleiro);

        printf("Jogador %c, insira a linha (1-%d) e a coluna (1-%d): ", jogadorAtual, TAMANHO, TAMANHO);
        scanf("%d %d", &linha, &coluna);

        if (fazerJogada(tabuleiro, linha - 1, coluna - 1, jogadorAtual)) {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        } else {
            printf("Jogada inválida. Tente novamente.\n");
        }

    } while (!verificarVitoria(tabuleiro, 'X') && !verificarVitoria(tabuleiro, 'O') && !tabuleiroCheio(tabuleiro));

    exibirTabuleiro(tabuleiro);
    if (verificarVitoria(tabuleiro, 'X')) {
        printf("Jogador X venceu!\n");
    } else if (verificarVitoria(tabuleiro, 'O')) {
        printf("Jogador O venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}

void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < TAMANHO - 1) {
            for (int k = 0; k < TAMANHO * 4 - 1; k++) {
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
}

bool fazerJogada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char jogador) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return true;
    } else {
        return false;
    }
}

bool verificarVitoria(char tabuleiro[TAMANHO][TAMANHO], char jogador) {
    for (int i = 0; i < TAMANHO; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return true;
        }
    }

    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return true;
    }

    return false;
}

bool tabuleiroCheio(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
