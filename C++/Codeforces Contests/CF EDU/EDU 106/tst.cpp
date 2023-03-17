#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define all(x) (x).begin(), (x).end()
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define c(a) cout << a << "\n";
#define endl '\n'
const long long MOD = 11092019;
const int N = 4e3 + 2;
ll powmod(ll a, ll b, ll mod)
{
    ll res = 1;
    a %= mod;
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
    }
    return res;
}
int main()
{
    fastIO;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll ans = 1e18;
        rep(i, n) cin >> a[i];
        ll sum1 = a[0], sum2 = 0;

        ll ma = a[0], mi = 1e18;
        for (int i = 1; i < n; i++)
        {
            if (i % 2)
                mi = min(mi, a[i]), sum1 += a[i];
            else
                ma = min(ma, a[i]), sum2 += a[i];
            if (i % 2)
            {
                ans = min(ans, (n - ((i + 1) / 2)) * ma + sum2 + (n - ((i + 1) / 2)) * mi + sum1);
            }
            else
                ans = min(ans, (n - ((i + 2) / 2)) * ma + sum2 + (n - (i / 2)) * mi + sum1);
        }
        c(ans)
    }
    return 0;
}