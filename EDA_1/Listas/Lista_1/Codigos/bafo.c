#include <stdio.h>

int main(){
    int A, B, totalA = 0, totalB = 0, rodada, Nrodada = 1;
    scanf("%d", &rodada);
    while (rodada != 0){
        for(int i = 0; i < rodada; i++){
            scanf("%d %d", &A, &B);
            totalA = totalA + A;
            totalB = totalB + B;
        }
        if(totalA > totalB){
            printf("Teste %d\n", Nrodada);
            printf("Aldo\n");
            printf("\n");
        }
        else{
            printf("Teste %d\n", Nrodada);
            printf("Beto\n");
            printf("\n");
        }
        totalA = 0;
        totalB = 0;
        Nrodada++;
        scanf("%d", &rodada);
    }
    return 0;
}