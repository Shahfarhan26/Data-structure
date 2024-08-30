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

void addNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
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

    addNode(&head1, 10);
    addNode(&head1, 20);
    addNode(&head1, 30);

    addNode(&head2, 40);
    addNode(&head2, 50);
    addNode(&head2, 60);

    printf("List 1: ");
    displayList(head1);

    printf("List 2: ");
    displayList(head2);

    concatenateLists(head1, head2);

    printf("Concatenated List: ");
    displayList(head1);

    return 0;
}