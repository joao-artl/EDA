#include <stdio.h>

int main(){
    int vetor[10000], tamanho, menor, indiceMenor;
    scanf("%d", &tamanho);
    scanf("%d", &vetor[0]);
    menor = vetor[0];
    indiceMenor = 0;
    for(int i = 1; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < tamanho; i++){
        if(menor > vetor[i]){
            menor = vetor[i];
            indiceMenor = i;
        }
    }
    printf("%d\n", indiceMenor);
    return 0;
}