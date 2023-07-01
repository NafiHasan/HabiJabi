#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

ll ncr(ll n){
    ll ans=1;
    for(ll i=n, j=1; j<=3; j++, i--)ans*=i;
    ans/=6;
    return ans;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        ll n;
        cin >>n;
        ll ara[n];
        for (ll i=0; i<n; i++)cin>>ara[i];
        sort (ara,ara+n);
        ll sum=0;
        for (ll i=0; i<n; i++){
            if (i && ara[i]==ara[i-1])continue;
            ll cnt=0;
            for (ll j=i; j<n ; j++){
                if (ara[j]-ara[i]>2)break;
                cnt++;
            }
            if (cnt>=3) sum+=ncr(cnt);
        }
        cout <<sum<<en;
    }   
    return 0;
}