#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void merge(Item *v, int inicio, int r1, int r2){
    Item *v2 = malloc(sizeof(Item)*(r2-inicio +1));
    int k = 0;
    int i = inicio;
    int j = r1+1;
    while(i <= r1 && j <= r2){
        if(lessEq(v[i],v[j])){
            v2[k++] = v[i++];
        }
        else{
            v2[k++] = v[j++];
        }
    }
    while(i <= r1){
        v2[k++] = v[i++];
    }
    while(j <= r2){
        v2[k++] = v[j++];
    }
    k = 0;
    for(i = inicio; i <= r2; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, int inicio, int fim){
    if(inicio >= fim){
        return;
    }
    int meio = (fim + inicio)/2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio+1, fim);
    merge(v, inicio, meio, fim);
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