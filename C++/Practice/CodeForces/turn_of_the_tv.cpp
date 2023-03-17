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
    
    int n;
    cin >> n;
    vector<pair<int,int>>vp;
    for (int i=0; i<n; i++){
        int x,y;
        cin >>x>>y;
        vp.push_back(make_pair(x,y));
    }   
    int ans=-1;
    sort(vp.begin(), vp.end());
    for (int i=0; i<n-1; i++){
        if (i==0 && n>1 && vp[i].first >= vp[i+1].first && vp[i].second <=vp[i+1].second)ans=i+1;
        else if (i && i<n-1 && n>2 && vp[i].first <= vp[i-1].second && vp[i].second >= vp[i+1].first )ans=i+1;
        else if (i && vp[i].first>=vp[i-1].first && vp[i].second<=vp[i-1].second)ans=i+1;
    }
    cout <<ans<<en;
    return 0;
}