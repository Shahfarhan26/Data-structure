//ceating a linked list, counting the nodes of the same list and adding the node at the end to same.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void nofnodes(struct node *head){
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
    printf("%d\n",count);
    
}
void printll(struct node *head){
    if (head == NULL){
        printf("the linked list is empty");
    }
    struct node *ptr = head;
    while (ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}
void natend(struct node *head,int data){
    struct node *ptr,*temp;
    if(head == NULL){
        printf("the linked list is empty");
    }
    temp = malloc(sizeof(struct node));
    temp -> data = data;
    temp -> link = NULL;
    ptr = head;
    while(ptr->link!=NULL){
        ptr = ptr -> link;
    }
    ptr -> link = temp;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL; 
    struct node *cur = malloc(sizeof(struct node));
    cur->data = 98;
    cur->link = NULL;
    head->link = cur;
    cur = malloc(sizeof(struct node));
    cur->data = 3;
    cur->link = NULL;
    head->link->link = cur;
    cur = malloc(sizeof(struct node));
    cur->data = 14;
    cur->link = NULL;
    head->link->link->link = cur;
    printf("count before adding a node:\n");
    nofnodes(head);
    printf("linked list before adding a node:\n");
    printll(head);
    printf("after adding the linked list and the count become:\n");
    natend(head,67);
    nofnodes(head);
    printll(head);
    return 0;
}