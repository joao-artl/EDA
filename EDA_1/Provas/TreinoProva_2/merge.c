#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void merge(Item *v, int l, int m, int r){
    Item *v2 = malloc(sizeof(Item)*(r-l +1));
    int k = 0;
    int i = l;
    int j = m+1;
    while(i <= m && j <= r){
        if(lessEq(v[i],v[j])){
            v2[k++] = v[i++];
        }
        else{
            v2[k++] = v[j++];
        }
    }
    while(i <= m){
        v2[k++] = v[i++];
    }
    while(j <= r){
        v2[k++] = v[j++];
    }
    k = 0;
    for(i = l; i <= r; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, int l, int r){
    if(l >= r){
        return;
    }
    int meio = (r + l)/2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    int j, tam;
    scanf("%d", &tam);
    Item numeros[tam];
    for(int i = 0; i < tam; i++){
        scanf("%d", &numeros[i]);
    }
    mergeSort(numeros, 0, tam-1);
    for(j = 0; j < tam-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[tam-1]);
    return 0;
}