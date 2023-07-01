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
        ll n, x;
        cin >>n>>x;
        ll a[n],sum=0,mx=LLONG_MAX;
        for (ll i=0; i<n; i++){
            cin >>a[i];
            ll cnt=1;
            ll num=a[i];
            while(num%x==0){
                num/=x;
                cnt++;
            }
            mx=min(mx,cnt);
        }
        mx++;
        for (ll i=0; i<n; i++){
            ll cnt=1, num=a[i];
            while(num%x==0 && cnt<mx){
                cnt++;
                num/=x;
            }
            sum+=cnt*a[i];
            mx=min(mx,cnt);
        }
        cout <<sum<<en;
    }   
    return 0;
}