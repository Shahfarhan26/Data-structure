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

void deleteHead(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteTail(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    struct Node* current = *head;
    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL) {
        if (current->data == value) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                *head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
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

    deleteHead(&head);
    printf("After deleting the head node:\n");
    displayList(head);

    deleteTail(&head);
    printf("After deleting the tail node:\n");
    displayList(head);

    deleteNode(&head, 20);
    printf("After deleting the node with value 20:\n");
    displayList(head);

    return 0;
}