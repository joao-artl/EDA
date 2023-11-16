#include <stdio.h>
#include <stdlib.h>

void merge(long int arr[], long int l, long int m, long int r)
{
    long int i, j, k;
    long int n1 = m - l + 1;
    long int n2 = r - m;
    long int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(long int arr[], long int l, long int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}

int main(){
    long int j, tam;
    scanf("%ld", &tam);
    long int numeros[tam+3];
    for(int i = 0; i < tam; i++){
        scanf("%ld", &numeros[i]);
    }
    mergeSort(numeros, 0, tam-1);
    for(j = 0; j < tam-1; j++){
        printf("%ld ", numeros[j]);
    }
    printf("%ld\n", numeros[tam-1]);
    return 0;
}