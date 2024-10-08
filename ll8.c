//second method for deleting the last node in the list.
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
void del_last(struct node *head){ 
    struct node *ptr = head;
    
    if (head == NULL)
    {
        printf("the linked list is empty ");
    }else if (head -> link == NULL)
    {
        free(head);
        head = NULL;
    }else
    {
        while (ptr -> link -> link != NULL)
        {
            ptr = ptr -> link;   
        }
        free(ptr -> link);
        ptr -> link = NULL;
    }
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;

    natend(head,22);
    natend(head,24);
    natend(head,25);

    del_last(head);
    
    printll(head);
    return 0;
}