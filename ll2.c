// adding a node at end another method.
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
struct node* add_at_end(struct node *ptr,int data){
    struct node *temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;
    ptr -> link = temp;
    return temp;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 97;
    head -> link = NULL;
    nofnodes(head);
    printll(head);
    struct node *ptr = head;
    ptr = add_at_end(ptr,12);
    nofnodes(head);
    printll(head);
    ptr = add_at_end(ptr,23);
    nofnodes(head);
    printll(head);
    ptr = add_at_end(ptr,34);
    nofnodes(head);
    printll(head);
    ptr = add_at_end(ptr,45);
    nofnodes(head);
    printll(head);
    ptr = add_at_end(ptr,56);
    nofnodes(head);
    printll(head);
    ptr = add_at_end(ptr,678);
    nofnodes(head);
    printll(head);

    return 0;
}