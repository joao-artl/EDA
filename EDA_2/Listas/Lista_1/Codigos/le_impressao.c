#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void imprime (celula *le){
    celula *l = le->prox;
    while(l != NULL){
        printf("%d -> ", l->dado);
        l = l->prox;
    }
    printf("NULL\n");
}

void imprime_rec (celula *le){
    celula *l = le->prox;
    if(l != NULL){
        printf("%d -> ", l->dado);
        return imprime_rec(le->prox);
    }
    printf("NULL\n");
    return;
}