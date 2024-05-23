#include <stdio.h>
#include <string.h>

int posicao(char* str, int n, char key) {
    for(int i = 0; i < n; i++){
        if (str[i] == key) return i;
    }
    return -1;
}
void posOrdem(char* pre, char* in, int n) {
    if(n == 0){
        return;
    }
    char root = pre[0];
    int pos = posicao(in, n, root);
    posOrdem(pre + 1, in, pos);
    posOrdem(pre + pos + 1, in + pos + 1, n - pos - 1);
    printf("%c", root);
}

int main(){
    int C, N;
    char pre[53], in[53];
    scanf("%d", &C);
    while(C--){
        scanf("%d %s %s", &N, pre, in);
        posOrdem(pre, in, N);
        printf("\n");
    }
    return 0;
}
