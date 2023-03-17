#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
	fast_io();
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		int n , p;
		cin >> n >> p;
		long long a[n][p], mx[n], mn[n];
		for (int i = 0; i < n; i++) {
			mx[i] = 0;
			mn[i] = LLONG_MAX;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				cin >> a[i][j];
				mx[i] = max(mx[i], a[i][j]);
				mn[i] = min(mn[i], a[i][j]);
			}
		}
		long long ans = mx[0], pre = mx[0];
		long long dp[n][2];
		memset(dp, 0 , sizeof(dp));
		mn[0] = mx[0];
		dp[0][0] = mx[0], dp[0][1] = mx[0];
		for (int i = 1; i < n; i++) {
			dp[i][0] =  dp[i - 1][0] + abs(mn[i - 1] - mx[i]) + (mx[i] - mn[i]);
			// abs(mn[i - 1] - mx[i]) + (mx[i] - mn[i]);
			dp[i][0] = min(dp[i][0] , dp[i - 1][1] + abs(mx[i - 1] - mx[i]) + (mx[i] - mn[i]));

			dp[i][1] =  dp[i - 1][1] + abs(mx[i - 1] - mn[i]) + (mx[i] - mn[i]);;
			// abs(mn[i - 1] - mx[i]) + (mx[i] - mn[i]);
			dp[i][1] = min(dp[i][1] , dp[i - 1][0] + abs(mn[i - 1] - mn[i]) + (mx[i] - mn[i]));
			// cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
		}
		ans = min(dp[n - 1][0], dp[n - 1][1]);
		
		cout << "Case #" << cs << ": " << ans << "\n";
	}
	return 0;
}