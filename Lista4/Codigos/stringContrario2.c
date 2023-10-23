#include <stdio.h>

int tamanhoString(char palavra[], int i){
    if(palavra[i+1] != '\0'){
        i++;
        return tamanhoString(palavra, i);
    }
    else{
        i++;
        return i;
    }
}

void inverteString(char palavra[], char invertida[], int tamanho, int i){
    if(tamanho >= 0){
        invertida[i] = palavra[tamanho];
        i++;
        tamanho--;
        return inverteString(palavra, invertida, tamanho, i);
    }
    else{
        return;
    }
}

int main(){
    char palavra[1000], palavraInvertida[1000];
    int i = 0, tamanho;
    scanf("%s", palavra);
    tamanho = tamanhoString(palavra, i);
    tamanho--;
    inverteString(palavra, palavraInvertida, tamanho, i);
    palavraInvertida[tamanho+1] = '\0';
    printf("%s\n", palavraInvertida);
}