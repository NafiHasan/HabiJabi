#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long

const ll mod = 998244353;

ll lcm(ll a, ll b) {
	return a * b / __gcd(a, b);
}

int main() {
	FastIO;
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<ll> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ll ans = 1;
		ll way = 0;
		for (int i = 1; i < n; i++) {
			if (a[i - 1] % a[i] != 0) {
				ans = 0;
				break;
			}
			if (a[i - 1] == a[i]) {
				way = m / a[i];
				ans = ans * way % mod;
				continue;
			}
			way = (m / a[i]);
			way %= mod;


			// counting all the multiples of a[i] which are divisors of a[i - 1],
			// can be easily done with prime factorization

			vector<ll> divs;
			for (ll j = 1; j * j <= a[i - 1]; j++) {
				if (a[i - 1] % j == 0) {
					// cout << j << "f ";
					ll div2 = a[i - 1] / j;
					bool pu = 1;
					for (int k = 0; k < divs.size(); k++) {
						if (j % divs[k] == 0) {
							pu = 0;
							break;
						}
					}
					if (pu && j > a[i] && j % a[i] == 0)divs.push_back(j);
				}
			}
			for (ll j = 1; j * j <= a[i - 1]; j++) {
				if (a[i - 1] % j == 0) {
					ll div2 = a[i - 1] / j;
					bool pu2 = 1;
					for (int k = 0; k < divs.size(); k++) {
						if (div2 % divs[k] == 0) {
							pu2 = 0;
							break;
						}
					}
					if (pu2 && div2 > a[i] && div2 % a[i] == 0) {
						divs.push_back(div2);
					}
				}
			}
			// excluding them
			//principle of inclusion-exclusion

			for (int j = 1; j < (1 << (int)divs.size()); j++) {
				ll lc = 1;
				int cnt = 0;
				for (int k = 0; k < divs.size(); k++) {
					if ((1 << k) & j) {
						lc = lcm(lc, divs[k]);
						cnt++; // can be done with xor or builtin popcount
					}
				}

				if (cnt % 2) {
					way -= m / lc;
					if (way < 0)way += mod;
				} else {
					way += m / lc;
					way %= mod;
				}
			}
			ans = ans * way % mod;

		}
		cout << ans << '\n';
	}
	return 0;
}