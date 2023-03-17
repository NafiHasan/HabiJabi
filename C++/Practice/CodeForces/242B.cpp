#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int mn=INT_MAX, mx=0;
    vector<pair<int,int>>v(n);
    for (int i=0; i<n; i++){
        cin >> v[i].first  >> v[i].second;
        mn=min(mn,v[i].first);
        mx=max(mx,v[i].second);
    }
    int ans=-1;
    for (int i=0; i<n; i++){
        if (v[i].first<=mn && v[i].second>=mx){
            ans=i+1;
            break;
        }
    }
    cout << ans<< en;
    return 0;
}