#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
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
	if (r == 0)return 1;
	if (r > n) return 0;
	return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {
	FastIO;
	factmodp();
	invfactmodp();
	while (1) {
		ll n, x;
		cin >> n >> x;
		if (n == 0)break;
		ll ans = 0;
		for (ll i = n - 1; i <= x; i++) {
			ans += ncr(i, (n - 1));
		}
		cout << ans << '\n';
	}
	return 0;
}