#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define int long long

const int mod = 1e9 + 7;


signed main() {
	FastIO;
	int n, val;
	cin >> n >> val;
	vector<int> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> dp(1000005, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= val; j++) {
			if (a[i] <= j)dp[j] += dp[j - a[i]];
			dp[j] %= mod;
		}
	}
	cout << dp[val] << '\n';
	return 0;
}