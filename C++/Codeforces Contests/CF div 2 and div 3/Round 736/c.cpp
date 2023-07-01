#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, m;
	cin >> n >> m;
	map<int, int>big, sm;
	for (int i = 0; i < m; i++) {
		int  u, v;
		cin >> u >> v;
		big[min(u, v)]++;
		sm[max(u, v)]++;
	}
	vector<int>liv(n + 1, 0);
	int ans = 0, gone = 0;
	for (int i = 1; i <= n; i++) {
		if (sm[i] - gone > 0 || big[i] == 0) {
			ans++;
			liv[i]++;
		} else if (big[i] > 0) {
			gone++;
		}
	}
	// ans = n - ans;
	// cout << ans << "\n";
	int q;
	cin >> q;
	// gone = 0;
	// int temp = ans;
	while (q--) {
		// ans = temp;
		int t, u, v;
		cin >> t;
		if (t < 3)cin >> u >> v;
		if (t == 1) {
			big[min(u, v)]++;
			sm[max(u, v)]++;
			// cout << sm[min(u, v)] << " " << gone << " ";
			if (sm[min(u, v)] - gone <= 0 && liv[min(u, v)] > 0) {
				ans--;
				big[min(u, v)] = 0;
				sm[min(u, v)] = 0;
				gone++;
				liv[min(u, v)] = 0;
			}
			// cout << ans << "\n";
		} else if (t == 2) {
			big[min(u, v)]--;
			// cout << big[min(u, v)] << "\n";
			sm[max(u, v)]--;
			if (big[min(u, v)] <= 0) {
				ans++;
				liv[min(u, v)] ++;
			}
			if (sm[max(u, v)] - gone <= 0 && big[max(u, v)] > 0 && liv[max(u, v)] > 0) {
				ans--;
				big[max(u, v)] = 0;
				sm[max(u, v)] = 0;
				gone++;
				liv[max(u, v)] = 0;
			}
		} else {
			cout << ans << "\n";
		}
	}
	return 0;
}