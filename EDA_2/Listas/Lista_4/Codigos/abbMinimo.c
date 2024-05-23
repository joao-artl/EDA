#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *minimo (no *r){
    if(r == NULL){
        return r;
    }
    no *max = r;
    while(max->esq != NULL){
        max = max->esq;
    }
    return max;
}