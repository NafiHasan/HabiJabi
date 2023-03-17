#include <stdio.h>
int main()
{
    bool prime[100010];
    for (int i=0; i<100010; i++)prime[i]=true;
    prime[1]=false;
    for (int i=2; i*i<=100010; i++){
        if (prime[i]){
            for (int j=i+i; j<100010; j+=i){
                prime[j]=false;
            }
        }
    }
    long long int sum[100010];
    for (int i=0; i<100010; i++)sum[i]=(long long int)0;
    for (int i=2; i<100010; i++){
        if (prime[i])sum[i]+=(long long int)i;
        sum[i]+=sum[i-1];
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d %d",&m,&n);
        printf("%lld\n",sum[n]-sum[m-1]);
    }
    return 0;
}