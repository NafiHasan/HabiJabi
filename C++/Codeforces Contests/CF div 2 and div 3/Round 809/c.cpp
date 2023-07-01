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
		vector<long long> a(n);
		int mx = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 1 && i < n - 1)mx++;
		}
		// cout << mx << '\n';
		for (int i = 1; i < n - 1; i++) {
			if (a[i] > a[i - 1] && a[i] > a[i + 1])cur++;
		}
		if (cur == mx) {
			cout << "0\n";
			continue;
		}
		long long ans = 0;
		if (n % 2 == 1) {
			for (int i = 1; i < n - 1; i += 2 ) {
				if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) {
					ans += max(a[i + 1], a[i - 1]) - a[i] + 1;
				}
			}
		} else {
			vector<long long> dp(n, 0);
			for (int i = 1; i < n - 1; i++) {
				long long inc = 0;
				if (a[i] <= a[i - 1] || a[i] <= a[i + 1]) {
					inc = max(a[i - 1], a[i + 1]) - a[i] + 1;
				}
				dp[i] = inc;
				long long ad = LLONG_MAX;
				if (i > 2) {
					ad = dp[i - 2];
				}
				if (i > 3) {
					// cout << (2 + (i - 4) / 2 + (n - i - 2) / 2) << '\n';
					if ((2 + (i - 4) / 2 + (n - i - 2) / 2) == mx)
						ad = min(ad, dp[i - 3]);
					// else ad = dp[i - 3];
				}
				if (ad != LLONG_MAX)dp[i] += ad;
			}
			// for (int i = 0; i < n; i++)cout << dp[i] << ' ';
			// cout  << '\n';
			ans = min(dp[n - 2], dp[n - 3]);
		}
		cout << ans << '\n';
	}
	return 0;
}