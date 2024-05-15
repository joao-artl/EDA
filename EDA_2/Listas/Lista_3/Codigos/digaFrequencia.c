#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a.v == b.v ? a.k < b.k : a.v < b.v)
#define exch(A,B){Item T = A; A = B; B = T;}
#define cmpexch(A,B){if(less(B,A))exch(A,B)}

typedef struct {
    int k, v;
} Item;

int partition(Item *v, int l, int r){
    Item pivot = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivot))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Item *v, int l, int r){
    if (r - l <= 32){
        return;
    }
    cmpexch(v[(r+l)/2], v[r]);
    cmpexch(v[l], v[(r+l)/2]);
    cmpexch(v[r], v[(r+l)/2]);

    int m = partition(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Item *v, int l, int r){
    for (int i = l + 1, j; i <= r; i++)
    {
        Item t = v[i];
        for (j = i; j > 0 && less(t, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = t;
    }
}

void quicksort(Item *v, int l, int r){
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

int main(){
    char s[1010];
    while (scanf(" %s", s) != EOF){
        int frequencia[130];
        Item v[130];
        for(int i = 0; i < 130; i++){
            frequencia[i] = 0;
        }
        for(int i = 0; s[i] != '\0'; i++){
            frequencia[s[i]]++;
        }
        int k = 0;
        for(int i = 0; i < 130; i++){
            if (frequencia[i]){
                v[k++] = (Item) {.k = i, .v=frequencia[i]};
            }
        }
        quicksort(v, 0, k-1);
        for(int i = 0; i < k; i++){
            printf("%d %d\n", v[i].k, v[i].v);
        }
        printf("\n");
    }
    return 0;
}