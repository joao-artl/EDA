#include <stdio.h>

int main(){
    int tam, x[10001];
    long long int soma = 0;
    scanf("%d", &tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &x[i]);
        soma = soma + x[i];
    }
    int contador = 0;
    long long int media = soma/tam;
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