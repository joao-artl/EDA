#include <stdio.h>

int main(){
    int tam, soma = 0, x[10001];
    scanf("%d", &tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &x[i]);
        soma = soma + x[i];
    }
    int contador = 0;
    int media = soma/tam;
    for(int j = 0; j < tam; j++){
        if(x[j] > media){
            printf("%d ", x[j]);
            contador++;
        }
    }
    if(contador == 0){
        printf("0");
    }
    printf("\n");
    return 0;
}