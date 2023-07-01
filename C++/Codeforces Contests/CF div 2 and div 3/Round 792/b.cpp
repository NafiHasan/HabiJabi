#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int n;
	cin >> n;
	int mod = 1e9 + 7;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= min(n, 6); i++)dp[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i < j)continue;
			dp[i] += dp[i - j];
			dp[i] %= mod;
		}
	}
	cout << dp[n] << '\n';
	return 0;
}