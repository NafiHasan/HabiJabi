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
    
    w(t){
        int n,k;
        cin >>n>>k;
        vector<pair<int,int>>vp;
        for (int i=0; i<n; i++){
            int x,y;
            cin >>x>>y;
            vp.push_back(make_pair(x,y));
        }
        int mx=0;
        vector <int>hi;
        for (int i=0; i<n; i++){
            mx=0;
            for (int j=0; j<n; j++){
                mx = max(mx, (abs(vp[j].first - vp[i].first) + abs(vp[j].second - vp[i].second)));
            }
            hi.push_back(mx);
        }
        int ans=*min_element(hi.begin(), hi.end());
        if (ans<=k)cout <<"1\n";
        else cout <<"-1\n";
    }
    return 0;
}