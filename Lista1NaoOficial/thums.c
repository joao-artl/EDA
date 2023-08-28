#include <stdio.h>

int main(){
    int batidas;
    scanf("%d", &batidas);
    for(int i = 1; i <= batidas; i++){
        if((i % 2) == 0){
            printf("THUMS THUMS THUMS THUMS THUMS THUMS\n");
        }
        else{
            printf("THUMS THUMS THUMS\n");
        }
    }
    return 0;
}