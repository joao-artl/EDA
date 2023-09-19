#include <stdio.h>

int main(){
    int aero, voo, A, B, vetor[10000], maior, i, n = 0;
    scanf("%d %d", &aero, &voo);
 
 while ( aero != 0 && voo != 0 ) {
  for (i=0; i <= aero; i++) {
   vetor[i] = 0;
  }
 
  for (i=0; i < voo; i++) {
   scanf("%d %d", &A, &B);
   vetor[A]++;
   vetor[B]++;
  }
 
  maior = 0;
  for (i=1; i <= aero; i++) {
   if (vetor[i] >= maior) {
    maior = vetor[i];
   }
  }
 
  n++;
  printf("Teste %d\n", n);
 
  for (i=0; i <= aero; i++) {
   if (vetor[i] == maior) {
    printf("%d ", i);
   }
  }
 
    printf("\n\n");
 
    scanf("%d %d", &aero, &voo);
    }
    return 0;
}