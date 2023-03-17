#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    ll a=79, b=83;
    ll ans=0;
    for (ll i=3; ;i++){
        if ((ll)(i * (i-1) *(i-2)) % (ll)79 == 0 && (ll)(i * (i-1) * (i - 2)) % (ll)83 == 0){
            ans=i;
            break;
        }
    }   
    cout<<ans<<en;
    return 0;
}