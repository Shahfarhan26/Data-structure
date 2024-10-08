//deleting a node at any position in the list.
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
void del_pos(struct node **head , int pos){ 
    struct node *prev = *head;
    struct node *cur = *head;
    
    if (*head == NULL)
    {
        printf("the linked list is empty ");
    }else if (pos == 1)
    {   
        *head = cur -> link;
        free(cur);
        cur = NULL;
    }else
    {
        while (pos != 1)
        {   
            prev = cur;
            cur = cur -> link;
            pos--;    
        }
        prev -> link = cur -> link;
        free( cur);
        cur = NULL;
    }
}
int main(){
    struct node *head = malloc(sizeof(struct node));
    head -> data = 21;
    head -> link = NULL;

    natend(head,22);
    natend(head,24);
    natend(head,25);

    del_pos(&head,3);
    
    printll(head);
    return 0;
}