#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    int ara[n+5];
    ara[0]=0;
    ara[1]=1;
    for (int i=2; i<=n; i++) ara[i]=ara[i-1]+ara[i-2];
    printf("%d\n",ara[n]);
    return 0;
}