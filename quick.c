#include<stdio.h>
int part(int a[],int lo,int hi);
void quick_sort(int a[], int lo,int hi);
void scan_arr(int a[],int len);
void print_arr(int a[],int len);
int main(){
    int len;
    printf("Enter the No. of elements :\n");
    scanf("%d",&len);
    int a[len];
    scan_arr(a,len);
    print_arr(a,len);
    printf("after sort \n");
    quick_sort(a,0,len-1);
    print_arr(a,len);
    return 0;
}
int part(int a[],int lo,int hi){
    int i,j,temp,p;
    i = lo;
    j = hi;
    p = a[lo];

    do
    {
        while (a[i] <= p)
        {
            i++;
        }
        while (a[j] > p)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[lo];
    a[lo] = a[j];
    a[j] = temp;
    return j;
}
void quick_sort(int a[], int lo,int hi){
    int pi;
    if (lo < hi)
    {
        pi = part(a,lo,hi);
        quick_sort(a,lo,pi - 1);
        quick_sort(a,pi + 1,hi);
    }
    
}
void print_arr(int a[],int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d",a[i]);
        printf("\t");
    }
    printf("\n");
    
}
void scan_arr(int a[],int len){
    printf("ENTER THE ELEMENTS FOR THE ARRAY:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&a[i]);
    } 
}