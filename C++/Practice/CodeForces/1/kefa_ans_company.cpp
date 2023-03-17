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
    
    ll n,d,best=0;
    cin >>n>>d;
    vector<pair<ll,ll>>vp;
    for (ll i=0; i<n; i++){
        ll x,y;
        cin >>x>>y;
        vp.push_back(make_pair(x,y));
        best=max(best,y);
    }   
    sort (vp.begin(), vp.end());
    ll cnt=vp[0].second,curnt=0;
    for (ll i=1; i<n; i++){
        while (vp[i].first - vp[curnt].first >= d){
            cnt-= vp[curnt].second;
            curnt++;
        }
        if (vp[i].first-vp[curnt].first<d){
            cnt += vp[i].second;
            best=max(cnt,best);
        }
        
    }
    cout <<best<<en;
    return 0;
}