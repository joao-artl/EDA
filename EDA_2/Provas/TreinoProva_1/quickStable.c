#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Item;

#define Key(A) (A.value)
#define OriginalIndex(A) (A.index)
#define less(A,B) (Key(A) < Key(B) || (Key(A) == Key(B) && OriginalIndex(A) < OriginalIndex(B)))
#define exch(A,B) {Item T = A; A = B; B = T;}
#define cmpexch(A,B) {if (less(B,A)) exch(A,B);}

int separa(Item *v, int l, int r) {
    Item c = v[r];  // pivô
    int j = l;
    for (int k = l; k < r; k++) {
        if (less(v[k], c)) {
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quickSort(Item *v, int l, int r) {
    if (r <= l) {  // condição de parada
        return;
    }
    int j = separa(v, l, r);  // posição do pivô
    quickSort(v, l, j - 1);  // números menores que o pivô
    quickSort(v, j + 1, r);  // números maiores que o pivô
}

int main() {
    int tam;
    scanf("%d", &tam);
    Item *numeros = malloc(tam * sizeof(Item));
    for (int i = 0; i < tam; i++) {
        scanf("%d", &numeros[i].value);
        numeros[i].index = i;
    }
    quickSort(numeros, 0, tam - 1);
    for (int j = 0; j < tam; j++) {
        if (j > 0) printf(" ");
        printf("%d", numeros[j].value);
    }
    printf("\n");
    free(numeros);
    return 0;
}