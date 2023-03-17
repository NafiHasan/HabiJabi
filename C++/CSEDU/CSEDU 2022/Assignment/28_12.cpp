#include<stdio.h>

int main (){
    int n;
    scanf("%d", &n);
    printf("%d! = ",n);
    long long ans=1;
    int i=n;
    while(i>=1){
        ans*=(long long)i;
        if (i==n && i!=1)printf("%d X ",i);
        else if (i==1)printf("1 = ");
        else printf("%d X ",i);
        i--;
    }
    printf("%lld\n", ans);
    return 0;
}