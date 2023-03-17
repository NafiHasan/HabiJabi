#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
const int mod = 1e9 + 7;
int n, x;
int coin[105];
int dp[1000005];
int way(int val, int last) {
	// cout << val << '\n';
	if (val == 0)return dp[val] = 1;
	if (val < 0)return dp[val] = 0;
	if (dp[val] != -1)return dp[val];
	int ans = 0;
	for (int i = last; i < n; i++) {
		// if (coin[i] < last)continue;
		if (val - coin[i] <= x )ans += way(val - coin[i], i);
		ans %= mod;
	}
	return dp[val] = ans % mod;
}


signed main() {
	FastIO;
	cin >> n >> x;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)cin >> coin[i];
	sort(coin, coin + n);
	cout << way(x, 0) << '\n';
	return 0;
}