#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 100005;
vector<int> edge[N];
vector<bool> vis(N, 0);
vector<int> v(N), w(N);

void dfs(int u) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			// w[i] = max(w[i], dfs(i));
			dfs(i);
		}
	}
	int ind = -1, mn = INT_MAX;
	for (int i : edge[u]) {
		// cout << "edge "  << i << '\n';
		if (w[i] < mn) {
			ind = i;
			mn = w[i];
		}
	}
	if (ind != -1) {
		w[u] = max(w[u], w[ind]);
		w[ind] = 0;
		// cout << ind << " ind\n";
	}
	// w[u] = max(w[u], w[ind]);
	// int tmp = w[u];
	// w[u] = 0
	// return ;
}



int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n;
		cin >> n;
		vector<int> forest;
		for (int i = 0; i <= n; i++) {
			v[i] = 0, w[i] = 0;
			edge[i].clear();
			vis[i] = 0;
		}

		for (int i = 1; i <= n; i++) cin >> w[i];
		for (int i = 1; i <= n; i++) cin >> v[i];
		for (int i = 1; i <= n; i++) {
			if (v[i] != 0) {
				edge[v[i]].push_back(i);
			} else {
				forest.push_back(i);
			}
		}

		for (int i = 0; i < forest.size(); i++)dfs(forest[i]);
		// w[1] = max(w [1] , dfs(1));
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans += (long long)w[i];
			// cout << w[i] << '\n';
		}
		cout << "Case #" << cs << ": " << ans << '\n';
	}
	return 0;
}