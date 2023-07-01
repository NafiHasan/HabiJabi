#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int N = 200005;

vector<int>edge[N], w(N, 0), ans(N, 0);
vector<bool> vis(N, 0), f(N, 0);
void dfs(int u, bool val) {
	vis[u] = 1;
	if (val == 1) {
		f[u] = 1;
		int cnt = 0;
		for (int i = 0; i < edge[u].size(); i++) {
			if (w[edge[u][i]] > 0)cnt += w[edge[u][i]];
			else cnt++;
		}
		// cout << u << ' ' << cnt << '\n';
		w[u] = cnt;
	} else {
		f[u] = 0;
		w[u] = 1;
	}
	for (int i : edge[u]) {
		if (!vis[i])dfs(i, !f[u]);
	}
}


int main() {
	fast_io();
	int n;
	cin >> n;
	// if (n == 2) {
	// 	cout << "2 2\n1 1\n";
	// 	return 0;
	// }
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	int one = 0;
	for (int i = 1; i <= n; i++) {
		if (edge[i].size() == 1) {
			one++;
		}
	}
	int root = 1;
	dfs(root, 1);
	int good = 0, sum = 0;
	// vector<int> ans(n+1, 0);8
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) {
			good++;
		} else {
			w[i] = 1;
		}
		sum += w[i];
	}
	ans = w;
	// cout << good << ' ' << sum << '\n';
	root = edge[1][0];
	// cout << root <<  '\n';
	// vis.clear();
	// f.clear();
	for (int i = 0; i <= n; i++) {
		w[i] = 0, vis[i] = 0, f[i] = 0;
	}
	dfs(root, 1);
	int g2 = 0, s2 = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) {
			g2++;
		} else w[i] = 1;
		s2 += w[i];
	}
	if (good < g2) {
		good = g2;
		sum = s2;
		ans = w;
	} else if (good == g2) {
		if (sum > s2) {
			sum = s2;
			ans = w;
		}
	}
	if (good <= one) {
		sum = n;
		good = one;
		for (int i = 1; i <= n; i++)ans[i] = 1;
	}
	cout << good << ' ' << sum << '\n';
	for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
	cout << "\n";
	return 0;
}