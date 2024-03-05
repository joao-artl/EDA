#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void empilha (celula *p, int x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->dado = x;
    ponteiro->prox = p->prox;
    p->prox = ponteiro;
}

int desempilha (celula *p, int *y){
    celula *lixo = p->prox;
    if(lixo==NULL)
        return 0;
    *y = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}
