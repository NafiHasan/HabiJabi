#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

const ll inf =1e18;
const ll mx=1e5+10;

// struct node{
//     ll u;
//     ll cost;
//     node(ll _u, ll _cost){
//         u=_u;
//         cost=_cost;
//     }
//     bool operator < (const node& p) const {
//         return cost > p.cost;
//     }
// };

vector<ll> diajkstra(ll n, vector<pair<ll, ll>>edg[]){
    vector<ll> dist(n+5,LLONG_MAX);
    priority_queue <pair<ll,ll>> q;
    q.push({0LL,1LL});
    dist[1]=(ll)0;
    int parent[n+1];
    memset(parent, -1, sizeof(parent));
    vector<bool>vis(n+1,0);
    while(!q.empty()){
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto i : edg[u]){
            int v=i.first , w=i.second;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
                q.push({-dist[v],v});   
            }
        }
    }
    // for (auto u : parent)cout << u << " " << parent[u] << en;
    bool ans=true;
    vector<int>path;
    path.push_back(n);
    for(int i=n; ;){
        if(parent[i]==1){
            path.push_back(1);
            break;
        }
        if(parent[i]!=-1){
            path.push_back(parent[i]);
            i=parent[i];
        }
        else {
            ans=false;
            break;
        }
    }
    if(ans){
        for(int i=path.size()-1; i>=0; i--)cout <<path[i]<<" ";
        cout <<"\n";
    }
    else cout << "-1\n";
    return dist;
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int n, e;
    cin >> n>> e;
    vector<pair<ll,ll>> edg[n+1];
    for(int i=0; i<e; i++){
        ll u, v,w;
        cin >> u >> v >> w;
        edg[u].push_back({v,w});
        edg[v].push_back({u,w});
        // cost[u].push_back(w);
        // cost[v].push_back(w);
    }
    vector<ll>dist(n+5);
    dist=diajkstra(n, edg);
    for (int i=1; i<=n; i++){
        cout << dist[i]<< en;
    }
    return 0;
}