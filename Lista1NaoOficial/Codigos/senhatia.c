#include <stdio.h>

int main(){
    int N, M, A, K, i;
    scanf("%d %d %d %d", &N, &M, &A, &K);
    char senha[1000];
    int CriterioM = 0, CriterioA = 0, CriterioK = 0;
    scanf("%s", senha);
    for(i = 0; senha[i] != '\0'; i++){
        if (senha[i] >= 'a' && senha[i] <= 'z'){
        CriterioM++;
        }
        if (senha[i] >= 'A' && senha[i] <= 'Z'){
        CriterioA++;
        }
        if (senha[i] >= '0' && senha[i] <= '9'){
        CriterioK++;
        }
    }
    if(i >= N && CriterioM >= M && CriterioA >= A && CriterioK >= K){
        printf("Ok =/\n");
    }
    else{
        printf("Ufa :)\n");
    }
    return 0;
}