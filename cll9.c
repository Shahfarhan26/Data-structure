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
node* del_P(node* tail,int pos){
    node* t = tail ->  next;
    if (tail == NULL)
    {
        return tail;
    }
    if (t -> next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        t = t -> next;
        pos --;
    }
    node* t2 = t -> next;
    t -> next = t2-> next;
    if (t2 == tail)
    {
        tail = t;
    }
    free(t2);
    t2 =  NULL;

    return tail;
}
int srch(node* tail){
    int n,c = 1;
    printf("\n\nenter the number you want search for:\t");
    scanf("%d",&n);
    node* t = tail -> next;
    if (tail == NULL)
    {
        return -2;
    }
    
    do
    {
        if (t -> data == n)
        {
            return c;
        }
        t = t -> next;
        c++;
    } while (t != tail -> next);
    return -1;
}
int main(){
    node* tail = NULL;
    
    tail = creat_cll(tail);
    print(tail);
    int index = srch(tail);
    if (index == -2)
    {
        printf("the list is empty");
    }else if (index == -1)
    {
        printf("the element is not found");
    }else{
        printf("the no. of elemnt is %d",index);
    }
    return 0;
    
}