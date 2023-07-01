#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), edges[n + 1], deg(n + 1, 0);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
			deg[u]++;
			deg[v]++;
		}
		if (m % 2 == 0) {
			cout << "0\n";
			continue;
		}
		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (deg[i] % 2 == 1)ans = min(ans, a[i]);
			else {
				for (auto j : edges[i]) {
					if (deg[j] % 2 == 0)ans = min(ans, a[i] + a[j]);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}