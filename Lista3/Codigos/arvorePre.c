#include <stdio.h>

typedef struct no {
int dado;
struct no *esq, *dir;
} no;

void pre_ordem (no *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        pos_ordem(raiz->esq);
        pos_ordem(raiz->dir);
        
    }
}