#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
} node;

void print(node* tail){
    
    if(tail == NULL){
        printf("the list is empty.");
        return;
    }
    node* temp = tail -> next;
    do{
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }while (temp != tail -> next);
    printf("\n");
}

node* add_e(node* tail, int data){
    node* p = malloc(sizeof(node));
    p -> prev = p;
    p -> data = data;
    p -> next = p;
    
    if (tail == NULL)
    {
        return p;

    }else{
        node* temp = tail -> next;
        p -> next = temp;
        p -> prev = tail;
        tail -> next = p;
        tail -> prev = p;
        tail = p;
        return tail;
    }
}

node* add_empty(int data){
    node* temp = malloc(sizeof(node));
    temp -> prev = temp;
    temp -> data = data;
    temp -> next = temp;
    return temp;
}

node* del_m(node* tail, int pos) {
    if (tail == NULL) {
        printf("The list is empty.\n");
        return NULL;
    }

    node* temp = tail->next;
    if (pos == 1 && temp == tail) {
        free(temp);
        return NULL;
    }

    int count = 1;
    while (count < pos && temp != tail) {
        temp = temp->next;
        count++;
    }

    if (count != pos) {
        printf("Position out of bounds.\n");
        return tail;
    }

    node* t1 = temp->prev;
    node* t2 = temp->next;
    t1->next = t2;
    t2->prev = t1;

    if (temp == tail) {
        tail = t1;
    }

    free(temp);
    return tail;
}

int main(){
    node* tail = NULL;

    tail = add_empty(10);
    tail = add_e(tail,20);
    tail = add_e(tail,30);
    tail = add_e(tail,40);
    tail = add_e(tail,50);

    printf(" List before deletion:\n");
    print(tail);
    tail = del_m(tail,5);
    printf(" \n\nList after deletion:\n");
    print(tail);

    return 0;
}