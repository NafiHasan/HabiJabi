#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll n, l , k;
ll dp[505][505];
ll signs[505], ti[505];

ll fun(ll now, ll taken, ll pre) {
	// cout << now << ' ' << taken << ' ' << pre << '\n';
	if (dp[now][pre] != -1) {
		// if (now == 4 && taken == 1 && pre == 2) cout << signs[now] << ' ' << ti[pre] << '\n';
		// cout << now << ' ' << taken << ' ' << dp[now][taken] << '\n';
		return dp[now][pre];
	}

	if (now == n) {
		// if (now == 4 && taken == 1 && pre == 2) cout << signs[now] << ' ' << ti[pre] << '\n';
		// cout << (signs[now] - signs[now - 1]) * ti[pre] << '\n';
		// cout << taken << '\n';
		ll ans = LLONG_MAX;
		if (taken < k)ans = min(ans, (signs[now] - signs[now - 1]) * ti[pre]);
		return dp[now][pre] = (signs[now] - signs[now - 1]) * ti[pre];
		// else return dp[now][taken] = (signs[now] - signs[now - 1]) * ti[]
	}

	ll ans = LLONG_MAX;
	for (ll i = 0; i <= k; i++) {
		ll rm = i + taken;
		if (rm > k)break;
		if (i != 0) {
			ans = min(ans, (signs[now] - signs[now - 1]) * ti[pre] + fun(now + 1, rm, pre));
		}
		if (i == 0)ans = min(ans, (signs[now] - signs[now - 1]) * ti[pre]  + fun(now + 1, rm, now));
	}
	return dp[now][pre] = ans;
}


int main() {
	FastIO;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)cin >> signs[i];
	for (int i = 0; i < n; i++)cin >> ti[i];
	signs[n] = l;
	ti[n] = ti[n - 1];
	memset(dp, -1 , sizeof dp);

	cout << fun(1, 0, 0) << '\n';
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= n; j++)cout << dp[i][j] << ' ';
	// 	cout << '\n';
	// }
	return 0;
}