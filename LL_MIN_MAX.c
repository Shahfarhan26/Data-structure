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

void findMinMax(struct Node* head, int* min, int* max) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    *min = head->data;
    *max = head->data;

    struct Node* current = head->next;

    while (current != NULL) {
        if (current->data < *min) {
            *min = current->data;
        }
        if (current->data > *max) {
            *max = current->data;
        }
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 5);
    addNode(&head, 30);
    addNode(&head, 15);

    int min, max;
    findMinMax(head, &min, &max);

    printf("Minimum value in the list: %d\n", min);
    printf("Maximum value in the list: %d\n", max);

    return 0;
}