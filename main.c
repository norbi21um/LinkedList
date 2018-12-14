#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>
#include "lista.h"
#include "sort.h"



//Print the menu
void printMenu(){
    printf("Enter number\n"
           "1 to add a person to the Linked List.\n"
           "2 to print the list.\n"
           "3 to sort the list with bubble sort.\n"
           "4 to sort the list with insertion sort.\n"
           "5 to sort the list with merge sort.\n"
           "////////////////////////////////////////\n"
           "9 to stop the program.\n\n");
}


//Adds a Node to the Linked List by changing the neighbouring Node's pointers
Node *AddNode(List *list, Node *previous) {
    printf("Enter a the person's name and age: \n");
    char name[20];
    int age;
    scanf("%s", &name);
    scanf("%d", &age);

    Node *newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    printf("%s is added to the list with the age of %d\n\n",newNode->name,newNode->age);

    newNode->next = NULL;
    newNode->previous = NULL;

    if(previous != NULL) {
        previous->next = newNode;
        newNode->previous = previous;
    }

    list->lenght = list->lenght + 1;

    return newNode;
}

//Frees up the linked list after the program has run its course
void CleanUp(Node *start) {

    Node *freeMe = start;
    Node *holdMe = NULL;
    while(freeMe != NULL) {
        holdMe = freeMe->next;
        printf("Free Name: %s Age: %d\n",
               freeMe->name,
               freeMe->age);
        free(freeMe);
        freeMe = holdMe;
    }
}

int main() {
    int controlInput;

    List mainList;
    mainList.head = NULL;
    mainList.tail = NULL;
    mainList.lenght = 0;

    printMenu();

    while(scanf("%d", &controlInput)) {

        if (controlInput == 9) {
            printf("\n\nIt's over.\n");
            break;
        } else if (controlInput == 1) {
            if(mainList.head == NULL) {
                mainList.head = AddNode(&mainList,NULL);
                mainList.tail = mainList.head;
            } else {
                mainList.tail = AddNode(&mainList, mainList.tail);
            }
        } else if (controlInput == 2) {
            printList(mainList.head);
        } else if (controlInput == 3) {
            printf("Bubble Sort:\n");
            bubbleSort(&mainList);
            printList(mainList.head);
        } else if (controlInput == 4) {
            printf("Insertion Sort:\n");
            insertionSort(&mainList);
            printList(mainList.head);
        } else if (controlInput == 5) {
            printf("Merge Sort:\n");
            mergeSort(&mainList.head);
            printList(mainList.head);
        }
    }

    CleanUp(mainList.head);

    return 0;
}