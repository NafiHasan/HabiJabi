#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    //ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll n,g,b;
        cin >> n >> g >> b;
        ll half=(n+1)/2;
        if (g>=half || b<=g)cout <<n<<en;
        else {
            ll cnt=(half-1)/g;
            ll ans=cnt*b;
            ans+=half;
            cout << max(ans,n) << en;
        }
    }
    return 0;
}