#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod = 1e9 + 7;
const int N = 1e5 + 10;
vector<ll>fact(N), invfact(N);

ll bigmod(ll a, ll n) {
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
	invfact[0] = 1;
	for (ll i = 1; i < N; i++)invfact[i] = bigmod(fact[i], mod - 2);
}

ll npr(ll n, ll r) {
	if (r == 0)return 1;
	if (n < r)return 0;
	ll ans = (fact[n] * invfact[r]) % mod;
	ans = (ans * invfact[n - r]) % mod;
	ans = (ans * fact[r]) % mod;
	return ans % mod;
}

int main() {
	fast_io();
	int tc;
	cin >> tc;
	factmodp();
	invfactmodp();
	while (tc--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		map<ll, ll>ind;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			ind[a[i]] = i + 1;
		}
		int l = min(ind[0], ind[1]), r = max(ind[0], ind[1]);
		ll ans = 1, cnt = 0, pre = 1, pos = 0;
		for (int i = 2; i < n; i++) {
			if (ind[i] > r) {
				if (cnt > 0) {
					ans = ans * npr((r - l - 1 - pos), cnt);
					ans %= mod;
					pos += cnt;
					cnt = 0;
				}
				pos++;
				r = ind[i];
				continue;
			}
			if (ind[i] < l) {
				if (cnt > 0) {
					ans = ans * npr((r - l - 1 - pos), cnt);
					ans %= mod;
					pos += cnt;
					cnt = 0;
				}
				pos++;
				l = ind[i];
				continue;
			}
			cnt++;
		}
		if (cnt > 0) {
			ans = ans * npr((r - l - 1 - pos), cnt);
			ans %= mod;
		}
		cout << ans << '\n';
	}
	return 0;
}