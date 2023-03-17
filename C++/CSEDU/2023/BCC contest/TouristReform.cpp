#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 400005;
vector<pair<int, int> > edge[N], ans(N, {0, 0});  // {adjacent edge, index}
vector<int> dfsTime(N), low(N), comp(N), bridgeTree[N], totalComp(N, 0);
vector<bool> vis(N, 0), isBridge(N, 0);
int timer = 0;

//to find bridges
void dfs(int u, int par) {
	pair<int, int> p = {0, 0};
	vis[u] = 1;
	dfsTime[u] = low[u] = ++timer;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].first, ind = edge[u][i].second;
		if (v == par) {
			// if(par != -1)ans[ind] = {v, u};
			continue; // don't visit the parent node
		}
		if (vis[v]) {  // cross edge
			// if (ans[ind] == p)
			//ans[ind] = {v, u};
			low[u] = min(low[u], dfsTime[v]);
		} else {
			//ans[ind] = {u, v};
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfsTime[u]) {  // checking among the back edges
				// u->v is a bridge
				isBridge[ind] = 1;
			} else {
				// ans[ind] = {u, v};
			}
		}
	}
}

int total, maxComp, root;
// to assign unique component number to each component and its children
void dfs2(int u, int comp_number) {
	vis[u] = 1;
	total++;
	comp[u] = comp_number;
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].first, ind = edge[u][i].second;
		if (!vis[v] && !isBridge[ind]) {
			dfs2(v, comp_number);
		}
	}
}

void dfs3(int u) {
	vis[u] = 1;
	// cout << u << '\n';
	pair<int, int> p = {0, 0};
	for (int i = 0; i < edge[u].size(); i++) {
		int v = edge[u][i].first, ind = edge[u][i].second;
		// if (v == par)continue;
		if (!vis[v]) {
			if (ans[ind] == p && !isBridge[ind]) {
				ans[ind] = {u, v};
			} else if (ans[ind] == p && isBridge[ind]) {
				ans[ind] = {v, u};
			}
			dfs3(v);
		} else {
			if (ans[ind] == p) {
				ans[ind] = {u, v};
			}
		}
	}
}

void make_bridge_tree(int n) {
	// assign unique component number to each component
	vis.assign(n + 1, 0);
	comp.assign(n + 1, -1);
	// int comp_number = 1;
	for (int i = 1; i <= n; i++) {
		total = 0;
		if (!vis[i]) {
			dfs2(i, i);
			totalComp[i] = total;
			maxComp = max(maxComp, total);
			//i will be the root of its component
		}
	}

	for (int i = 1; i <= n; i++) {
		if (totalComp[comp[i]] == maxComp) {
			root = i;
			break;
		}
	}

	vis.assign(n + 1, 0);
	dfs3(root);
}

void find_bridges(int n) {
	timer = 0;
	vis.assign(n + 1, 0);
	low.assign(n + 1, -1);
	dfsTime.assign(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i, -1);
	}
}

int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> allEdges;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
		allEdges.push_back({u, v});
	}

	find_bridges(n);
	make_bridge_tree(n);
	cout << maxComp << '\n';
	for (int i = 0; i < m; i++) {
		int u = allEdges[i].first, v = allEdges[i].second;
		pair<int, int> p = {0, 0};
		// if (isBridge[i]) {
		// 	if (totalComp[comp[u]] <= totalComp[comp[v]]) {
		// 		ans[i] = {u, v};
		// 	} else {
		// 		ans[i] = {v, u};
		// 	}
		// }
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	}
	return 0;
}