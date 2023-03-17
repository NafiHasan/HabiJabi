#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
const ll mod = 1e9 + 7;
int main() {
	FastIO;
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	int cur = 0;
	vector<ll> dp(n + 1, 0), presum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		if (a[i - 1] > cur) {
			dp[i] = (dp[i] + presum[i - 1] + 1) % mod;

			presum[i] = (presum[i] + dp[i]) % mod;

			presum[i] = (presum[i] + presum[i - 1]) % mod;

			cur = a[i - 1];
		} else {
			presum[i] = (presum[i] + presum[i - 1]) % mod;

			dp[i] = dp[i - 1];

			presum[i] = (presum[i] + dp[i]) % mod;
		}
	}
	cout << (dp[n] % mod) << '\n';
	return 0;
}