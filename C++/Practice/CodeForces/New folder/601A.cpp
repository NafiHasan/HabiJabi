#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"

const int inf=1e9;
vector<int>ed_train[100000], ed_bus[100000];

int bfs(int n, vector<int>edges[]){
    int dist[n];
    for(int i=0; i<n; i++)dist[i]=inf;
    dist[0]=0;
    queue <int>q;
    q.push(0);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0; i<edges[u].size(); i++){
            int v=edges[u][i];
            if(dist[v] > dist[u] + 1){
                dist[v]= dist[u] +1;
                q.push(v);
            }
        }
    }
    return dist[n-1];
}

int main ()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >>n>>m;
    map<pair<int,int>,int> train;
    for(int i=0; i<m; i++){
        int u,v;
        cin >>u>>v;
        u--;v--;
        ed_train[u].push_back(v);
        ed_train[v].push_back(u);
        train[{min(u,v), max(u,v)}]++;
    }
    int t=bfs(n,ed_train);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(train[{i,j}]==0){
                ed_bus[i].push_back(j);
                ed_bus[j].push_back(i);
            }
        }
    }
    int b=bfs(n, ed_bus);
    if(t==inf || b==inf){
        cout << "-1\n";
        return 0;
    }
    else {
        cout <<max(b,t)<<en;
    }
    return 0;
}