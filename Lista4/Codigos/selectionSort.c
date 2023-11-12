#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int num[], int tam)
{
    int i, j, min_idx;
    for (i = 0; i < tam-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < tam; j++)
          if (num[j] < num[min_idx])
            min_idx = j;
           if(min_idx != i)
            swap(&num[min_idx], &num[i]);
    }
}

int main(){
    int numeros[1001], j, i = 0;
    while(scanf("%d", &numeros[i]) != EOF){
        i++;
    }
    selectionSort(numeros, i);
    for(j = 0; j < i-1; j++){
        printf("%d ", numeros[j]);
    }
    printf("%d\n", numeros[i-1]);
    return 0;
}