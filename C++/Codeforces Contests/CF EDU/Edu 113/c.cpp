#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll p = 998244353;

ll fact[200005], invfact[200005];

long long bigmod(long long a, long long n) {
	a %= p;
	long long ans = 1;
	while (n) {
		if (n & 1) ans = ans * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return ans % p;
}
void factmodp() {
	fact[0] = 1LL;
	for (ll i = 1; i < 200005; i++)fact[i] = (fact[i - 1] * i) % p;
}

void invfactmodp() {
	invfact[0] = 1;
	for (ll i = 1; i < 200005; i++)invfact[i] = bigmod(fact[i], p - 2);
}

long long ncr(long long n, long long r) {
	if (r == 0)return 1;
	long long ans = (fact[n] * invfact[r]) % p;
	ans = (ans * invfact[n - r]) % p;
	return ans % p ;
}


int main() {
	fast_io();
	factmodp();
	invfactmodp();
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		ll mx = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			mx = max(mx, a[i]);
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)if (a[i] == mx)cnt++;
		if (cnt > 1) {
			cout << fact[n] << '\n';
			continue;
		}
		int small = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] + 1 < mx)small++;
		}
		ll minus = 0, ans = fact[n];
		for (int i = 0; i <= small; i++) {
			ll temp = ncr(small, i);
			temp = (temp * fact[i]) % p ;
			temp = (temp * fact[n - i - 1]) % p;
			minus += temp;
			minus %= p;
			// cout << minus << '\n';
		}
		// cout << ans << ' ' << minus << '\n';
		ans -= minus;
		ans += p;
		ans %= p;
		cout << ans << '\n';
	}
	return 0;
}