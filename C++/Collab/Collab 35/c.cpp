#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod = 1e6 + 3;
const int N = 1e6 + 10;
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
void factmodp() {
	fact[0] = 1LL;
	for (ll i = 1; i < N; i++)fact[i] = (fact[i - 1] * i) % mod;
}

void invfactmodp() {
	inv[0] = 1;
	for (ll i = 1; i < N; i++)inv[i] = binpow(fact[i] , mod - 2);
}

ll ncr(ll n, ll r) {
	// n %= mod, r %= mod;
	if (r == 0)return 1;
	if (r > n) return 0;
	return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {
	FastIO;
	factmodp();
	invfactmodp();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, l, r;
		cin >> n >> l >> r;
		ll ans = ncr((n + (r - l + 1)) / mod, n / mod) * ncr((n + (r - l + 1)) % mod, n % mod) % mod;
		ans--;
		ans = (ans + mod) % mod;
		cout << ans << '\n';
	}
	return 0;
}