#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 300005;
vector<pair<int, int> > edge[N];  // {adjacent edge, index}
vector<int> dfsTime(N), low(N), comp(N), roots;
vector<bool> vis(N, 0), isBridge(N, 0);
int timer = 0;

//to find bridges
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

// to assign unique component number to each component and its children
int cnt = 0;
void dfs2(int u, int comp_number) {
	vis[u] = 1;
	cnt++;
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
	vis.assign(n + 1, 0);
	comp.assign(n + 1, -1);
	int comp_number = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs2(i, i);
			roots.push_back(cnt);
			//i will be the root of its component
		}
	}
	// for (int i = 0; i <= n; i++)bridgeTree[i].clear();

	// //creating bridge tree
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 0; j < edge[i].size(); j++) {
	// 		int v = edge[i][j].first;
	// 		if (comp[i] != comp[v]) {
	// 			bridgeTree[comp[i]].push_back(comp[v]);
	// 			bridgeTree[comp[v]].push_back(comp[i]);
	// 		}
	// 	}
	// }
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
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back({v, i});
		edge[v].push_back({u, i});
	}
	find_bridges(n);
	make_bridge_tree(n);
	long long all = (long long)n * (long long)(n - 1) / 2;
	long long pos = 0;
	vector<long long> suf(roots.size() + 1, 0);
	for (int i = roots.size() - 1; i >= 0; i--) {
		suf[i] = suf[i + 1] + roots[i];
	}
	for (int i = 0; i < roots.size(); i++) {
		pos += (long long)roots[i] * (long long)suf[i + 1];
	}
	double ans = (double)pos / (double)all;
	cout << fixed << setprecision(5) << ans << '\n';
	return 0;
}