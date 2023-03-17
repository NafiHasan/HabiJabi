#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e5 + 5;

int n, m;
set<int> adj[MAX_N];

// print the euler circuit in an undirected graph
void euler() {
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    vector<int> res;
    stack<int> st; st.push(1);
    while (st.size()) {
        int u = st.top();
        if (adj[u].empty()) {
            res.push_back(u);
            st.pop();
        } else {
            int v = *adj[u].begin();
            adj[u].erase(v);
            adj[v].erase(u);
            st.push(v);
        }
    }
    if ((int) res.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (int u : res) cout << u << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    euler();
}