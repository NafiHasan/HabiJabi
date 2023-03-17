#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int mod = 1e9 + 7;
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	vector<int> dp(1000005, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]] = 1;
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (i < a[j])continue;
			dp[i] = dp[i] + dp[i - a[j]];
			dp[i] %= mod;
		}
	}
	cout << dp[x] << '\n';
	return 0;
}