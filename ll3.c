// adding node at the beginning of the list.
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *link;
};
void printll(struct node *head){
    if (head == NULL){
        printf("the linked list is empty");
    }
    struct node *ptr = head;
    int i = 1;
    while (ptr!=NULL)
    {
        printf("%d node's data is :%d\n",i,ptr->data);
        ptr = ptr->link;
        i++;
    }
}void nofnodes(struct node *head){
    int count = 0;
    if (head == NULL){
        printf("the linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr!=NULL)
    {
        count++;
        ptr = ptr->link;
    }
    printf("count = %d.\n",count);
    
}
struct node* add_beg(struct node *head, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> link = NULL;

    ptr -> link = head;
    head = ptr;

    return head;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 97;
    head -> link = NULL;
    
    struct node *ptr = malloc(sizeof(struct node));
    ptr -> data = 10;
    ptr -> link = NULL;

    head -> link = ptr;

    int d = 3;
    head = add_beg(head,d);
    ptr = head;

    printll(head);
    

    return 0;
}