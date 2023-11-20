#include <stdio.h>
#include <stdlib.h>

// Macros
typedef int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void selectionRecursivo(Item *v, int l, int r){
    if(l == r) return;
    int min = l;
    for(int i = l+1; i <= r; i++){
        if(less(v[i], v[min])){
            min = i;
        }
    }
    exch(v[min], v[l]);
    selectionRecursivo(v, l+1, r);
}

void selectionIterativo(Item *v, int l, int r){
    for(int i = l; i < r; i++){
        int min = i;
        for(int j = i+1; j <= r; j++){
            if(less(v[j], v[min])){
                min = j;
            }
        }
        exch(v[i], v[min]);
    }
}

void bubbleSort(Item *v, int l, int r){
    for(int i = l; i < r; i++ ){
        for(int j = l; j < r; j++){
            if(less(v[j+1], v[j])){
                exch(v[j+1], v[j]);
            }    
        }
    }
}

void insertionSort(Item *v, int l, int r){
    for(int i = r; i > l; i--){
        cmpexch(v[i-1], v[i]);
    }
    for(int i = l+2; i <= r; i++){
        int j = i; 
        Item tmp = v[j];
        while(less(tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void insertionSortH(Item *v, int l, int r, int h){
    for(int i = l+h; i <=r; i++){
        int j = i;
        Item tmp = v[i];
        while(j >= l+h && less(tmp, v[j-h])){
            v[j] = v[j-h]; j -= h;
        }
        v[j] = tmp;
    }
}

void shellSort(Item *v, int l, int r){
    int h;
    for(h = 1; h <= (r-l)/9; h = 3*h+1);
    for( ; h > 0; h = h/3){
        insertionSortH(v, l, r, h);
    }
}

int partition(Item *v, int l, int r){
    int c = v[r];
    int j = l;
    for(int k = l; k < r; k++){
        if(less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quickSort(Item *v, int l, int r){
    if(r <= l) return;
    int j;
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);
    j = partition(v, l, r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int partitionV2(Item *v, int l, int r){
    int i = l;
    int j = r+1;
    int pivot = v[l];

    while(1){
        while (v[++i] < pivot) if (i == r) break ;
        while (pivot < v[--j]) if (j == l) break ;
            if (i >= j) break;
            exch (v[i], v[j]);
    }
    exch(v[l], v[j]);
    return j;
}

void merge(Item *v, int l, int m, int r){
    int tam = r+1-l;
    Item *aux = malloc(sizeof(Item)*tam);
    int k = 0;
    int i = l;
    int j = m+1;

    while(i <= m && j <= r){
        if(lessEq(v[i], v[j])){
            aux[k++] = v[i++];
        }
        else{
            aux[k++] = v[j++];
        }
    }
    while(i <= m){
        aux[k++] = v[i++];
    }
    while(j <= r){
        aux[k++] = v[j++];
    }
    k = 0;
    for(int i = l; i <= r; i++){
        v[i] = aux[k++];
    }
    free(aux);
}

void mergeSort(Item *v, int l, int r){
    if(l >= r) return;
    int m = (l+r)/2;
    mergeSort(v, l, m);
    mergeSort(v, m+1, r);
    merge(v, l, m, r);
}

int main(){
    return 0;
}