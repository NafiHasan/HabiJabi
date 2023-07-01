#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> seg(m);
		for (int i = 0; i < m; i++)cin >> seg[i].first >> seg[i].second;
		int q;
		cin >> q;
		vector<int> ch(q);
		for (int i = 0; i < q; i++)cin >> ch[i];
		int lo = 0, hi = q - 1, mid, ans = INT_MAX;
		while (lo <= hi) {
			mid = (lo + hi) / 2;
			bool done = 0;
			vector<int> a(n, 0);
			for (int i = 0; i <= mid; i++) {
				a[ch[i] - 1] = 1;
			}
			vector<int> presum(n + 1, 0);
			for (int i = 0; i < n; i++) {
				presum[i + 1] = presum[i] + a[i];
			}
			for (int i = 0; i < m; i++) {
				int l = seg[i].first, r = seg[i].second;
				int sum = presum[r] - presum[l - 1];
				if (sum >= (r - l + 3) / 2) {
					done = 1;
					break;
				}
			}

			if (done) {
				hi = mid - 1;
				ans = min(ans, mid);
			} else lo = mid + 1;
		}
		if (ans == INT_MAX)ans = -2;
		cout << ans + 1 << '\n';
	}
	return 0;
}