#ifndef SORT_H
#define SORT_H

#include "lista.h"

Node* sortedMerge(Node *a, Node *b);

void frontBackSplit(Node *source, Node **frontRef, Node **backRef);

void insertNodeBefore(List *list, Node *node, Node *nodeToBeInserted);

void insertionSort(List *list);

void bubbleSort(List *list);

void mergeSort(Node **headRef);

#endif