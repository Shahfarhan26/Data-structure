// reversing of the list using functions.
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
struct node* reverse(struct node *head){
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL){
        next  =  head -> link;
        head -> link = prev;
        prev = head;
        head = next;        
    }
    head = prev;
    return head;
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;

    natend(head,22);
    natend(head,24);
    natend(head,25);
    printf("linked list:\n");

    printll(head);
    head = reverse(head);
    printf("after reversing:\n");
    printll(head);
    
    return 0;
}