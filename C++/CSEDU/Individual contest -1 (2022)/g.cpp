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
		vector<int> a(n), last(200005, -1), dp(n, -1);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		dp[0] = 0;
		last[a[0]] = 0;
		for (int i = 1; i < n; i++) {
			int tmp = i - 1;
			if (last[a[i]] != -1)tmp = last[a[i]];
			dp[i] = min(dp[i - 1] + 1, dp[tmp] + 1);
			last[a[i]] = i;
		}
		cout << dp[n - 1] << "\n";
	}
	return 0;
}