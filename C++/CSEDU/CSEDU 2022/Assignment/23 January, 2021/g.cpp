#include <stdio.h>
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    bool prime[b+5];
    for (int i =0; i<b+5; i++)prime[i]=true;
    prime[1]=false;
    for(int i=2; i*i<=b+5; i++){
        if (prime[i]==true){
            for (int j=i+i; j<b+5; j+=i)prime[j]=false;
        }
    }
    for (int i=a; i<=b; i++){
        if (prime[i])printf("%d\n",i);
    }
    return 0;
}