#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 400005;
const int INF = 1e9 + 7;

vector<int> edge[N], depth(N, INF);
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i);
			// if (depth[i] + 1 == edge[u].size()) depth[u] = min (depth[u] , depth[i] + 1);
			// depth[u] = min(depth[u], depth[i] + 1);
			// depth[i] = min(depth[i] , depth[u] + 1);
			// depth[i] = min(depth[i], depth[u]);
		}
		if (depth[i] + 1 == edge[u].size()) depth[u] = min (depth[u] , depth[i] + 1);
		// if (depth[u] + 1 == edge[i].size()) depth[i] = min(depth[i], depth[u] + 1);
		// if (depth[u] + 1 == edge[i].size()) depth[i] = depth[u] + 1;
		// depth[u] = min(depth[u], depth[i] + 1);
		// depth[i] = min(depth[i] , depth[u] + 1);
	}
	// if (edge[u].size() == 1)depth[u] = 0;
	// return depth[u];
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;

		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			depth[i] = INF;
			edge[i].clear();
		}

		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) {
			if (edge[i].size() <= 1)depth[i] = 1;
		}
		dfs(1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			cout << i << ' ' << depth[i] << '\n';
			if (depth[i] > k)cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}