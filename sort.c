#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>
#include "lista.h"
#include "sort.h"


Node* sortedMerge(Node *a, Node *b);
void frontBackSplit(Node *source, Node **frontRef, Node **backRef);

//Inserts a given Node before an other Node
void insertNodeBefore(List *list, Node *node, Node *nodeToBeInserted){
    if (node == nodeToBeInserted)
        return;

    // nTBI is the last
    if(nodeToBeInserted->next == NULL)
        list->tail = nodeToBeInserted->previous;

    // nTBI is the first
    if(nodeToBeInserted->previous == NULL)
        list->head = nodeToBeInserted->next;

    // node is the first
    if(node->previous == NULL)
        list->head = nodeToBeInserted;

    {
        Node *temNodeToBeInsertedPrev = nodeToBeInserted->previous;
        Node *temNodeToBeInsertedNext = nodeToBeInserted->next;

        if(node->previous != NULL)
            node->previous->next = nodeToBeInserted;


        nodeToBeInserted->previous = node->previous;
        nodeToBeInserted->next = node;

        node->previous = nodeToBeInserted;

        temNodeToBeInsertedPrev->next = temNodeToBeInsertedNext;

        if(temNodeToBeInsertedNext != NULL)
            temNodeToBeInsertedNext->previous = temNodeToBeInsertedPrev;
    }
}


//Sorts the Linked List with the Insertion Sort algorithm
void insertionSort(List *list){
    int i,j,n = list->lenght;

    for (i = 1; i < n; i++){
        Node *key = searchByIndex(list,i);
        j = 0;

        while(j < i) {
            if  (searchByIndex(list,j)->age > key->age) {
                insertNodeBefore(list,searchByIndex(list,j),searchByIndex(list,i));
                break;
            } else {
                j++;
            }
        }
    }
}

//Sorts the Linked List with the Bubble Sort algorithm
void bubbleSort(List *list){
    int i, j, firstPerson, secondPerson;
    Node *temp1;
    Node *temp2;
    for(i = 0; i < list->lenght-1; i++){
        for(j = 0; j < list->lenght-1; j++){

            firstPerson = j;
            secondPerson = j+1;

            temp1 = searchByIndex(list,firstPerson);
            temp2 = searchByIndex(list,secondPerson);

            if(temp1->age > temp2->age){
                swapList(list, firstPerson, secondPerson);
            }
        }
    }
}

//Sorts the Linked List with the Merge Sort algorithm
void mergeSort(Node **headRef){
    Node* head = *headRef;
    Node* a;
    Node* b;

    if ((head == NULL) || (head->next == NULL)){
        return;
    }

    frontBackSplit(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = sortedMerge(a, b);
}

//Takes two sorted lists as parameters and merges them into one
Node* sortedMerge(Node *a, Node *b){
    struct Node* result = NULL;

    if (a == NULL)
        return(b);
    else if (b==NULL)
        return(a);

    if (a->age <= b->age){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return(result);
}

//Splits the list into two halves
void frontBackSplit(Node *source, Node **frontRef, Node **backRef){
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    while (fast != NULL){
        fast = fast->next;
        if (fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}