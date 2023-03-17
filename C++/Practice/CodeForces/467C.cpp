#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll n, m ,k;
    cin >> n >> m >> k;
    ll a[n];
    for (ll i=0; i<n; i++)cin >> a[i];
    sort (a,a+n, greater<ll>());
    ll ans=0;
    for (int i=0; i<(m*k); i++) ans +=a[i];
    cout << ans << en;
    return 0;
}