#include <stdio.h>
int main(){
    long long m,n;
    scanf("%lld %lld", &m, &n);
    printf("%lld\n%lld\n%lld\n%lld\n%lld\n",m+n,m-n,m*n,m/n,m%n);
    return 0;
}