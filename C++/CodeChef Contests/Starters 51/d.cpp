#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		ll dp[n + 1][2];
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++)cin >> a[i];
		for (int i = 1; i < n; i++) {
			dp[i][0] = max(dp[i - 1][0] + (a[i] ^ a[i - 1]), dp[i - 1][1] + (a[i] ^ (a[i - 1] + x)));
			dp[i][1] = max(dp[i - 1][0] + ((a[i] + x) ^ a[i - 1]), dp[i - 1][1] + ((a[i] + x) ^ (a[i - 1] + x)));
			// cout << dp[i][0] << ' ' << dp[i][1] << '\n';
		}
		cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
	}
	return 0;
}