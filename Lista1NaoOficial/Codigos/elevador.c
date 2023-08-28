#include <stdio.h>

int main(){
    int capacidade, saida, entrada, leituras, pessoas = 0, detector = 0;
    scanf("%d %d", &leituras, &capacidade);
    for(int i = 0; i < leituras; i++){
        scanf("%d %d", &saida, &entrada);
        pessoas = pessoas + entrada - saida;
        if(pessoas > capacidade){
            detector++;
        }
    }
    if (detector == 0)
    {
        printf("N\n");
    }
    else{
        printf("S\n");
    }

}