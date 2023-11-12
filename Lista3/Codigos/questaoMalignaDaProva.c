#include <stdio.h>
int pilha[1000], t;

void empilha(int i) {
    pilha[t++] = i;
}

int desempilha() {
    return pilha[--t];
}

int pilhavazia () {
   return t <= 0;
}

int espia() {
    return pilha[t-1];
}

int re_ordena(int vet[], int tam) {
    t = 0;
    for(int i = 0, seq = 1; i < tam; i++) {
        if(vet[i] != seq) {
            empilha(vet[i]);
        } 

        else {
            seq++;
            while(!pilhavazia() && espia() == seq) {
                desempilha();
                seq++;
            }
        }
    }

    return pilhavazia();
}

int main() {
    int n;

    scanf("%d", &n);
    while(n != 0) {
        int mobiles[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &mobiles[i]);

        int result = re_ordena(mobiles, n);
        if(result) printf("yes\n");
        else printf("no\n");

        scanf("%d", &n);
    }

return 0;
}