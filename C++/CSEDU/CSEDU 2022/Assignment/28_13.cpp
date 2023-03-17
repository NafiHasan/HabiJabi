#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    int a=9, d=6;
    int sum=(n*(2*a+((n-1)*d)))/2;
    printf("%d\n",sum);
    return 0;  
}