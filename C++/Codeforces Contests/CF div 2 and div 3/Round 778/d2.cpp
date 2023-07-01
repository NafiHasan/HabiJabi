#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll int
#define MAX 10000003

// const ll mod=1e9+7;
const ll mod = 998244353;

map<pair<ll, ll> , pair<ll, ll>> mp;
const int N = 200005;
vector<int> edge[N];
vector<bool> vis(N, 0);

ll prime[MAX];
unordered_map<int, int> max_map;

ll bigmod(ll a, ll n) {
	a %= mod;
	ll ans = 1;
	while (n) {
		if (n & 1LL) ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1LL;
	}
	return ans % mod;
}



// ll lcm(ll a, ll b) {
// 	return a * b / (__gcd(a, b));
// }



void dfs(int u, pair<ll, ll> now) {
	vis[u] = 1;

	for (int i : edge[u]) {
		if (!vis[i]) {
			ll f = now.first * mp[ {u, i}].first;
			ll s = now.second * mp[ {u, i}].second;
			dfs(i, {f, s});
			// if (i == 1) cout << "f " << f << ' ' << s << '\n';
			mp[ {1, i}] = {f / __gcd(f, s), s / __gcd(f, s)};
		}
		// if (i == 4 )cout << u << '\n';
		if (i != 1 && mp[ {1, i}].first == 0) {
			// mp[ {1, i}].first = mp[ {1, u}].first * mp[ {u, i}].first;
			// mp[ {1, i}].second = mp[ {1, u}].second * mp[ {u, i}].second;
			mp[ {1, i}] = now;
			// cout << 1 << ' ' << i << ' ' << now.first << ' ' << now.second << '\n';
		}
	}
}




// Function to find the smallest prime factors
// of numbers upto MAX
void sieve() {
	prime[0] = prime[1] = 1LL;
	for (ll i = 2; i < MAX; i++) {
		if (prime[i] == 0) {
			for (ll j = i * 2LL; j < MAX; j += i) {
				if (prime[j] == 0) {
					prime[j] = i;
				}
			}
			prime[i] = i;
		}
	}
}

// Function to return the LCM modulo M
ll lcmModuloM(vector<ll> ar) {

	for (int i = 0; i < ar.size(); i++) {
		ll num = ar[i];
		unordered_map<ll, ll> temp;

		// Temp stores mapping of prime factor to
		// its power for the current element
		while (num > 1) {

			// Factor is the smallest prime factor of num
			ll factor = prime[num];

			// Increase count of factor in temp
			temp[factor]++;
			// Reduce num by its prime factor
			num /= factor;
		}

		for (auto it : temp) {

			// Store the highest power of every prime
			// found till now in a new map max_map
			max_map[it.first] = max(max_map[it.first], it.second);
		}
	}

	ll ans = 1;

	for (auto it : max_map) {

		// LCM is product of primes to their highest powers modulo M
		ans = (ans * bigmod(it.first, it.second)) % mod;
	}

	return ans;
}


int main() {
	fast_io();
	sieve();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		for (int i = 0; i <= n ; i++) {
			edge[i].clear();
			vis[i] = 0;
		}
		// lc.clear();
		max_map.clear();
		mp.clear();
		for (int i = 0; i < n - 1; i++) {
			ll u, v , x, y;
			cin >> u >> v >> x >> y;
			mp[ {u, v}] = {x, y};
			mp[ {v, u}] = {y, x};
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		dfs(1, {1, 1});
		ll lc = 1;
		vector<ll> lv;

		for (ll i = 2; i <= n; i++) {
			lv.push_back(mp[ {1, i}].first);
		}

		lc = lcmModuloM(lv);
		vector<long long> ans(n + 5, 0);
		ans[1] = lc;
		for (int i = 2; i <= n; i++) {

			ans[i] = (long long)lc  * (long long)mp[ {1, i}].second   / (long long)mp[ {1, i}].first;
			ans[i] %= mod;
		}
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += ans[i];
			cnt %= mod;
		}
		cout << cnt << '\n';
	}
	return 0;
}