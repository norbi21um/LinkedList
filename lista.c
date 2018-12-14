#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

//Prints the Linked List
void printList(Node *start){
    Node *currentPerson = start;
    int counter = 0;

    while (currentPerson != NULL){
        counter++;
        printf("%d. %s, %d\n", counter, currentPerson->name, currentPerson->age);
        currentPerson = currentPerson->next;
    }

}

//Swaps two given nodes in a Linked List
void swapNodes(Node *a, Node *b){
    if (a == b)
        return;

    if(a->next==b){
        if(a->previous != NULL)
            a->previous->next = b;

        if(b->next != NULL)
            b->next->previous = a;

        b->previous = a->previous;
        a->previous = b;
        a->next = b->next;
        b->next = a;
    } else if(b->next==a){
        if(b->previous != NULL)
            b->previous->next = a;

        if(a->next != NULL)
            a->next->previous = b;

        a->previous = b->previous;
        b->previous = a;
        b->next = a->next;
        a->next = b;
    } else{

        Node *temAPrev;
        Node *temANext;
        if(a->previous == NULL){
            temAPrev = NULL;
        } else {
            temAPrev = a->previous;
        }

        if(a->next == NULL) {
            temANext = NULL;
        } else {
            temANext = a->next;
        }

        if(a->previous != NULL)
            a->previous->next = b;

        if(a->next != NULL)
            a->next->previous = b;

        if(b->previous != NULL)
            b->previous->next = a;

        if(b->next != NULL)
            b->next->previous = a;

        a->previous = b->previous;
        a->next = b->next;
        b->previous = temAPrev;
        b->next = temANext;
    }

}

//Controls the swapNodes method with index input values and corrects the Linked List's values (Head, Tail)
void swapList(List *list, int firstPersonIndex, int secondPersonIndex){
    if(firstPersonIndex == secondPersonIndex)
        return;

    Node *currentPerson = list->head;
    Node *person1 = NULL, *person2 = NULL;
    int currentIndex = 0;

    while (currentPerson != NULL){
        if(currentIndex == firstPersonIndex){
            person1 = currentPerson;
        }
        if(currentIndex == secondPersonIndex){
            person2 = currentPerson;
        }

        if(person1 != NULL && person2 != NULL)
            break;
        currentPerson = currentPerson->next;
        currentIndex++;
    }

    swapNodes(person1,person2);

    if(firstPersonIndex == 0){
        list->head = person2;
    }
    if(secondPersonIndex == 0){
        list->head = person1;
    }
    if(firstPersonIndex == list->lenght-1){
        list->tail = person2;
    }
    if(secondPersonIndex == list->lenght-1){
        list->tail = person1;
    }
}

//Searches a Node in the Linked List by its index
Node *searchByIndex(List *list, int index){
    Node *returnValue = list->head;
    for(int i = 0; i < index; i++){
        returnValue = returnValue->next;
    }
    return returnValue;
}