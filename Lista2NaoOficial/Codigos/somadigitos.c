#include <stdio.h>

int somadigitos(int i, int soma){
    soma = soma + i % 10;
    if(i / 10 >= 0 && i / 10 < 10){
        soma = soma + i / 10;
        return soma;
    }
    else{
        i = i / 10;
        return somadigitos(i, soma);
    }
}

int main(){
    int numero, soma = 0;
    scanf("%d", &numero);
    soma = somadigitos(numero, soma);
    printf("%d\n", soma);
    return 0;
}