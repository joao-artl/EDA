#include <stdio.h>

int main (){
    char string[1001];
    int tamanho;
    scanf("%s", &string);
    for(tamanho = 0;string[tamanho]!= '\0';tamanho++);
    printf("%d\n", tamanho);
    
}