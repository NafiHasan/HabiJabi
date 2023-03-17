#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define rep(i,a,n) for (int i=a; i<n; i++)
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


int main ()
{
    w(t){
        ll n,k;
        cin >>n>>k;
        vector<ll> v;
        for (ll i=0; i<n; i++){
            ll a;
            cin >>a;
            v.push_back(a);
        }
        sort (v.begin(),v.end());
        ll last=v.size()-1;
        for (ll i=0; i<k; i++){
            v[last]+=v[last-i-1];
            v[last-i-1]=0;
        }
        cout <<v[last]<<endl;
    }
    return 0;
}