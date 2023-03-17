#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const ll p=1e9+7;
ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    ll ans = 1;
    r = min(r, n - r);
    for (ll i = n, j = 1; j <= r; j++, i--)
    {
        ans *= i;
        ans/=j;
        ans %= p;
        //cout <<ans<<" ";
    }
    // ll fac=1;
    // for (ll i = r; i >= 1; i--){
    //     ans /= i;
    //     cout <<ans<<" ";
    // }
    return ans%p;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n,r;
    cin >>n>>r;
    cout <<ncr(n,r);
    return 0;
}