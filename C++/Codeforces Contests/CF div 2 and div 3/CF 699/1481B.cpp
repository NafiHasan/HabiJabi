#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll n,k;
        cin >>n>>k;
        ll a[n];
        for (ll i=0; i<n; i++)cin >>a[i];
        if (n==1)cout <<"-1\n";
        else {
            ll ans=0;
            for (ll i = 0; i < n-1; i++)
            {
                if (!i && a[i+1] > a[i]){
                    if (a[i+1]-a[i] <= k){
                        k -= a[i + 1] - a[i];
                        a[i] = a[i + 1];
                    }
                    else {
                        k=0;
                        ans = i + 1;
                        break;
                    }
                    if (k==0){
                        ans=i+1;
                        break;
                    }
                }
                else if (i && a[i+1]>a[i]){
                    ll inc=min(a[i-1]+1, a[i+1]);
                    if (inc-a[i] <= k){
                        k -= inc - a[i];
                        a[i]=inc;
                    }
                    else {
                        k=0;
                        ans=i+1;
                        break;
                    }
                    if (k==0){
                        ans=i+1;
                        break;
                    }
                    if (a[i]<a[i+1] || a[i]>a[i-1])i-=2;
                }
                //cout <<a[i]<<" " <<i<< " \n";
            }
            if (k)cout <<"-1\n";
            else cout <<ans<<en;
        }
    }
    return 0;
}