#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

const ll p=1e9+7;

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll x,y,n;
    cin >> x >> y >>n;
    ll z=y-x;
    ll ans;
    if (n%3LL==0LL)ans=z;
    else if (n%3LL==1LL) ans =x;
    else ans=y;
    // cout << ans <<en;
    ll pos=n/3LL;
    // cout << pos<<en;
    if (n%3)pos++;
    if (pos%2){
            while(ans<0)ans+=p;
            cout << ans%p<<en;
    }
    else {
        ans*=-1LL;
        while(ans<0)ans+=p;
        cout << ans%p <<en;
    } 
    return 0;
}