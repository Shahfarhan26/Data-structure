#include<stdio.h>
#include<stdlib.h>
 
typedef struct node {
    struct node* prev;
    int data;
    struct node* next;
} node;

node* add_beg(node* head, int data ){
    node* p = malloc(sizeof(node));
    p -> prev = NULL;
    p -> data = data;
    p -> next = NULL;
    
    p -> next = head;
    if (head != NULL)
    {
        head -> prev = p;
        head = p;
    }
    head = p;
    return head;
    
}
node* add_end(node* head,int data){
    node* temp = head;
    node* p = malloc(sizeof(node));
    p -> prev = NULL;
    p -> data = data;
    p -> next = NULL;

    if (head != NULL)
    {
        printf("the linked list is empty");
    }
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    p -> prev = temp;
    temp -> next = p;
    return head;
    
}
node* add_empty(node* head, int data){
    node* temp = malloc(sizeof(node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    head = temp;
    return head;
}
void print(node* head){
    node* temp = head;
    
    while(temp != NULL){
        printf("%d\n",temp -> data);
        temp = temp -> next;
    }
}

node* reverse(node* head){
    node* p1 = head;
    node* p2 = p1 -> next;

    p1 -> next = NULL;
    p1 -> prev = p2;

    while(p2 != NULL){
        p2 -> prev = p2 -> next;
        p2 -> next = p1;
        p1 = p2;
        p2 = p2 ->prev;
    }
    head = p1;
    return head;
}
int main(){
    node* head = NULL;
    head = add_empty(head,10);
    head = add_end(head,20);
    head = add_end(head,30);
    head = add_end(head,40);
    head = add_end(head,50);
    printf("the list before reverising is as follows: \n");
    print(head);
    head = reverse(head);
    printf("the list after reverising is as follows: \n");
    print(head);
    return 0;
}