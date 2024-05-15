#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* next;
} Node;

void insert(Node** table, int address, int key) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = table[address];
    table[address] = newNode;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Node* start) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    if (start == NULL)
        return;
    do {
        swapped = 0;
        ptr1 = start;
        while (ptr1->next != lptr){
            if (ptr1->key > ptr1->next->key) {
                swap(&ptr1->key, &ptr1->next->key);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void printTable(Node** table, int M) {
    for(int i = 0; i < M; i++){
        printf("%d ->", i);
        bubbleSort(table[i]);
        Node* temp = table[i];
        while (temp != NULL) {
            printf(" %d ->", temp->key);
            temp = temp->next;
        }
        printf(" \\\n");
    }
}

void freeTable(Node** table, int M) {
    for (int i = 0; i < M; i++) {
        Node* temp = table[i];
        while (temp != NULL) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        Node** table = (Node**) calloc(M, sizeof(Node*));

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int address = key % M;
            insert(table, address, key);
        }

        printTable(table, M);
        freeTable(table, M);
        free(table);

        if (N > 0) printf("\n");
    }
    return 0;
}