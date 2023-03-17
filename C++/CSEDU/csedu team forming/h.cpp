#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"
 
ll big=pow(10,9)+7;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    ll n,k,sum=1;
    cin >>n>>k;
    for(ll i=0; i<k; i++){
        ll x,y;
        cin >>x>>y;
    }
    for (ll i=2; i<=n; i++){
        sum*=i;
        sum%=big;
    }
    if (k!=0){
        sum/=n;
        ll p = n - (2 * k);
        ll ans = p * p * (p + 1) / 2;
        ans %= big;
        sum = (sum + ans) % big;
    }
    cout <<sum<<endl;
    return 0;
}