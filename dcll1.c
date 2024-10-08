#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
} node;
node* add_b(node* tail, int data){
    node* temp = malloc(sizeof(node));
    temp -> prev = NULL;
    temp -> data = data;
    temp -> next = NULL;
    if (tail == NULL)
    {
        printf("the list is empty");

    }else if (tail -> next == NULL)
    {
        node* ptr = tail;
        ptr -> next = temp;
        ptr -> prev = temp;
        temp -> next = ptr;
        temp -> prev = ptr;
        return tail;
    }else{
        node* ptr = tail -> next;
        tail -> next = temp;
        ptr -> prev = temp;
        temp -> next = ptr;
        temp -> prev = tail;
        return tail;
    }
    
}
void print(node* tail){
    node* temp = tail -> next;
    
    do{
        printf("%d\t",temp -> data);
        temp = temp -> next;
    }while (temp != tail -> next);
}
int main(){
    node* tail = malloc(sizeof(node));
    tail -> prev = NULL;
    tail -> data = 10;
    tail -> next = NULL;

    tail = add_b(tail,20);
    tail = add_b(tail,30);
    tail = add_b(tail,40);
    tail = add_b(tail,50);
    print(tail);
    return 0;
}