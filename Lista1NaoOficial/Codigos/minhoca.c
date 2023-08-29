#include <stdio.h>

int main(){
    int linhas, colunas,caminho = 0, maior = 0;
    scanf("%d %d", &linhas, &colunas);
    int campo[linhas][colunas];
    int i = 0, j = 0;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &campo[i][j]);
        }
    }
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            caminho = caminho + campo[i][j];
        }
    }
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            scanf("%d", &campo[i][j]);
        }
    }
}