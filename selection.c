#include<stdio.h>
void selection_sort(int ar[], int len);
void scan_arr(int arr[],int len);
void print_arr(int arr[],int len);
int main(){
    int len;
    printf("Enter the No. of elements :\n");
    scanf("%d",&len);
    int arr[len];
    scan_arr(arr,len);
    selection_sort(arr,len);
    print_arr(arr,len);
    return 0;
}
void selection_sort(int arr[], int len){
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
            {
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        
    }
    
}
void print_arr(int arr[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",arr[i]);
        printf("\t");
    }
    
}
void scan_arr(int arr[],int len){
    printf("ENTER THE ELEMENTS FOR THE ARRAY:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&arr[i]);
    } 
}