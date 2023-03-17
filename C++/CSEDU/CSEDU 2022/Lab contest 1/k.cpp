#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 505;
vector<pair<int, int>> edge[N];
vector<bool> vis(N, 0);
int mx = INT_MIN;
vector<int> tmp;

void dfs(int u) {
	vis[u] = 1;
	tmp.push_back(u);

	for (pair<int, int> i : edge[u]) {
		if (!vis[i.first] && i.second == mx) {
			dfs(i.first);
		}
	}
}


int main() {
	fast_io();
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			edge[i].clear();
		}
		mx = INT_MIN;
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edge[u].push_back({v, w});
			edge[v].push_back({u, w});
			mx = max(mx, w);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i])continue;
			tmp.clear();
			dfs(i);
			ans = max(ans, (int)tmp.size());
		}
		cout << ans << '\n';
	}
	return 0;
}