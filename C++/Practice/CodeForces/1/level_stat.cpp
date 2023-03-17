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
        int n;
        cin >>n;
        vector<pair<int,int>>vp;
        for (int i=0; i<n; i++){
            int x,y;
            cin >>x>>y;
            vp.push_back(make_pair(x,y));
        }
        int cnt=1;
        for (int i=0; i<n; i++){
            if (i && (vp[i].first <vp[i-1].first || vp[i].second <vp[i-1].second)){
                cnt=0;break;
            }
            else if (i && ((vp[i].first-vp[i-1].first)<(vp[i].second-vp[i-1].second))){
                cnt=0;break;
            }
            else if (vp[i].first<vp[i].second){
                cnt=0; break;
            }
        }
        (cnt==1? cout <<"YES\n" : cout <<"NO\n");
    }   
    return 0;
}