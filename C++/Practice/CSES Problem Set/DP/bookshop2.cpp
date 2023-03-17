#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll int

// map
ll dp[1005][100005], price[1005], page[1005];
ll n, x;


int main() {
	FastIO;
	cin >> n >> x;
	for (int i = 0; i < n; i++)cin >> price[i];
	for (int i = 0; i < n; i++)cin >> page[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (price[i - 1] <= j) {
				dp[i][j] = max(dp[i][j], page[i - 1] + dp[i - 1][j - price[i - 1]]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}

		}
	}
	cout << dp[n][x] << '\n';
	return 0;
}