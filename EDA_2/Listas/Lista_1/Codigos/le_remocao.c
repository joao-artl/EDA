#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
	int dado;
	struct celula *prox;
} celula;

celula *posicao(celula * le, int x){
  celula *elemento = le;
  for (elemento = elemento; elemento -> prox != NULL; elemento = elemento -> prox){
    if (elemento -> prox -> dado == x){
      return elemento;
    }
  }
  return elemento;
}


int remove_depois(celula *p){
  if (p->prox!=NULL){
    celula *prox_p = p->prox;
    int dado_removido = prox_p->dado;
    p->prox = prox_p->prox;
    free(prox_p);
    return dado_removido;
  } 
  else{
    return 1;
  }
}

void remove_elemento(celula *le, int x){
  if(le->prox!=NULL){
    celula *antes_x = posicao(le, x);
    celula *x_encontrado = antes_x->prox;
    antes_x->prox = x_encontrado->prox;
    free(x_encontrado);
  }
  
}

void remove_todos_elementos(celula *le, int x){
  celula *anterior = le;
  if(le->prox!=NULL){
    for (celula *elemento = le->prox; elemento != NULL; elemento = elemento->prox){
      if(elemento->dado == x){
        anterior->prox = elemento->prox;
      }
      anterior = elemento;
    }
  }
}