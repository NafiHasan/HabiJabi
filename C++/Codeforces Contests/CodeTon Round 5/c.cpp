#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)cin >> a[i];
		vector<int> dp(n + 1, 0);
		vector<pair<int, int>> best(200005, { -1, -1}); // val, ind
		for (int i = n - 1; i >= 0; i--) {
			dp[i] = max(dp[i + 1], dp[i]);
			if (best[a[i]].second > i) {
				dp[i] = max(dp[i], best[a[i]].second - i + 1 + best[a[i]].first);
			}
			if (dp[i + 1] > best[a[i]].first + (best[a[i]].second - i)) {
				best[a[i]] = {dp[i + 1], i};
			}
			// cout << dp[i] << ' ';
		}
		cout << dp[0] << '\n';
	}
	return 0;
}