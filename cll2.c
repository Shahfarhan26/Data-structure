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

node* add_end(node* tail, int data){
    node* temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL; 

    temp -> next = tail -> next;
    tail -> next = temp;
    tail = tail -> next;
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
    
    tail = add_end(tail,20);
    tail = add_end(tail,30);
    tail = add_end(tail,40);
    tail = add_end(tail,50);
    tail = add_end(tail,60);
    tail = add_end(tail,70);
    tail = add_end(tail,80);
    tail = add_end(tail,90);

    print(tail);

    return 0;
    
}