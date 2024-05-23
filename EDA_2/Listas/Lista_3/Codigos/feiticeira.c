#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 262147 

typedef struct item {
    long long int id;
    long long int quantity;
    struct item *next;
} Item;

typedef struct {
    Item *buckets[MAX_ITEMS];
} HashTable;

long long int hash(long long int key) {
    return abs(key % MAX_ITEMS);
}

void initHashTable(HashTable *ht) {
    for (long long int i = 0; i < MAX_ITEMS; i++) {
        ht->buckets[i] = NULL;
    }
}

void addOrUpdateItem(HashTable *ht, long long int id, long long int quantity) {
    long long int index = hash(id);
    Item *item = ht->buckets[index];
    
    while (item != NULL) {
        if (item->id == id) {
            item->quantity += quantity;
            return;
        }
        item = item->next;
    }

    item = malloc(sizeof(Item));
    item->id = id;
    item->quantity = quantity;
    item->next = ht->buckets[index];
    ht->buckets[index] = item;
}

long long int totalItems(HashTable *ht) {
    long long int total = 0;
    for (long long int i = 0; i < MAX_ITEMS; i++) {
        Item *item = ht->buckets[i];
        while (item != NULL) {
            total += item->quantity;
            item = item->next;
        }
    }
    return total;
}

void freeHashTable(HashTable *ht) {
    for (long long int i = 0; i < MAX_ITEMS; i++) {
        Item *item = ht->buckets[i];
        while (item != NULL) {
            Item *tmp = item;
            item = item->next;
            free(tmp);
        }
    }
}

int main() {
    HashTable ht;
    initHashTable(&ht);
    long long int n;
    scanf("%lld", &n);
    
    for (long long int i = 0; i < n; i++) {
        long long int id, quantity;
        scanf("%lld %lld", &id, &quantity);
        addOrUpdateItem(&ht, id, quantity);
    }
    
    printf("%lld\n", totalItems(&ht));
    freeHashTable(&ht);
    return 0;
}
