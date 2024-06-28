#include <stdio.h>
#include <string.h>

#define MAX_PEOPLE 300

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);
    if (xRoot != yRoot) {
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    char names[MAX_PEOPLE][21];
    int parent[MAX_PEOPLE];
    int rank[MAX_PEOPLE];
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int nameCount = 0;
    for (int i = 0; i < N; i++) {
        char name1[21], relation[21], name2[21];
        scanf("%s %s %s", name1, relation, name2);
        int idx1 = -1, idx2 = -1;
        for (int j = 0; j < nameCount; j++) {
            if (strcmp(names[j], name1) == 0)
                idx1 = j;
            if (strcmp(names[j], name2) == 0)
                idx2 = j;
        }
        if (idx1 == -1) {
            strcpy(names[nameCount], name1);
            idx1 = nameCount;
            nameCount++;
        }
        if (idx2 == -1) {
            strcpy(names[nameCount], name2);
            idx2 = nameCount;
            nameCount++;
        }
        unionSets(parent, rank, idx1, idx2);
    }
    int familyCount = 0;
    int familyRepresentatives[MAX_PEOPLE] = {0};
    for (int i = 0; i < M; i++) {
        int representative = find(parent, i);
        if (!familyRepresentatives[representative]) {
            familyRepresentatives[representative] = 1;
            familyCount++;
        }
    }
    printf("%d\n", familyCount);
    return 0;
}
