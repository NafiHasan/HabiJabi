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
        ll n;
        cin>>n;
        ll a[n], val[n];
        bool vis[n];
        for (ll i=0; i<n; i++){
            cin >>a[i];
            vis[i]=false;
            val[i]=a[i];
        }
        for (ll i=0; i<n; i++){
                ll j = i + a[i];
                if (j < n){
                    val[j] = max(val[j],val[i]+a[j]);
                }
        }
        cout <<*max_element(val,val+n)<<en;
    }
    return 0;
}