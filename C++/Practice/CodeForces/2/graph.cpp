#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

//finding shortest path using bfs

vector <int> edge[1000], cost[1000];
const int inf=1e9;

//edge[i][j]= jth node connected with i;
// cost[i][j]= cost of the edge 

int bfs(int source, int dest){
    int dis[100];
    for(int i=0; i<100; i++) dis[i]=inf;

    queue <int> q;
    q.push(source);
    dis[source]=0;

    while (q.size()){
        int u=q.front(); q.pop()
    }
}

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    vector <int > adj[n];   
    bool vis[n];
    memset(vis, false, sizeof(vis));
    
    return 0;
}