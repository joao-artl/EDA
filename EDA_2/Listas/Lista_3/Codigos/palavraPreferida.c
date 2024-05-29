#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char word[17];
    int count;
    struct Node *next;
} Node;

#define TABLE_SIZE 65537
Node *hashTable[TABLE_SIZE];

unsigned int hash(const char *word){
    unsigned int hash = 0;
    while (*word){
        hash = (hash * 31) + *word++;
    }
    return hash % TABLE_SIZE;
}

Node *findEntry(const char *word){
    unsigned int index = hash(word);
    Node *entry = hashTable[index];
    while (entry != NULL && strcmp(entry->word, word) != 0){
        entry = entry->next;
    }
    return entry;
}

void addVote(const char *word){
    unsigned int index = hash(word);
    Node *entry = findEntry(word);
    if (entry == NULL) {
        entry = (Node *)malloc(sizeof(Node));
        strcpy(entry->word, word);
        entry->count = 1;
        entry->next = hashTable[index];
        hashTable[index] = entry;
    } else {
        entry->count++;
    }
}

int getVoteCount(const char *word){
    Node *entry = findEntry(word);
    return (entry != NULL) ? entry->count : 0;
}

void resetVoteCount(const char *word){
    Node *entry = findEntry(word);
    if (entry != NULL) {
        entry->count = 0;
    }
}

int main(){
    int command;
    char word[17];
    for (int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
    while (scanf("%d %s", &command, word) != EOF){
        if (command == 1){
            addVote(word);
        } else if (command == 2){
            printf("%d\n", getVoteCount(word));
        } else if (command == 3){
            resetVoteCount(word);
        }
    }
    for (int i = 0; i < TABLE_SIZE; i++){
        Node *entry = hashTable[i];
        while (entry != NULL){
            Node *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }
    return 0;
}