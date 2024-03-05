#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_FLOORS 1000001

int grafo[MAX_FLOORS][2];

bool bfs(int s, int n, int meta, int dist[], int pred[]) {
    bool visited[MAX_FLOORS] = {false};

    int queue[MAX_FLOORS];
    int front = 0, rear = 0;

    visited[s] = true;
    dist[s] = 0;
    queue[rear++] = s;

    while (front < rear) {
        s = queue[front++];
        
        for (int i = 0; i < 2; ++i) {
            int next_floor = grafo[s][i];
            if (!visited[next_floor]) {
                visited[next_floor] = true;
                dist[next_floor] = dist[s] + 1;
                pred[next_floor] = s;
                queue[rear++] = next_floor;

                if (next_floor == meta)
                    return true;
            }
        }
    }

    return false;
}

void solve(int s, int dest, int v) {
    int pred[MAX_FLOORS], dist[MAX_FLOORS];
    for (int i = 1; i <= v; ++i) {
        pred[i] = -1;
        dist[i] = INT_MAX;
    }

    if (!bfs(s, v, dest, dist, pred)) {
        printf("use the stairs\n");
        return;
    }

    printf("%d\n", dist[dest]);
}

int main() {
    int andares, inicio, meta, cima, baixo;

    scanf("%d %d %d %d %d", &andares, &inicio, &meta, &cima, &baixo);

    for (int i = 1; i <= andares; ++i) {
        if (i + cima <= andares) {
            grafo[i][0] = i + cima;
        }

        if (i - baixo >= 1) {
            grafo[i][1] = i - baixo;
        }
    }

    if (inicio == meta)
        printf("0\n");
    else
        solve(inicio, meta, andares + 1);

    return 0;
}
