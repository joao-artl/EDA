#include <stdio.h>
#include <stdlib.h>

void insertionSort(int num[], int tam)
{
    int i, key, j;
    for (i = 1; i < tam; i++) {
        key = num[i];
        j = i - 1;
        while (j >= 0 && num[j] > key) {
            num[j + 1] = num[j];
            j = j - 1;
        }
        num[j + 1] = key;
    }
}

int main(){
    int numeros[50001], j, i = 0;
    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }
    insertionSort(numeros, i);
    for(j = 0; j < i-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[i-1]);
    return 0;
}