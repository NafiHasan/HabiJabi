#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const int inf=1e9;

void bfs(int n, vector<int>edges[], int *dist){
    queue<int> pq;
    for (int i = 0; i < n; i++) dist[i] = inf;
    dist[0] = 0;
    pq.push(0);
    while (!pq.empty()){
        int u = pq.front(); pq.pop();
        for (int j = 0; j < edges[u].size(); j++) {
            int v = edges[u][j];
            if ((dist[u] + 1) < dist[v]){
                dist[v] = dist[u] + 1;
                pq.push(v);
            }
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    w(t){
        int n, m;
        cin >> n >> m;
        int dist[n];
        vector<int>edges[n],parent[n];
        int dp[n][2];
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            parent[v].push_back(u);
            edges[u].push_back(v);
        }
        bfs(n,edges,dist);
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = dist[i];
            dp[i][1] = dist[i];
        }
        vector<int>topo;
        queue<int>p;
        int root,mn=INT_MAX;
        for (int i=0; i<n; i++){
            if (dist[i]<mn && parent[i].size()){
                mn=dist[i];
                root=i;
            }
        }
        p.push(root);
        bool vis[n];
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        dp[0][0]=0;
        dp[0][1]=0;
        while(p.size()){
            int u=p.front(); p.pop();
            for (int j=0; j<parent[u].size(); j++){
                //cout <<"came ";
                int v=parent[u][j];
                if (vis[v]==false){
                    p.push(v);
                    vis[v]=true;
                    int x = v, y = u;
                    if (dist[x] >= dist[y])
                    {
                        //dp[x][0] = min(dp[x][0], dp[y][0] + 1);
                        dp[x][1] = min(dp[x][1], dp[y][0]);
                        //dp[x][0] = min(dp[x][0],dist[x]);
                        //if (x==2 && y==0)cout <<dp[x][0]<<en;
                    }
                    else
                    {
                        dp[x][0] = min(dp[x][0], dp[y][0]);
                        //dp[x][0] = min(dp[x][0], dp[y][1]);
                        dp[x][1] = min(dp[x][1], dp[y][1]); // change krte hbe
                        //if (x==2 && y==5)cout <<dp[x][0]<<en;
                    }
                    //cout <<x<<" "<<dp[x][0]<<" "<< dp[x][1]<<en;
                }
            }
        }
        // for (int i=1; i<topo.size(); i++){
            
        // }
        for (int i=0; i<n; i++)cout <<min({dist[i],dp[i][0],dp[i][1]})<<" ";
        cout <<en;
    }   
    return 0;
}