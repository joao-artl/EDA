#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int desenfileira (celula *f, int *y){
    if (f->prox != NULL)
    {
        *y = f->prox->dado;
        f->prox = f->prox->prox;
        return 1;
    }
    return 0;
}