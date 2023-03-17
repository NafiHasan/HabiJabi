#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod = 1e9 + 7;
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
	if (r == 0)return 1;
	if (r > n) return 0;
	return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

int main() {
	fast_io();
	factmodp();
	invfactmodp();
	string s;
	cin >> s;
	int n = s.size();
	long long ans = fact[n];
	vector<int> cnt(26, 0);
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		ans = ans * inv[cnt[i]] % mod;
	}
	cout << ans << '\n';
	return 0;
}