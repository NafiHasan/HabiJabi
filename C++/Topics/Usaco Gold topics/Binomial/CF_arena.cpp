#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod = 998244353;
const int N = 2e3 + 10;
vector<ll>fact(N), inv(N);

ll binpow(ll a, ll n) {
	a %= mod;
	ll ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans % mod;
}
// void factmodp() {
// 	fact[0] = 1LL;
// 	for (ll i = 1; i < N; i++)fact[i] = (fact[i - 1] * i) % mod;
// }

// void invfactmodp() {
// 	inv[0] = 1;
// 	for (ll i = 1; i < N; i++)inv[i] = binpow(fact[i] , mod - 2);
// }

// ll ncr(ll n, ll r) {
// 	if (r == 0)return 1;
// 	if (r > n) return 0;
// 	return fact[n] * inv[r] % mod * inv[n - r] % mod;
// }
int main() {
	fast_io();
	// factmodp();
	// invfactmodp();
	ll n, x;
	cin >> n >> x;
	ll ans = binpow(x, n);
	if (x < n) {
		cout << ans << '\n';
		return 0;
	}
	cout << ans << '\n';
	ll sum = 0;
	for (ll i = (x - n + 1), j = x - 1 ; i >= 1; i--, j--) {
		// ans = ans - (n * binpow(j, n - 1) % mod);
		// ans = (ans + mod) % mod;
		cout << j << ' ' << n - 1 << '\n';
		sum += binpow(j, n - 1) % mod;
		// sum %= mod;
		// cout << ans << '\n';

	}
	sum = sum * n % mod;
	ans = (ans - sum + mod) % mod;
	cout << ans << '\n';
	return 0;
}