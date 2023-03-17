#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int dp[1000005];
vector<pair<int, int>> tmp(1005);
int n, k;

int fun(int cur, int taken) {
	if (cur >= n || taken > k)return 0;
	if (dp[taken] != -1)return dp[taken];

	int ans = 0;
	if (taken + tmp[cur].second <= k)
		ans = max(ans, tmp[cur].first + fun(cur + 1, taken + tmp[cur].second));
	ans = max(ans, fun(cur + 1, taken));
	return dp[taken] = ans;
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	vector<int>d(1005, 1005);
	d[1] = 0;
	for (int i = 1; i < 1005; ++i) {
		for (int x = 1; x <= i; ++x) {
			int j = i + i / x;
			if (j < 1005) d[j] = min(d[j], d[i] + 1);
		}
	}
	while (tc--) {
		cin >> n >> k;
		vector<int> b(n), c(n);
		for (int i = 0; i < n; i++)cin >> b[i];
		for (int i = 0; i < n; i++)cin >> c[i];


		for (int i = 0; i < n; i++) {
			// int cnt = 0;
			// int now = 1;
			// while (now < b[i]) {
			// 	for (int j = 1; j <= now; j++) {
			// 		if (now + (now / j) <= b[i]) {
			// 			now += (now / j);
			// 			cnt++;
			// 			break;
			// 		}
			// 	}
			// }
			tmp[i] = {c[i], d[b[i]]};
			// cout << c[i] << ' ' << d[b[i]] << '\n';
		}
		memset(dp, -1, sizeof dp);
		int ans = fun(0, 0);
		cout << ans << '\n';
		for (int i = 1; i < 10; i++)cout << dp[i] << ' ';
	}
	return 0;
}