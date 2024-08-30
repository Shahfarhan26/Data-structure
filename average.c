#include <stdio.h>

/* Program to find the average of all the elements in an array. */
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
float avg(int arr1[],int n){
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum = sum + arr1[i];
    }
    return (sum/n);
}
int main() {
    int arr1[100], n, i, v;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    sarr(arr1, n);
    parr(arr1, n);
    float x;
    x = avg(arr1,n);
    printf("the average of all the elements in the array = %8.2f\n",x);
    return 0;
}