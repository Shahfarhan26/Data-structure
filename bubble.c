#include<stdio.h>
void bubble_sort(int a[], int n);
void scan(int a[],int n);
void print(int a[],int n);
int main(){
    int n;
    printf("Enter the No. of elements :\n");
    scanf("%d",&n);
    int a[n];
    scan(a,n);
    bubble_sort(a,n);
    print(a,n);
    return 0;
}
void bubble_sort(int a[], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
            
        }
        
    }
      
}
void print(int a[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    
}
void scan(int a[],int len){
    printf("ENTER THE ELEMENTS FOR THE ARRAY:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&a[i]);
    } 
}