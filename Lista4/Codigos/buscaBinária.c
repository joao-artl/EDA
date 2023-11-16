#include <stdio.h>
#include <stdlib.h>

int local;
int buscaBinaria(int vetor[], int inicio, int fim, int numero){
    if(inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == numero){
            return meio;
        }
        if (vetor[meio] < numero){
            local = meio + 1;
            return buscaBinaria(vetor, meio+1, fim, numero);
        }
        else{
            local = meio;
            return buscaBinaria(vetor, inicio, meio-1, numero);
        }
    }
    return -1;
}

int main(){
    int tamVet, tamSearch;
    scanf("%d %d", &tamVet, &tamSearch);
    int vetor[tamVet], numero, index;
    for(int i = 0; i < tamVet; i++){
        scanf("%d", &vetor[i]);
    }
    for(int j = 0; j < tamSearch; j++){
        scanf("%d", &numero);
        index = buscaBinaria(vetor, 0, tamVet-1, numero);
        if(index != -1){
            printf("%d\n", index);
        }
        else{
            printf("%d\n", local);
        }
    }
    return 0;
}