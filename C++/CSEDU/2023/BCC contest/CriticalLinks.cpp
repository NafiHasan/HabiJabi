#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
const int N = 300005;
vector<pair<int, int> > edge[N], bridges;
vector<int> dfsTime(N), low(N);
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
				bridges.push_back({min(u, v), max(u, v)});
				isBridge[ind] = 1;
			}
		}
	}
}

void find_bridges(int n) {
	timer = 0;
	vis.assign(n + 1, 0);
	low.assign(n + 1, -1);
	dfsTime.assign(n + 1, -1);
	for (int i = 0; i < n; i++) {
		if (!vis[i])dfs(i, -1);
	}
}


int main() {
	// FastIO;
	while (1) {
		int n;
		cin >> n;
		if (cin.eof())break;
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
		}
		for (int i = 0; i < n; i++) {
			string s;
			int u, v, m;
			cin >> u >> s;
			m = stoi(s.substr(1, (int)s.size() - 2));
			for (int j = 0; j < m; j++) {
				cin >> v;
				edge[u].push_back({v, i});
				edge[v].push_back({u, i});
			}
		}
		bridges.clear();
		find_bridges(n);
		cout << bridges.size() << " critical links\n";
		sort(bridges.begin(), bridges.end());
		for (int i = 0; i < bridges.size(); i++) {
			cout << bridges[i].first << " - " << bridges[i].second << '\n';
		}
		cout << "\n";
	}
	return 0;
}