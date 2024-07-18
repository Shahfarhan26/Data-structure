#include <stdio.h>

/* Program to find minimum and maximum of array. */
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
int findmax(int arr1[],int n){
    int i;
    int max = arr1[0];
    for (i = 0; i < n; i++)
    {
        if(arr1[i] > max){
            max = arr1[i];
        }
    }
    return max;  
}
int findmin(int arr1[],int n){
    int i;
    int min = arr1[0];
    for (i = 0; i < n; i++)
    {
        if(arr1[i] < min){
            min = arr1[i];
        }
    }
    return min;
}
int main() {
    int arr1[100], n, min, max;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    sarr(arr1, n);
    parr(arr1, n);
    min = findmin(arr1,n);
    max = findmax(arr1,n);
    printf("max = %d and min = %d.\n",max,min);
    return 0;
}
