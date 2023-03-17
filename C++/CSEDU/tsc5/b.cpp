#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<pair<int,int>>vp(n);
    for (int i=0; i<n; i++)cin >>vp[i].first>>vp[i].second;
    int ans=1,mn=0,mx=n,cnt=1,preva,prevb;
    for (int i=0; i<n; i++){
        mn=max(mn,vp[i].first),mx=min(mx,vp[i].second);
        
    }   
    return 0;
}