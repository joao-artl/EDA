#include <stdio.h>

int main(){
    char palavra[1000];
    char inverso[1000];
    scanf("%s", palavra);
    int i, tamanho, j;
    for(tamanho = 0; palavra[tamanho] != '\0'; tamanho++);
    for(i = tamanho-1, j = 0; i >= 0; i--, j++){
        inverso[j] = palavra[i];
    }
    inverso[j] = '\0';
    printf("%s\n", inverso);
    return 0;
}