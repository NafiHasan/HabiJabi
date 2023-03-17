#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long
const ll mod = 1e9 + 7;

int main() {
	FastIO;
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int i = 0; i < n; i++)cin >> grid[i];
	int dp[n + 1][n + 1];
	memset(dp, 0, sizeof dp);
	dp[1][1] = 1;
	if (grid[0][0] == '*') {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == '*')continue;
			dp[i + 1][j + 1] += dp[i][j  + 1] % mod + dp[i + 1][j] % mod;
			dp[i + 1][j + 1] %= mod;
		}
	}
	cout << dp[n][n] << '\n';
	return 0;
}