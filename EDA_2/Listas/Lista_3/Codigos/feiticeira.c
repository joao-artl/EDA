#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 100003

typedef struct Node {
    int64_t key;
    int64_t quantity;
    struct Node* next;
} Node;

unsigned int hash(int64_t key) {
    return abs(key) % HASH_TABLE_SIZE;
}

Node* createNode(int64_t key, int64_t quantity) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->quantity = quantity;
    newNode->next = NULL;
    return newNode;
}

Node* findOrCreate(Node** hashTable, int64_t key) {
    unsigned int index = hash(key);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    Node* newNode = createNode(key, 0);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    return newNode;
}

int main() {
    int N;
    scanf("%d", &N);
    Node* hashTable[HASH_TABLE_SIZE] = {NULL};
    for (int i = 0; i < N; i++) {
        int64_t K, Q;
        scanf("%lld %lld", &K, &Q);
        
        Node* node = findOrCreate(hashTable, K);
        node->quantity += Q;
        if (node->quantity < 0) {
            node->quantity = 0;
        }
    }
    int64_t totalItems = 0;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            totalItems += current->quantity;
            current = current->next;
        }
    }
    printf("%lld\n", totalItems);
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return 0;
}