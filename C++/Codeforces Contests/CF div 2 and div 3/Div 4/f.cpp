#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc; cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n), lef(n, 0), ri(n, 0);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 0; i < n; i++) {
			if (i == 0)lef[i] = a[i];
			else lef[i] = lef[i - 1] + a[i];
			// cout << lef[i] << ' ';
		}
		// cout << "\n";
		for (int i = n - 1, j = 0; i >= 0; j++, i--) {
			if (i == n - 1)ri[j] = a[i];
			else ri[j] = ri[j - 1] + a[i];
			// cout << ri[j] << ' ';
		}
		// cout << "\n";
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			int find = lef[i];
			int lo = 0, hi = n - i - 2, mid;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (ri[mid] == find) {
					ans = max(ans, i + 1 + mid + 1);
					break;
				} else if (ri[mid] < find) {
					lo = mid + 1;
				} else hi = mid  - 1 ;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}