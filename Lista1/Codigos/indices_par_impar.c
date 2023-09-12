#include <stdio.h>

int main(){
    int vetor[10000], i, tamanho, vetorpar[10000], tamanhoPar = 0 , vetorimpar[10000], tamanhoImpar = 0;
    scanf("%d", &tamanho);

    for(i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    for(i = 0; i < tamanho; i++ ){
        if(vetor[i] % 2 == 0){
            vetorpar[tamanhoPar] = i;
            tamanhoPar++;
        }
        if(vetor[i] % 2 != 0){
            vetorimpar[tamanhoImpar] = i;
            tamanhoImpar++;
        }
    }
    for(i = 0; i < tamanhoPar; i++){
        printf("%d ", vetorpar[i]);
    }
    printf("\n");
    for(i = 0; i < tamanhoImpar; i++){
        printf("%d ", vetorimpar[i]);
    }
    printf("\n");
    return 0;
}