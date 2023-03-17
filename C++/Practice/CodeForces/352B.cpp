#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
#define si 100005
int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    map<int,int>m;
    for (int i=0; i<n; i++)cin >> a[i];
    vector<int>v[si+5];
    // int prev1=-1, prev2=-1, cur=-1;
    for (int i=0; i<n; i++){
        if (m[a[i]]==-1)continue;
        v[a[i]].push_back(i);
        if (v[a[i]].size()>2){
            int last=v[a[i]].size()-1;
            if (v[a[i]][last]-v[a[i]][last-1] != v[a[i]][last-1]-v[a[i]][last-2])
                m[a[i]]=-1;
        }
    }
    vector <pair<int,int>>ans;
    for (int i=1; i<si ; i++){
        if (m[i]==-1 || v[i].size()==0)continue;
        if (v[i].size()==1)
            ans.push_back({i,0});
        else ans.push_back({i,v[i][1]-v[i][0]});
    }
    cout << ans.size() << en;
    for (int i=0; i<ans.size(); i++)cout << ans [i].first << " " << ans[i].second<<en; 
    return 0;
}