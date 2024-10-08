#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int stack_arr[MAX];
int top = -1;

void push(int data){
    if (isfull())
    {
        printf("stack owerflow.");
        exit(1);
    }
    top++;
    stack_arr[top] = data;
}
int pop(){
    int val;
    if (isempty())
    {
        printf("stack underflow.");
        exit(1);
    }
    val = stack_arr[top];
    top--;
    return val;
}

int isfull(){
    if (top == MAX - 1)
    {
        return 1;
    }else
        return 0;
}
int isempty(){
    if (top == -1)
    {
        return 1;
    }else 
        return 0;
    
}
void print(){
    if (top == -1)
    {
        printf("stack underflow\n");
        return;
    }
    for (int i = top; i >= 0 ; i--)
    {
        printf("%d",stack_arr[i]);
        printf("\n");
    }
    
}

void prime(int num){
    int i = 2;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num = num / i;
        }
        i++;
    }
    while (top != -1)
    {
        printf("%d",pop());
        printf("\t");
    }
    
    
}

int main(){
    prime(100001);
    return 0;
}