#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N], low(N), tim(N);
vector<bool> vis(N, 0);
vector<pair<int, int>> tree, back;
bool bridge = 0;
int tCnt = 0, root;
map<pair<int, int>, int> mp;

void dfs(int u, int par) {
	tCnt++;
	vis[u] = 1;
	tim[u] = tCnt;
	low[u] = tim[u];
	for (int i : edge[u]) {
		if (i == par)continue;
		if (!vis[i]) {
			if (mp[ {u, i}] == 0) {
				tree.push_back({u, i});
				mp[ {u, i}]++;
				mp[ {i, u}]++;
			}
			// tree.push_back({u, i});
			dfs(i, u);
			// low[u] = min(low[u], low[i]);
			// low[u] = min(low[u], tim[i]);
		} else {
			// back.push_back({u, i});
			if (mp[ {u, i}] == 0) {
				back.push_back({u, i});
				mp[ {u, i}]++;
				mp[ {i, u}]++;
			}
		}
		if (i != par)low[u] = min(low[u], low[i]);
	}
	if (low[u] >= tim[u] && u != root) {
		bridge = 1;
	}
}



int main() {
	FastIO;
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> all;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		all.push_back({u, v});
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	root = 1;
	dfs(1, -1);
	// for (int i = 1; i <= n; i++)cout << "time " << tim[i] << '\n';
	// for (int i = 1; i <= n; i++)cout << "low " << low[i] << '\n';
	if (bridge)cout << "0\n";
	else {
		for (int i = 0; i < all.size(); i++) {
			// if (tim[all[i].first] == tim[all[i].second] - 1)
			// 	cout << all[i].first << ' ' << all[i].second << '\n';
			// else
			// 	cout << all[i].second << ' ' << all[i].first << '\n';
		}
		for (int i = 0; i < tree.size(); i++)cout << tree[i].first << ' ' << tree[i].second << '\n';
		for (int i = 0; i < back.size(); i++)cout << back[i].first << ' ' << back[i].second << '\n';
	}
	return 0;
}