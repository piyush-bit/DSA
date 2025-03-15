// wap to find the generic root of a number 
#include<stdio.h>

int genric_root(int x ){
    if(x<10)
    return x;

    int sum =0 ; 
    int n = x ;
    while (n>0){
        sum+=n%10;
        n/=10;
    }

    return genric_root(sum);
}

int main (){
    int x ;
    printf("Enter the number");
    scanf("%d",&x);
    printf("%d",genric_root(x));
    return 0;
}