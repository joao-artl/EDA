#include <stdio.h>

char* ponteiro;

void trocaX(char palavra[], int i){
    if(palavra[i] != '\0'){
    ponteiro = palavra;

}

void trocaX(char palavra[], int i){
    if(palavra[i] == 'x'){
        palavra[i] = 'y';
        i++;
        trocaX(palavra, i);
    }
    else{
        if(palavra[i] != '\0'){
        ponteiro = palavra;
    }
        else{
        i++;
        trocaX(palavra, i);
        }
    }
}

int main(){
    char palavra[1000];
    int i = 0;
    scanf("%s", palavra);
    trocaX(palavra, i);
    printf("%s", *&ponteiro);
    return 0;
}