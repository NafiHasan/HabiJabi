#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	FastIO;
	int n, m;
	string s, t;
	cin >> s >> t;
	n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 5, vector<int> (m + 5, 1e9));
	dp[0][0] = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 && j != 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
			}
			if (j == 0 && i != 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
			if (i > 0 && j > 0) {
				int cost = 0;
				if (s[i - 1] != t[j - 1])cost = 1;
				dp[i][j] = min(dp[i][j], min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost)));
			}
		}
	}
	cout << dp[n][m] << '\n';

	return 0;
}