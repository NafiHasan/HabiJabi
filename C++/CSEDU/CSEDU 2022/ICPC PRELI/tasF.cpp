#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>primes;
void bitwise_seive()
{
    int arr[(1000000>> 6) + 1];
    memset(arr,0,sizeof(arr));
    for (int i = 3; i*i <= 1000000; i+= 2)
    {
        if(!(arr[i >> 6 ] & (1 << ((i >> 1) & 31)))){
            for (int j = i*i; j <= 1000000; j+=2*i)
            {
                arr[j >> 6] |= (1 << ((j >> 1) & 31));
            }
            
        }
    }
    primes.push_back(2);
    for (int i = 3; i <= 1000000; i+=2)
    {
        if(!(arr[i >> 6 ] & (1 << ((i >> 1) & 31)))){
            primes.push_back(i);
        }
    }
    
}
int main()
{
    bitwise_seive();
    // printf("%d\n",primes.size());
    // for (int i = 0; i < 25; i++)
    // {
    //     printf("%lld ",primes[i]);
    // }
    // printf("\n");
    int t;
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++)
    {
        ll a, b, m;
        scanf("%lld %lld %lld", &a, &b, &m);
        if(a > b)swap(a, b);
        ll ans = m+1;
        if(a==b){
            printf("Case %d: 0\n",tc);
            continue;
        }
        bool zero = false;
        vector<ll>v;
        for (int i = 0; primes[i] <= b && i < primes.size(); i++)
        {
            if(a%primes[i]==b%primes[i]){
                if(!zero){
                    if(a%primes[i]==0){
                        ans--;
                        zero = true;
                    }
                }
                v.push_back(primes[i]);
                ll c = a%primes[i];
                ll d = (m+c)/primes[i];
                ans -= d;
                for(int j = 0;j < v.size()-1 && d  > 0; j++){
                    ans += d/v[j];
                    d/= v[j];
                }
            }
        }
        printf("Case %d: %lld\n",tc,ans);
    }
    
}