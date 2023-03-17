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

    ll n,w;
    cin >>n>>w;
    vector <pair<pair<ll,ll>,ll>>vp;
    for (int i=0;i <n; i++){
        ll x,y,z;
        cin >>x>>y>>z;
        vp.push_back(make_pair(make_pair(x,y),z));
    }
    sort (vp.begin(), vp.end());
    //for (int i=0; i<n; i++)cout <<vp[i].first.first<<" "<<vp[i].first.second<<" "<<vp[i].second<<en;
    ll cost=vp[0].second,last=vp[0].first.second;
    //cout <<vp[0].first.second<<en;
    ll hi=0;
    for (int i=1; i<n; i++){
        if (vp[i].first.first < last) {
            cost += vp[i].second;
            hi=max(hi,cost);
        } 
        else {
            hi=max(hi,cost);
            cost=vp[i].second;
        }
        ll l=vp[i].first.second;
        last = max(last,l);
    }
    //ll ans=*max_element(v.begin(),v.end());
    cout <<hi<<en;
    if (hi>w)cout <<"No\n";
    else cout <<"Yes\n";
    return 0;
}