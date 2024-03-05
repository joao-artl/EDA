#include <stdio.h>

int pares(char palavra[], int i, int p){
    if(palavra[i+2] != '\0'){
        if(palavra[i] == palavra[i+2]){
            p++;
            i++;
            return pares(palavra, i, p);
        }
        else{
            i++;
            return pares(palavra, i, p);
        }
    }
    else{
        return p;
    }
}

int main(){
    char palavra[1001];
    scanf("%s", palavra);
    int i = 0, j, p = 0;
    j = pares(palavra, i, p);
    printf("%d\n", j);
    return 0;
}