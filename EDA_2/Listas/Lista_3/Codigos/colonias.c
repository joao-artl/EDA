#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLONIES 2097169
#define MAX_FOOD_LENGTH 11

typedef struct node {
    char food[MAX_FOOD_LENGTH];
    struct node *next;
} Node;

typedef struct {
    int colonyID;
    Node *foods;
} HashTable;

HashTable hashTable[MAX_COLONIES];

void initHashTable(){
    for (int i = 0; i < MAX_COLONIES; i++){
        hashTable[i].colonyID = -1;
        hashTable[i].foods = NULL;
    }
}

int hashFunction(int colonyID){
    return colonyID % MAX_COLONIES;
}

Node* createNode(char *food){
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->food, food);
    newNode->next = NULL;
    return newNode;
}

void insertFood(int colonyID, char *food){
    int index = hashFunction(colonyID);
    while (hashTable[index].colonyID != -1 && hashTable[index].colonyID != colonyID){
        index = (index + 1) % MAX_COLONIES; 
    }
    if (hashTable[index].colonyID == -1){
        hashTable[index].colonyID = colonyID;
    }
    Node *current = hashTable[index].foods;
    while (current != NULL) {
        if (strcmp(current->food, food) == 0){
            printf("%d\n", colonyID);
            return;
        }
        current = current->next;
    }
    Node *newFood = createNode(food);
    newFood->next = hashTable[index].foods;
    hashTable[index].foods = newFood;
}

int main(){
    initHashTable();
    unsigned int id;
    char food[MAX_FOOD_LENGTH];
    while (scanf("%u %s", &id, food) != EOF){
        insertFood(id, food);
    }
    return 0;
}