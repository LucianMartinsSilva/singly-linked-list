#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node *nextNode;
} Node;

Node *createNode(int key, int data);

void printList(Node *headNode);

Node *searchNode(Node *headNode, int key);

Node *insertNode(Node *headNode, int key, int value, int position);

int main(void) {
    Node *headNode = createNode(1, 10);
    headNode->nextNode = createNode(2, 20);
    headNode->nextNode->nextNode = createNode(3, 30);
    headNode->nextNode->nextNode->nextNode = createNode(4, 40);

    printf("Original list:\n");
    printList(headNode);

    int keyToSearch = 3;
    Node *foundNode = searchNode(headNode, keyToSearch);
    if (foundNode != NULL) {
        printf("Value for key %d is %d.\n", keyToSearch, foundNode->value);
    } else {
        printf("Key not found in the list: %d.\n", keyToSearch);
    }

    headNode = insertNode(headNode, 5, 50, 0);
    headNode = insertNode(headNode, 6, 60, 2);
    headNode = insertNode(headNode, 7, 70, 6);

    printf("List after insertions:\n");
    printList(headNode);

    return 0;
}

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
        printf("Position out of founds.\n");
        return headNode;
    }
    newNode->nextNode = currentNode->nextNode;
    currentNode->nextNode = newNode;
    return headNode;
}


