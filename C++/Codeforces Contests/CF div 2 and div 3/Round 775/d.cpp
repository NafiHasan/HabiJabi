#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		long long n, c;
		cin >> n >> c;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		if (a[0] != 1) {
			cout << "NO\n";
			continue;
		}
		bool ans = 1;
		for (int i = 1; i < n; i++) {
			int lo = i, hi = n - 1, mid, ind = -1;
			long long find = a[i];
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (a[mid] >= find * 2 && a[mid] < find * (2 * find - 1)) {
					ind = mid;
					break;
				} else if (a[mid] < 2 * find) {
					lo = mid + 1;
				} else hi = mid - 1;
			}
			if (ind == -1)continue;
			else {
				ans = 0;
				break;
			}
		}
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}