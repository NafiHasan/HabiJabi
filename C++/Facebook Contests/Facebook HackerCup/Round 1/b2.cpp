#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
const ll mod = 1e9 + 7;

int main() {
	FastIO;
	int tc;
	cin >> tc;
	for (int cs = 1; cs <= tc; cs++) {
		cout << "Case #" << cs << ": ";
		ll n;
		cin >> n;
		vector<pair<ll, ll>> a(n);
		ll sum1 = 0, sum2 = 0, a1 = 0, a2 = 0, b1 = 0, b2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].first >> a[i].second;
			sum1 = (sum1 + ((a[i].first % mod) * (a[i].first % mod)) % mod) % mod;
			sum1 = (sum1 + ((a[i].second % mod) * (a[i].second % mod)) % mod) % mod;
			a1 = (a1 + a[i].first % mod) % mod; a2 = (a2 + a[i].second % mod) % mod;
			a1 %= mod; a2 %= mod;
		}
		ll q;
		cin >> q;
		sum1 = (q % mod) * (sum1 % mod) % mod;
		// sum1 = q * sum1 % mod;
		vector<pair<ll, ll>> b(q);
		for (int i = 0; i < q; i++) {
			cin >> b[i].first >> b[i].second;
			sum2 = (sum2 + ((b[i].first % mod) * (b[i].first % mod)) % mod) % mod;
			sum2 = (sum2 + ((b[i].second % mod) * (b[i].second % mod)) % mod) % mod;
			b1 = (b1 + b[i].first % mod) % mod; b2 = (b2 + b[i].second % mod) % mod;
			b1 %= mod; b2 %= mod;
		}
		sum2 = (n % mod) * (sum2 % mod) % mod;
		ll ans = (sum1 + sum2) % mod;
		ll minus = (((a1 % mod) * (b1 % mod) % mod) + ((a2 % mod) * (b2 % mod) % mod)) % mod;
		minus = (2LL * minus) % mod;
		// cout << ans << ' ' << minus << '\n';
		ans = (ans - minus + mod) % mod;
		cout << ans << '\n';
	}
	return 0;
}