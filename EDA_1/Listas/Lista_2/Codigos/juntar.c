#include <stdio.h>
#define less(A,B) (A < B)

typedef struct celula {
	int dado;
	struct celula *prox;
}celula;

void mescla_listas(celula *l1, celula *l2, celula *l3) {
	celula *fim = l3;
	l1 = l1->prox; l2 = l2->prox;
	while (l1 && l2) {
		if (less(l1->dado, l2->dado)) {
			fim->prox = l1;
			fim = fim->prox;
			l1 = l1->prox;
			fim->prox = NULL;
		} else {
			fim->prox = l2;
			fim = fim->prox;
			l2 = l2->prox;
			fim->prox = NULL;
		}
	}
	if (l1) fim->prox = l1;
	else fim->prox = l2;
}
