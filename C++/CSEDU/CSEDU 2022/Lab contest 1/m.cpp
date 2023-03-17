#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			dfs(i);
		}
	}
}



int main() {
	fast_io();
	int cs = 1;
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)return 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				ans++;
			}
		}
		cout << "Case " << cs++ << ": " << ans << '\n';

		for (int i = 0; i <= n; i++) {
			vis[i] = 0;
			edge[i].clear();
		}
	}
	return 0;
}