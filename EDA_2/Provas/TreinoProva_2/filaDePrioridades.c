#include <stdio.h>
#include <stdlib.h>

typedef struct FP{
    int *chaves;
    int n, tam;
} FP;

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

FP *cria_fila(int tam){
    FP *fp = malloc(sizeof(FP));
    fp->chaves = malloc(tam * sizeof(int));
    fp-> n = 0;
    fp -> tam = tam;
    return fp;
}

void sobe_no_heap(FP *fp){
    int k = fp->n-1;
    int pai = (k-1)/2;
    while(k > 0 && fp->chaves[pai] < fp->chaves[k]){
        troca(&fp->chaves[pai], &fp->chaves[k]);
        k = pai;
        pai = (k-1)/2;
    }
}

void insere(FP *fp, int x){
    if(fp->n+1 >= fp->tam){
        fp->tam *= 2;
        fp->chaves = realloc(fp->chaves,fp->tam);
    }
    fp->chaves[fp->n] = x;
    fp->n++;
    sobe_no_heap(fp);
}

int maior(FP *fp, int k, int e, int d, int *m){
    int valor = fp->chaves[k];
    if(e < fp->n){
        if(fp->chaves[e] > fp->chaves[k]){
            *m = e;
            valor = fp->chaves[e];
        }
        if(d < fp->n && fp->chaves[d] > valor){
            *m = d;
            valor = fp->chaves[d];
        }
    }
    return valor;
}

int extrai_maximo(FP *fp){
    if(fp->n > 0){
        fp->n--;
        troca(&fp->chaves[0], &fp->chaves[fp->n]);
        int k = 0, esq = 2*k+1, dir = 2*k+2, m;
        while(maior(fp, k, esq, dir, &m) > fp->chaves[k]){
            troca(&fp->chaves[k], &fp->chaves[m]);
            k = m;
            esq = 2*k+1; 
            dir = 2*k+2;
        }
        return fp->chaves[fp->n];
    }
    return 0;
}