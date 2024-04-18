#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r){
    int *v2 = malloc(sizeof(int)*(r-l+1));
    int k = 0;
    int i = l;
    int j = m+1;
    while(i <= m && j <= r){
        if(v[i] >= v[j]){
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

void mergeSort(int *v, int l, int r){
    if(l >= r){
        return;
    }
    int meio = (l + r) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio+1, r);
    merge(v, l, meio, r);
}

int main(){
    int n;
    scanf("%d", &n);
    int v[10];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    mergeSort(v,0,n);
    for(int i = 1; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("%d\n", v[n]);
    return 0;
}