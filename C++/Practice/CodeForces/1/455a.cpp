#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
#define en "\n"

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n;
    cin >>n;
    ll ara[n];
    map<ll, ll> m;
    vector<ll> v;
    for (ll i=0; i<n; i++){
        cin >> ara[i];
        m[ara[i]]++;
    }
    sort (ara,ara+n);
    v.push_back(ara[0]);
    for (ll i=1; i< n; i++)if (ara[i]!=ara[i-1])v.push_back(ara[i]);
    ll dp[v[v.size()-1]];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[v[0]]=m[v[0]]*v[0];
    for (ll i=1; i<v.size(); i++){
        if (v[i]-v[i-1]==1 && i>1)dp[v[i]] = max(dp[v[i-1]], dp[v[i - 2]] + m[v[i]] * v[i]);
        else if (i == 1 && v[i] - v[i - 1] == 1)
            dp[v[i]] = max(dp[v[i - 1]], m[v[i]] * v[i]);
        else
            dp[v[i]] = dp[v[i-1]]+m[v[i]]*v[i];
    }
    cout <<dp[v[v.size()-1]]<<en;
    return 0;
}