#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	vector<int>ded(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int  u, v;
		cin >> u >> v;
		if (u > v)swap(u, v);
		ded[u]++;
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ded[i] == 0)ans++;
	}
	// cout << ans << "\n";
	int q;
	cin >> q;
	while (q--) {
		int t, u, v;
		cin >> t;
		if (t < 3) {
			cin >> u >> v;
			if (u > v)swap(u, v);
		}
		if (t == 1) {
			ded[u]++;
			if (ded[u] == 1) {
				ans--;
			}
		} else if (t == 2) {
			ded[u]--;
			if (ded[u] == 0)ans++;
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}