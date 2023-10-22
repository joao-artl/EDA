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
    long long int numero;
    scanf("%lld", &numero);
    while (numero != 0){
        int contador = 0, i = 0;
        long long int resultado = numero;
        while (resultado > 9){
            resultado = somadigitos(resultado, i);
            if(resultado % 9 == 0){
                contador++;
            }
        }
        if(numero == 9){
            printf("9 is a multiple of 9 and has 9-degree 1.");
        }
        else if(resultado % 9 == 0){
            printf("%d is a multiple of 9 and has 9-degree %d.", numero, contador);
        }
        else{
            printf("%d is not a multiple of 9.", numero);
        }
        scanf("%lld", &numero);
    }
    return 0;
}