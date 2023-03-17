#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N], dfsTime(N), low(N);
vector<bool> vis(N, 0);
int timer = 0;
vector<pair<int, int>> bridges;

void dfs(int u, int par) {
	vis[u] = 1;
	dfsTime[u] = low[u] = ++timer;
	for (int v : edge[u]) {
		if (v == par)
			continue; // don't visit the parent node
		if (vis[v]) {  // cross edge
			low[u] = min(low[u], dfsTime[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfsTime[u]) {  // checking among the back edges
				// u->v is a bridge
				bridges.push_back({min(u, v), max(u, v)});
			}
		}
	}
}

void find_bridges(int n) {
	bridges.clear();
	timer = 0;
	vis.assign(n, 0);
	low.assign(n, -1);
	dfsTime.assign(n, -1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i, -1);
	}
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
			edge[i].clear();
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		find_bridges(n);
		sort(bridges.begin(), bridges.end());
		cout << "Caso #" << cs << '\n';
		if (bridges.size() == 0) {
			cout << "Sin bloqueos\n";
		} else {
			cout << bridges.size() << '\n';
			for (pair<int, int> x : bridges) {
				cout << x.first << ' ' << x.second << '\n';
			}
		}
	}
	return 0;
}