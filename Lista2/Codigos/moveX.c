#include <stdio.h>

int *p;
// Conta o numero de x e salva palavra sem x
int contaX(int numeroX, char palavra[], int tamanho, char novaPalavra[], int i){
    if(palavra[tamanho] != '\0'){
        if(palavra[tamanho] == 'x'){
            numeroX++;
            tamanho++;
            return contaX(numeroX, palavra, tamanho, novaPalavra, i);
        }
        else{
            novaPalavra[i] = palavra[tamanho];
            tamanho++;
            i++;
            novaPalavra[i] ='\0';
            return contaX(numeroX, palavra, tamanho, novaPalavra, i);
        }
    }
    p = tamanho;
    return numeroX;
}

void imprimeX(int numeroX){
    if(numeroX != 0){
        printf("x");
        numeroX--;
        imprimeX(numeroX);
    }
    return;
}

int main(){
    int numeroX = 0, tamanho = 0, i = 0;
    char palavra[150], novaPalavra[150];
    scanf("%s", palavra);
    numeroX = contaX(numeroX, palavra, tamanho, novaPalavra, i);
    printf("%s",novaPalavra);
    imprimeX(numeroX);
    printf("\n");
    return 0;

}