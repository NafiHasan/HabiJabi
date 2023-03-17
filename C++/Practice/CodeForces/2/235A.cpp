#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

ll lcm(ll a, ll b, ll c){
    ll x=(a*b)/(__gcd(a,b));
    return (x*c)/(__gcd(x,c));
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n;
    cin >>n;
    if (n<3)cout <<n<<en;
    else if (n%2==1)cout <<n*(n-1)*(n-2)<<en;
    else  {
        ll ans=0;
        ans=max(lcm(n,n-1,n-3), lcm(n-1,n-2,n-3));
        cout << ans << en;
    }
    return 0;
}