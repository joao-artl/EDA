#include <stdio.h>

int main(){
    int tamanho;
    scanf("%d", &tamanho);
    int matriz1[tamanho][tamanho], matriz2[tamanho][tamanho], matrizResultado[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            matrizResultado[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("%d ", matrizResultado[i][j]);
        }
        printf("\n");
    }
    return 0;
}