#include <stdio.h>
#include <math.h>
/* Program to find the standard deviation and variance.*/
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
float mean(int arr1[],int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr1[i];
    }
    return (float)(sum/n);
}
float vari(int arr1[],int n,float avg){
    int v = 0;
    for (int i = 0; i < n; i++)
    {
        v = v + pow(arr1[i] - avg,2);
    }
    return (float)v/n;
}
int main() {
    int arr1[100], n;
    float avg,sd,var;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    sarr(arr1, n);
    parr(arr1, n);
    avg = mean(arr1,n);
    var = vari(arr1,n,avg);
    sd = sqrt(var);
    printf("avg = %8.2f \n",avg);
    printf("var = %8.2f \n",var);
    printf(" sd = %8.2f \n",sd);
    return 0;
}