#include <stdio.h>
#include <stdbool.h>

#define MAX_N 2000
#define MAX_J 1000000

bool visitados[MAX_N];
bool vizinhancas[MAX_N][MAX_N];
bool resultado[MAX_J];

void marcar_vizinhos(int local, int N) {
    for (int i = 0; i < N; i++) {
        if (vizinhancas[local][i]) {
            visitados[i] = true;
        }
    }
}

int main() {
    int N, M, J;
    scanf("%d %d %d", &N, &M, &J);
    for (int i = 0; i < N; i++) {
        visitados[i] = false;
        for (int j = 0; j < N; j++) {
            vizinhancas[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        int A, vizinho;
        scanf("%d", &A);
        for (int j = 0; j < A; j++) {
            scanf("%d", &vizinho);
            vizinhancas[i][vizinho] = true;
        }
    }
    for (int i = 0; i < M; i++) {
        int local;
        scanf("%d", &local);
        visitados[local] = true;
        marcar_vizinhos(local, N);
    }
    for (int i = 0; i < J; i++) {
        int local;
        scanf("%d", &local);
        resultado[i] = visitados[local];
    }
    for (int i = 0; i < J; i++) {
        if (resultado[i]) {
            printf("Eu vou estar la\n");
        } else {
            printf("Nao vou estar la\n");
        }
    }
    return 0;
}