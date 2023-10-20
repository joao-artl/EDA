#include <stdio.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

celula *p;

celula *busca (celula *le, int x){

    while (le -> dado != x && le -> prox != NULL){
        le = le -> prox;
    }
    if(le -> prox == NULL){
        p = NULL;
    }
    if(le -> dado == x){
        p = le;
    }
    return p;
}

celula *busca_rec (celula *le, int x){
    
    if(le -> dado != x && le -> prox != NULL){
        return busca_rec(le -> prox, x);
    }
    if(le -> dado == x){
        p = le;
        return p;
    }
    if(le -> prox == NULL){
        p = NULL;
        return p;
    }
}