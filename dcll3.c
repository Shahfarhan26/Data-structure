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

node* add_e(node* tail, int data){
    node* p = malloc(sizeof(node));
    p -> prev = NULL;
    p -> data = data;
    p -> next = NULL;
    
    if (tail == NULL)
    {
        return p;

    }else{
        node* temp = tail -> next;
        p -> next = temp;
        p -> prev = tail;
        tail -> next = p;
        tail -> prev = p;
        tail = p;
        return tail;
    }
}

node* add_empty(int data){
    node* temp = malloc(sizeof(node));
    temp -> prev = temp;
    temp -> data = 10;
    temp -> next = temp;
    return temp;
}

node* add_m(node* tail,int data,int pos){
    node* temp = malloc(sizeof(node));
    temp -> prev = temp;
    temp -> data = data;
    temp -> next = temp;
    if (tail == NULL)
    {
        return temp;
    }

    node* ptr = tail -> next;
    while (pos > 1)
    {
        ptr = ptr -> next;
        pos--;
    }
    node* ptr2 = ptr -> next;
    temp -> prev = ptr;
    temp -> next = ptr -> next;
    ptr2 -> prev = temp;
    ptr -> next = temp;

    if(ptr == tail){
        tail = tail -> next;
    }
    return tail;
}

int main(){
    node* tail = NULL;

    tail = add_empty(10);
    tail = add_m(tail,20,1);
    tail = add_m(tail,30,2);
    tail = add_m(tail,40,3);
    tail = add_e(tail,50);

    print(tail);
    return 0;
}