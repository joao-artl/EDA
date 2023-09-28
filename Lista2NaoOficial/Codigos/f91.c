#include <stdio.h>

int f91(int i){
    int x;
    if(i >= 101){
        i = i - 10;
        return i;
    }
    if(i <= 100){
        i = i + 11;
        x = f91(i);
        return f91(x);
    }
}

int main(){
    int numero, valor;
    scanf("%d", &numero);
    while(numero != 0){
        valor = f91(numero);
        printf("f91(%d) = %d\n", numero, valor);
        scanf("%d", &numero);
    }
    return 0;
}