#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct celula {
    no *dado;
    struct celula *prox;
} celula;


celula *cria_pilha(){
    celula *topo = malloc(sizeof(celula));
    topo->prox = NULL;
    return topo;
}

int isPilhaVazia(celula *pilha){
    if(pilha->prox == NULL)
        return 0;
    else
        return 1;
}

void empilha (celula *p, no *x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->dado = x;
    ponteiro->prox = p->prox;
    p->prox = ponteiro;
}

no* desempilha (celula *p){
    no* numero;
    celula *lixo = p->prox;
    numero = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return numero;
}

    void pre_ordem (no *raiz){
    if(raiz == NULL)
        return;

    celula *pilha = cria_pilha();
    empilha(pilha, raiz);

    while(isPilhaVazia(pilha) != 0){
        raiz = desempilha(pilha);
        printf("%d ", raiz->dado);
        if(raiz->dir != NULL)
            empilha(pilha, raiz->dir);
        if(raiz->esq != NULL)
            empilha(pilha, raiz->esq);
    }
}