#include <stdio.h>
#include <stdlib.h>
typedef struct fila {
    int *dados;
    int N, inicio, fim;
} fila;

int desenfileira (fila *f, int *y){
    if(f->inicio == f->fim)  
    return 0;

    *y = f->dados[f->inicio++];
    if(f->inicio == f->N) f->inicio = 0;
    return 1;
}

int enfileira(fila *f, int x) {
    if((f->fim+1) % f->N == f->inicio)
    return 0;

    f->dados[f->fim++] = x;
    if(f->fim == f->N) f->fim = 0;
    return 1;
}