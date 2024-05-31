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
    celula* lixo = p->prox;
    numero = lixo->dado;
    p->prox = lixo->prox;
    free(lixo);
    return numero;
}

void pos_ordem (no *raiz){
    no* atual = raiz;
    celula* pilha = cria_pilha();

    while(atual!=NULL || isPilhaVazia(pilha)==1){
        if(atual!=NULL){
            empilha(pilha, atual);
            atual = atual->esq;
        }else{
            no* temp = pilha->prox->dado->dir;
            if(temp==NULL){
                temp = desempilha(pilha);
                printf("%d ", temp->dado);
                
                while(isPilhaVazia(pilha)==1 && temp==pilha->prox->dado->dir){
                    temp = desempilha(pilha);
                    printf("%d ", temp->dado);
                }
            }else{
                atual = temp;
            }
        }
    }
}