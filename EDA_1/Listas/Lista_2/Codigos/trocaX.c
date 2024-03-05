#include <stdio.h>

char* ponteiro;

void trocaX(char palavra[], int i){
    if(palavra[i] == 'x'){
        palavra[i] = 'y';
        i++;
        trocaX(palavra, i);
    }
    else{
        if(palavra[i] != '\0'){
        i++;
        trocaX(palavra, i);
    }
        else{
        ponteiro = palavra;
        return;
        }
    }
}

int main(){
    char palavra[1001];
    int i = 0;
    scanf("%s", palavra);
    trocaX(palavra, i);
    printf("%s\n", *&ponteiro);
    return 0;
}