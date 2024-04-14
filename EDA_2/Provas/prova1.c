#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

// *a cria o ponteiro a e &a acessa o endereço em a
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *v, int l, int r){ //tbm conhecido como separa ou partição
    int pivo = v[r]; // pivô
    int j = l;
    for(int k = l; k < r; k++){
        if(v[k] <= pivo){
            swap(v[k],v[j]);
            j++;
        }
    }
    swap(v[j],v[r]);
    return j;
}

void quickSort(int *v, int l, int r){
    int j;
    if(r <= l){
        return;
    }
    // coloca a mediana de 3 elementos na ultima posição
    cmpexch(v[(r+l)/2], v[r]);
    cmpexch(v[l], v[(r+l)/2]);
    cmpexch(v[r], v[(r+l)/2]);
    j = partition(v,l,r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

void merge(int *v, int l, int m, int r){
    int *v2 = malloc(sizeof(int)*(r-l+1));
    int k = 0;
    int i = l;
    int j = m+1;
    while(i <= m && j <= r){
        if(v[i] <= v[j]){
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
    int k = 0;
    for(i = l; i <= r; i++){
        v[i] = v2[k++];
    }
    free(v2);
}

void mergeSort(int *v, int l, int r){
    if(l >= r){
        return;
    }
    int meio = (l + r) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}