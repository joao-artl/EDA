#include <stdio.h>

int main(){
    int Vetor[1000000], i, tamanho;
    scanf("%d", &tamanho);
    for(i = 0; i < tamanho; i++){
        scanf("%d", &Vetor[i]);
    }
    for(i = 0; i < tamanho; i++){
        if(Vetor[i] % 2 == 0){
            printf("%d " , Vetor[i]);
        }
    }
    printf("\n");
    for(i = 0; i < tamanho; i++){
        if(Vetor[i] % 2 != 0){
            printf("%d ", Vetor[i]);
        }
    }
    printf("\n");
    return 0;
}