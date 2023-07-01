#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int dp[200010][4][65];
int n;
string s;
int mx = 0;

int fun(int ind, int three, int seven) {
	// cout << ind << ' ' << three << ' ' << seven << '\n';
	// if (__builtin_popcount(seven) > 3)cout << "what";
	if (ind == 8)return 0;
	if (dp[ind][three][seven] != -1)return dp[ind][three][seven];

	int ans = 0;

	if (__builtin_popcount(three) == 2) {
		int num = (~(1 << 5)) & seven;
		num <<= 1;
		ans = fun(ind + 1, 2, num);
	} else {

		int num = (~(1 << 5)) & seven;
		num <<= 1;
		int n_t = (~(1 << 1)) & three;
		n_t <<= 1;

		ans = max(ans, fun(ind + 1, n_t, num));

		if (__builtin_popcount(seven) < 3) {
			num ^= 1;
			n_t ^= 1;
			int add = (s[ind] - 'a') + 1;
			ans = max(ans, add + fun(ind + 1, n_t , num));
		}
	}
	// mx = max(mx, ans);
	return dp[ind][three][seven] = ans;
}


int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		n = s.size();
		memset(dp, 0, sizeof(dp));
		// mx = 0;
		// fun(0, 0, 0);
		// int mx = 0;
		// dp[0][0][0]
		// fun(0, 0, 0);

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < 4; j++) {
		// 		for (int k = 0; k < 65; k++) {
		// 			if (dp[i][j][k] == -1)dp[i][j][k] = 0;
		// 		}
		// 	}
		// }

		for (int k = 0; k < 65; k++) {
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < n ; i++) {
					// cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
					if (__builtin_popcount(j) == 2) {
						int num = (~(1 << 5)) & k;
						num <<= 1;
						dp[i + 1][2][num] = max(dp[i + 1][2][num], dp[i][j][k]);
					} else {
						int num = (~(1 << 5)) & k;
						num <<= 1;
						int n_t = (~(1 << 1)) & j;
						n_t <<= 1;

						dp[i + 1][n_t][num] = max(dp[i + 1][n_t][num], dp[i][j][k]);
						// ans = max(ans, fun(ind + 1, n_t, num));

						if (__builtin_popcount(k) < 3) {
							num ^= 1;
							n_t ^= 1;
							int add = (s[i + 1] - 'a') + 1;
							// ans = max(ans, add + fun(ind + 1, n_t , num));
							dp[i + 1][n_t][num] = max(dp[i + 1][n_t][num], dp[i][j][k] + add);
							cout << i << ' ' << j << ' ' << k << '\n';
							cout << i + 1 << ' ' << n_t << ' ' << num << '\n';
						}
					}
				}
			}
		}
		mx = 0;
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 65; k++) {
					// cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
					mx = max(mx, dp[i][j][k]);
				}
			}
		}
		cout << mx << '\n';
	}
	return 0;
}