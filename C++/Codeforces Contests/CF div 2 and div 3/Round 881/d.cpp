#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long

const int N = 200005;
vector<int> edge[N], leaf(N, 0);
vector<bool> vis(N, 0);

void dfs(int u) {
	vis[u] = 1;

	for (int v : edge[u]) {
		if (!vis[v]) {
			dfs(v);
			leaf[u] += max(1LL, leaf[v]);
		}
	}
	if (u != 1 && edge[u].size() == 1) {
		leaf[u]++;
	}
}



int32_t main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0;
			leaf[i] = 0;
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1);
		int q;
		cin >> q;
		while (q--) {
			int u, v;
			cin >> u >> v;
			cout << leaf[u] * leaf[v] << '\n';
		}
	}
	return 0;
}