#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        ll n,q;
        cin >>n>>q;
        vector<pair<int,int>>vp;
        ll point[n];
        memset(point,0,sizeof(point));
        ll mx=0;
        ll win=1,mom=0;
        for (ll i=0; i<q; i++){
            int x,y;
            cin >>x>>y;
            point[x-1]+=y;
            vp.push_back(make_pair(x,y));
        }
        for (int i=0; i<n; i++){
            if (point[i]>mx){
                mx=point[i];
                win=i;
            }
            else if (point[i]==mx && win>i){
                win=i;
            }
        }
        ll sum[]=;
        for (ll i=0;i<vp.size(); i++){
            
            if (i==win && point[i]==mx)mom=
        }
        cout <<mom<<en;
    }   
    return 0;
}