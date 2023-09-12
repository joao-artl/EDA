#include <stdio.h>

int main(){
    int A,B,C;
    scanf("%d %d %d", &A, &B, &C);
    if(A != B && B == C){
        printf("A\n");
    }
    if(B != A && A == C){
        printf("B\n");
    }
    if(C != B && B == A){
        printf("C\n");
    }
        if(A == B && B == C && A == C){
        printf("empate\n");
    }
}