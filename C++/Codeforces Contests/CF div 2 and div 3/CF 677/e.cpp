#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define endl "\n"


ll fact(ll n){
    ll sum=1;
    for (ll i=1; i<=n; i++)sum*=i;
    return sum;
}
ll comb(ll n,ll x){
    ll sum=1;
    ll xmax=max(x,(n-x));
    ll xmin=min(x,(n-x));
    for (int i=n; i>xmax; i--)sum*=i;
    sum/=fact(xmin);
    return sum;
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n,sum=1;
    cin >>n;
    sum*=comb(n,n/2);
    sum/=2;
    sum*=fact(n/2-1)*fact(n/2-1);
    cout <<sum<<endl;
    return 0;
}