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

node* add_pos(node* tail , int data,int pos){
    node* temp = malloc(sizeof(node));
    temp -> data = data;
    temp -> next = NULL;

    node* ptr = tail -> next;

    while(pos > 1){
        ptr = ptr -> next;
        pos--;
    }
    if (ptr == tail)
    {
        temp -> next = tail -> next;
        tail -> next = temp;
        tail = tail -> next;
    }
    else
    {
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
    if (ptr == tail)
    {
        tail = tail ->next;
    }
    
    return tail;
}

int main(){
    node* tail = NULL;

    tail = add_empty(10); 
    tail = add_pos(tail,20,1);
    tail = add_pos(tail,30,2);
    tail = add_pos(tail,40,3);
    tail = add_pos(tail,50,4);
    tail = add_pos(tail,60,5);
    tail = add_pos(tail,70,6);
    tail = add_pos(tail,80,7);
    tail = add_pos(tail,90,8);
    tail = add_pos(tail,100,9);
    print(tail);

    return 0;
    
}