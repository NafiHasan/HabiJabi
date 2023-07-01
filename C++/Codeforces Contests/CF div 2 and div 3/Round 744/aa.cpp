#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define ll long long

const ll mod = 1e9 + 7;
const int N = 2e5 + 10;
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

ll ncr(ll n, ll r) {
	if (r == 0)return 1;
	ll ans = (fact[n] * invfact[r]) % mod;
	ans = (ans * invfact[n - r]) % mod;
	return ans % mod;
}


int main() {
	fast_io();
	factmodp();
	cout << fact[] << "\n";
	int cnt = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			for (int k = 1; k <= 6; k++) {
				for (int l = 1; l <= 6; l++) {
					for (int m = 1; m <= 6; m++) {
						for (int n = 1; n <= 6; n++) {
							if (i == j || i == k || j == k || j == l || i == l || i == m || i == n || j == m || j == n || k == l || k == m || k == n || l == m || l == n || m == n)continue;
							int a[] = {i, j, k, l, m, n};
							int ans = 0;
							for (int o = 0; o < 5; o++) {
								if (a[o] < a[o + 1])ans++;
							}
							if (ans >= 3)cnt++;;
						}
					}
				}
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}