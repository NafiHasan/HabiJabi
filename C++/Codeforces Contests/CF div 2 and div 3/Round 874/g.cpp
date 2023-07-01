#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;
vector<int> edge[N], child(N, 0);
vector<bool> vis(N, 0);
bool ok;
map<pair<int, int> , int> mp;
void dfs(int u, int par) {
	vis[u] = 1;

	for (int v : edge[u]) {
		if (!vis[v]) {
			dfs(v, u);
			if (child[v] > 0 && child[v] == 2) {
				child[v] = 0;
				mp[ {u, v}]++;
				mp[ {v, u}]++;
			} else if (child[v] != 2) {
				child[u] += child[v] + 1;
			} else if (child[v] == 0)child[u]++;
		}
	}
	// cout << u << ' ' << child[u] << '\n';
	if (child[u] > 1 && child[u] != 2)ok = 0;
	// else if (child[u] > 0 && child[u] % 2 == 0 && par != -1) {
	// 	mp[ {u, par}]++;
	// 	mp[ {par, u}]++;
	// 	child[u] = 0;
	// }
}



int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		for (int i = 0; i <= n; i++) {
			edge[i].clear();
			vis[i] = 0;
			child[i] = 0;
		}
		mp.clear();

		vector<pair<int, int>> vp(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			vp[i] = {u, v};
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if (n % 3 != 0) {
			cout << "-1\n";
			continue;
		}
		ok = 1;
		dfs(1, -1);
		if (ok) {
			vector<int> ans;
			for (int i = 0; i < n - 1; i++) {
				if (mp[vp[i]] != 0)ans.push_back(i + 1);
			}
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); i++)cout << ans[i] << ' ';
			cout << '\n';
		} else cout << "-1\n";
	}
	return 0;
}