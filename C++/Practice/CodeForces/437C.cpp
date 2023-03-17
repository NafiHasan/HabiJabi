#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"


int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    ll w [n], cost[n];
    memset(w,0LL,sizeof(w));
    for (int i=0; i<n; i++)cin >> cost[i];
    vector<int>edges[n];
    for (int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        u--,v--;
        edges[u].push_back(v);
        w[u]+=cost[v];
        edges[v].push_back(u);
        w[v]+=cost[u];
    }
    //for (int i=0; i<n; i++) cout << w[i] << " ";
    //cout << en;
    map<int,int>cut;
    int cnt=0;
    long long ans=0;
    while (cnt<=n){
        int ind;
        ll mn=-1, own=-1;
        for (int j=0; j<n; j++){
            if (cut[j]==0 && mn<cost[j]){
                mn=cost[j];
                ind=j;
                own=w[j];
            }
            else if (cut[j]==0 && mn==cost[j]){
                if (w[j]<own){
                    mn = cost[j];
                    ind = j;
                    own = w[j];
                }
            }
        }
        ans+=w[ind];
        //cout << ind << " " << w[ind] << en;
        cut[ind]++;
        for (int j=0; j<edges[ind].size(); j++){
            int v = edges[ind][j];
            if (cut[v]==0){
                w[v] -= cost[ind];
            }
        }
        cnt++;
    }
    cout << ans << en;
    return 0;
}