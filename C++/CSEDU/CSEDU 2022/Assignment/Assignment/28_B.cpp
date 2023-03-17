#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    // checking for prime numbers
    bool prime [300];
    for(int i=1; i<300; i++) prime[i]=true;
    prime [1]=false;
    for(int i=2; i*i<=300; i++){
        if(prime[i]){
            for(int j=i+i; j<=300 ; j+=i) prime[j]=false;
        }
    }
    // calculating sum for the primes 
    long long sum_primes[300];
    for(int i=0; i<255; i++)sum_primes[i]=0;
    for(int i=1; i<255; i++){
        for(int j=1; j<=i; j++){
            if(prime[j] && j<i)sum_primes[i]+=sum_primes[j];
            else sum_primes[i]+=j;
        }
    }
    printf("%lld\n",sum_primes[n]);
    return 0;
}