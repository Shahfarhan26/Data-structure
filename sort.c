#include <stdio.h>

/* Program to change the order of the array to ascending or descending. */
void sarr(int arr1[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
}

void parr(int arr1[], int n) {
    printf("The elements of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}
void ascend(int arr1[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if(arr1[j] > arr1[j + 1]){
                int temp = arr1[j];
                arr1[j] = arr1[j +1];
                arr1[j + 1] = temp;
            }
        }
        
    }
    
}
void descend(int arr1[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if(arr1[j] < arr1[j + 1]){
                int temp = arr1[j];
                arr1[j] = arr1[j +1];
                arr1[j + 1] = temp;
            }
        }
        
    }
}
int main() {
    int arr1[100], n, x, max;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    sarr(arr1, n);
    parr(arr1, n);
    printf("enter '0' for ascending order,'1' for descending order:-\n");
    scanf("%d",x);
    if(x==0){
        ascend(arr1,n);
    }else if(x == 1){
        descend(arr1,n);
    }
    parr(arr1,n);
    return 0;
}