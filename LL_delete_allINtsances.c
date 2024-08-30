#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
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
}

void concatenateLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) {
        head1 = head2;
        return;
    }
    struct Node* current = head1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = head2;
}

void deleteAllInstances(struct Node** head, int value) {
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            struct Node* temp = current;
            if (prev == NULL) { // Deleting head node
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    addNodeAtTail(&head1, 10);
    addNodeAtTail(&head1, 20);
    addNodeAtTail(&head1, 30);
    addNodeAtTail(&head1, 10); // Duplicate element

    addNodeAtTail(&head2, 40);
    addNodeAtTail(&head2, 50);
    addNodeAtTail(&head2, 10); // Duplicate element
    addNodeAtTail(&head2, 60);

    printf("List 1 before deletion: ");
    displayList(head1);

    deleteAllInstances(&head1, 10);

    printf("List 1 after deleting all instances of 10: ");
    displayList(head1);

    printf("List 2: ");
    displayList(head2);

    concatenateLists(head1, head2);

    printf("Concatenated List after deletion: ");
    displayList(head1);

    return 0;
}