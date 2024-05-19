#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum cor{Vermelho, Preto};
typedef struct No{
    int chave;
    enum cor cor;
    struct No *esq, *dir;
} No;

No *rotaciona_direita(No *r){
    No *y = r->esq;
    y->cor = r->cor;
    r->cor = Vermelho;
    r->esq = y->dir;
    y->dir = r;
    return y;
}

No *rotaciona_esquerda(No *r){
    No *y = r->dir;
    y->cor = r->cor;
    r->cor = Vermelho;
    r->dir = y->esq;
    y->esq = r;
    return y;
}

void sobe_cor(No *r){
    r->cor = Vermelho;
    r->esq->cor = r->dir->cor = Preto;
}

int ehVermelho(No *r){
    if(r != NULL && r->cor == Vermelho){
        return 1;
    }
    return 0;
}

No *corrige_raiz(No *r){
    if(ehVermelho(r->esq) && ehVermelho( r->esq->esq)){
        r = rotaciona_direita(r);
    }
    if(ehVermelho(r->esq)&& ehVermelho(r->dir)){
        sobe_cor(r);
    }
    if(ehVermelho(r->dir)){
        r = rotaciona_esquerda(r);
    }
    return r;
}

No *insere(No *r, int x){
    if(r == NULL){
        No *novo = calloc(1, sizeof(No));
        novo->chave = x;
        novo->cor = Vermelho;
        return novo;
    }
    else if(x < r->chave){
        r->esq = insere(r->esq, x);
    }
    else if(x > r->chave){
        r->dir = insere(r->dir, x);
    }
    r = corrige_raiz(r);
    return r;
}