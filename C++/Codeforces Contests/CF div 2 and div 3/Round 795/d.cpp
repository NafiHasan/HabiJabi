#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<long long> a(n), presum(n + 1, 0), mn(n + 2, 1e18 + 9), mx(n + 2, -1e18 + 9);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			presum[i + 1] = presum[i] + a[i];
		}
		for (int i = n; i >= 1; i--) {
			mx[i] = max(mx[i + 1], presum[i]);
		}
		// cout << '\n';
		for (int i = 1; i <= n; i++) {
			mn[i] = min(mn[i - 1], presum[i]);
			cout << mn[i] << ' ';
		}
		cout << '\n';
		bool ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > 0) {
				long long lo = i + 1, hi = n, mid, ind2 = n, mxx = presum[n];
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (mx[mid] >= mxx) {
						mxx = mx[mid];
						lo = mid + 1;
						ind2 = mid;
					} else hi = mid - 1;
				}
				lo = 0, hi = i;
				long long ind1 = 0, mnn = presum[0];
				while (lo <= hi) {
					mid = (lo + hi) / 2;
					if (mn[mid] <= mnn) {
						mnn = mn[mid];
						hi = mid - 1;
						ind1 = mid;
					} else {
						lo = mid + 1;
						// cout << lo << ' ' << hi << '\n';
					}
				}
				cout << ind1 << ' ' << ind2 <<  '\n';
				if (presum[ind2] - presum[ind1] > a[i]) {
					// cout << i << '\n';
					// cout << ind1 << ' ' << ind2 << '\n';
					cout << presum[ind2] - presum[ind1] << '\n';
					ans = 1;
					break;
				}
			}
		}
		if (!ans)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}