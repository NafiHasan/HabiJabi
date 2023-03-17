#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;
const ll N = 5000;
ll dp[N + 5][N + 5], cnt[N + 5][2];
ll n, m;
vector<ll> toss(N);

map<ll, ll> mp;

ll f(ll ind, ll streak) {
	if (ind >= n)return 0;
	if (dp[ind][streak] != -1)return dp[ind][streak];

	ll ans = 0;
	ans = max(ans, toss[ind] + mp[streak + 1] + f(ind + 1, streak + 1));
	ans = max(ans, f(ind + 1, 0));
	return dp[ind][streak] = ans;
}


int main() {
	FastIO;
	cin >> n >> m;

	for (int i = 0; i < n; i++)cin >> toss[i];
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		mp[x] = y;
	}

	// memset(cnt, 0, sizeof(cnt));
	memset(dp, -1, sizeof(dp));
	// dp[0][0] = toss[0], dp[0][1] = toss[0];
	// for (int i = 1; i < n ; i++) {
	// 	for (int st = 0; st <= i; st++){

	// 	}
	// }
	ll ans = max(toss[0] + mp[1] + f(1, 1), f(1, 0));
	cout << ans << '\n';
	return 0;
}