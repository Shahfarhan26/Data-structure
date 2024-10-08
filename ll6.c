//deleting a node at the beginning of the list.
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

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
struct node* del_beg(struct node *head){
    if(head == NULL){
        printf("the linked list is empty");
    }else
    {
        struct node *ptr = head;
        head = head -> link;
        free(ptr);
        ptr = NULL;
    }
    
    return head;

}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;

    natend(head,22);
    natend(head,24);
    natend(head,25);

    head = del_beg(head);
    
    printll(head);
    return 0;
}