#include <stdio.h>

int main(){ 
    int tamanho;
    scanf("%d", &tamanho);
    int vetor[tamanho], numero, contador = 0;
    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }
    scanf("%d", &numero);
    for(int i = 0; i < tamanho; i++){
        if(numero == vetor[i]){
            contador++;
        }
    }
    if(contador == 0){
        printf("nao pertence");
    }
    else{
        printf("pertence");
    }
    return 0;
}