#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        ll n, k;
        cin >>n>>k;
        ll h[n];
        for (ll i=0; i<n; i++)cin >>h[i];
        ll base[n][2];
        for (int i=1; i<n; i++)base[i][0]=h[i];
        base[0][0]=base[0][1]=h[0];
        bool ans=true;
        for (ll i=1; i<n; i++){
            if (h[i]>=)
        }
        if (ans)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}