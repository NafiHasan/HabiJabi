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
    ll n,k;
    cin >>n>>k;
    vector<ll>v;
    v.push_back(1);
    if (n!=1)v.push_back(n);
    ll lim=sqrt(n+1);
    for (ll i=2; i<=lim; i++){
        if (n%i==0){
            v.push_back(i);
            if (i!=(n/i))v.push_back(n/i);
        }
    } 
    sort (v.begin(),v.end());
    if (k>v.size())cout <<"-1\n";
    else cout <<v[k-1]<<endl;
    return 0;
}