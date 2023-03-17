#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	while (tc--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n), presum(10005, 0);
		int mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (i < k - 1) presum[a[i]] = 1;
			else presum[a[i]] = k;
		}
		for (int i = 1; i <= 10005; i++) {
			// if(a[i] < k)presum[i] = i + 1;
			// else presum[i] =
			if (presum[i] == 0)presum[i] = presum[max(0, i - 1)];
			// cout << i << ' ' << presum[i] << '\n';
		}
		int ans = 0;
		// for (int i = 0; i < n; i++) {
		// 	if (a[i] > p)break;
		// 	if (a[i] > (p - a[i]))presum[a[i]] = presum[a[i]] + presum[p - a[i]];
		// 	cout << a[i] << ' ' << presum[a[i]] << '\n';
		// }
		for (int i = 0; i < n; i++) {
			if (i >= k) {
				presum[a[i] + a[i - k]] = presum[a[i]] + presum[a[i - k]];
			}
			// if (i > p)break;
			// if (i > (p - i))presum[i] = presum[i] + presum[p - i];
			cout << a[i] << ' ' << presum[a[i]] << '\n';
		}
		for (int i = 0; i <= 10005; i++) {
			if (i > p)break;
			ans = max(ans, presum[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}