#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n,k; cin >>n>>k;
    ll ans=0;
    while(n){
        n/=k;
        ans+=n;
    }
    cout << ans <<en;
    return 0;
}