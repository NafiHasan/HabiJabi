#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
typedef long long ll;

ll dp[205][205][30];
ll a[205], fv[205], tw[205];
ll n, k;

ll f(ll ind, ll cap, ll five) {

	if (ind >= n)return 0;
	if (cap <= 0)return 0;
	if (dp[ind][cap][five] != -1)return dp[ind][cap][five];


	ll ans = 0;
	ans = max(ans, f(ind + 1, cap, five));
	ans = max(ans, f(ind + 1, cap - 1, five + fv[ind]) + tw[ind]);

	return dp[ind][cap][five] = ans;
}



int main() {
	FastIO;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ll tmp = a[i];
		while (tmp > 0 && tmp % 2 == 0) {
			tw[i]++;
			tmp /= 2;
		}
		tmp = a[i];
		while (tmp > 0 && tmp % 5 == 0) {
			tw[i]++;
			tmp /= 5;
		}
	}
	memset(dp, -1, sizeof dp);
	ll ans ;
	ans = min(f(0, k, 0), 0LL);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int l = 0; l < 30; l++) {
				cout << i << ' ' << j << ' ' << l << ' ' << dp[i][j][l] << '\n';
				ans = max(ans, min(dp[i][j][l], (ll)l));
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}