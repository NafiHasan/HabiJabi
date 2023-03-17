#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
ll mod = 1000000000 + 7;
ll factorial[1000000 + 1];
ll bigmod(ll a, ll b)
{
    if (a == 0)
        return 1;
    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            product *= a;
            b--;
            product %= mod;
        }
        a *= a;
        a %= mod;
        b /= 2;
    }
    return product;
}
ll NcR(ll n, ll r)
{
    ll a = factorial[n];
    ll b = factorial[n - r] * factorial[r];
    b %= mod;
    b = bigmod(b, mod - 2);
    return (a * b) % mod;
}
int main()
{
    int t;
    scanf("%d", &t);
    factorial[0] = 1ll;
    for (ll i = 1; i < 1000000 + 1; i++)
    {
        factorial[i] = factorial[i - 1] * i;
        factorial[i] %= mod;
    }
    while (t--)
    {
        ll n;
        scanf("%lld", &n);
        ll a;
        ll ans = 0;
                cout << NcR(100000,1000) <<"\n";

        // printf("%d\n", bigmod(2, 10));
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &a);
            a %= mod;
            ll b = (NcR(n + 1, i + 1) - 1);
            //if(ans<0 || b<0)printf("%lld\n", ans);
            if(b<0)b+=mod;
            b%=mod;
            ll x=((a%mod)*(b%mod))%mod;
            ans += x;
            //if(ans<0)ans+=mod;
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
}