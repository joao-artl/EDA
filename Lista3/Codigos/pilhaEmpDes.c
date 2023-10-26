#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

void empilha(celula *p, int x)
{
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    celula *temp;
    if (p->prox != NULL)
    {
        temp = p->prox;
        p->prox = nova;
        nova->prox = temp;
    }
    else{
        p->prox = nova;
    }
}

int desempilha(celula *p, int *y)
{
    if (p->prox != NULL)
    {
        *y = p->prox->dado;
        p->prox = p->prox->prox;
        return 1;
    }
    return 0;
}