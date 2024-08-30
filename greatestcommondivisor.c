#include<stdio.h>
int gcd(int a,int b);
int main(){
    int a,b;
    printf("enter two  positive integers :\n");
    scanf("%d %d",&a,&b);
    printf("the greatest common integer between %d and %d is %d \n",a,b,gcd(a,b));
    return 0;
}
int gcd(int a,int b){
    if (b == 0)
    {
        return a;
    }else{
        return gcd(b , a % b);
    }
}