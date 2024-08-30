#include<stdio.h>
/*program to make a union of two user define arrays.*/
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
    };
    printf("\n");
}
void ascend(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j +1];
                arr[j + 1] = temp;
            }
        }
        
    }
    
}
void uni(int arr1[],int arr2[],int n1,int n2){
    int i,j,k;
    int n = n1 + n2;
    int temp[n];
    for ( i = 0; i < n1; i++)
    {
        temp[i] = arr1[i];
    }
    for (int j = 0; i < n2; j++){
        temp[i + j] = arr2[j];
    }
    ascend(temp,n);
    for (i = 0; i < n; i++)
    {
        if (i == 0 || temp[i] != temp[i - 1])
        {
            printf("%d",temp[i]);
        }
        printf("\n");
    }
    }
int main(){
    int n1,n2;
    int arr1[n1],arr2[n2];
    printf("Enter the no. of elements in array A :");
    scanf("%d",&n1);
    sarr(arr1,n1);
    parr(arr1,n1);
    printf("Enter the no. of elements in array b :");
    scanf("%d",&n2);
    sarr(arr2,n2);
    parr(arr2,n2);
    printf("The Union of array A and B is:");
    uni(arr1,arr2,n1,n2);
    return 0;
}