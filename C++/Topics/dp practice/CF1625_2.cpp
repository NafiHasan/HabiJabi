#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

ll n, l , k;
ll dp[505][505];
ll signs[505], ti[505];

ll fun(ll cur_ind, ll cur_skipped) {
	if (cur_ind >= n) {
		return 0;
	}

	if (dp[cur_ind][cur_skipped] != -1) {
		return dp[cur_ind][cur_skipped];
	}

	ll ans = LLONG_MAX;

	for (int i = 0; i <= k ; i++) {
		if (cur_skipped + i > k)break;
		ll take = cur_ind + i + 1;
		if (take > n)break;
		ans = min(ans, (signs[take] - signs[cur_ind]) * ti[cur_ind] + fun(take, cur_skipped + i));
		// taking the current index = cur_ind and skipping the next i indices
	}

	return dp[cur_ind][cur_skipped] = ans;
}


int main() {
	FastIO;
	cin >> n >> l >> k;
	for (int i = 0; i < n; i++)cin >> signs[i];
	for (int i = 0; i < n; i++)cin >> ti[i];
	signs[n] = l;
	ti[n] = 0;
	memset(dp, -1 , sizeof dp);

	cout << fun(0, 0) << '\n';
	return 0;
}