#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void insertionSortH(Item *v, int inicio, int fim, int salto){
    for(int i = inicio+salto; i<=fim; i++){
        int j = i;
        Item tmp = v[i];
        while(j >= inicio+salto && less(tmp, v[j-salto])){
            v[j] = v[j-salto]; j -= salto;
        }
        v[j] = tmp;
    }
}

void shellSort(Item *v, int inicio, int fim){
    int salto;
    for(salto = 1; salto<=(fim-inicio)/9; salto = 3*salto+1){
        for(; salto > 0; salto = salto / 3){
            insertionSortH(v,inicio,fim,salto);
        }
    }
}

int main(){
    int j, tam;
    scanf("%d", &tam);
    Item numeros[tam];
    for(int i = 0; i < tam; i++){
        scanf("%d", &numeros[i]);
    }
    shellSort(numeros, 0, tam-1);
    for(j = 0; j < tam-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[tam-1]);
    return 0;
}