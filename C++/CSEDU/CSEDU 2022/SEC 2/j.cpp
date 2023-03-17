#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	int a[n][n];
	vector<int> all;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			all.push_back(a[i][j]);
		}
	}
	sort(all.begin(), all.end());
	int ans = INT_MAX, lo = 0, hi = INT_MAX, mid;
	while (lo <= hi) {
		mid = (lo + hi) / 2;
		int x, y;
		vector<pair<int, int>> tmp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] == mid) {
					tmp.push_back({i, j});
				}
			}
		}
		bool ok = 0;
		for (int i = 0; i < tmp.size(); i++) {
			x = tmp[i].first - k + 1, y = tmp[i].second - k + 1;
			x = max(x, 0), y = max(y, 0);
			vector<int> got;
			cout << all[mid] << ' ' << x << ' ' << y << '\n';
			for (int j = x; j <= n - k; j++) {
				for (int l = y; l <= n - k; l++) {
					got.push_back(a[j][l]);
				}
			}
			sort(got.rbegin(), got.rend());
			int med = k * k / 2;
			if (got[med] == mid) {
				ok = 1;
				break;
			}
		}
		if (ok) {
			ans = min(ans, mid);
			hi = mid - 1;
		} else lo = mid + 1;
	}
	cout << ans << '\n';
	return 0;
}