//
// Created by Lucian on 09/06/2024.
//
#include "DoublyLinkedList.h"

Node *createNode(int key, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = data;
    newNode->nextNode = NULL;
    return newNode;
}

void printList(Node *headNode) {
    Node *currentNode = headNode;
    while (currentNode != NULL) {
        printf("%d (%d) -> ", currentNode->key, currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");
}

Node *searchNode(Node *headNode, int key) {
    Node *currentNode = headNode;
    while (currentNode != NULL) {
        if (currentNode->key == key) {
            return currentNode;
        }
        currentNode = currentNode->nextNode;
    }
    return NULL;
}

Node *insertNode(Node *headNode, int key, int value, int position) {
    Node *newNode = createNode(key, value);

    if (position == 0) {
        newNode->nextNode = headNode;
        headNode = newNode;
        return headNode;
    }

    Node *currentNode = headNode;
    int count = 0;

    while ((currentNode != NULL) && (count < position - 1)) {
        currentNode = currentNode->nextNode;
        count++;
    }
    if (currentNode == NULL) {
        printf("Position out of bounds.\n");
        return headNode;
    }
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
    return headNode;
}

void removeNode(Node **headNodePointer, int key) {
    if (headNodePointer == NULL || *headNodePointer == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *headNode = *headNodePointer;
    Node *nodeToBeRemoved = searchNode(headNode, key);

    if (nodeToBeRemoved == NULL) {
        printf("Node not found.\n");
        return;
    }
    if (nodeToBeRemoved == headNode) {
        *headNodePointer = headNode->nextNode;
        free(headNode);
        return;
    }
    Node *currentNode = headNode;

    while (currentNode->nextNode != nodeToBeRemoved) {
        currentNode = currentNode->nextNode;
    }
    currentNode->nextNode = nodeToBeRemoved->nextNode;
    free(nodeToBeRemoved);
}