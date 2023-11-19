#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

int separa(Item *v, int l, int r){
    Item c = v[r]; //pivô
    int j = l;
    for(int k = l; k < r; k++){
        if(lessEq(v[k],c)){
            exch(v[k],v[j]);
            j++;
        } 
    }
    exch(v[j],v[r]);
    return j;
}

void quickSort(Item *v, int l, int r){
    if(r <= l){
        return;
    }
    int j;
    j = separa(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int main(){
    int j, tam;
    scanf("%d", &tam);
    Item numeros[tam];
    for(int i = 0; i < tam; i++){
        scanf("%d", &numeros[i]);
    }
    quickSort(numeros, 0, tam-1);
    for(j = 0; j < tam-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[tam-1]);
    return 0;
}