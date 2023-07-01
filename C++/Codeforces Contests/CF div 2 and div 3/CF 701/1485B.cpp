#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    ll n,q,k;
    cin >>n>>q>>k;
    ll a[n];
    for (ll i=0; i<n; i++)cin >>a[i];
    ll pre[n+1];
    for (ll i=0; i<n; i++){
        if (i==0)pre[i]=a[i+1]-2;       //check
        else if (i<n-1) pre[i]=a[i+1]-a[i-1]-2;
        else pre[i]=k-a[i-1]-1;
        //cout <<pre[i]<<" ";
    }
    ll sum[n+1];
    sum[0]=0;
    for (ll i=1; i<=n; i++){
        sum[i] = sum[i - 1] + pre[i - 1];
        //cout <<sum[i]<<" ";
    }
    while(q--){
        ll l,r,p;
        cin >>l>>r;
        if (r-l==1){
            ll x=k-a[r-2]+a[l]-3;
            cout <<max(x,0LL)<<en;
            continue;
        }
        else if (r==l){
            cout <<k-1<<en;
            continue;
        }
        else {
            p = a[l] - 2 + k - a[r - 2]-1;
            if (p < 0)
                p = 0;
            cout << p + sum[r-1] - sum[l] << en;
        }
    }
    return 0;
}