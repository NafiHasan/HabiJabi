#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

struct LCA {
	vector<int> tin, tout;
	vector<vector<int>> par;
	vector<bool> vis;
	int timer = 0;
	int Log = 25, N;
	LCA(int n, vector<int> edge[]) {
		N = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < edge[i].size(); j++) {
				// adj[i].push_back(edge[i][j]);
			}
		}
		Log = ceil(log2(n)) + 2;
		tin.resize(n + 5);
		tout.resize(n + 5);
		par.assign(n + 5, vector<int> (Log, -1));
		// par.resize(n + 5, vector<int> (Log));
		vis.resize(n + 5);
		// dfs(0);
		// preProcess();
	}

	int isAncestor(int u, int v) {
		if (tin[u] <= tin[v] && tout[u] >= tout[v])return u;
		if (tin[v] <= tin[u] && tout[v] >= tout[u])return v;
		return -1;
	}

	void dfs(int u) {
		vis[u] = 1;
		tin[u] = timer++;
		// for (int v : adj[u]) {
		// 	if (!vis[v]) {
		// 		dfs(v);
		// 		par[v][0] = u;
		// 	}
		// }
		tout[u] = timer++;
	}

	void preProcess() {
		for (int i = 1; i <= Log; i++) {
			for (int j = 0; j < N; j++) {
				if (par[j][i - 1] != -1)par[j][i] = par[par[j][i - 1]][i - 1];
			}
		}
	}

	int lca(int u, int v) {
		int cur = u;
		cur = isAncestor(u, v);
		for (int i = Log; i >= 0; i--) {
			if (par[v][i] != -1 && isAncestor(u, par[v][i]) == -1) {
				v = par[v][i];
			}
		}
		if (cur == -1)cur = par[v][0];
		return cur;
	}
};


int main() {
	FastIO;
	int n;
	cin >> n;
	vector<int> edge[n + 10];
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		while (m--) {
			int v; cin >> v;
			edge[i].push_back(v);
			edge[v].push_back(i);
		}
	}

	LCA lc(n, edge);
	lc.dfs(0);
	lc.preProcess();

	int q; cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << u << ' ' << v << '\n';
		cout << lc.lca(u, v) << '\n';
	}
	return 0;
}