#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void selectionSort(Item *v, int l, int r){
    if(l == r) return;
    int min = l;
    for(int i = l + 1; i <= r; i++ ){
        if(less(v[i], v[min])){
            min = i;
        }
    }
    exch(v[min], v[l]);
    return selectionSort(v, l + 1, r);
}

int main(){
    int j, tam;
    scanf("%d", &tam);
    Item numeros[tam];
    for(int i = 0; i < tam; i++){
        scanf("%d", &numeros[i]);
    }
    selectionSort(numeros, 0, tam-1);
    for(j = 0; j < tam-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[tam-1]);
    return 0;
}