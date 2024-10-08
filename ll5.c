//adding a node at any position in the list.
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
void add_pos(struct node *head , int data , int pos){
    struct node *ptr = head;
    struct node *ptr1 = malloc(sizeof(struct node));
    ptr1 -> data = data;
    ptr1 -> link = NULL;
    pos--;
    while(pos != 1){
        ptr = ptr -> link;
        pos--;
    }
    ptr1 -> link = ptr -> link;
    ptr -> link = ptr1;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;

    natend(head,22);
    natend(head,24);
    natend(head,25);

    add_pos(head,23,3);
    
    printll(head);
    return 0;
}