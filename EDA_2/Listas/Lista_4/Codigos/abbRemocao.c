#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no* remove_antecessor(no **r){
    no *p = *r, *q = p->esq;
    if(q->dir == NULL){
        p->esq = q->esq;
        return q;
    }
    while(q->dir != NULL){
        p = q;
        q = q->dir;
    }
    p->dir = q->esq;
    return q;
}

no *remover(no *r, int x) {
    if(r == NULL){
        return NULL;
    }
    if(x < r->chave){
        r->esq = remover(r->esq, x);
    }
    else if(x > r->chave){
        r->dir = remover(r->dir, x);
    }
    else{ 
        if(r->esq == NULL && r->dir == NULL) {
            free(r);
            return NULL;
        } 
        else if(r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } 
        else if(r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        } 
        else{
            no *temp = remove_antecessor(&r);
            r->chave = temp->chave;
            free(temp);
        }
    }
    return r;
}