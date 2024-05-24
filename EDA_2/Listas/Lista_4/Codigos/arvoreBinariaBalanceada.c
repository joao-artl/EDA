#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no* newNode(int chave){
   no* node = (no*) malloc(sizeof(no));
   node->chave = chave;
   node->esq = NULL;
   node->dir = NULL;
   return node;
}

int height(no* node){
   if(node == NULL){
      return 0;
   }
   int esqHeight = height(node->esq);
   int dirHeight = height(node->dir);
   if(esqHeight == -1 || dirHeight == -1 || abs(esqHeight - dirHeight) > 1){
      return -1; 
   }
   return 1 + (esqHeight > dirHeight ? esqHeight : dirHeight);
}

int isBalanced(no* r){
    return height(r) != -1;
}

int main(){
   int N;
   scanf("%d", &N);
   if(N == 0){
      printf("Sim\n");
      return 0;
   }
   no*nodes[N];
   for(int i = 0; i < N; i++){
      nodes[i] = newNode(i + 1);
   }

    for(int i = 1; i < N; i++){
      int parent;
      scanf("%d", &parent);
      parent--;
      if(nodes[parent]->esq == NULL){
            nodes[parent]->esq = nodes[i];
      }
      else{
         nodes[parent]->dir = nodes[i];
      }
   }
   if(isBalanced(nodes[0])){
      printf("Sim\n");
   } 
   else {
      printf("Nao\n");
   }
   return 0;
}