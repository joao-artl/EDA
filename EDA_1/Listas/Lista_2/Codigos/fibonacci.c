#include <stdio.h>

unsigned long int f[100];

long int fibonacci (int n){
    if(n <= 2){
        f[n] = 1;
    }
    else if(f[n] == NULL){
        f[n] = fibonacci(n-1) + fibonacci(n-2);
    }
    return f[n];

}

/*int main(){
    int numero;
    scanf("%d", &numero);
    unsigned long int resultado;
    resultado = fibonacci(numero);
    printf("%lu", resultado);
    return 0;

}*/