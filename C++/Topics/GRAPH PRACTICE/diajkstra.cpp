#include <bits/stdc++.h>
using namespace std;

#define w(t) int t; cin >> t; while (t--)
#define ll long long int
#define en "\n"
const int inf = 1e9;

struct node {
    int u; int cost;
    node(int _u, int _cost) {    // ei part o bujhi nai
        u = _u;
        cost = _cost;
    }
    bool operator < (const node& p) const {   //operator overloading jeta ami bujhi nai
        return cost > p.cost;
    }
};

void diajkstra(vector<int> edg[],  vector<int> cost[], int source, int dest) {
    int dist[10000];
    for (int i = 0; i < 10000; i++) dist[i] = inf;

    priority_queue<node> q;    //similar to bfs, just use the priority queue instead of using queue
    q.push(node(source, 0));
    dist[source] = 0;

    while (!q.empty()) {
        node top = q.top();
        q.pop();
        int u = top.u;

        for (int i = 0; i < (int)edg[u].size(); i++) {
            int v = edg[u][i];

            if (dist[u] + cost[u][i] < dist[v]) {
                dist[v] = dist[u] + cost[u][i];
                q.push(node(v, dist[v]));
            }
        }
    }
    cout << dist[dest] << "\n";
}



int main () {
    vector<int>edg[10000], cost[10000];
    int numnodes, numedges;
    cin >> numnodes >> numedges;
    for (int i = 0; i < numedges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg [u].push_back(v);
        edg [v].push_back(u);
        cost [u].push_back(w);
        edg [v].push_back(w);
    }
    int source, destination;
    cin >> source >> destination;

    diajkstra(edg, cost, source, destination);
    return 0;
}