#include <stdio.h>
#include <stdlib.h>

typedef long int Item;
#define Key(A) (A)
#define less(A,B) (Key(A) < Key (B))
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}
#define lessEq(A,B) (Key(A) <= Key (B))

void merge(Item *v, long int l, long int m, long int r){
    Item *v2 = malloc(sizeof(Item)*(r-l+1));
    long int k = 0;
    long int i = l;
    long int j = m + 1;
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
    for(long int z = l; z <= r; z++){
        v[z] = v2[k++];
    }
    free(v2);
}

void mergeSort(Item *v, long int l, long int r){
    if(l >= r){
        return;
    }
    long int m = (r + l) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

int main(){
    long int n;
    scanf("%ld", &n);
    long int v[n+1];
    for(long int i = 0; i < n; i++){
        scanf("%ld", &v[i]);
    }
    mergeSort(v,0,n);
    for(long int i = 0; i < n-1; i++){
        printf("%ld ", v[i]);
    }
    printf("%ld\n", v[n-1]);
    return 0;
}