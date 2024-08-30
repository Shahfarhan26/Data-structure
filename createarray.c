#include<stdio.h>
/*to make scan and print an array using functions.*/
void sarr(int arr1[],int n){
     printf("Enter %d elements :",n);
    for ( int i = 0; i < n; i++)
    {
        scanf("%d",&arr1[i]);
    };
}    
void parr(int arr1[],int n){
    printf("The elements of the array are : ");
    for ( int i = 0; i < n; i++)
    {
        printf("%d",arr1[i]);
        printf(" ");
    };
    printf("\n");
}

int main(){
    int arr1[100],n;
    printf("Enter no. of elements :");
    scanf("%d",&n);

    sarr(arr1,n);
    parr(arr1,n);
  return 0;
}