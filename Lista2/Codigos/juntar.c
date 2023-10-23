#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    celula *p = l1->prox;
    
    while(p != NULL){
        l3->prox = p;
        p = p->prox;
    }
    p = l3->prox;
    celula *l = l2->prox;
    while (p != NULL || l != NULL){
        if(p->dado <= l->dado && p->prox->dado >= l->dado){
            l->prox = p->prox;
            p->prox = l;
        }
    }
    
}