#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

struct node{
    int u,cost;
    node(int _u, int _cost){
        u=_u;
        cost=_cost;
    }
    bool operator < (const node& p) const{
        return cost > p.cost;
    }
};

void dijkstra(int n, vector<int> edg[], vector<int>cost[]){
    int dist[n+1];
    for(int i=0; i<n+1; i++)dist[i]=1e9;
    priority_queue<node>q;
    q.push(node(1,0));
    dist[1]=0;
    vector<int>bests;
    while(!q.empty()){
        node top=q.top();
        q.pop();
        int u=top.u;
        for(int i=0; i<edg[u].size(); i++){
            int v=edg[u][i];
            //cout <<v<<" ";
            if (v == n)
                bests.push_back(dist[u]+cost[u][i]);
            if (dist[u] + cost[u][i] < dist[v]){
                dist[v]=dist[u]+cost[u][i];
                q.push(node(v,dist[v]));
            }
            if(v==n)bests.push_back(dist[u]+cost[u][i]);
        }
    }
    sort(bests.rbegin(), bests.rend());
    for(int i=0; i<n; i++)cout << bests[i]<<" ";
}

int main ()
{
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int tc=1;
    w(t){
        int n, e;
        cin >>n>> e;
        int mx=max(n+1, e+1);
        vector<int>edg[mx], cost[mx];
        for(int i=0; i<e; i++){
            int u,v,w;
            cin >> u>> v>> w;
            edg[u].push_back(v);
            edg[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijkstra(n,edg,cost);
    }
    return 0;
}