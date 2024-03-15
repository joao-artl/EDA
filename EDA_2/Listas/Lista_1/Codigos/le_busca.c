#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
    int dado;
    struct celula *prox;
} celula;

celula *achou;

celula *busca (celula *le, int x){
    while (le->prox != NULL && le->dado != x)
    {
        le = le->prox;
    }
    if(le->prox == NULL){
        achou = NULL;
    }
    if(le->dado == x){
        achou = le;
    }
    return achou;
}
celula *busca_rec(celula *le, int x){
    if(le->prox != NULL && le->dado != x)
    {
        busca_rec(le->prox,x);
    }
    if(le->prox == NULL){
        achou = NULL;
    }
    if(le->dado == x){
        achou = le;
    }
    return achou;
}