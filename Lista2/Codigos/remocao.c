#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

int remove_depois (celula *p){
    celula *lista =
}

void remove_elemento (celula *le, int x){
    celula *p = le->prox;

    p->prox = p->prox->prox;
    return;
}

void remove_todos_elementos (celula *le, int x){
    celula *p = le->prox;
    while (p != NULL){
        
    }
    return;
}