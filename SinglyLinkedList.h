//
// Created by Lucian on 09/06/2024.
//

#ifndef LINKEDLIST_DOUBLYLINKEDLIST_H
#define LINKEDLIST_DOUBLYLINKEDLIST_H

#endif //LINKEDLIST_DOUBLYLINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    int value;
    struct Node *nextNode;
} Node;

Node *createNode(int key, int data);

void printList(Node *headNode);

Node *searchNode(Node *headNode, int key);

Node *insertNode(Node *headNode, int key, int value, int position);

void removeNode(Node **headNodePointer, int key);
