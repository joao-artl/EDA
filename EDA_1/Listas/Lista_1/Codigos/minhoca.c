#include <stdio.h>

int main() {
    int linhas, colunas, caminho = 0, maior = 0;
    scanf("%d %d", &linhas, &colunas);
    int campo[linhas][colunas];
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &campo[i][j]);
        }
    }

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            caminho += campo[j][i];
        }
        if (maior < caminho) {
            maior = caminho;
        }
        caminho = 0;
    }
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            caminho += campo[i][j];
        }
        if (maior < caminho) {
            maior = caminho;
        }
        caminho = 0;
    }
    printf("%d\n", maior);
    return 0;
}