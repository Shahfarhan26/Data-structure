#include<stdio.h>
void merge(int a[], int mid,int hi,int lo);
void merge_sort(int a[], int lo,int hi);
void scan_arr(int a[],int len);
void print_arr(int a[],int len);
int main(){
    int len;
    printf("Enter the No. of elements :\n");
    scanf("%d",&len);
    int a[len];
    scan_arr(a,len);
    merge_sort(a,0,len-1);
    print_arr(a,len);
    return 0;
}
void merge(int a[], int mid,int hi,int lo){
    int i,j,k,b[hi + 1];
    i = lo;
    j = mid + 1;
    k = lo;

    while (i <= mid && j <= hi)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++; 
            k++;
        }else{
            b[k] = a[j];
            j++; 
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++; 
        k++;
    }
    while (j <= hi)
    {
        b[k] = a[j];
        j++; 
        k++;
    }
    for (int i = lo; i <= hi; i++)
    {
        a[i] = b[i];
    }
    
    
}
void merge_sort(int a[], int lo,int hi){
    int mid;
    if (lo < hi)
    {
        mid = (lo + hi)/2;
        merge_sort(a,lo,mid);
        merge_sort(a,mid + 1,hi);
        merge(a,mid,hi,lo);
    }
    
}
void print_arr(int a[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    
}
void scan_arr(int a[],int len){
    printf("ENTER THE ELEMENTS FOR THE ARRAY:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&a[i]);
    } 
}