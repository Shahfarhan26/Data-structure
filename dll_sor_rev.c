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

void sortList(struct Node** head) {
    if (*head == NULL) {
        return;
    }
    int swapped;
    struct Node* ptr1;
    struct Node* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = *head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void reverseList(struct Node** head) {
    struct Node* temp = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct Node* head = NULL;

    addNodeAtTail(&head, 30);
    addNodeAtTail(&head, 10);
    addNodeAtTail(&head, 50);
    addNodeAtTail(&head, 20);
    addNodeAtTail(&head, 40);

    printf("Original List (Head to Tail): ");
    displayList(head);

    printf("Original List (Tail to Head): ");
    displayListReverse(head);

    sortList(&head);
    printf("Sorted List (Head to Tail): ");
    displayList(head);

    reverseList(&head);
    printf("Reversed List (Head to Tail): ");
    displayList(head);

    return 0;
}