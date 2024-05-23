#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int altura(no *r) {
    if (r == NULL)
        return 0;
    int esqAltura = altura(r->esq);
    int dirAltura = altura(r->dir);
    if (esqAltura > dirAltura)
        return esqAltura + 1;
    else
        return dirAltura + 1;
}