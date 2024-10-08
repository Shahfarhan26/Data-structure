#include<stdio.h>
void insertion_sort(int a[], int n);
void scan(int a[],int n);
void print(int a[],int n);
int main(){
    int n;
    printf("Enter the No. of elements :\n");
    scanf("%d",&n);
    int a[n];
    scan(a,n);
    insertion_sort(a,n);
    print(a,n);
    return 0;
}
void insertion_sort(int a[], int n){
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    
    
}
void print(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    
}
void scan(int a[],int n){
    printf("ENTER THE ELEMENTS FOR THE ARRAY:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    } 
}