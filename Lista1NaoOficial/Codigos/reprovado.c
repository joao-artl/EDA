#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int nota;
    char nome[10];
    struct Node *prox;
} Node;

typedef struct Lista
{
    int tam;
    Node *inicio;
} Lista;



