#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		sort(a.begin(), a.end());
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			int lo = i + 1, hi = n - 1, mid;
			int ind1 = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] + a[i] >= l) {
					ind1 = mid;
					hi = mid - 1;
				} else lo = mid + 1;
			}
			if (ind1 == -1)continue;
			lo = ind1, hi = n - 1;
			int ind2 = -1;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] + a[i] <= r) {
					ind2 = mid;
					lo = mid + 1;
				} else hi = mid - 1;
			}
			// cout << i << ' ' << ind1 << ' ' << ind2 << '\n';
			if (ind2 != -1)ans += (ind2 - ind1 + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}