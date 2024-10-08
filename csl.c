#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* add_empty(int data){
    node* temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = temp;

    return temp;
}

node* add_beg(node* tail, int data){
    node* temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = tail -> next;
    tail -> next = temp;
    return tail; 
}

void print(node* tail){
    node* p = tail -> next;
    do
    {
        printf("%d\t",p -> data);
        p = p -> next;
    } while (p != tail -> next);
    
}

int main(){
    node* tail = NULL;
    tail = add_empty(10);
    tail = add_beg(tail,20);
    tail = add_beg(tail,30);
    tail = add_beg(tail,40);

    print(tail);
    return 0;
    
}