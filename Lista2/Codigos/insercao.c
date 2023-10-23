#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *p = malloc(sizeof(celula));
    p->dado = x;
    p->prox = le->prox;
    le->prox = p;
}

void insere_antes (celula *le, int x, int y){
    celula *p = le->prox;
    celula *novo = malloc (sizeof (celula));
    novo->dado = x;
    if(le->prox != NULL){
        if(le->prox == y){
            insere_inicio(p, x);
            return;
        }
        while(p->prox != NULL){
            if(p->prox->dado == y){
            novo->prox = p->prox;
            p->prox = novo;
            return;
            }
            p = p->prox;
        }
        p->prox = novo;
        return;
    }
    p->dado = novo->dado;
    return;
}