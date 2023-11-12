#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int num[], int tam){
    int i, j;
    int troca = -1;
    for (i = 0; i < tam - 1; i++) {
        troca = 0;
        for (j = 0; j < tam - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                swap(&num[j], &num[j + 1]);
                troca = 1;
            }
        }
        if (troca == 0){
            break;
        }
    }
}

int main(){
    int numeros[1001], j, i = 0;
    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }
    bubbleSort(numeros, i);
    for(j = 0; j < i-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[i-1]);
    return 0;
}