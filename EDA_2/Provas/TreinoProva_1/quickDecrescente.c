#include <stdio.h>
#include <stdlib.h>

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
        if(v[k] >= pivo){
            swap(&v[k],&v[j]);
            j++;
        }
    }
    swap(&v[j],&v[r]);
    return j;
}

void quickSort(int *v, int l, int r){
    int j;
    if(r <= l){
        return;
    }
    j = partition(v,l,r);
    quickSort(v, l, j-1);
    quickSort(v, j+1, r);
}

int main(){
    int n;
    scanf("%d", &n);
    int v[10];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    quickSort(v,0,n);
    for(int i = 1; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n]);
    return 0;
}