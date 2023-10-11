#include <stdio.h>

int somadigitos(long long int i, int soma){
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
    long long int numero, soma = 0;
    scanf("%lld", &numero);
    soma = somadigitos(numero, soma);
    printf("%lld\n", soma);
    return 0;
}
