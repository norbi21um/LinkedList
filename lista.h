#ifndef LISTA_H
#define LISTA_H
typedef struct Node{
    char name[20];
    int age;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct List{
    struct Node *head;
    struct Node *tail;
    int lenght;
} List;


void printList(Node *start);

void swapNodes(Node *a, Node *b);

void swapList(List *list, int firstPersonIndex, int secondPersonIndex);

Node *searchByIndex(List *list, int index);

#endif