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

node* creat_cll(node* tail){
    int n = 0,data;

    do
    {
        printf("Enter the number of nodes to be created :\n");
        scanf("%d",&n);
    }while (n <= 0);

    printf("Enter data for 1 node:\t");
    scanf("%d",&data);

    tail = add_empty(data);

    for(int i = 1; i < n ; i++){
        printf("Enter data for %d node:\t",i+1);
        scanf("%d",&data);
        tail = add_end(tail,data);
    }
    return tail;
}

node* del_b(node* tail){
    node* t = tail -> next;
    tail -> next =  t -> next;
    free(t);
    t = NULL;

    return tail;
}

node* del_l(node* tail){
    node* t = tail ->  next;
    if (t == tail)
    {
        return tail;
    }
    if (t -> next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (t -> next != tail)
    {
        t = t -> next;
    }
    t -> next = tail -> next;
    free(tail);
    tail = t;
    return tail;

}
int main(){
    node* tail = NULL;

    tail = creat_cll(tail);
    print(tail);
    tail = del_l(tail);
    printf("\n\nafter deletion:\t");
    print(tail);
    return 0;
    
}