#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

long long bigmod (long long a, long long n) {
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

ll dp[30][180];
ll n, x;
ll fun(ll dice_left, ll score) {
	if (dp[dice_left][score] != -1)return dp[dice_left][score];
	if (dice_left == 0 && score >= x)return 1;
	else if (dice_left == 0 && score < x)return 0;
	ll ans = 0;
	for (ll i = 1; i < 7; i++) {
		ans += fun(dice_left - 1, score + i);
	}
	return dp[dice_left][score] = ans;
}


int main() {
	FastIO;
	while (1) {
		cin >> n >> x;
		if (n == 0)break;
		memset(dp, -1, sizeof dp);
		ll ans = 0;
		ans = fun(n, 0);
		ll div = bigmod(6LL, n);
		ll g = __gcd(ans, div);
		ans /= g, div /= g;
		if (ans == 0)cout << "0\n";
		else if (div == 1)cout << ans << '\n';
		else cout << ans << "/" << div << '\n';
	}
	return 0;
}