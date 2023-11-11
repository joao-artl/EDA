#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void enfileira (celula **f, int x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->prox = (*f)->prox;
    (*f)->prox = ponteiro;
    (*f)->dado = x;
    *f = ponteiro;
}

int desenfileira (celula *f, int *y){
    celula *tira = f->prox;
    if(f->prox==f)
        return 0;
    
    else{
        *y=tira->dado;
        f->prox = tira->prox;
	    free(tira);
        return 1;
    }
}