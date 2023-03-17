#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 300005;
vector<pair<int, int> > edge[N];
vector<int> dfsTime(N), low(N), comp(N), bridgeTree[N];
vector<bool> vis(N, 0), isBridge(N, 0);
int timer = 0;

void dfs(int u, int par) {
	vis[u] = 1;
	dfsTime[u] = low[u] = ++timer;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].first, ind = edge[u][i].second;
		if (v == par)
			continue; // don't visit the parent node
		if (vis[v]) {  // cross edge
			low[u] = min(low[u], dfsTime[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfsTime[u]) {  // checking among the back edges
				// u->v is a bridge
				isBridge[ind] = 1;
			}
		}
	}
}

void dfs2(int u, int comp_number) {
	vis[u] = 1;
	comp[u] = comp_number;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].first, ind = edge[u][i].second;
		if (!vis[v] && !isBridge[ind]) {
			dfs2(v, comp_number);
		}
	}
}


void make_bridge_tree(int n) {
	// assign unique component number to each component
	vis.assign(n, 0);
	int comp_number = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs2(i, i);
			// comp_number++;

		}
	}

	//creating bridge tree
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			int v = edge[i][j].first;
			if (comp[i] != comp[v]) {
				bridgeTree[comp[i]].push_back(comp[v]);
				bridgeTree[comp[v]].push_back(comp[i]);
			}
		}
	}
}

void find_bridges(int n) {
	timer = 0;
	vis.assign(n, 0);
	low.assign(n, -1);
	dfsTime.assign(n, -1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i, -1);
	}
}

int maxDis, lastNode = 1;

void dfs3(int u, int dis) {
	// cout << u << ' ' << dis << '\n';
	vis[u] = 1;
	if (dis > maxDis)lastNode = u;
	maxDis = max(maxDis, dis);
	for (int v : bridgeTree[u]) {
		if (!vis[v]) {
			dfs3(v, dis + 1);
		}
	}
}

int main() {
	// FastIO;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
	}
	find_bridges(n);
	make_bridge_tree(n);

	// finding diameter
	int best = 0, edge1, edge2;

	vis.assign(n + 1, 0);

	// cout << comp[1] << '\n';
	dfs3(comp[1], 0);
	edge1 = comp[lastNode];
	maxDis = 0;

	// cout << lastNode << '\n';
	vis.assign(n + 1, 0);
	dfs3(lastNode, 0);
	edge2 = comp[lastNode];

	if (maxDis == 0 || edge1 == edge2) {
		edge1 = 1; edge2 = 2;
	}
	cout << edge1 << ' ' << edge2 << '\n';
	return 0;
}