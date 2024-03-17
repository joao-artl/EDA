#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

celula *cria_fila(){
    celula *novo = malloc(sizeof(celula));
    novo->prox=novo;
    return novo;
}

celula *enfileira(celula *fila, int x){
    celula *ponteiro = malloc(sizeof(celula));
    ponteiro->prox = fila->prox;
    fila->prox = ponteiro;
    fila->dado = x;
    return ponteiro;
}

int desenfileira (celula *f ){
    int numero = 0;
    celula *tira = f->prox;
    if(f->prox==f)
        return 0;
    
    else{
        numero = tira->dado;
        f->prox = tira->prox;
	    free(tira);
        return numero;
    }
}

int main(){
    int cartas, numero = 0;
    int i = 0, cont = 0;
    celula *fila;
    fila = cria_fila();

    scanf("%d", &cartas);

    for(i = 1; i <= cartas; i++){
        fila = enfileira(fila, i);
    }

    printf("Cartas descartadas:");
    cont = 1;
    for(cont = cartas; cont >= 1; cont--){
        if(cont > 2){
            printf(" %d,", desenfileira(fila));
        numero = desenfileira(fila);
        fila = enfileira(fila, numero);
        }
        if(cont == 2)
            printf(" %d\n", desenfileira(fila));
        if(cont == 1){
            printf("Carta restante:");
            printf(" %d\n", desenfileira(fila));
        }
    }
    return 0;
}