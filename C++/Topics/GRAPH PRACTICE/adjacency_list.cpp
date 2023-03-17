#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const int inf=1e9;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int nodes, N_edges;
    cin >> nodes >> N_edges;
    vector <int >edge[N_edges];
    for(int i=0; i<N_edges; i++){
        int x,y;   // there is an edge between x and y
        cin >>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    int dist[nodes];
    for(int i=1; i<=nodes; i++)dist[i]=inf;
    int source, dest;
    cin >>source>> dest;
    queue<int>q;
    q.push(source);
    dist[source]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<edge[u].size(); i++){
            int v= edge[u][i];
            if(dist[v]>dist[u]){
                q.push(edge[u][i]);
                dist[v] = dist[u] + 1;
            }
        }
    }
    cout << dist[dest]<<en;
    return 0;
}