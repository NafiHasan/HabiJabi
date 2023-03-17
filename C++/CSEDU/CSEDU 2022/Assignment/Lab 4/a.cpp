#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    long long int a[n];
    for (int i=0; i<n; i++) scanf("%lld",&a[i]);
    long long int best=0,cnt=0;
    for (int i=0; i<n; i++){
        if (cnt+a[i]>0)cnt+=a[i];
        else cnt=0;
        if (best<cnt)best=cnt;
    }
    printf("%lld\n",best);
    return 0;
}