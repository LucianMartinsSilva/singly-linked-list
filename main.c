#include "SinglyLinkedList.c"

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
    removeNode(&headNode, 6);
    removeNode(&headNode, 5);
    removeNode(&headNode, 20);


    printf("List after insertions:\n");
    printList(headNode);

    return 0;
}