#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod = 1e9 + 7;

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

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n);
		map<ll, ll> cnt;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[a[i]]++;
		}
		sort(a.begin(), a.end());
		ll l = 0, r = 0;
		ll wind = 1LL;
		while (r < n && l < n) {
			if (a[r] - a[l] < m - 1) {
				r++;
			} else if (a[r] - a[l] >= m) {
				l++;
			} else break;
		}
		// cout << l << ' ' << r << '\n';
		if (r >= n || (r - l < m - 1)) {
			cout << "0\n";
			continue;
		}
		for (ll i = l; i <= r; i++) {
			if (i > 0 && a[i] == a[i - 1])continue;
			wind = wind * cnt[a[i]] % mod;
		}
		// cout << wind << '\n';
		ll ans = wind;
		r++;
		int dif = m + 1;
		while (r < n && l < n) {
			if (r > 0 && a[r] == a[r - 1]) {
				r++;
			} else if (l > 0 && a[l] == a[l - 1])l++;
			else if (a[r] - a[l] < m - 1) {
				r++;
				dif++;
			} else if (a[r] - a[l] >= m) {
				wind = wind * binpow(cnt[a[l]], mod - 2LL) % mod;
				l++;
				dif--;
			} else {
				// cout << a[l] << ' ' << a[r] << ' ' << dif << '\n';
				if (dif == m) {
					wind = wind * cnt[a[r]] % mod;
					ans += wind;
					ans %= mod;
				}
				r++;
				dif++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}