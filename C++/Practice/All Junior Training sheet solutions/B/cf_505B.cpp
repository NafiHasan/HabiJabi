#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 205;

vector<pair<int, int>> edge[N];
vector<bool> vis(N, 0);
map<int, int> mp;
int clr = 0;

void dfs(int u, int des, int color) {
	vis[u] = 1;
	if (u == des) {
		if (mp[color] == 0) {
			clr++;
			mp[color]++;
		}
		return;
	}
	for (int i = 0; i < edge[u].size(); i++) {
		if (!vis[edge[u][i].first] && edge[u][i].second == color)dfs(edge[u][i].first, des, color);
	}
}

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, x;
		cin >> u >> v >> x;
		edge[u].push_back({v, x});
		edge[v].push_back({u, x});
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		clr = 0;
		mp.clear();
		for (int i = 0; i < edge[u].size(); i++) {
			for (int j = 0; j < N; j++)vis[j] = 0;
			dfs(u, v, edge[u][i].second);
		}
		cout << clr << '\n';
	}
	return 0;
}