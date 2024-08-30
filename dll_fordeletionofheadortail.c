#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNodeAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    newNode->next = *head;
    *head = newNode;
}

void addNodeAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        return;
    }

    struct Node* current = *head;

    // Case 1: Deleting the head node
    if (current->data == value) {
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(current);
        return;
    }

    // Traverse the list to find the node to delete
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    // If the node with the specified value is not found
    if (current == NULL) {
        return;
    }

    // Case 2: Deleting the tail node
    if (current->next == NULL) {
        current->prev->next = NULL;
    } else {
        // Case 3: Deleting a middle node
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    
    free(current);
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void displayListReverse(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    addNodeAtTail(&head, 10);
    addNodeAtTail(&head, 20);
    addNodeAtTail(&head, 30);
    addNodeAtTail(&head, 40);

    printf("Doubly Linked List (Head to Tail): ");
    displayList(head);

    printf("Doubly Linked List (Tail to Head): ");
    displayListReverse(head);

    deleteNode(&head, 10); // Delete head
    printf("After deleting the head node (value 10):\n");
    displayList(head);

    deleteNode(&head, 40); // Delete tail
    printf("After deleting the tail node (value 40):\n");
    displayList(head);

    deleteNode(&head, 20); // Delete a middle node
    printf("After deleting the node with value 20:\n");
    displayList(head);

    return 0;
}