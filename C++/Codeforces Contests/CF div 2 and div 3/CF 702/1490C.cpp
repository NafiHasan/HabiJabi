#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    w(t){
        ll n;
        cin>>n;
        bool found=false;
        for (ll i=1; i*i*i<=n && !found; i++){
            ll lo=1,hi=10000,mid;
            while(lo<=hi){
                mid=(lo+hi)/2;
                if (mid*mid*mid+i*i*i == n){
                    found=true;
                    break;
                }
                else if (mid * mid * mid + i * i * i > n)hi=mid-1;
                else lo=mid+1;
            }
        }
        if (found)cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}