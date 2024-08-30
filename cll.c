#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;
    return newNode;
}

void insertAtHead(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

void insertAtTail(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp->data == value) {
        if (temp->next == *head) {
            free(temp);
            *head = NULL;
            return;
        }
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        prev->next = temp->next;
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != *head && temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next->data == value) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    }
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);

    printf("Circular Linked List: ");
    displayList(head);

    insertAtHead(&head, 5);
    printf("After inserting 5 at the head: ");
    displayList(head);

    deleteNode(&head, 30);
    printf("After deleting the node with value 30: ");
    displayList(head);

    deleteNode(&head, 5);
    printf("After deleting the node with value 5: ");
    displayList(head);

    deleteNode(&head, 40);
    printf("After deleting the node with value 40: ");
    displayList(head);

    deleteNode(&head, 10);
    printf("After deleting the node with value 10: ");
    displayList(head);

    return 0;
}